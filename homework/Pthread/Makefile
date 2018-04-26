.PHONY:all
all: tcreate tjoin tdetach
tcreate:tcreate.c
	gcc tcreate.c -o tcreate -lpthread

tjoin:tjoin.c
	gcc tjoin.c -o tjoin -lpthread

tdetach:tdetach.c
	gcc tdetach.c -o tdetach -lpthread

.PHONY:clean
clean:
	rm tcreate tjoin tdetach
