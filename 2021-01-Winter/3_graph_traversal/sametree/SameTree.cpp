// Michael Cho
//
// Compare two trees for equality

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) {
        return true;
    }
    if(p == nullptr || q == nullptr) {
        return false;
    }
    if(p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main() {
	TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);

    TreeNode t3 = TreeNode(3, &t1, &t2);
    TreeNode t4 = TreeNode(3, &t1, &t2);

    cout << isSameTree(&t1, &t2) << endl;
    cout << isSameTree(&t3, &t4) << endl;
}

