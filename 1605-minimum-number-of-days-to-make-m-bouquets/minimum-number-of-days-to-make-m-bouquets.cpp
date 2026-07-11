class Solution {
public:
bool isPossible(vector<int>& bloomDay, int m, int k, int day) {

    int flowers = 0;
    int bouquets = 0;
    for(int x:bloomDay){
        if(x<=day){
            flowers++;    //flower has bloomed
        
           if(flowers==k){
              bouquets++;
              flowers=0;
            }
        }
        else{
            flowers=0;
        }
    }
    return bouquets >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) 
           return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,m,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return low;
    }
};