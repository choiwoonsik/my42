/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:47:59 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/17 14:56:02 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
int 	ft_putnbr(int num);

int		check_val(char *num)
{
	int		n;
	int		real_num;
	int		minus;

	real_num = 0;
	n = 0;
	minus = 1;
	if (num[n] == '-')
	{
		minus = -1;
		n++;
	}
	while (num[n] <= '9' && num[n] >= '0')
	{
		if (num[n + 1] <= '9' && num[n + 1] >= '0')
		{
			real_num += num[n] - '0';
			real_num *= 10;
		}
		else
			real_num += num[n] - '0';
		n++;
	}
	return (real_num * minus);
}

int		check_operator(char *oper)
{
	int		n;
	int		flag;

	flag = 0;
	n = 0;
	if(oper[n] == '+' || oper[n] == '-' || oper[n] == '/' || oper[n] == '*' || oper[n] == '%')

	return (0);
}

int		calculator(int val1, char oper, int val2)
{
	if (oper == '+')
		return val1 + val2;
	else if (oper == '-')
		return	val1 - val2;
	else if (oper == '/')
	{
		if (val2 == 0)
			return (-1);
		return	val1 / val2;
	}
	else if(oper == '*')
		return val1 * val2;
	else if (oper == '%')
	{
		if (val2 == 0)
			return (-2);
		return val1 % val2;
	}
}

int		calc(char **argv, int (*calculator)(int, char, int))
{
	int		num1;
	int		num2;
	char	oper;
	int		answer;

	oper = 0;
	num1 = check_val(argv[0]);
	printf("num1>>%d\n", num1);
	num2 = check_val(argv[2]);
	printf("num2>>%d\n", num2);
	if(check_operator(argv[1]))
		oper = check_operator(argv[1]);
	answer = calculator(num1, oper, num2);
	if (answer == -1)
	{
		write(1, "Stop : division by zero\n", 26);
		return (-1);
	}
	else if (answer == -2)
	{
		write(1, "Stop : modulo by zero\n", 24);
		return (-1);
	}
	else if (answer == -3)
		return (-1);
	return answer;
}

int		main(int argc, char *argv[])
{
	int		result;

	if (argc != 4)
		return (0);
	else
		result = calc(&argv[1], calculator);
	printf("	result>%d\n", result);
	ft_putnbr(result);
	return (0);
}