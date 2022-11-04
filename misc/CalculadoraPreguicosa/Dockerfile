FROM gcc:latest as builder
RUN apt update
WORKDIR /tmp/
COPY ./ /tmp/
RUN gcc -o calc calc.c
RUN strip calc

FROM ubuntu:22.10
EXPOSE 47002
RUN apt update && apt install -y socat python3
RUN useradd -m eits
WORKDIR /home/eits
COPY --from=builder /tmp/calc /opt/calc
COPY --from=builder /tmp/flag.txt /home/eits/flag.txt
ENTRYPOINT socat tcp-listen:47002,fork exec:/opt/calc,su=eits
