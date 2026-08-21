class Solution {
public:
vector<int> nextSmallerEle(vector<int>&v){
    stack<int>st;
    st.push(-1);
    vector<int>ans(v.size(),-1);
    for(int i=v.size()-1;i>=0;i--){
        while(!st.empty() && st.top() != -1 && v[st.top()] > v[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerEle(vector<int>&v){
    stack<int>st;
    st.push(-1);
    vector<int>ans(v.size(),-1);
    for(int i=0;i<v.size();i++){
        while(!st.empty() && st.top() != -1 && v[st.top()] >= v[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmallerEle(arr);
        auto prev = prevSmallerEle(arr);
        long long sum = 0;
        const int MOD = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            // for each index element , i wnat to find 
            //  how many times ith ele is contributing to the sum
            int nexti = next[i]==-1?arr.size() : next[i];
            int previ = prev[i];
            int left = i-previ;
            int right = nexti-i;
            long long no_of_times = (left*right)%MOD;
            long long total = (no_of_times * arr[i]) % MOD;
            sum= (sum+total) % MOD;
        }
        return sum;

    }
};