.PHONY: docker start stop restart

docker: executor
	docker build -t fabrica_de_shellcode .

start: docker
	docker run -d -p 47301:47301 --name fabrica_de_shellcode --rm -t fabrica_de_shellcode

stop:
	docker stop fabrica_de_shellcode

restart: stop start

executor: executor.c
	gcc -z execstack -o $@ $^
