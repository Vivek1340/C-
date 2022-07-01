#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
//   //fixed memory allocation
//     char a[1000] = {'1','a','b','c','\0'};

// //dynamic memory allocation
// //dynamic array
// string s = "hello world";
// //another way to declare by making a call to the constructor
// string d  ("hello world");
// cout<< a <<endl;
// cout<< s << endl;
// cout<< s <<endl;

//accepting input from user
//third arrgument is a deleminator for getline function 
//whenever we hit . it will break
// string b;
// getline(cin,b,'.');
// //iterating over a string
// for(char ch : b){
//     cout<<ch<<",";
// }
// cout<< b <<endl;

//array of strings using vector<string>
int n=5;
vector<string> sarr;
string temp;

while(n--){
    getline(cin,temp);
    sarr.push_back(temp);
}
for(string x: sarr){
    cout<<x<<",";
}

}