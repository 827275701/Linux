.PHONY:all
all:read write
write:write.c
	gcc -g $^ -o $@

read: read.c
	gcc -g $^ -o $@
	
.PHONY:clean
clean:
	rm write read
