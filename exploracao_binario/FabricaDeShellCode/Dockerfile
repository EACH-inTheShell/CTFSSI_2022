FROM ubuntu

EXPOSE 47301
WORKDIR /opt

RUN apt update && apt install -y socat

COPY ./executor /opt/executor
COPY ./flag.txt /opt/flag.txt

ENTRYPOINT socat tcp-listen:47301,fork exec:/opt/executor,stderr,pty,ctty,echo=0
