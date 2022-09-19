.PHONY: all start stop restart logs

all:
	docker build -t umacabecacheiadeinformacoes .

start: all
	docker run -d --rm -it -p 47100:8080 --name umacabecacheiadeinformacoes umacabecacheiadeinformacoes

stop:
	docker stop umacabecacheiadeinformacoes

restart: stop start

logs:
	docker logs -f umacabecacheiadeinformacoes
