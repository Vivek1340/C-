#include<iostream>
using namespace std;

class Vector{
    //Data Members
    int *arr;
    int cs;        //current size
    int ms;         //maximum size


    //Constructor ,Destructor,METHODS
public:
    Vector(int max_size = 5){
        cs = 0;
        ms = max_size;
        arr = new int[ms];
    }

    // d does not changes inside the function
    void push_back(const int d){
        //two case
        if(cs == ms){
            //create a new array and delete the old one , double the capacity
            int *oldArr = arr;
            ms = 2* ms;
            arr = new int [ms];

            //copy the element
            for(int i=0;i<cs;i++){
                arr[i] = oldArr[i];
            }

            //delete
            delete[] oldArr;
        }

        arr[cs] = d;
        cs++;
    }

    void pop_back(){
        if(cs>=0){
        cs--;
        }
    }

    bool isEmpty()const{
        return cs==0;
    }

    //front, back, at [i],][]
    int front()const{
        return arr[0];
    }

    int back()const{
        return arr[cs-1];
    }
// const function are those which do not modify the data members


    int at(int i) const{
        return arr[i];
    }

    int size() const{
    return cs;
    }

    int capacity()const{
        return ms;
    }
// [] whenever this opertor is used by the obbject it will return arr of i
// since i is not changing inside the function (i.e i++ or i--)  we should use const
    int operator[](const int i) const {
        return arr[i];
    }

};

int main(){
    Vector v;
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