FROM ubuntu:22.10

EXPOSE 3128

RUN apt update && apt install -y squid apache2

COPY ports.conf /etc/apache2/ports.conf
COPY proxy.conf /etc/squid/conf.d/proxy.conf

COPY flag.txt /var/www/html/flag.txt

ENTRYPOINT /etc/init.d/squid start && /etc/init.d/apache2 start && tail -f /var/log/apache2/access.log /var/log/squid/access.log
