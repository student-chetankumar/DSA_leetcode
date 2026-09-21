class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        // Using map
        // unordered_map<int,int>freq;
        // for(auto i:nums){
        //     freq[i]++;
        // }
        // for(auto i:freq){
        //     if(i.second>1){
        //         ans.push_back(i.first);
        //     }
        // }

        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};