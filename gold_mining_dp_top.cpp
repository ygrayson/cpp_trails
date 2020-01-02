#include <iostream>
using namespace std;
#define M 5
#define N 5

// small helper function for max of 3 nums
int max_int(const int a, const int b, const int c){
    int max = a;
    if (b > max){ max = b; }
    if (c > max){ max = c; }
    return max;
}


int optimal_amount(const int gold_mine[M][N], int position[]) {
    static int optimal_gold[M][N] = {{0}};

    //base case: right-most colomn
    if (position[1] == N-1) {
        optimal_gold[position[0]][position[1]] = gold_mine[position[0]][position[1]];
        return optimal_gold[position[0]][position[1]];
    }
    //recursive case
    else {
        int right_pos[] = {position[0], position[1]+1};
        int right_up_pos[] = {max(0, position[0]-1), position[1]+1};
        int right_down_pos[] = {min(M-1, position[0]+1), position[1]+1};
        int best_amount = max_int(optimal_amount(gold_mine, right_up_pos),
                                    optimal_amount(gold_mine, right_pos),
                                    optimal_amount(gold_mine, right_down_pos));
        optimal_gold[position[0]][position[1]] = gold_mine[position[0]][position[1]] + best_amount;
        return optimal_gold[position[0]][position[1]];
    }
}



int main() {
    const int gold_mine[M][N] = {{1,2,3,4,5},
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