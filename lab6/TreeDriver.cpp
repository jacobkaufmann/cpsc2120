// Jacob Kaufmann
// TreeDriver.cpp

// Wasn't sure what all to adapt the driver for
// I added some general cases

#include <iostream>
#include "TreeNode.h"
using namespace std;

int main()
{
     // Create tree by hand here.
     TreeNode * t1 = new TreeNode("A");
     TreeNode * t2 = new TreeNode("B");
     TreeNode * t3 = new TreeNode("C");
     TreeNode * t4 = new TreeNode("D");
     TreeNode * t5 = new TreeNode("E");
     TreeNode * t6 = new TreeNode("F");
     TreeNode * t7 = new TreeNode("G");
     cout << *t1 << " " << *t2 << " " << *t3 << " " << *t4 << " " << *t5 << " " << *t6 << " " << *t7 << endl;

     t1->setLeft(t2);
     t1->setRight(t3);
     t2->setLeft(t4);
     t2->setRight(t5);
     t3->setLeft(t6);
     t3->setRight(t7);

     cout << "Postorder should be DEBFGCA" << endl;
     t1->postorder( );
     cout << endl;
     cout << "Preorder should be ABDECFG" << endl;
     t1->preorder( );
     cout << endl;

     // One child of root on the left
     TreeNode * l1 = new TreeNode("A");
     TreeNode * l2 = new TreeNode("B");
     l1->setLeft(l2);

     cout << endl << "Testing for one child of the root on the left" << endl;
     cout << "Postorder should be BA" << endl;
     l1->postorder();
     cout << endl;
     cout << "Preorder should be AB" << endl;
     l1->preorder();
     cout << endl;

     // One child of root on the right
     TreeNode * r1 = new TreeNode("A");
     TreeNode * r2 = new TreeNode("B");
     r1->setRight(r2);

     cout << endl << "Testing for one child of the root on the right" << endl;
     cout << "Postorder should be BA" << endl;
     r1->postorder();
     cout << endl;
     cout << "Preorder should be AB" << endl;
     r1->preorder();
     cout << endl;

     // Single node
     TreeNode * c1 = new TreeNode("A");

     cout << endl << "Testing for a single node" << endl;
     cout << "Postorder should be A" << endl;
     c1->postorder();
     cout << endl;
     cout << "Preorder should be A" << endl;
     c1->preorder();
     cout << endl;

     delete t1;
     delete t2;
     delete t3;
     delete t4;
     delete t5;
     delete t6;
     delete t7;

     delete l1;
     delete l2;

     delete r1;
     delete r2;

     delete c1;
     return 0;
}

