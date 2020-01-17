#include <iostream>
#include <vector>

std::vector<int>& merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
  int backOfArray = nums1.size()-1;

  while(m-1 > 0)
  {
    if(nums1[m-1] < nums2[n-1])
    {
      nums1[backOfArray] = nums2[n-1];
      n--;
      backOfArray--;
    }
    else if (nums1[m-1] > nums2[n-1])
    {
      nums1[backOfArray] = nums1[m-1];
      nums1[m-1] = 0;

      m--;
      backOfArray--;
    }
    else
    {
      nums1[backOfArray] = nums2[n-1];
      n--;
      m--;
      backOfArray--;
    }

  }
  return nums1;
}


int main()
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
  for (int i = 0; i < nums1.size(); i++)
  {
    std::cout << nums1[i] << ", ";
  }
}
