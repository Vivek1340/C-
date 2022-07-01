/*Given N sticks and an array length where each length[i] represents length of each stick.
Your task is to make maximum number of pairs of these sticks such that the difference between the length of two sticks is at most D. 
A stick can't be part of more than one pair of sticks.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    // your code goes here
    int n = length.size();
    int count = 0;
    sort(length.begin(),length.end());
    for(int i=0;i<n-1;i++){
        if((length[i+1]-length[i])<=D){
            count++;
            i++;
        }
    }
    return count;
    
}

int main(){
    vector<int> length {1,3,3,9,4};
    cout<<pairSticks(length , 2);
    return 0;
}