
class Solution {
public:
   int topdown(int n, vector<int>& dp){
    if(n==1 || n==0){
        return n;
    }
    if(n==2) return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=topdown(n-1,dp)+topdown(n-2,dp)+topdown(n-3,dp);
    return dp[n];
   }
   int tribonacci(int n) {
       int a=0,b=1,c=1,ans;
       if(n==0 || n==1) return n;
       if(n==2) return 1;
       for(int i=3;i<=n;i++)
       {
         ans=a+b+c;
         a=b;
         b=c;
         c=ans;
       }
    // step 1 . create dp array
    // vector<int>dp(n+1,-1);
    // int ans=topdown(n,dp);
        
       return ans;
    }
};
   