class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[nums[i][j]]++;
            }
        }

        for(auto x:mp){
            if(x.second==n){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};