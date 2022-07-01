#include<iostream>
#include"hashTable.h"

using namespace std;

int main(){

    Hashtable<int> h;
    h.insert("Mango" , 100);
    h.insert("Apple" , 120);
    h.insert("Banana" , 140);
    h.insert("Orange" , 200);
    h.insert("kiwi" , 120);
    h.insert("pineapple" , 190);
    h.insert("papaya" , 140);
    h.insert("litchi" , 200);
  
    h.print();

    string fruit;
    cin>>fruit;
    // int *price = h.search(fruit);

    // if(price != NULL){
    //     cout<<"Price of "<<fruit<<" is "<<*price<<endl;
    // }
    // else{
    //     cout<<"Fruit is not present";
    // }

    // h.erase("Mango");

//   cout<<"Price of "<<fruit<<" is " << h.search1(fruit);
    
    h["newFruit"] = 200;
    cout<<"New Fruit cost : "<<h["newFruit"]<<endl;
    h["newFruit"] += 20;

    cout<<"New fruit updated cost : "<<h["newFruit"]<<endl;
    return 0;
}