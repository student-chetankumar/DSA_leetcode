class Solution {
public:

    bool isPalindrome(int x) {
     long long rem,n;
     long long r=0;
     n=x;
     while(n>0){
        rem=n%10;
        r=r*10+rem;
        n/=10;
     }
    if(r==x){
        return true;
    }
    return false;
    }
};