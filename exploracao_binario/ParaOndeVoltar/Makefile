.PHONY: docker start stop restart

NAME=para_onde_voltar
PORT=47304

docker: stack
	docker build -t $(NAME) .

start: docker
	docker run -d -p $(PORT):$(PORT) --name $(NAME) --rm -t $(NAME)

stop:
	docker stop $(NAME)

restart: stop start

stack: stack.c
	gcc -fno-stack-protector -o $@ $^
