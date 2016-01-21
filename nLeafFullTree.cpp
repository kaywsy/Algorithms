//return whether a binary is a full tree with n leaf nodes
//idea: get the leaf number and height of the tree
//if the leaf number is power of 2 and is equal to n, return true
#include <iostream>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i) : val(i), left(NULL), right(NULL) {}
};

int getNum(TreeNode* root);
int getHeight(TreeNode* root);

bool nLeafFullTree(TreeNode* root, int n) {
    if (root == NULL) return false;
    int leaf = getNum(root);
    int height = getHeight(root);
    if (pow(2, height-1) == n && leaf == n) return true;
    return false;
}

int getNum(TreeNode* root) {
    if (root -> left == NULL && root -> right == NULL) return 1;
    else if (root -> left == NULL || root -> right == NULL) {
        return root -> left == NULL? getNum(root -> right) : getNum(root -> left);
    } else {
        return getNum(root -> left) + getNum(root -> right);
    }
}

int getHeight(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(getHeight(root -> left), getHeight(root -> right));
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(8);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(12);
    root -> right -> left = new TreeNode(10);
    cout << nLeafFullTree(root, 2) << endl;
}
