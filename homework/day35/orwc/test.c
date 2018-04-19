/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Mar 2018 09:29:54 PM PDT
 ************************************************************************/


#include<stdio.h>

int main ()
{
    char sentence []="Rudolph is 12 years old";
    char str [20];
    char str1 [20];
    int i;

    sscanf (sentence,"%s%*d",str,&i);
    printf ("%s, %d\n",str, i);
   // sscanf (sentence,"%s %s",str, str1);
   // printf ("%s\n",str);
//    printf ("%s\n",str1);
//
    return 0;

}
