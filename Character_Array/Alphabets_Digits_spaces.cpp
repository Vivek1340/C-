#include<iostream>
#include<cstring>
using namespace std;

int main(){

char ch;
ch = cin.get();

//counts
int alpha = 0;
int digit = 0;
int space = 0;
while(ch!='\n'){
    if(ch>='0' and ch<='9'){
        digit++;
    }
    else if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z')){
        alpha++;
    }
    else if(ch==' ' or ch =='\t'){
        space++;
    }

    ch = cin.get();
}
cout<<"Total alphabets : "<<alpha<<endl;
cout<<"Total Digits : "<<digit<<endl;
cout<<"Total Spaces : "<<space<<endl;

    return 0;
}