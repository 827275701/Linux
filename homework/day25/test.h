/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Mar 2018 11:46:25 PM PDT
 ************************************************************************/

#pragma once

#define NAME_MAX 32
#define SEX_MAX 4
#define TEL_MAX 12
#define NODE_MAX_SIZE (NAME_MAX)+(SEX_MAX)+(TEL_MAX)

void face();
void AddAContact();
void DeleteAContact(char* to_delete_name);
void SearchAContact(char* to_search_name);
void ModifyAContact(char* to_modify_name);
void ShowAllContact();
void EmptyAllContact();
void SortAllContact();
