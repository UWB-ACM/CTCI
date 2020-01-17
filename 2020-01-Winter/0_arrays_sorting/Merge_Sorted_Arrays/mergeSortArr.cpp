#include <iostream>
#include <vector>
using namespace std;

std::vector<int> &merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
  int backOfArray = nums1.size() - 1;

  while (m - 1 >= 0 && n - 1 >= 0)
  {
    if (nums1[m - 1] < nums2[n - 1])
    {
      nums1[backOfArray] = nums2[n - 1];
      n--;
    }
    else
    {
      nums1[backOfArray] = nums1[m - 1];
      m--;
    }
    backOfArray--;
  }

  while (n - 1 >= 0)
  {
    nums1[backOfArray] = nums2[n - 1];
    backOfArray--;
    n--;
  }

  return nums1;
}

void printVector(std::vector<int> numsVect)
{
  for (int i = 0; i < numsVect.size(); i++)
  {
    std::cout << numsVect[i] << ", ";
  }
  
  std::cout << std::endl;
}

// Test case for LeetCode output
void test1()
{
  std::vector<int> nums1(6);
  nums1[0] = 1;
  nums1[1] = 2;
  nums1[2] = 3;

  std::vector<int> nums2(3);
  nums2[0] = 2;
  nums2[1] = 5;
  nums2[2] = 6;
  nums1 = merge(nums1, 3, nums2, 3);
  printVector(nums1);

  std::cout << std::endl;
}

// Test case to make sure duplicates are handled
void test2()
{
  std::vector<int> nums1(10);
  nums1[0] = 0;
  nums1[1] = 1;
  nums1[2] = 1;
  nums1[3] = 3;

  std::vector<int> nums2(6);
  nums2[0] = 1;
  nums2[1] = 2;
  nums2[2] = 2;
  nums2[3] = 3;
  nums2[4] = 4;
  nums2[5] = 5;

  nums1 = merge(nums1, 4, nums2, 6);
  printVector(nums1);

  std::cout << std::endl;
}

// Test case where nums1 exhausted before nums2, so nums2 goes and dumps all its values in
void test3()
{
  std::vector<int> nums1(10);
  nums1[0] = 66;
  nums1[1] = 77;
  nums1[2] = 88;
  nums1[3] = 99;

  std::vector<int> nums2(6);
  nums2[0] = 1;
  nums2[1] = 2;
  nums2[2] = 2;
  nums2[3] = 3;
  nums2[4] = 4;
  nums2[5] = 5;

  nums1 = merge(nums1, 4, nums2, 6);
  printVector(nums1);

  std::cout << std::endl;
}

int main()
{
  test1();
  test2();
  test3();
}
