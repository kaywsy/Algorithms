//Kth largest element in n unsorted array
//given n unsorted arrays, return the Kth largest element among all

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Entry {
    int index;
    int val;
    Entry(int x, int y) : index(x), val(y) {};
};

struct compare {
    bool operator() (Entry a, Entry b) {
        return a.val < b.val;
    }
};

int kthLargest(vector<vector<int>>& nums, int k) {
    int n = (int)nums.size();
    priority_queue<Entry, vector<Entry>, compare> heap;
    vector<int> index(n, 0);
    for (int i = 0; i < n; ++i) {
        sort(nums[i].begin(), nums[i].end(), greater<int>());
    }
    
    for (int i = 0; i < n; ++i) {
        Entry cur(i, nums[i][0]);
        heap.push(cur);
    }
    
    for (int i = 0; i < k - 1; ++i) {
        Entry largest = heap.top();
        heap.pop();
        int cur_index = largest.index;
        if (index[cur_index] < nums[cur_index].size()-1) {
            index[cur_index]++;
            Entry newEntry(cur_index, nums[cur_index][index[cur_index]]);
            heap.push(newEntry);
        }
    }
    return heap.top().val;
}

int main() {
    vector<vector<int>> nums = {{2, 1, 5, 3}, {4, 6, 1, 9}, {3, 3, 10}, {12, 7}};
    cout << kthLargest(nums, 1) << endl;
    return 0;
}
