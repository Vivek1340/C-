#include<iostream>
#include<cstring>
using namespace std;

int main(){

    // char a[] = "abcdeghi";
    // cout<<a<<endl;
    // char b[100];
    // cin>>b;
    // cout<<b<<endl;

    // cout<<strlen(a)<<endl;//number of visible characters
    // cout<<sizeof(a)<<endl;//+1 because of null character
    char sentence[1000];
    char temp = cin.get();
    int len =1;
    while(temp!='\n'){
        // len++;
        // cout<<temp;
        sentence[len++] = temp;
        //update the valuue of temp;
        temp = cin.get();
    }
    sentence[len] = '\0';
    cout<<"Length "<<len<<endl;
    cout<<sentence;


    return  0;

}