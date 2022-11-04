.PHONY: docker start stop restart

NAME=um_passo_para_tras_dois_para_frente
PORT=47305

docker: stack
	docker build -t $(NAME) .

start: docker
	docker run -d -p $(PORT):$(PORT) --name $(NAME) --rm -t $(NAME)

stop:
	docker stop $(NAME)

restart: stop start

stack: stack.c
	gcc -fno-stack-protector -o $@ $^
