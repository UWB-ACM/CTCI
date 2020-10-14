#include <iostream>
#import <vector>
using namespace std;

int removeDuplicates(std::vector<int>& nums) {

    if(nums.size() == 0){
        return 0;
    }

    //Pointer to the last, unique element in the array
    int left = 0;
    int right = 1;
    int size = nums.size();

    //Iterate through thr entire vector
    while ( right < size ){

        if ( nums[right] == nums[left]) {
            right++;
        }else{
            left++;
            nums[left] = nums[right];
            right++;
        }
    }
    //return the total unique elements in the array
    return left + 1;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    int unique = removeDuplicates(nums);

    for (int i = 0; i < unique ; ++i) {
        cout << nums[i] <<" ";
    }
    cout<<endl;

    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(1);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(3);
    nums2.push_back(4);

    int unique2 = removeDuplicates(nums2);

    for (int i = 0; i < unique2 ; ++i) {
        cout << nums2[i] <<" ";
    }

    return 0;
}
