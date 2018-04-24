#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>



int main ()
{
    umask(0);
    char str[] = "hellow world\n";
    int len = sizeof(str)/sizeof(str[0]);
    int fp = open("myfile", O_WRONLY | O_CREAT, 0644);
    
    int count = 5;
    while(count--) {
        write(fp, str, len - 1);
    }

    close(fp); 

   // FILE* fp = fopen("myfile", "w+");
//    char str[] = "hellow world\n";
//    int len = sizeof(str)/sizeof(str[0]);
//    int i = 0;
//    for(; i < 10; i++) {
//        fwrite(str, 1, len-1, stdout);
//    }
//
   // fread(str, 1, len-1, fp); 
   // for(i = 0; i < 10; i++){
   //     puts(str);
   // }
   // fclose(fp);
    return 0;

}
