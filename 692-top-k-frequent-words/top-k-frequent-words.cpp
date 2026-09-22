class compare{
    public:
      bool operator()(pair<string,int> a,pair<string,int> b){
        if(a.second!=b.second)
           return  a.second > b.second;
        
        return a.first < b.first;
      }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        // count frequency
        unordered_map<string,int>freq;
        for(auto x:words){
            freq[x]++;
        }

        // create min heap
        priority_queue<pair<string,int> ,vector<pair<string,int>>,compare> pq;

        for(auto x:freq){
            pq.push(x);

            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};