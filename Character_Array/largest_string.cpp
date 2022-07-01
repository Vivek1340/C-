#include<iostream>
#include<cstring>
using namespace std;
//Problem : Read N - strings and print the largest string . Each string can have upto 1000 character


int main(){

    int n;
    cin>>n;

    //used to consume  1 /n character so that loop can work properly

    cin.get();
    char sentence[1000];
    char largest[100];
    int largest_len = 0;

    while(n--){
        cin.getline(sentence,1000);
        //cout<< sentance <<endl;
        int len = strlen(sentence);
        if(len> largest_len){
            largest_len= len;
            strcpy(largest,sentence);   
        }
    }

    cout<<"largest sentence is "<<largest;
    return 0;
} 