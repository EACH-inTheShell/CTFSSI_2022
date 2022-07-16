.PHONY: all local start stop restart logs

all:
	docker build -t umladinonosfios .

local: build/
	cmake --build $<

start: all
	docker run --rm -d --name umladinonosfios -p 47000:47000 umladinonosfios

stop:
	docker stop umladinonosfios

restart: stop start

logs:
	docker logs -f umladinonosfios

build/:
	cmake -B $@
