class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>b(n,vector<int>(n));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               b[i][j]=arr[j][i];
            }
        }

    
       for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
               int temp=b[i][j];
               b[i][j]=b[i][n-j-1];
               b[i][n-j-1]=temp;
        }
     }
     arr=b;
    }
};