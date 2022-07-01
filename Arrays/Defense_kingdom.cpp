#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    
    int n = position.size();
    sort(position.begin(),position.end());
    int largest_w=-1;
    int largest_h = -1;
    int value = 0;
    for(int i=0;i<n-1;i++){
        value =  position[i+1].first-position[i].first;
        largest_w = max(largest_w,value);
    }
    largest_w = largest_w-1;
    if(largest_w<(W -position[n-1].first)){
            largest_w = W -position[n-1].first;
        }
    sort(position.begin(),position.end(),sortbysec);
    int result=0;
    for(int i = 0;i<n-1;i++){
        result = position[i+1].second - position[i].second;
        largest_h = max(largest_h,  result);
       
    }
    largest_h = largest_h-1;
    if(largest_h<(H -position[n-1].second)){
            largest_h = H -position[n-1].second;
        }
    int final = ((largest_w)*(largest_h));
    return final;
    
}

int main(){
    vector<pair<int , int>>position {{3,8},{11,2},{8,6}};
    int result;
     result = defkin(15 , 8 , position);

    cout<<result;
    return 0;
}