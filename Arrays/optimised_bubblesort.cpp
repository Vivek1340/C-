#include<iostream>
#include<vector>
using namespace std;

void optimisedBubbleSort(vector<int> v){
    int n = v.size();
     //  vector<int> a;

        // for(int i=0;i<n-1;i++){
        //     if(v[i+1]>v[i]){
        //         a[i]=v[i];
        //     }
        //     return a;
        // }
        
   
      for(int times = 1;times<=n-1;times++){
        for(int j=0;j<n-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }

}

int main(){
    vector<int> v{2,3,4,1,5};
    optimisedBubbleSort(v);
    for(auto x:v){
        cout<<x<<",";
            }


    return 0;
}
