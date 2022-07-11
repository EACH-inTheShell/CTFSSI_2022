FROM gcc:latest as builder
RUN apt update && apt install -y cmake
WORKDIR /tmp/
COPY ./ /tmp/
RUN cmake -B build/ && cmake --build build/

FROM ubuntu:latest
COPY --from=builder /tmp/build/server /server
ENTRYPOINT /server
