#include "stdio.h"
#include "libft.h"

int main(void)
{
    printf("TEST LIBRARY FUNCTION TEST\n\n");

    // ft_atoi() : 문자열을 숫자로 변환하는 함수
    printf("ft_atoi() TEST\n\n");

    char *numA = "-987654321";
    char *numB = "987654321";

    int a = ft_atoi(numA);
    int b = ft_atoi(numB);

    printf("numA : %d\t numB : %d\n", a, b);
    printf("RESULT : %d\n", a + b);

    // ft_strjoin() : 문자열을 합치는 함수
    printf("\nft_strjoin() TEST\n\n");

    char *s1 = "this is ";
    char *s2 = "ft_strjoin() test";

    char *s3 = ft_strjoin(s1, s2);
    printf("<%s>  |  <%s>\n", s1, s2);
    printf("RESULT : %s\n", s3);

    // ft_split() : 문자열을 특정 문자를 기준으로 여러 문자열로 나누는 함수
    printf("\nft_split() TEST\n\n");

    char *s4 = "this is ft_split test case, is it splited correctly??";
    char **result = ft_split(s4, ' '); // split by 'space'

    for (int i = 0; i <= sizeof(*result); i++)
    {
        printf("%s\n", result[i]);
    }
}