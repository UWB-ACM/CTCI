#include <iostream>
#include <queue>
using namespace std;

class BTree;
struct TreeNode;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

static int deepestLeavesSum(TreeNode* root) {

  queue<TreeNode*> queue;
  queue.push(root);                         // we insert the root into the queue
  int currSum = 0;        //will store the sum of the nodes at the current level

  while(!queue.empty()){
    currSum = 0;                  // reset the sum at each new level of the tree
    int size = queue.size();     // locking the size of the queue before we add more nodes to it

    //for the size of the queue
    for(int i =0; i< size;i++){
      auto node = queue.front();
      // Pop one node of the queue
      queue.pop();

      currSum += node->val;
      //get left child into queue
      if(node->left !=nullptr){

        queue.push(node->left);
      }
      //get right child into queue
      if(node->right !=nullptr){
        queue.push(node->right);
      }
    }
  }
  return currSum;
}

int main() {
  /**
   * Please note: This code does not check for memory leaks
   */

  /**
   *             1
               /   \
             2      3
            / \     \
          4   5      6
         /            \
        7              8
   */
  TreeNode *test1= new TreeNode(1);
  TreeNode *test2= new TreeNode(2);
  TreeNode *test3= new TreeNode(3);
  TreeNode *test4= new TreeNode(4);
  TreeNode *test5= new TreeNode(5);
  TreeNode *test6= new TreeNode(6);
  TreeNode *test7= new TreeNode(7);
  TreeNode *test8= new TreeNode(8);

  test1->left = test2;
  test1->right = test3;
  test2->left = test4;
  test2->right= test5;
  test4->left = test7;
  test3->right = test6;
  test6->right = test8;

  int result = deepestLeavesSum(test1);
  cout << "Result is: " <<result<<endl;

  return 0;
}