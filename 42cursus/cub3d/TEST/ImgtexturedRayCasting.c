/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImgtexturedRayCasting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:43:05 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 16:30:40 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

#define mapWidth 		24
#define mapHeight 		24
#define screenWidth 	640
#define screenHeight	480
#define texWidth		64
#define texHeight		64

typedef struct	s_img
{
	void		*img;
	int			*data;

	int			bits_per_pixel;
	int			size_line;
	int			endian;

	int			img_width;
	int			img_height;
}				t_img;

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

	// moveSpeed
	double		moveSpeed;
	// rotateSpeed
	double		rotSpeed;

	t_img		img;
	
	int			buf[screenHeight][screenWidth];
	int			**texture;
}				t_info;

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void	draw(t_info *info)
{
	int		y;
	int		x;

	y = 0;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			info->img.data[y * screenWidth + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win, info->img.img, 0, 0);
	
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
			//x좌표가 작다면 x증가 아니면 y증가
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
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		
		//구해진 광선부터 벽까지의 거리를 가지고 벽의 높이를 결정 : 벽의 높이 = 맵의 높이 / 광선의 거리 (즉 멀수록 낮아진다)
		int lineHeight = (int)(screenHeight / perpWallDist);

		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drwaEnd = lineHeight / 2 + screenHeight / 2;
		if (drwaEnd >= screenHeight)
			drwaEnd = screenHeight - 1;
		
		// 광선에 부딪힌 벽의 텍스처를 선택해주기
		int texNum = worldMap[mapX][mapY] - 1;
		// 1을 빼주는 이유는 0번째 텍스처도 0으로 표현되고 벽이 없는 것도 0으로 표현되기 때문입니다.

		// wallX의 값 구하기
		// 벽이 어디 맞았는지의 값
		double wallX;
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		// wallX를 이용해서 텍스처의 x좌표인 texX를 계산
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		// 스크린 픽셀당 텍스쳐 좌표를 얼마나 증가시킬지 정한다
		double step = 1.0 * texHeight / lineHeight;
		// 텍스쳐 좌표 
		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
		
		int d_y = drawStart;
		while (d_y < drwaEnd)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int cololr = info->texture[texNum][texHeight * texY + texX];
			if (side == 1)
				cololr = (cololr >> 1) & 8355711;
			info->buf[d_y][x] = cololr;
			d_y++;
		}
		x++;
	}
}

int		main_loop(t_info *info)
{
	calc(info);
	draw(info);

	int		i;
	int		j;

	i = 0;
	while (i < screenHeight)
	{
		j = 0;
		while (j < screenWidth)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}

	return (0);
}

int		key_press(int key, t_info *info)
{
	if (key == KEY_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)info->posY])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)info->posX][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == KEY_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)info->posY])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)info->posX][(int)(info->posY - info->dirY * info->moveSpeed)])
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

void	f_free(t_info *info)
{
	int i = 0;

	while (i < 8)
	{
		free(info->texture[i]);
		info->texture[i] = NULL;
		i++;
	}
	free(info->texture);
	info->texture = NULL;
}

int		f_init(t_info *info)
{

	info->posX = 22;	
	info->posY = 11.5;

	info->dirX = -1;
	info->dirY = 0;

	info->planeX = 0;
	info->planeY = 0.66;

	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;

	if(!(info->texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	
	int i = 0;
	int j = 0;
	while (i < 8)
	{
		if(!(info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
		j = 0;
		while (j < texHeight * texWidth)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < screenHeight)
	{
		j = 0;
		while (j < screenWidth)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int		y;
	int		x;

	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx_ptr, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx_ptr, img->img);	
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "./pics/bluestone.xpm", &img);
	load_image(info, info->texture[1], "./pics/colorstone.xpm", &img);
	load_image(info, info->texture[2], "./pics/eagle.xpm", &img);
	load_image(info, info->texture[3], "./pics/greenlight.xpm", &img);
	load_image(info, info->texture[4], "./pics/greystone.xpm", &img);
	load_image(info, info->texture[5], "./pics/mossy.xpm", &img);
	load_image(info, info->texture[6], "./pics/pillar.xpm", &img);
	load_image(info, info->texture[7], "./pics/purplestone.xpm", &img);
}

int main()
{
	t_info		info;
	//mlx_init()으로 창 생성 - 반환값은 void*
	info.mlx_ptr = mlx_init();

	f_init(&info);

	load_texture(&info);

	//화면을 생성 - mlx_new_window()
	info.win = mlx_new_window(info.mlx_ptr, screenWidth, screenHeight, "mlx");

	info.img.img = mlx_new_image(info.mlx_ptr, screenWidth, screenHeight);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel, &info.img.size_line, &info.img.endian);

	//화면을 생성한 후 게임 루프가 시작
	//이 반복문은 계속 반복해서 전체 프레임을 그려내고 입력을 읽는 일을 합니다.
	mlx_loop_hook(info.mlx_ptr, &main_loop, &info);
	
	// mlx_hook을 통해 원하는 창에서 발행하는 함수호출, 메시지, 이벤트(키보드, 마우스)를 감지해서 반응한다
	//funct_ptr는 이벤트 발생시 당신이 호출하고 싶은 함수를 가리키는 함수 포인터 입니다. 
	//이 할당은 win_ptr에 의해 특정된 윈도우에만 적용됩니다.
	//param의 주소는 호출될 때마다 전달되고 필요한 매개 변수를 저장하는 데 사용해야합니다.
	mlx_hook(info.win, KEY_PRESS, 0, &key_press, &info);

	// 지속적으로 반복해주는 곳
	mlx_loop(info.mlx_ptr);
	
	f_free(&info);
}