FROM php:8.1-apache

EXPOSE 80

RUN apt update && apt install -y unzip

COPY flag.txt /
COPY site/ /var/www/html/
