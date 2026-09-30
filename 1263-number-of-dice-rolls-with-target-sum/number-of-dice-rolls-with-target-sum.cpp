class Solution {
public:
int solve(int n, int k ,int target){
    // base case
    if(n<0 || target <0){
        return 0;
    }
    if(n==0 && target==0){
        return 1;
    }
    if(n==0 && target!=0){
        return 0;
    }
    if(n!=0 && target==0){
        return 0;
    }
    int ans = 0;
    for(int val=1;val<=k;val++){
        ans = ans+solve(n-1,k,target-val);
    }
    return ans;
}
// 2D DP
int solveUsingMem(int n, int k ,int target,vector<vector<int>>&dp){
    // base case
    if(n<0 || target <0){
        return 0;
    }
    if(n==0 && target==0){
        return 1;
    }
    if(n==0 && target!=0){
        return 0;
    }
    if(n!=0 && target==0){
        return 0;
    }

    // dp base case
    if(dp[n][target]!=-1){
        return dp[n][target];
    }

    int ans = 0;
    for(int val=1;val<=k;val++){
        ans =(ans+solveUsingMem(n-1,k,target-val,dp)) % 1000000007;
    }
    dp[n][target]=ans;

    return dp[n][target];
}
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans = solveUsingMem(n,k,target,dp);
        return ans;
    }
};