class compare{
    public:
      bool operator()(pair<int,int> a,pair<int,int> b){
        return  a.second > b.second;
      }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>freq;
        for(auto x:nums){
            freq[x]++;
        }

        priority_queue<pair<int,int> ,vector<pair<int,int>>,compare> pq;

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
        return ans;
    }
};