#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[1000] = "apple";
    char b[1000];
//calc length
cout<< strlen(a)<<endl;

//copy string 

strcpy(b,a);
cout<<b <<endl;

//comoare two strings  - will give zero if strings are equal
cout<<strcmp(a,b)<<endl;
//concatenate two string
char web[] = "www.";
char domain[] = "google.com";
cout<<strcat(web,domain) <<endl;






//will give any positive or negative value if stringa are not equal
strcpy(b, strcat(web,domain));
cout<<strcmp(b,a)<<endl;

    return 0;
}