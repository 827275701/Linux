/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Mar 2018 09:37:29 AM PDT
 ************************************************************************/

#include"test.h"

int main()
{
    int n = 0;
    while(1)
    {
        face();
        printf("请选择(0~7):>");    
        scanf("%d",&n);
        while(n > 7 || n < 0)
        {
            printf("enter error!\n");    
            printf("pleace choose(0~7):>");    
            scanf("%d",&n);
        }
        switch(n)
        {
            case 0:
                return 0;
            break;
            
            case 1:
                AddAContact();
            break;
            
            case 2:
                DeleteAContact("Bob","18165151223");
            break;
            
            case 3:
                SearchAContact("Bob");
            break;
            
            case 4:
                ModifyAContact("Bob");
            break;
            
            case 5:
                ShowAllContact();
            break;
            
            case 6:
                EmptyAllContact();
            break;
            
            case 7:
                SortAllContact();
            break;
            default:
            break;
        }
    }
    return 0;
}

