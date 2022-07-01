#include<iostream>
#include<vector>
using namespace std;

vector<int> kRotate (vector<int> a, int k){
int n =a.size();
vector<int> v;
k = k%n;
    for(int i=0;i<n;i++){
        if(i<k){
            v.push_back(a[i+n-k]);
        }
        else{
            v.push_back(a[i-k]);
        }
    }
    return v;
    

}

int main(){
    vector<int> a{1,3,5};
    for(int i=0;i<a.size();i++){
        cout<<kRotate(a, 2)[i]<<",";
    }
    
}
