class Solution {
public:
    int scoreOfParentheses(string s) {
        int count=0;
        stack<int>st;
        st.push(0);
        for(auto ch:s){
            if(ch=='('){
                st.push(0);
            }else{
                int x=st.top();
                st.pop();
                if(x==0){
                    count=1;
                }else{
                    count=2*x;
                }

                st.top()+=count;
            }
        }
        return st.top();
    }
};