//sorted array of integers from 1 - N
//each integer appears 3 times
//delete one of them, find it out

#include <iostream>
#include <vector>

using namespace std;

//method 1: brute force
//O(n)
int missingEle1(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 0;
    while (i < nums.size() - 1) {
        if (i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2] ) {
            i += 3;
        } else {
            break;
        }
    }
    return nums[i];
}

//method 2: binary search
//O(lgn)
int missingEle2(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int l = 0, r = (int)nums.size()-1;
    while (l < r - 2) {
        int m = l + (r - l) / 2;
        int first = m - (m % 3);
        int second = first + 1;
        int third = second + 1;
        if (first >= l && third <= r) {
            if (nums[first] == nums[second] && nums[second] == nums[third]) {
                l = third + 1;
            } else {
                r = third;
            }
        }
    }
    return nums[l];
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5};
    cout << missingEle1(nums) << " " << missingEle2(nums) << endl;
    nums = {1, 1, 1, 2, 2, 3, 3, 3};
    cout << missingEle1(nums) << " " << missingEle2(nums) << endl;
    nums = {1, 1};
    cout << missingEle1(nums) << " " << missingEle2(nums) << endl;
    nums = {1, 1, 1, 2, 2};
    cout << missingEle1(nums) << " " << missingEle2(nums) << endl;
}
