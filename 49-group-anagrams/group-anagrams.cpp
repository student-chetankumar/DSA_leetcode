class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};
        vector<vector<string>> ans;

        unordered_map<string , vector<string>> mp;
        for(auto st:strs){
           string key =st;
           sort(key.begin(),key.end());
           mp[key].push_back(st);
        }
        for(auto &st:mp){
             ans.push_back(st.second);
        }
    return ans;
    }
};