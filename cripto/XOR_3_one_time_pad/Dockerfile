FROM python:3.10.8-alpine

EXPOSE 47400

WORKDIR /app

RUN apk update && apk add socat

COPY rodar_no_server.py .

ENTRYPOINT socat tcp-listen:47400,fork exec:/app/rodar_no_server.py,stderr,pty,ctty,echo=0,raw
