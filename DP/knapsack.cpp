#include <iostream>
#include <vector>
using namespace std;

// Recursiv code -> Top Down
int knapsack(int wts[], int prices[], int N, int W)
{
    // base case
    if (N == 0 or W == 0)
    {
        return 0;
    }

    // recursive case
    int inc = 0, exc = 0;
    if (wts[N - 1] <= W)
    {
        inc = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
    }
    exc = knapsack(wts,prices,N-1,W);
    return max(inc,exc);
}

//Botom up DP

int knapSackDp(int wts[], int prices[],int N, int W){

vector<vector<int> > dp(N+1, vector<int> (W+1 , 0));

for(int n =1;n<=N;n++){
    for(int w=1;w<=W;w++){
        int inc =0, exc=0;

        if(wts[n-1] <= w){
            inc  = prices[n-1]+dp[n-1][w-wts[n-1]];
        }
        exc = dp[n-1][w];

        dp[n][w]= max(inc,exc);
    }
}

return dp[N][W];

}

int main(){

    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int N = 4;
    int W= 11;

    cout<<knapsack(wts,prices,N,W)<<endl;
    cout<<knapSackDp(wts,prices,N,W)<<endl;

    return 0;
}