.PHONY:all
all:lock_unlock producer_consumer gdb_pthread
lock_unlock:lock_unlock.c
	gcc lock_unlock.c -o lock_unlock -lpthread
producer_consumer:producer_consumer.c
	gcc producer_consumer.c -o producer_consumer -lpthread
gdb_pthread:gdb_pthread.c
	gcc -g gdb_pthread.c -o gdb_pthread -lpthread
.PHONY:clean
clean:
	rm lock_unlock producer_consumer gdb_pthread
