.PHONY: docker start stop restart

docker:
	docker build -t proxyaberto .

start: docker
	docker run -d -p 3128:3128 --name proxyaberto --rm -t proxyaberto

stop:
	docker stop proxyaberto

restart: stop start

logs:
	docker logs -f proxyaberto
