#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main() {
    int fp = open("myfile", O_RDONLY);
    if(fp < 0) {
        perror("open");
        return 1;
    }
    char* str = "hellow world\n";
    char buff[1024];
    ssize_t s;
    while(1) {
        s = read(fp, buff, strlen(str));
        if(s > 0) {
            printf("%s", buff);
        }else {
            break;
        }
    }
    close(fp);
    return 0;
}
