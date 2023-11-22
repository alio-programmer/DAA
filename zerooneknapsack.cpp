#include <bits/stdc++.h> 
using namespace std; 
int knapSack(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>> dp){
    if(n==0 || W==0) return 0;

    if(dp[n][W]!=-1) return dp[n][W];

    int nottake = knapSack(W, wt, val, n-1, dp);
    int take = INT_MIN;
    if(wt[n]<=W){
        take = val[n] + knapSack(W-wt[n], wt, val, n-1, dp);
    }

    return dp[n][W] = max(take, nottake);
}
int main(){ 
	vector<int> profit = { 60, 100, 120 }; 
	vector<int> weight = { 10, 20, 30 }; 
	int W = 50; 
    int n = profit.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
	int ans = knapSack(W, weight, profit, n-1, dp); 
    cout<<ans<<endl;
    return 0;
} 

