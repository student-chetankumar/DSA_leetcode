class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiantQ , direQ;
        int i=0;
        for(;i<senate.size();i++){
            char senator = senate[i];
            if(senator == 'R') radiantQ.push(i);
            if(senator == 'D') direQ.push(i);
        }

        while(!radiantQ.empty() && !direQ.empty()){
            int rfront = radiantQ.front();
            radiantQ.pop();

            int dfront = direQ.front();
            direQ.pop();

            if(rfront < dfront){
                radiantQ.push(i++);
            }else{
                direQ.push(i++);
            }                                 
        }

             if(!radiantQ.empty()) return "Radiant";  
             return "Dire"; 
    }
};