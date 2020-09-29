CREATE DATABASE wordpress;

GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;

ALTER USER 'root'@'localhost' IDENTIFIED BY '';

use mysql;

select user, host, plugin from mysql.user;

update user set plugin='' where user='root';

FLUSH PRIVILEGES;

EXIT