#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution test1;
    Solution test2;

    vector<int> testNumbers {4,5,6,7,0,1,2};
    vector<int> testNumbers2 {4,5,6,7,0,1,2};

    cout << test1.search(testNumbers, 0) << endl;
    cout << test2.search(testNumbers2, 3) << endl;
}
