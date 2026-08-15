class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int num : nums){
            f[num]++;
        }
        for(int i=0;i<nums.size();i++){
            if(f[nums[i]]==1){
                return nums[i];
            }
        }
        
        return -1;
    }
};