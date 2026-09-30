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


int solveUsingTabulation(int n, int k, int target) {
    int mod = 1000000007;

    vector<vector<long long int>> dp(
        n + 1,
        vector<long long int>(target + 1, 0)
    );

    dp[0][0] = 1;

    // Reverse flow
    for(int a = 1; a <= n; a++) {

        for(int t = 0; t <= target; t++) {

            long long int ans = 0;

            for(int val = 1; val <= k; val++) {

                if(t - val >= 0) {
                    ans = (ans + dp[a - 1][t - val]) % mod;
                }
            }

            dp[a][t] = ans;
        }
    }

    return dp[n][target];
}
    int numRollsToTarget(int n, int k, int target) {
        
        // vector<vector<int>>dp(n+1,vector<long long>(target+1,-1));
        int ans = solveUsingTabulation(n,k,target);
        return ans;
    }
};