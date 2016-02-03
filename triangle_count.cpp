//triangle count
//given an array of integers, count number of triples that can build an triangle
//given array = [3, 4, 6, 7], return 3, they are:
//[3, 4, 6], [3, 6, 7], [4, 6, 7]
//given array = [4, 4, 4, 4], return 4, they are:
//[4(1), 4(2), 4(3)], [4(1), 4(2), 4(4)], [4(1), 4(3), 4(4)], [4(2), 4(3), 4(4)]

#include <iostream>
#include <vector>

using namespace std;

//method1: brute force O(n^3)
//three for loops
//i = 0 -> n, j = 0 -> i, k = 0 -> j
int triangleCount1(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int cnt = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                if(nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j]
                   && nums[j] + nums[k] > nums[i]) cnt++;
            }
        }
    }
    return cnt;
}

//method2: sort + two sum larger
//O(nlgn) + O(n^2) = O(n^2)
int triangleCount2(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 2; i < (int)nums.size(); ++i) {
        int l = 0, r = i-1;
        while (l < r) {
            if (nums[l] + nums[r] > nums[i]) {
                cnt += (r - l);
                r--;
            } else {
                l++;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> nums1 = {3, 6, 7, 4};
    vector<int> nums2 = {4, 4, 4, 4};
    cout << triangleCount1(nums1) << " " << triangleCount2(nums1) << endl;
    cout << triangleCount1(nums2) << " " << triangleCount2(nums2) << endl;
    return 0;
}
