class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>st(nums[i].begin(),nums[i].end());

            for(int x:st){
                mp[x]++;
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