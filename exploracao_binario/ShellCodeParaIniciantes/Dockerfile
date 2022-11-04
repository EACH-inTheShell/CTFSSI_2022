FROM ubuntu:22.10

EXPOSE 47300
WORKDIR /opt

RUN apt update && apt install -y socat

COPY ./executor /opt/executor
COPY ./flag.txt /opt/flag.txt

ENTRYPOINT socat tcp-listen:47300,fork exec:/opt/executor,stderr,pty,ctty,echo=0
