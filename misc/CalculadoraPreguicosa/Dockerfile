FROM gcc:latest as builder
RUN apt update
WORKDIR /tmp/
COPY ./ /tmp/
RUN gcc -o calc calc.c
RUN strip calc

FROM ubuntu:latest
EXPOSE 47002
RUN apt update && apt install -y socat python3
COPY --from=builder /tmp/calc /calc
COPY --from=builder /tmp/flag.txt /flag.txt
ENTRYPOINT socat tcp-listen:47002,fork exec:/calc
