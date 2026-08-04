class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e= *max_element(nums.begin(), nums.end());
        
        while(s<=e){
            int mid=s+(e-s)/2;
            int sum=0;
            for(int x:nums){
                sum+=(x+mid-1)/mid;
            }
            if(sum<=threshold){
               e=mid-1;
            }else{
               s=mid+1;

            }
        }
    return s;
    }
};