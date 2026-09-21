class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int current=mp[s[i]];
            if(i+1<n && current<mp[s[i+1]]){
                ans=ans-current;
            }else{
                ans=ans+current;
            }
        }
        return ans;
    }
};