class Solution {
public:
    int search(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target) return i;
        // }
    
    int s=0,e=nums.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target) 
            return mid;

        // left half search
        if(nums[s]<=nums[mid]){
            if(target>=nums[s] && target<nums[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        else{
        // right half search
         if(nums[mid]<=nums[e]){
            if(target>nums[mid] && target<=nums[e])
                s=mid+1;
            else
                e=mid-1;
        }
      }
    }
    return -1;
    }
};