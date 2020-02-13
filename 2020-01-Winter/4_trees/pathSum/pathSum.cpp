#include <iostream>
#include <queue>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//gone through the tree, no path
		if (root == NULL)
			return false;
		//subtract root from the sum at each visited node
		sum -= root->val;
		//if no children
		if (root->left == NULL && root->right == NULL)
		{
			//sum after subtracting is equal to 0
			//means there is a path from root to leaf 
			if (sum == 0)
				return true;
		}
		//recursive call passing left child or right child as root and new sum
		return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
	}
};

class Solution2 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//gone through the tree, no path
		if (root == NULL)
			return false;

		queue <TreeNode*> qlayer;
		qlayer.push(root);
		while (!qlayer.empty())
		{
			TreeNode *ptr = qlayer.front();
			//if no children
			if (ptr->left == NULL && ptr->right == NULL)
			{
				//value at the end is equal to sum
				//means there is a path from root to leaf 
				if (ptr->val == sum)
					return true;
			}
			else
			{
				//go layer by layer
				//the current value is added to the left child
				//add the node to the queue
				if (ptr->left != NULL)
				{
					ptr->left->val += ptr->val;
					qlayer.push(ptr->left);
				}
				//the current value is added to the right child
				if (ptr->right != NULL)
				{
					ptr->right->val += ptr->val;
					qlayer.push(ptr->right);
				}
			}
			qlayer.pop();
		}
		return false;
	}
};

int main() {
	Solution temp;
	Solution2 temp2;
	/* binary tree
	5
	/  \
	4	 8
	/  	/  \
	11   13  4
	/ \        \
	7  2		 1
	*/
	int sum = 22;

	TreeNode *root;
	root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);

	cout << "[5,4,8,11,null,13,4,7,2,null,null,null,1] sum=22 : " << (temp.hasPathSum(root, sum)) << endl; // output:true
	cout << "[5,4,8,11,null,13,4,7,2,null,null,null,1] sum=22 : " << (temp2.hasPathSum(root, sum)) << endl; // output:true

	/* binary tree
	 				 1
					/ \
				  -2	3
	*/
	sum = 1;
	TreeNode *root2;
	root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(3);
	cout << "[1,-2,3] sum=1 : " << (temp.hasPathSum(root, sum)) << endl; //output:false
	cout << "[1,-2,3] sum=1 : " << (temp2.hasPathSum(root, sum)) << endl; // output:false

	return 0;
}
