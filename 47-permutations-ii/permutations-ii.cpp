class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,int index){
        if(index==nums.size()) {
            ans.push_back(nums);
            return ;
        }

       unordered_set<int>Set;
       // if(dp[index]!-1) return dp[index];

        for(int i=index;i<nums.size();i++){
            if(Set.count(nums[i]))
                continue;
            Set.insert(nums[i]);
            swap(nums[index],nums[i]);
            solve(nums,index+1);
            swap(nums[index],nums[i]);
        }
    
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};