class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int total_element=m*n;
      

        int StartingRow=0;
        int endingCol=n-1;
        int endingRow=m-1;
        int StartingCol=0;

          int count=0;
        while(count<total_element)
        {
          //printf startingRow
          for(int i=StartingCol;i<=endingCol && count<total_element;i++){
            ans.push_back(matrix[StartingRow][i]);
            count++;
          }
          StartingRow++;
          //print endingCol
          for(int i=StartingRow;i<=endingRow && count<total_element;i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
          }
          endingCol--;

          //print endingRow
           for(int i=endingCol;i>=StartingCol && count<total_element;i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
          }
         endingRow--;
          //print startingCol
          for(int i=endingRow;i>=StartingRow && count<total_element;i--){
            ans.push_back(matrix[i][StartingCol]);
            count++;
          }
          StartingCol++;
        }
        return ans;
    }
};