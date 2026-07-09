class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
       int s=0,e=a.size()-1;
      
       while(s<e){
        int mid=s+(e-s)/2;
        if(s==e){
             return  s;
         }
        if(mid%2==0){
            if(a[mid]==a[mid+1]){
                s=mid+2;
            }
            else {
                e=mid;
            }
            }
            else {
               if(a[mid]==a[mid-1])
               { 
                s=mid+1;
               }
                else {
                    e=mid-1;
                }
            } 
       }
       return  a[s];
    }
};