#include "stdio.h"
#include "ft_printf.h"

int main(void)
{
    // FT_PRINTF FUNCTION TEST
    ft_printf("THIS IS TEST\n");
    ft_printf("42 SEOUL SUBJECT TEST\n");

    // 정수 출력
    for (int i = 0; i < 3; i++)
        ft_printf("%d\t", i);
    ft_printf("\n");

    // 문자 출력
    char *str = "I AM WOONSIK";
    ft_printf("|%20s|\n", str);
    ft_printf("|%-20s|\n", str);

    // 16진수, 10진수 출력
    ft_printf("TEST NUMBER\n");
    ft_printf("%x\t %X\t %d\n", 100, 100, 100);
    ft_printf("%x\t %X\t %d\n", 255, 255, 255);
}