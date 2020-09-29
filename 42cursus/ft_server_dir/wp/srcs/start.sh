service nginx start
service php7.3-fpm start
service mysql start
while true;
    do echo "live";
    sleep 600;
done