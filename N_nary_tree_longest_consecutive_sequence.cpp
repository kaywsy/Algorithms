//given a n-nary tree, find the length of the longest consecutive sequence
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> child;
    TreeNode(int x, int n) {
        val = x;
        child = vector<TreeNode*>(n, NULL);
    }
};

int dfs(TreeNode* root, int count, int preVal) {
    if (root == NULL) return 0;
    count = root -> val == preVal + 1 ? count + 1 : 1;
    int temp = 0;
    for (TreeNode* n : root -> child) {
        temp = max(temp, dfs(n, count, root -> val));
    }
    return max(count, temp);
}

int longestSequence(TreeNode* root) {
    if (root == NULL) return 0;
    return dfs(root, 0, root -> val - 1);
}

int main() {
    TreeNode* root = new TreeNode(3, 3);
    root -> child[0] = new TreeNode(2, 2);
    root -> child[1] = new TreeNode(4, 3);
    root -> child[2] = new TreeNode(5, 2);
    root -> child[0] -> child[0] = new TreeNode(6, 0);
    root -> child[0] -> child[1] = new TreeNode(3, 0);
    root -> child[1] -> child[0] = new TreeNode(3, 1);
    root -> child[1] -> child[1] = new TreeNode(5, 2);
    root -> child[1] -> child[2] = new TreeNode(7, 0);
    root -> child[2] -> child[0] = new TreeNode(9, 0);
    root -> child[2] -> child[1] = new TreeNode(6, 0);
    root -> child[1] -> child[0] -> child[0] = new TreeNode(7, 0);
    root -> child[1] -> child[1] -> child[0] = new TreeNode(6, 0);
    root -> child[1] -> child[1] -> child[1] = new TreeNode(5, 0);
    cout << longestSequence(root) << endl;
}
