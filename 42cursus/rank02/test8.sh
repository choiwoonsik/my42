gcc -Wall -Werror -Wextra gnl8.c main.c -o gnl8
./gnl8 < gnl8.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl8.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res gnl8