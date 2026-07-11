class Solution {
public:
bool ispossible(vector<int>& nums, int k,int mid ){
    int count=1;
    int sum=0;
    for(int num:nums){
    if(sum+num<=mid){
        sum+=num;
    }else{
        count++;
        sum=num;
    }
    }
    return count<=k;
}
     int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,k,mid))
               high=mid-1;
            else 
               low=mid+1;
        }  
    
    return low;
   }
};