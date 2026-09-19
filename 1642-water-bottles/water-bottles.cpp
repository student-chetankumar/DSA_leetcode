class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int total=numBottles;
       while(numBottles>=numExchange){
        int newBottle = numBottles/numExchange;
        total+=newBottle;
        numBottles = newBottle + (numBottles % numExchange);
       } 
       return total;
    }
};