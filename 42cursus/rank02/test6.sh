gcc -Wall -Werror -Wextra gnl6.c main.c -o gnl6
./gnl6 < gnl6.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl6.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res gnl6