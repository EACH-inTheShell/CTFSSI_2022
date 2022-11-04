.PHONY: docker start stop restart

NAME=overflow_para_bebes
PORT=47302

docker: stack
	docker build -t $(NAME) .

start: docker
	docker run -d -p $(PORT):$(PORT) --name $(NAME) --rm -t $(NAME)

stop:
	docker stop $(NAME)

restart: stop start

stack: stack.c
	gcc -z execstack -o $@ $^
