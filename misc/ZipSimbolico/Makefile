.PHONY: all build start stop restart

all: build

build:
	docker build -t zipsimbolico .

start: build
	docker run --rm -d -p 47101:80 --name zipsimbolico zipsimbolico

stop:
	docker stop zipsimbolico || true

restart: stop start

logs:
	docker logs -f zipsimbolico || true
