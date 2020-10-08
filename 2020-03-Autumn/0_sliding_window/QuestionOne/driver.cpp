// Bill Zhao

#include <vector>
#include <algorithm>
#include <iostream>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            count++;
            max = std::max(count, max);
        } else {
            count = 0;
        }
    }
    return max;
}

int main() {
    std::vector<int> four (11,0);
    four[0] = 1;
    four[1] = 1;
    four[3] = 1;
    four[4] = 1;
    four[5] = 1;
    four[6] = 1;
    four[10] = 1;
    // {1,1,0,1,1,1,1,0,0,0,1}
    if (findMaxConsecutiveOnes(four) == 4) {
        std::cout << "Solution is accepted!" << std::endl;
    } else {
        std::cout << "Solution failed, try again!" << std::endl;
    }
}