.PHONY: docker start stop restart

docker:
	docker build -t teste .

start: docker
	docker run -d -p 1234:1234 --name teste --rm -t teste

stop:
	docker stop teste

restart: stop start

logs:
	docker logs -f teste
