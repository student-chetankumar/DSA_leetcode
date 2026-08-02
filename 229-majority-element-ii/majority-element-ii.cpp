class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
       int n= v.size();
       vector<int>a;
       for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(v[i]==v[j]){
                count++;
            }
        }
        if(count >n/3){
            if(find(a.begin(),a.end(),v[i])==a.end()){
                 a.push_back(v[i]);
            }
           
        }
       }
       return a;
    }
};