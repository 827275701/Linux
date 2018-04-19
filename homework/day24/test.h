/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Mar 2018 09:06:43 AM PDT
 ************************************************************************/

#ifndef _TEST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct P{
    char name[64];
    char tel[12];
}P;
void face();
void AddAContact();
void DeleteAContact(const char *n, const char *t);
void SearchAContact(const char *name);
int ModifyAContact(const char* p);
void ShwAllContact();
void EmptyAllContact();
void SortAllContact();
#define _TEST_H
#endif
