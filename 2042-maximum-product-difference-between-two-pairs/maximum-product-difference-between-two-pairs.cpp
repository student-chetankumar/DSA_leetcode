class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
      int firstmax=INT_MIN;
      int secondmax=INT_MIN;
      int firstmin=INT_MAX;
      int secondmin=INT_MAX;

        for(auto x:nums){
            if(x>firstmax){
                
                secondmax=firstmax;
                firstmax=x;
            }
            else if(secondmax<x){
                secondmax=x;
            }
        }

        for(auto x:nums){
            if(x<firstmin){
                
                secondmin=firstmin;
                firstmin=x;
            }
            else if(secondmin>x){
                secondmin=x;
            }
        }
        int ans= (firstmax*secondmax)-(firstmin*secondmin);
        return ans;

    // OR using sort function
    // sort(nums.begin(),nums.end());
    // int n=nums.size();
    // return ((nums[n-1]*nums[n-2])-(nums[0]*nums[1]));
    }
};