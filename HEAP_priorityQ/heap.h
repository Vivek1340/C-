#include<vector>
#include<iostream>
using namespace std;


class Heap{
    vector<int> v;
//O(log(n))
    void heapify(int i){

        int left = 2*i;
        int right = 2*i + 1;
        int minIdx = i;
        if(left<v.size()and v[left]<v[i]){
            minIdx = left;
        }
        if(right<v.size() and v[right]<v[minIdx]){
            minIdx = right;
        }
        if(minIdx!=i){
            swap(v[i],v[minIdx]);
            heapify(minIdx);
        }
    }

public:
    Heap(int default_size=10){
        v.reserve(default_size+1);
        v.push_back(-1);
//for blocking 0th index so that it can not be used
//which will make the parent child relation calculation easier
    };

void push(int data){
    
    //add data to the end of the heap
    v.push_back(data);
    int idx = v.size()-1;
    int parent = idx/2;
    while(idx>1 and v[idx]< v[parent]){
        swap(v[idx],v[parent]);
        idx = parent;
        parent = parent/2;
    }
}
//return min element
int top(){
    return v[1];
}
//remove the minimum element
void pop(){
    //steps
    //step 1. swap first and last elements
    int idx = v.size()-1;
    swap(v[1],v[idx]);

    //step 2. remove last element
    v.pop_back();

    //step 3. make a min heap of the remaining elements using heapify
    heapify(1);
}

bool empty(){
    return v.size()==1;
}
void display(){
    for(int x : v){
        cout<<x<<"->";
    }
    cout<<endl;
}

};