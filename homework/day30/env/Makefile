.PHONY:all
all:setenv getenv
setenv:setenv.c
	gcc -g $^ -o $@
getenv:getenv.c
	gcc -g $^ -o $@
.PHONY:clean
	rm setenv getenv
