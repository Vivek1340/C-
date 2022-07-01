#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n :";
    cin>>n;
    vector<int> arr(n,0);

    
    for(int i=0;i<n;i++){
        arr[i] = n-i;
    }

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }

    auto start_time = clock();
    sort(arr.begin(),arr.end());
    
    auto end_time = clock();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    

    cout<<"time taken is :"<<end_time-start_time<<endl;
    return 0;
}