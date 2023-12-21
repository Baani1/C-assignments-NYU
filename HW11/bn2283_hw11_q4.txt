#include <iostream>
#include <vector>

using namespace std;

// Function to find the lowest cost to traverse the game board
int minCostJumpGame(vector<int>& board, int currentIndex, vector<int>& memo) {
    if (currentIndex == board.size() - 1) {
        return board[currentIndex];
    }

    if (memo[currentIndex] != -1) {
        return memo[currentIndex];
    }

    int costMove = board[currentIndex] + minCostJumpGame(board, currentIndex + 1, memo);
    int costJump = board[currentIndex] + minCostJumpGame(board, currentIndex + 2, memo);

    memo[currentIndex] = min(costMove, costJump);

    return memo[currentIndex];
}

int main() {
    vector<int> board = {0, 3, 80, 6, 57, 10};
    int n = board.size();
    vector<int> memo(n, -1);

    int lowestCost = minCostJumpGame(board, 0, memo);

    cout << "Lowest cost to reach the end: " << lowestCost << endl;

    return 0;
}
