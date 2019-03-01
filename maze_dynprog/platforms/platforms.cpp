#include <bits/stdc++.h>
#include <cassert> 
using namespace std; 
  
int findPlatform(int arr[], int dep[], int n) 
{ 
    // Insert all the times (arr. and dep.) 
    // in the multimap. 
    multimap<int, char> order; 
    for (int i = 0; i < n; i++) { 
  
        // If its arrival then second value 
        // of pair is 'a' else 'd' 
        order.insert(make_pair(arr[i], 'a')); 
        order.insert(make_pair(dep[i], 'd')); 
    } 
  
    int result = 0; 
    int plat_needed = 0; 
  
    multimap<int, char>::iterator it = order.begin(); 
  
    // Start iterating the multimap. 
    for (; it != order.end(); it++) { 
        // If its 'a' then add 1 to plat_needed 
        // else minus 1 from plat_needed. 
        if ((*it).second == 'a') 
            plat_needed++; 
        else
            plat_needed--; 
  
        if (plat_needed>result) 
            result = plat_needed; 
    } 
    return result; 
} 


int main() 
{ 
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int answer = findPlatform(arr, dep, n);
    cout << "Minimum Number of Platforms Required = "
         << answer << endl;
    assert(answer == 3);
    int arr1[] = { 300,  450, 600, 900,  925, 940,  950,  1015, 1100 };
    int dep1[] = { 1130, 610, 630, 1030, 945, 1300, 1210, 1130, 1200 }; 
    n = sizeof(arr1) / sizeof(arr1[0]);
    answer = findPlatform(arr1, dep1, n);
    cout << "Minimum Number of Platforms Required = "
         << answer << endl;
    assert(answer == 5);
    return 0; 
} 
