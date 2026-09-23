class Solution {
public:
    string reverseWords(string s) {
        string word="";
        stack<string>st;
        for(char ch:s){
            if(ch==' '){
                if(word!=""){
                    st.push(word);
                    word="";
                }
            }else{
                word+=ch;
            }
        }
//       last word
        if(word != "") {
            st.push(word);
        }

        string ans="";


        while(!st.empty()){
            ans+=st.top();
            st.pop();

            if(!st.empty()){
                ans+=' ';
            }
        }

        return ans;
    }
};