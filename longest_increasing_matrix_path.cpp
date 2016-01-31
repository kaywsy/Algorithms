//idea from poj 1088
//given an integer matrix, find the length of the longest increasing path and return the path
//dp + bfs
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int dp(vector<vector<int>> &matrix, vector<vector<int>> &opt, int i, int j, int r, int c);

int longestPathMatrix(vector<vector<int>> &matrix, vector<int> &path) {
    if (matrix.size() == 0) return 0;
    int r = (int)matrix.size(), c = (int)matrix[0].size();
    int maxlen = 0;
    pair<int, int> endPoint;
    vector<vector<int>> opt(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (dp(matrix, opt, i, j, r, c) > maxlen) {
                maxlen = dp(matrix, opt, i, j, r, c);
                endPoint.first = i;
                endPoint.second = j;
            }
        }
    }
    path.push_back(matrix[endPoint.first][endPoint.second]);
                   
    for (int i = endPoint.first, j = endPoint.second; opt[i][j] > 1;) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : dirs) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < r && newj >= 0 && newj < c) {
                if (opt[newi][newj] == opt[i][j] - 1 && matrix[newi][newj] < matrix[i][j]) {
                    path.push_back(matrix[newi][newj]);
                    i = newi;
                    j = newj;
                }
            }
        }
    }
    return maxlen;
    
}

int dp(vector<vector<int>> &matrix, vector<vector<int>> &opt, int i, int j, int r, int c) {
    if (opt[i][j] > 0) return opt[i][j];
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    for (auto dir : dirs) {
        int newi = i + dir.first, newj = j + dir.second;
        if (newi >= 0 && newi < r && newj >= 0 && newj < c) {
            if (matrix[newi][newj] < matrix[i][j]) {
                opt[i][j] = max(opt[i][j], dp(matrix, opt, newi, newj, r, c));
            }
        }
    }
    return ++opt[i][j];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> test = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    vector<int> path;
    int maxlen = longestPathMatrix(test, path);
    
    cout << "max length is: " << maxlen << endl;
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    
    return 0;
}
