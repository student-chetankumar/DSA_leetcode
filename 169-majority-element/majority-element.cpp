class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    //1. brute force 
    //    for(int i=0;i<n;i++){
    //     int count=0;
    //     for(int j=0;j<n;j++){
    //         if(nums[i]==nums[j]){
    //             count++;
    //         }
    //     }
    //     if(count>n/2){
    //     return nums[i];
    //     }
    //    }

    // 2.optimized approach
    // sort(nums.begin(),nums.end());
    // int count=1;
    // int ans=nums[0];
    // for(int i=1;i<n;i++){
    //     if(nums[i]==nums[i-1]){
    //         count++;
    //         ans=nums[i];
    //     }else{
    //         count=1;
    //         ans=nums[i];
    //     }      
    //      if(count>n/2){
    //         return ans;
    //     }
    // }
    //    return -1;

    // 3.moore's voting algo
    int freq=0,ans=0;
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
    }
};