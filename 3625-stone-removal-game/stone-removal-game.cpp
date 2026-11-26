class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        int turn = 0;

        while (n >= stones) {
            n -= stones;
            stones--;

            turn++;
        }

        return turn % 2 != 0;
    }
};


// Explanation (Point by Point)
// 1. stones = 10 → Alice removes 10 stones first.
// 2. turn = 0 → Keeps track of the number of successful moves.
// 3. while (n >= stones) → Checks whether the current player can remove the required stones.
// 4. n -= stones → Removes the stones from the pile.
// 5. stones-- → Next player must remove 1 fewer stone.
// 6. turn++ → Increases the turn count.
// 7. return turn % 2 == 1:
//    - Odd number of successful moves → Alice wins.
//    - Even number of successful moves → Bob wins.