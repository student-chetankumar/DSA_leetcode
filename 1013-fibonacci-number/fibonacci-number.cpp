class Solution {
public:
int topdown(int n){
    if( n==0 || n==1 ) return n;
    
    int ans =  topdown(n-1)+topdown(n-2);
    return ans;
}
    int fib(int n) {
    //     int a=0,b=1;
    //     int ans;
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     for(int i=2 ; i<=n;i++){
    //         ans=a+b;
    //         a=b;
    //         b=ans;
    //     }
    // return ans;
    // // return fib(n-1)+fib(n-2);
    // vector<int>dp(n+1,-1);
    int ans = topdown(n);
    return ans;
    }
};