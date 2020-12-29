gcc -Wall -Werror -Wextra gnl3.c main.c -o gnl3
./gnl3 < gnl3.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl3.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res gnl3