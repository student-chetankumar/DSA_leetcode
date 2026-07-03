class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            // for odd length
            int left=i,right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                count++;
                left--;
                right++;
            }

            // for even length
            left=i,right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                count++;
                left--;
                right++;
            }  
        }
    return count;
    }
};