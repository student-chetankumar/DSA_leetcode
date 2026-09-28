class Solution {
public:
int solve(vector<int>& nums , int curr, int prev){
    if(curr>=nums.size()){
        return 0;
    }
    int include = 0;
    
    if(prev == -1 || nums[curr]>nums[prev]){
        include = 1+solve(nums,curr+1,curr);
    }
    int exclude = 0+solve(nums,curr+1,prev);
    int finalAns = max(include,exclude);
    return finalAns;
}

// 2D dp
int solveMem(vector<int>& nums , int curr, int prev,vector<vector<int>>& dp){
    if(curr>=nums.size()){
        return 0;
    }

    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    int include = 0;
    
    if(prev == -1 || nums[curr]>nums[prev]){
        include = 1+solveMem(nums,curr+1,curr,dp);
    }
    int exclude = 0+solveMem(nums,curr+1,prev,dp);
    int finalAns = max(include,exclude);
    dp[curr][prev+1]=finalAns;
    return dp[curr][prev+1];
}


    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solve(nums,curr,prev);
        int ans = solveMem(nums,curr,prev,dp);
        return ans;
    }
};