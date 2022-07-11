.PHONY: all start

all:
	docker build -t umladinonosfios .

start: all
	docker run --rm -d --name umladinonosfios -p 47000:47000 umladinonosfios
