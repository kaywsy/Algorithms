//given an array of n integers, a moving window(size k)
//move the window at each iteration from the start
//find the median of the element inside the window
//e.g. for array [1, 2, 7, 8, 5], window size k = 3
//return [2, 7, 7]


#include <iostream>
#include <vector>
#include <set>


using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> result;
    multiset<int, less<int>> larger;
    multiset<int, greater<int>> smaller;
    for (int i = 0; i < nums.size(); ++i) {
        if (i >= k) {
            if (larger.find(nums[i-k]) != larger.end()) {
                larger.erase(larger.find(nums[i-k]));
            } else {
                smaller.erase(smaller.find(nums[i-k]));
            }
        }
        if (smaller.empty() || nums[i] > *smaller.begin()) {
            larger.insert(nums[i]);
            while (larger.size() > smaller.size()) {
                smaller.insert(*larger.begin());
                larger.erase(larger.begin());
            }
        } else {
            smaller.insert(nums[i]);
            while (smaller.size() > larger.size() + 1) {
                larger.insert(*smaller.begin());
                smaller.erase(smaller.begin());
            }
        }
        if (i+1 >= k) {
            if (smaller.size() == larger.size()) {
                result.push_back((*larger.begin() + *smaller.begin()) / 2.0);
            } else {
                result.push_back((double)*smaller.begin());
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 7, 8, 5};
    vector<double> result = medianSlidingWindow(nums, 3);
    for (auto r : result) {
        cout << r << " ";
    }
    return 0;
}
