class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n=nums.size();
    // vector<int>v(n+1,-1);
    // for(int i=0;i<n;i++){
    //     v[nums[i]]=1;
    // }
    // for(int i=0;i<v.size();i++){
    //     if(v[i]==-1) return i;
    // }
    // return nums.size();
    int maxSum=n*(n+1)/2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+nums[i];
    }
      return maxSum-sum;
    }
};