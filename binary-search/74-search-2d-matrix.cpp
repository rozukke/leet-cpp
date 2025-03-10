#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int low = 0;
        int high = (matrix.size() * matrix[0].size()) - 1;

        while (low < high) {
            int search_index = low + (high - low) / 2;
            if (getMatrixIndex(matrix, search_index) >= target) {
                high = search_index;
            } else {
                low = search_index + 1;
            }
        }
        return getMatrixIndex(matrix, high) == target;
    }

    int getMatrixIndex(std::vector<std::vector<int>>& matrix, int index) {
        int column_len = matrix.size();
        int row_len = matrix[0].size();

        int index_in_column = index / row_len;
        int index_in_row = index % row_len;

        return matrix[index_in_column][index_in_row];
    }
};
