FROM ubuntu:22.10

EXPOSE 47303
WORKDIR /opt

RUN apt update && apt install -y socat

COPY ./flag.txt /opt/flag.txt
COPY ./stack /opt/stack

ENTRYPOINT socat tcp-listen:47303,fork exec:/opt/stack,stderr,pty,ctty,echo=0,raw
