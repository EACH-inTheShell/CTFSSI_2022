.PHONY: docker start stop restart clean

docker:
	docker build -t manytimepad .

start: docker
	docker run -d -p 47400:47400 --name manytimepad --rm -t manytimepad

stop:
	docker stop manytimepad

restart: stop start

logs:
	docker logs -f manytimepad

clean:
	docker container stop -t=0 manytimepad || echo 'error'
	docker container rm manytimepad || echo 'error'
	docker image rm manytimepad || echo 'error'
