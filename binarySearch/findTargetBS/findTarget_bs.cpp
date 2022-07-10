#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given sorted int array, search for a target value
    Ex. nums = [-1,0,3,5,9,12], target = 9 -> 4 (index)

    Since array is sorted, perform binary search

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
}; 

int main(){
    
    Solution sol;
    vector<int> sortedNums{-1,0,3,5,9,12};
    int target = 9;
    cout<<"target found at index: "<<sol.search(sortedNums, target);
    return 0;
}