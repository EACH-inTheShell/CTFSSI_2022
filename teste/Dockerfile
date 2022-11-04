FROM ubuntu:22.10
EXPOSE 1234
COPY teste.py /teste.py

RUN apt-get update -y
RUN apt-get install python3 -y
RUN apt-get install socat -y
RUN chmod 777 /teste.py

ENTRYPOINT  socat tcp-listen:1234,fork exec:/teste.py
