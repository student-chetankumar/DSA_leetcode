class Solution {
public:
void solve(string digits,int index,string current,vector<string>&ans){
    vector<string> keypad = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    if(index==digits.size()){
        ans.push_back(current);
        return;
    }

    string letter = keypad[digits[index]-'0'];

    for(char ch:letter){
        current.push_back(ch);
        solve(digits,index+1,current,ans);
        current.pop_back();
    }
}
    
    vector<string> letterCombinations(string digits) {
       vector<string>ans;
       int index=0;
       solve(digits,index,"",ans);
       return ans;
    

    }
};