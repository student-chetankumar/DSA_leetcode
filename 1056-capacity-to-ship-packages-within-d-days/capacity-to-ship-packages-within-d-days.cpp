class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        while(s<=e){
            int mid=s+(e-s)/2;
            int day=1;
            int load=0;
            for(int w:weights){
                if(load+w<=mid){
                    load+=w;
                }else{
                    day++;
                    load=w;
                }
            }
                
                if(day<=days){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            
        }
    return s;
    }
};