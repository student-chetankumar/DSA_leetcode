class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int balance =0;
        int deficit = 0;

        for(int i=0;i<gas.size();i++){
        //  If available gas is less than the cost,
        // we cannot continue from our current starting point.
            if(balance+gas[i]<cost[i]){
                deficit += balance+gas[i]-cost[i];
                start = i+1;
                balance = 0;
            }else{
                // We have enough gas to travel to the next station.

                balance = balance+gas[i]-cost[i];
            }
        }
        // If their sum is >= 0, total gas is enough to complete
        //     the circular route.
        if(balance + deficit >=0){
            return start;       // Valid starting gas station
        }
        else{
            return -1;           // Not possible to complete the circuit
        }
    }
};