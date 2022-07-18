.PHONY: all start stop restart logs

all:
	docker build -t calculadorapreguicosa .

start: all
	docker run -d --rm -it -p 47002:47002 --name calculadorapreguicosa calculadorapreguicosa

stop:
	docker stop calculadorapreguicosa

restart: stop start

logs:
	docker logs -f calculadorapreguicosa
