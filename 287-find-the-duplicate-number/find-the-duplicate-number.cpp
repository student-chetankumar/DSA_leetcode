class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//      sort(nums.begin(),nums.end());
//    for(int i=0;i<nums.size()-1;i++)
//    {
//       if(nums[i]==nums[i+1])
//       {
//         return nums[i];
//       }
  
//    }
//         return -1;
    int s=0,e=nums.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;

        int count=0;
        for(int num:nums){
            if(num<=mid){
                count++;
            }
        }

        if(count>mid){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
    }
};