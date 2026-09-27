class Solution {
public:
int maxloot(vector<int>& arr , int i,int dp[]){
        if(i>=arr.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int steal = arr[i]+maxloot(arr,i+2,dp);
        int skip  = maxloot(arr,i+1,dp);
        return dp[i]=max(steal,skip);
    }

int solveUsingTabulation(vector<int>& arr ){
    int n=arr.size();
    
    vector<int>dp(n+1,-1);
    // base case
    dp[n]=0;

    for(int i=n-1;i>=0;i--){
        int temp=0;
        if(i+2<=n){
            temp = dp[i+2];
        }
        int steal = arr[i]+temp;
        int skip  = 0+ dp[i+1];
        int ans = max(steal,skip);
        dp[i]=ans;
    }

    return dp[0];
}
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // int dp[n];
        // fill(dp,dp+n,-1);
        // return maxloot(nums,0,dp);
        int ans = solveUsingTabulation(nums);
        return ans;
    }
};