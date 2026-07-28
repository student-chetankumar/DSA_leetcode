class Solution {
public:
bool solve(string &s, int st,int e){
    while(st<e && !isalnum(s[st])) st++;
    while(st<e && !isalnum(s[e])) e--;
    
    if(st>=e) return true;
    if(tolower(s[st])!=tolower(s[e])){
       return false;
    }
    return solve(s,st+1,e-1);

}
    bool isPalindrome(string s) {
        
    //   int st=0,e=s.size()-1;
    //   while(st<e){
    //     if(!isalnum(s[st]))  st++ ;
    //     else if(!isalnum(s[e]))  e--;
    //     else {
    //         if(tolower(s[st])!=tolower(s[e])) return false;
    //             st++;
    //             e--;
    //     }
    //   }  
       return solve(s,0,s.length());
    }
};