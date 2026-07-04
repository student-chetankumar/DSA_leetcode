class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n) return "";
        vector<int>freq(128,0);

        for(char c : t){
            freq[c]++;
        }

        int left = 0 , minlen = INT_MAX ,count=m, start=-1;

        for(int right=0;right<n;right++){
            if(freq[s[right]]>0)
                count--;
            
            freq[s[right]]--;
            
            while(count==0){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }

                freq[s[left]]++;

                if(freq[s[left]]>0)
                   count++;
                
                left++;
            }

        }

        if(start==-1) return "";
        return s.substr(start,minlen);
        
    }
};