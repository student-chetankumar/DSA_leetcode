class Solution {
public:
int solveUsingrecurion(vector<int>& coins, int amount,vector<int>&dp){
    // base case
    if(amount==0){
        return 0;
    }

    if(dp[amount]!=-1){
        return dp[amount];
    }

    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(coins[i]<=amount){
            // valid
            int ans = solveUsingrecurion(coins , amount-coins[i],dp);
            // ans can be invalid or valid
            if(ans != INT_MAX){
                // it may or may be a minimum ans
                mini = min(mini,1+ans);
                

            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        int n=amount;
        vector<int>dp(n+1,-1);
        int ans = solveUsingrecurion(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }else
            return ans;
    }
};