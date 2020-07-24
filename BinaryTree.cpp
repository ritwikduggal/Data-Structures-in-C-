#include<iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree
{
  public:
    class TreeNode
    {
      public:
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(const T & dataArgument) : data(dataArgument), left(nullptr), right(nullptr) { }
    };
   BinaryTree() : root_(nullptr) { }

   void shout(TreeNode* nod)
   {
      if (nod)
      {
        cout << nod->data;
      }
      cout << " ";
   }

   TreeNode* getRootPtr()
   {
     return root_;
   }

   void createCompleteTree(const std::vector<T>& contents)
   {
     if (contents.empty()) return;
     root_ = new TreeNode(contents[0]);
     queue<TreeNode**> childPtrPtrQueue;
     childPtrPtrQueue.push(&(root_->left));
     childPtrPtrQueue.push(&(root_->right));
     for (unsigned int i = 1; i < contents.size(); i++)
     {
       TreeNode** childPtrPtr = childPtrPtrQueue.front();
       childPtrPtrQueue.pop();
       TreeNode*& actualChildPtr = *childPtrPtr;
       actualChildPtr = new TreeNode(contents[i]);
       childPtrPtrQueue.push(&(actualChildPtr->left));
       childPtrPtrQueue.push(&(actualChildPtr->right));
     }
   }

   BinaryTree(const std::vector<T>& contents) : BinaryTree()
   {
     createCompleteTree(contents);
   }

   void inOrder(TreeNode* nod)
   {
     if (nod)
     {
       inOrder(nod->left);
       shout(nod);
       inOrder(nod->right);
     }
   }
   private:

   TreeNode *root_;

};

int main()
{
  BinaryTree<int> tree({1,2,3,4,5,6,7});
  auto rootPtr = tree.getRootPtr();
  cout<<"In-order traversal with the complete tree"<<endl;
  tree.inOrder(rootPtr);
  cout<<endl<<endl;
}
