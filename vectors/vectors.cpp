#include<iostream>
#include<vector>
using namespace std;

int main(){
    //Demo vector
    //vector<int> arr = {1,2,10,12,15};

    //Fill constructor
    vector<int> arr(10,7);

    //pop_back
    arr.pop_back();
    //push_back O(1)
    arr.push_back(16);

    //print  aLL THE ELEMENTS
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    //Size of the vector (no of elements)
    cout<<arr.size()<<endl;

    //capacit of the vector
    cout<<arr.capacity()<<endl;
}