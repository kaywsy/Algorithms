//given n x m non-negative intergers representing an elevation map 2d
//where the area of each cell is 1 x 1
//compute how much water it is able to trap after raining
// [12, 13, 0, 12]
// [13, 4, 13, 12]
// [13, 8, 10, 12]
// [12, 13, 12, 12]
// [13, 13, 13, 13]
// return 14

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cell {
    int x, y;
    int h;
    cell(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
};

struct compare {
    bool operator()(const cell& a, const cell& b) {
        return a.h > b.h;
    }
};

int trapWater(vector<vector<int>>& heights) {
    if (heights.size() == 0) return 0;
    int n = (int)heights.size(), m = (int)heights[0].size();
    priority_queue<cell, vector<cell>, compare> heap;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int water = 0;
    for (int i = 0; i < n; ++i) {
        heap.emplace(i, 0, heights[i][0]);
        heap.emplace(i, m-1, heights[i][m-1]);
        visited[i][0] = visited[i][m-1] = true;
    }
    for (int i = 1; i < m - 1; ++i) {
        heap.emplace(0, i, heights[0][i]);
        heap.emplace(n-1, i, heights[n-1][i]);
        visited[0][i] = visited[n-1][i] = true;
    }
    while(!heap.empty()) {
        cell cur = heap.top();
        heap.pop();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : dirs) {
            int newi = cur.x + dir.first, newj = cur.y + dir.second;
            if (newi >= 0 && newi < n && newj >= 0 && newj < m && !visited[newi][newj]) {
                water += max(0, cur.h - heights[newi][newj]);
                heap.emplace(newi, newj, max(cur.h, heights[newi][newj]));
                visited[newi][newj] = true;
            }
        }
    }
    return water;
}

int main() {
    vector<vector<int>> heights = {{12, 13, 0, 12}, {13, 4, 13, 12}, {13, 8, 10, 12}, {12, 13, 12, 12}, {13, 13, 13, 13}};
    cout << trapWater(heights) << endl;
    return 0;
}
