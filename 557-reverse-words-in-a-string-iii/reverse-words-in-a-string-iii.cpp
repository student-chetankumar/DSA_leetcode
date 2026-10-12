class Solution {
public:
    string reverseWords(string s) {
       stack<char>st;
       string ans="";
       for(auto ch:s){
          if(ch==' '){
            while(!st.empty()){
            ans+=st.top();
            st.pop();
            }
            ans+=' ';
          }else{
            st.push(ch);
          } 
       }

       while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
       return ans; 
    }
};