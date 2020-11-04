/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:43:05 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/03 18:41:11 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

#define mapWidth 		24
#define mapHeight 		24
#define screenWidth 	640
#define screenHeight	480

typedef struct	s_info
{
	void		*mlx_ptr;
	void		*win;

	//start pos
	double		posX;
	double		posY;

	//direction vector
	double		dirX;
	double		dirY;

	//camera plane
	double		planeX;
	double		planeY;

	//current frame
	double		time;
	//previous frame
	double		oldTime;

	// moveSpeed
	double		moveSpeed;
	// rotateSpeed
	double		rotSpeed;
}				t_info;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	verLine(t_info *info, int x, int startY, int endY, int color)
{
	int		y;

	y = startY;
	while (y <= endY)
	{
		mlx_pixel_put(info->mlx_ptr, info->win, x, y, color);
		//mlx_new_image(info->mlx_ptr, x, endY - startY);
		y++;
	}
}

void	calc(t_info *info)
{
	int		x;
	
	x = 0;
	while (x < screenWidth)
	{
		//x - corodinate in camera space
		// cameraX : while문의 x값(화면의 수직선)이 카메라 평면에서 차지하는 위치의 x좌표
		// for문의 x값이 0이면 (스크린의 왼쪽 끝이면) cameraX = -1
		// for문의 x값이 w/2이면 (스크린의 중앙이면) cameraX = 0
		// for문의 x값이 w이면 (스크린의 오른쪽 끝이면) cameraX = 1
		double camera_X = 2 * x / (double)screenWidth - 1;

		// 광선의 시작점은 플레이어 위치로 한다
		// 광선의 방향벡터이다 - 광선의 방향은 (방향벡터) + (카메라평면 * 배수) 이다
		double rayDirX = info->dirX + info->planeX * camera_X;
		double rayDirY = info->dirY + info->planeY * camera_X;

		// 맵중에서 우리가 있는 박스, 현재 광선의 위치로 광선이 있는 한칸이다
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		// 다음 x 또는 y좌표까지의 시작 위치로부터의 광선 거리
		double sideDistX;
		double sideDistY;

		// x or y 벽에서 다음 벽까지의 광선 거리 - 피타고라스의 정리 이용
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		// 광선의 이동거리 계산
		double perpWallDist;

		//x 또는 y 방향(+1 또는 -1)에서 어느 방향으로 갈지
		int stepX;
		int stepY;

		//벽이 맞았는지 체크
		int hit = 0;
		// 북남 or 동서 방향의 벽 체크 - x면에 부딫힌 경우 : 0 - y면에 부딫힌 경우 : 1
		int side;

		// sideDist 초기화
		// 만약 광선의 x방향이 음수라면 stepX를 -1, 양수라면 1로 설정

		// sideDistX : ray가 양수일경우, 광선의 시작점으로부터 오른쪽으로 이동하다가 처음만나는 x면까지의 거리
		// 			 : ray가 음수일경우, 광선의 시작점으로부터 왼쪽으로 이동하다가 처음만나는 x면까지의 거리

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		// 만약 광선의 y방향이 음수라면 stepY를 -1, 양수라면 1로 설정
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

		// DDA알고리즘 
		// 2차원 그리드를 지나가는 선이 어떤 네모칸과 부딪히는지 찾을 때 일반적으로 사용되는 알고리즘

		// 벽에 부딪힐 때마다 한칸씩 광선을 이동시킨다, x or y 방향으로
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//벽에 맞은 경우
			if (worldMap[mapX][mapY] > 0) 
				hit = 1;
		}

		// 광선의 시작점에서 벽까지의 이동거리를 계산
		// 이를 통해 벽의 높이를 그릴때 사용
		// 어안렌즈 효과를 피하기 위해 플레이어 위치까지의 유클리드 거리가 아닌 카메라평면까지의 수직거리를 이용한다
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 + stepY) / 2) / rayDirY;

		
		//구해진 광선부터 벽까지의 거리를 가지고 벽의 높이를 결정 : 벽의 높이 = 맵의 높이 / 광선의 거리 (즉 멀수록 낮아진다)
		int lineHeight = (int)(screenHeight / perpWallDist);

		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drwaEnd = lineHeight / 2 + screenHeight / 2;
		if (drwaEnd >= screenHeight)
			drwaEnd = screenHeight - 1;
		
		// 부딪힌 벽에 따라 색 넣어주기
		int color;

		if (worldMap[mapX][mapY] == 1)
			color = 0xFF0000;
		else if (worldMap[mapX][mapY] == 2)
			color = 0x00FF00;
		else if (worldMap[mapX][mapY] == 3)
			color = 0x0000FF;
		else if (worldMap[mapX][mapY] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
		
		//x면 벽과 y면 벽에 다른 색 주기
		if (side == 1)
			color = color/2;

		// 수직선 그리기 - x를 현재 반복문 width만큼 모두 그리게 된다
		verLine(info, x, drawStart, drwaEnd, color);

		x++;
	}
}

int		main_loop(t_info *info)
{
	calc(info);

	return (0);
}

int		key_press(int key, t_info *info)
{
	if (key == KEY_W)
	{
		if (worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)info->posY] == FALSE)
			info->posX += info->dirX * info->moveSpeed;
		if (worldMap[(int)info->posX][(int)(info->posY + info->dirY * info->moveSpeed)] == FALSE)
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == KEY_S)
	{
		if (worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)info->posY] == FALSE)
			info->posX -= info->dirX * info->moveSpeed;
		if (worldMap[(int)info->posX][(int)(info->posY - info->dirY * info->moveSpeed)] == FALSE)
			info->posY -= info->dirY * info->moveSpeed;
	}
	if (key == KEY_D)
	{
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);

		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	if (key == KEY_A)
	{
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);

		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

void	f_init(t_info *info)
{
	info->posX = 12;	
	info->posY = 5;

	info->dirX = -1;
	info->dirY = 0;

	info->planeX = 0;
	info->planeY = 0.66;

	info->time = 0;
	info->oldTime = 0;

	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
}

int main()
{
	t_info		info;

	//mlx_init()으로 창 생성 - 반환값은 void*
	info.mlx_ptr = mlx_init();
	f_init(&info);

	//화면을 생성 - mlx_new_window()
	info.win = mlx_new_window(info.mlx_ptr, screenWidth, screenHeight, "mlx");

	//화면을 생성한 후 게임 루프가 시작
	//이 반복문은 계속 반복해서 전체 프레임을 그려내고 입력을 읽는 일을 합니다.
	mlx_loop_hook(info.mlx_ptr, &main_loop, &info);
	
	// mlx_hook을 통해 원하는 창에서 발행하는 함수호출, 메시지, 이벤트(키보드, 마우스)를 감지해서 반응한다
	//funct_ptr는 이벤트 발생시 당신이 호출하고 싶은 함수를 가리키는 함수 포인터 입니다. 
	//이 할당은 win_ptr에 의해 특정된 윈도우에만 적용됩니다.
	//param의 주소는 호출될 때마다 전달되고 필요한 매개 변수를 저장하는 데 사용해야합니다.
	mlx_hook(info.win, KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx_ptr);
}