class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>freq;
        for(auto x:s){
            freq[x]++;
            if(freq[x]==2){
                 return x;
            }
        }
       return ' ';
    }
};