.PHONY: docker start stop restart

docker: executor
	docker build -t shellcode_para_iniciantes .

start: docker
	docker run -d -p 47300:47300 --name shellcode_para_iniciantes --rm -t shellcode_para_iniciantes

stop:
	docker stop shellcode_para_iniciantes

restart: stop start

executor: executor.c
	gcc -z execstack -o $@ $^
