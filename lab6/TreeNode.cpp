// Jacob Kaufmann
// TreeNode.cpp

#include "TreeNode.h"

TreeNode::TreeNode(string str) : value(str)
{
    lchild = nullptr;
    rchild = nullptr;
}

void TreeNode::setLeft(TreeNode* l)
{
    lchild = l;
}

void TreeNode::setRight(TreeNode* r)
{
    rchild = r;
}

void TreeNode::postorder() const
{
    if(lchild != nullptr)
        lchild->postorder();
    if(rchild != nullptr)
	rchild->postorder();
    cout << value;
}

void TreeNode::preorder() const
{
    stack<const TreeNode*> tree;
    const TreeNode* cursor = this;
    tree.push(cursor);
    while(!tree.empty())
    {
	const TreeNode *hold = tree.top();
	tree.pop();
	cout << *hold;
	if(hold->rchild)
	    tree.push(hold->rchild);
	if(hold->lchild)
	    tree.push(hold->lchild);
    }
}

ostream & operator<< (ostream & out, const TreeNode & node)
{
    out << node.value;
    return out;
}
