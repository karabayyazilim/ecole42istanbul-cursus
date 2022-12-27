all: data db wp up

up:
	docker-compose -f ./srcs/docker-compose.yml up -d
data:
	mkdir /home/akarabay/data
db:
	mkdir /home/akarabay/data/db
wp:
	mkdir /home/akarabay/data/wp

down:
	docker-compose -f ./srcs/docker-compose.yml down

.PHONY: up data db wp down
