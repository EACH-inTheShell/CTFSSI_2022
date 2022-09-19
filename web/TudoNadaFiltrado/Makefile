.PHONY: all build start stop restart

all: build

build:
	docker build -t tudonadafiltrado .

start:
	docker run -d --rm --name tudonadafiltrado -p 47200:80 tudonadafiltrado

stop:
	docker stop tudonadafiltrado

restart: stop start
