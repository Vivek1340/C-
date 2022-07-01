#include<iostream>
#include "vector.h"
using namespace std;
int main(){

    //same vector class can be used to target different datatype

    Vector<char> vc;
    vc.push_back('v');
    vc.push_back('i');
    vc.push_back('v');
    vc.push_back('e');
    vc.push_back('k');
    //print all character

    for(int i=0;i<vc.size();i++){
        cout<<vc[i];
    }
    cout<<endl;

    Vector <int> v; 
     //here we need to specify our datatype as int  refer vector.h
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.pop_back();
    cout<<v.front()<<endl;
    cout<<v.at(2)<<endl;
    cout<<v.back()<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;

    //print all the element 

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }

}