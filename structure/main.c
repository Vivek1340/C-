#include <stdio.h>
#include<string.h>
#include <stdlib.h>

struct info
{
    char name[20];
    float mob_no;
    int age;
    char tested;
    char asymptotic[3];
}p[10];
int main()
{   int count=0,temp=0,data=0,i;
    float percent;

    printf("no of data");
    scanf("%d",&data);
    for(i=0;i<data;i++)
    {
        printf("enter your name\n");
        scanf("%s",&p[i].name);
        printf("enter mob no\n");
        scanf("%f",&p[i].mob_no);
        printf("enter age\n");
        scanf("%d",&p[i].age);
        printf("if tested\n");
        scanf("%s",&p[i].tested);
        printf("if asymptotic\n");
        scanf("%s",&p[i].asymptotic);
        if(p[i].tested=='y'||p[i].tested=='Y')
        {
            temp++;
        }
        if(p[i].tested=='Y'||p[i].tested=='y')
           {
             if(p[i].asymptotic=='N'||p[i].asymptotic=='n')
                { count++;
                }
           }
     }
        percent=(count/temp)*100;
        printf("%f",percent);
    return 0;
}
