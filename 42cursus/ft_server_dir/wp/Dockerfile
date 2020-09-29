# 아래 명령어를 통해 debian:buster가 pull된다
FROM debian:buster

RUN apt-get update

# niginx 웹서버 다운받고 설정
RUN apt-get -y install nginx
RUN service nginx start
RUN apt-get -y install openssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

# 권한 설정 및 보안 설정
RUN chmod 600 localhost.dev.*
RUN mv localhost.dev.crt /etc/ssl/certs/
RUN mv localhost.dev.key /etc/ssl/private/
COPY ./srcs/default /etc/nginx/sites-available/default
RUN service nginx reload

#php-fpm 설치
RUN apt-get -y install php-fpm
RUN service php7.3-fpm start

#2번 방법 phpmyadmin 을 공식사이트에서 다운받고 설정
RUN apt-get -y install wget
RUN apt-get -y install wget mariadb-server php-mysql
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN rm -rf phpMyAdmin-4.9.0.1-all-languages.tar.gz

#추가
RUN mv phpMyAdmin-4.9.0.1-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html
RUN cp -rp /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin/.
COPY ./srcs/my.cnf /etc/mysql/.
COPY ./srcs/default /etc/nginx/sites-available/default

# mysql실행
RUN chmod -R 755 /var/lib/mysql/
COPY ./srcs/wordpress.sql /var/www/
RUN service mysql start && mysql -u root mysql < /var/www/wordpress.sql;

RUN service nginx restart
RUN service php7.3-fpm restart

## wordpress 설치
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN rm -rf latest.tar.gz 
RUN mv wordpress /var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress

RUN apt-get -y install vim

EXPOSE 80
EXPOSE 443

COPY ./srcs/start.sh ./
CMD ["/bin/bash", "/start.sh", "start"]
#RUN docker run -it -p 80:80 -p 443:443 --name ws_nginx wchoi:latest
