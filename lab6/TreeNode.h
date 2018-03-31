// Jacob Kaufmann
// TreeNode.h

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <stack>
using namespace std;

class TreeNode {

  private:
      const string value;    // contains node value
      TreeNode * lchild;   // reference to node's left child
      TreeNode * rchild;   // reference to node's right child

  public:
      TreeNode (string str);

      void setLeft( TreeNode* l);
      void setRight( TreeNode* r);

      void postorder ( ) const;
      void preorder( ) const;

      friend ostream & operator<< ( ostream & , const TreeNode & );
};

#endif
