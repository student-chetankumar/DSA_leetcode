class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       if(k<0) return 0;
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        
        while(i<n && j<n){
            if(i==j ||abs( nums[j]-nums[i])<k){
                j++;
            }
            else  if(abs(nums[j]-nums[i])>k){
                i++;
            }
            else {
                ans++;
                i++;
                j++;
                while (j < n && nums[j] == nums[j - 1]) j++;
            }
        }
        return ans;
    }
};