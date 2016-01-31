//reconstruct queue
//several people in a queue with different heights
//we know all the heights and a status vector about #people higher than each person ahead him
//reconstruct queue to the right order
//eg. 5 people in a queue with height 1 - 5
//status vector is [0, 1, 0, 3, 2]
//the right order is 4, 2, 5, 1, 3

#include <iostream>
#include <vector>

using namespace std;

vector<int> reconstructQueue(vector<int>& heights, vector<int> status) {
    if (heights.size() == 0) return {};
    sort(heights.begin(), heights.end(),greater<int>());
    vector<int> result;
    for (int i = (int)status.size() - 1; i >= 0; --i) {
        result.push_back(heights[status[i]]);
        heights.erase(heights.begin() + status[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> heights = {1, 2, 3, 4, 5};
    vector<int> status = {0, 1, 0, 3, 2};
    vector<int> result = reconstructQueue(heights, status);
    for (int i = 0; i < (int)result.size(); ++i) {
        cout << result[i] << " ";
    }
}
