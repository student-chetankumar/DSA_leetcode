class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0,leftsum=0,rightsum=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }

        for(int i=0;i<nums.size();i++){

            rightsum=total-leftsum-nums[i];
            if(leftsum==rightsum){
                return i;
            }
            leftsum+=nums[i];
        }

        return -1;

        
    }
};