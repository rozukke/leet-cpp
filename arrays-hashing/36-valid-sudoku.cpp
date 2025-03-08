// Solution: tedious but simple. Iterate through rows, columns, and squares. For each iteration, keep track of
// digits by keeping a 32 bit int and setting a bit for each digit to save on space.
// Space and time complexity is O(1) since sudoku grid size is fixed.
//
// NOTE: Alternative is to iterate once, and save all the hashes to arrays that keep track of the whole state.
// LESSON LEARNED:
// int arr[3], arr[4] = {0}; // NO!!!! This does not init the first to zeroes
//
// Naive: same as above, but using bool[9] to keep track of each check.
#include <cstdint>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // check rows
        for (auto const& row : board) {
            uint32_t hash = 0;
            for (auto const num : row) {
                uint32_t bit = 1 << (num - '0' - 1);
                if (hash & bit) {
                    return false;
                } else {
                    hash |= bit;
                }
            }
        }
        // check columns
        for (int i = 0; i < board.size(); ++i) {
            uint32_t hash = 0;
            for (int j = 0; j < board.size(); ++j) {
                uint32_t bit = 1 << (board[j][i] - '0' - 1);
                if (hash & bit) {
                    return false;
                } else {
                    hash |= bit;
                }
            }
        }
        // check squares
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                if (!checkSquare(board, i, j)) return false;
            }
        }
        return true;
    }

    bool checkSquare(std::vector<std::vector<char>>& board, int i, int j) {
        uint32_t hash = 0;
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                uint32_t bit = 1 << (board[i + k][j + l] - '0' - 1);
                if (hash & bit) {
                    return false;
                } else {
                    hash |= bit;
                }
            }
        }
        return true;
    }

    bool isValidSudokuAlt(std::vector<std::vector<char>>& board) {
        uint32_t rows[9] = {0};
        uint32_t cols[9] = {0};
        uint32_t squares[3][3] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                uint32_t bit = 1 << (board[r][c] - '1');

                // rows
                if (rows[r] & bit) {
                    return false;
                } else {
                    rows[r] |= bit;
                }
                //cols
                if (cols[c] & bit) {
                    return false;
                } else {
                    cols[c] |= bit;
                }
                //squares
                if (squares[r/3][c/3] & bit) {
                    return false;
                } else {
                    squares[r/3][c/3] |= bit;
                }
            }
        }
        return true;
    }
};
