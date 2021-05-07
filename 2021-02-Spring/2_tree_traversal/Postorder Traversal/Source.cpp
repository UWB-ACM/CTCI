// 145. Binary Tree Postorder Traversal
// Solution by Olga Kuriatnyk

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;

	// in case when was called defult constructor to creat root node
	if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
		return ans;
	}

	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty()) {
		TreeNode* curr = s.top();
		s.pop();
		if (curr == nullptr) {
			continue;
		}

		ans.push_back(curr->val);
		s.push(curr->left);
		s.push(curr->right);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

// helper function to print vector
void printVector(vector<int> v) {
	cout << "[";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i+1 < v.size()) {
			cout << ",";
		}
	}
	cout << "]" << endl;
}

int main() {
	// Example 1
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	root->right = node2;
	root->left = nullptr;
	node2->left = node3;
	vector<int> result = postorderTraversal(root);
	printVector(result);

	// Example 2
	TreeNode* root2 = new TreeNode();
	vector<int> result2 = postorderTraversal(root2);
	printVector(result2);

	// Example 3
	TreeNode* root3 = new TreeNode(1);
	vector<int> result3 = postorderTraversal(root3);
	printVector(result3);

	// Example 4
	TreeNode* root4 = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	root4->left = left;
	vector<int> result4 = postorderTraversal(root4);
	printVector(result4);
}