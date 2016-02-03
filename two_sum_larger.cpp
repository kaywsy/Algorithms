//two sum larger
//given an array of integers, count the number of pairs whose two number sum is larger than target
//idea: sort + two pointers
//time complexity: O(nlgn) + O(n) = O(nlgn)

#include <iostream>
#include <vector>

using namespace std;

int twoSumLarger(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int i = 0, j = (int)nums.size()-1, cnt = 0;
    while (i < j) {
        //case 1: nums[i] + nums[j] > target
        //j--
        //increase cnt by j-i
        if (nums[i] + nums[j] > target) {
            cnt += j - i;
            j--;
        }
        //case 2: nums[i] + nums[j] <= target
        //i++
        else {
            i++;
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = {3, 4, 5, 7, 8};
    cout << twoSumLarger(nums, 9) << endl;
    return 0;
}
