gcc -Wall -Werror -Wextra gnl5.c main.c -o gnl5
./gnl5 < gnl5.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl5.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res gnl5