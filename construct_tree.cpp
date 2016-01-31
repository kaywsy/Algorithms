//construct a tree from input
//input:
// e f g
// a b c
// b d e
//output:
//       a
//      / \
//     b   c
//    / \
//   d   e
//      / \
//     f   g

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x) : val(x) {
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

TreeNode* constructTree(vector<vector<char>>& input) {
    if (input.size() == 0) return NULL;
    unordered_map<char, TreeNode*> m;
    for (int i = 0; i < input.size(); ++i) {
        TreeNode *newroot, *newleft, *newright;
        if (m.find(input[i][0]) == m.end()) {
            newroot = new TreeNode(input[i][0]);
            m[input[i][0]] = newroot;
        } else {
            newroot = m[input[i][0]];
        }
        if (m.find(input[i][1]) == m.end()) {
            newleft = new TreeNode(input[i][1]);
            m[input[i][1]] = newleft;
        } else {
            newleft = m[input[i][1]];
        }
        if (m.find(input[i][2]) == m.end()) {
            newright = new TreeNode(input[i][2]);
            m[input[i][2]] = newright;
        } else {
            newright = m[input[i][2]];
        }
        newroot -> left = newleft;
        newroot -> right = newright;
        newleft -> parent = newroot;
        newright -> parent = newroot;
    }
    TreeNode* root = m[input[0][0]];
    while (root -> parent != NULL) {
        root = root -> parent;
    }
    return root;
}

int main() {
    vector<vector<char>> test ={{'e', 'f', 'g'}, {'a', 'b', 'c'}, {'b', 'd', 'e'}};
    TreeNode* root = constructTree(test);
    int cur_cnt = 1, next_cnt = 0, visited = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        visited++;
        cout << cur -> val << " ";
        if (cur -> left != NULL) {
            q.push(cur -> left);
            next_cnt++;
        }
        if (cur -> right != NULL) {
            q.push(cur -> right);
            next_cnt++;
        }
        if (visited == cur_cnt) {
            cur_cnt = next_cnt;
            next_cnt = 0;
            visited = 0;
            cout << endl;
        }
        
    }
    
}
