gcc -Wall -Werror -Wextra gnl2.c main.c -o gnl2
./gnl2 < gnl2.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl2.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res gnl2