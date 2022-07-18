FROM gcc:latest as builder
RUN apt update && apt install -y cmake
WORKDIR /tmp/
COPY ./ /tmp/
RUN cmake -B build/ && cmake --build build/
RUN strip build/server

FROM ubuntu:latest
EXPOSE 47000
COPY --from=builder /tmp/build/server /server
COPY --from=builder /tmp/map.txt /map.txt
COPY --from=builder /tmp/flag.txt /flag.txt
ENTRYPOINT /server
