#include <vector>
#include <cstdint>

#define HORIZONTAL 0
#define VERTICAL 1
#define SUB_BOX 2

class Solution {
  public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
      std::uint16_t check[3];

      // Check horizontally
      for (unsigned int i = 0; i < 9; i++) {
        std::uint8_t subBoxYI = i / 3 * 3;
        std::uint8_t subBoxXI = i % 3 * 3;

        for (unsigned int j = 0; j < 3; j++) {
          check[j] = 0;
        }

        for (unsigned int j = 0; j < 9; j++) {
          std::uint8_t subBoxY = subBoxYI + j / 3;
          std::uint8_t subBoxX = subBoxXI + j % 3;

          if ((board[i][j] != '.' && check[HORIZONTAL] & 1 << (board[i][j] - '1')) ||
              (board[j][i] != '.' && check[VERTICAL]   & 1 << (board[j][i] - '1')) ||
              (board[subBoxY][subBoxX] != '.' && check[SUB_BOX] & 1 << (board[subBoxY][subBoxX] - '1'))) {
            return false;

          } else {
            if (board[i][j] != '.') check[HORIZONTAL] |= 1 << (board[i][j] - '1');
            if (board[j][i] != '.') check[VERTICAL]   |= 1 << (board[j][i] - '1');
            if (board[subBoxY][subBoxX] != '.') check[SUB_BOX] |= 1 << (board[subBoxY][subBoxX] - '1');
          }
        }
      }

      return true;
    }
};

