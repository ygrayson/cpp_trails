#include <iostream>
#define M 5
#define N 5

int optimal_amount(int gold_mine[M][N], int position[]) {
    static int optimal_gold[M][N] = {{0}};

    //base case: left-most colomn
    if (position[1] == N-1) {
        optimal_gold[position[0]][position[1]] = gold_mine[position[0]][position[1]];
        return optimal_gold[position[0]][position[1]];
    }
    //recursive case
    else {
        optimal_gold[position[0]][position[1]] = std::max(optimal_amount(gold_mine, {1, 2}),
                                                          optimal_amount(gold_mine, {position[0], position[1]+1}),
                                                          optimal_amount(gold_mine, {position[0]+1, position[1]+1}));
        return optimal_gold[position[0]][position[1]];
    }
}


int main() {
    int gold_mine[M][N] = {{1,2,3,4,5},
                            {2,3,4,5,6},
                            {5,3,6,8,5},
                            {7,4,2,6,9},
                            {1,1,1,1,1}};
    int start_pos[2] = {2, 0}; //second entry must be 0 (left-most colomn)

    int max_gold;
    max_gold = optimal_amount(gold_mine, start_pos);
    std::cout << max_gold << std::endl;

    return 0;
}