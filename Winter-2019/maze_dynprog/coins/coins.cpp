#include <cassert>
#include <iostream>

using namespace std;

int coinsNaive(int amount, int denoms[], int denomCount, int denomIndex) {
    // check index bounds first
    if (denomIndex >= denomCount - 1) return 1;
    int permutations = 0;
    // recursively solve subproblems for smaller denominations
    for (int i = 0; i <= (amount / denoms[denomIndex]); i++) {
        // recursive call
        permutations += coinsNaive(amount - (denoms[denomIndex] * i), denoms, denomCount, denomIndex + 1);
    }
    return permutations;
}

int coinsDynamic(int amount, int denoms[], int denomCount, int denomIndex, int computed[][4]) {
    // check index bounds first
    if (denomIndex >= denomCount - 1) return 1;
    if (computed[amount][denomIndex] > 0) return computed[amount][denomIndex];
    int permutations = 0;
    for (int i = 0; i <= (amount / denoms[denomIndex]); i++) {
        int newAmount = amount - (denoms[denomIndex] * i);
        permutations += coinsDynamic(newAmount, denoms, denomCount, denomIndex + 1, computed);
    }
    computed[amount][denomIndex] = permutations;
    return permutations;
}

int main() {
    int denoms[4]{25, 10, 5, 1};
    int testInput[5]{5, 10, 25, 100, 1000};
    int testAnswers[5]{2, 4, 13, 242, 142511};
    cout << "Testing naive solution:" << endl;
    for (int i = 0; i < 5; i++) {
        int answer = coinsNaive(testInput[i], denoms, 4, 0);
        cout << "For amount " << testInput[i] << " got result " << answer << endl;
        assert(answer == testAnswers[i]);
    }
    cout << "Testing dynamic solution:" << endl;
    for (int i = 0; i < 5; i++) {
        int computedVals[testInput[i] + 1][4];
        for (int j = 0; j < testInput[i] + 1; j++) {
            for (int k = 0; k < 4; k++) {
                computedVals[j][k] = 0;
            }
        }
        int answer = coinsDynamic(testInput[i], denoms, 4, 0, computedVals);
        cout << "For amount " << testInput[i] << " got result " << answer << endl;
        assert(answer == testAnswers[i]);
    }
}
