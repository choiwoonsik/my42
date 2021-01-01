gcc -Wall -Werror -Wextra gnl4.c main.c -o gnl4
./gnl4 < gnl4.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl4.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res gnl4