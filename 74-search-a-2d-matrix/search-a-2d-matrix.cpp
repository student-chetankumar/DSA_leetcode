class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row = m.size();
        int col = m[0].size();

        int s = 0, e = row * col - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int element = m[mid / col][mid % col]; // flattening 2D → 1D

            if (element == target) {
                return true;
            }
            else if (element < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return false;
    }
};
