#include <iostream>
using namespace std;

int BCTR = 0;
int BFCT = 0;
int ACTR = 0;
int BalCost = 0;
int CTR = 0;

class BSTree {
private:
  struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
      data = x;
      left = right = nullptr;
    }
  };

  Node *root;

  void insertNode(Node *&ptr, int x) {
    ++BCTR;
    if (ptr == nullptr)
      ptr = new Node(x);
    else if (x <= ptr->data)
      insertNode(ptr->left, x);
    else
      insertNode(ptr->right, x);
  }

  int CalcHeight(Node *&ptr) {
    if (ptr) {
      int left = 1 + CalcHeight(ptr->left);
      int right = 1 + CalcHeight(ptr->right);
      if (left > right) {
        // ptr->height=left;
        return left;
      } else {
        // ptr->height=right;
        return right;
      }
    } else {
      return 0;
    }
  }

  void Find(Node *&ptr, int x) {

    if (ptr == NULL) {
      cout << "Not found" << endl;

    } else if (x == ptr->data) {
      cout << "found" << endl;

    } else if (x <= ptr->data) {
      BFCT += 1;
      Find(ptr->left, x);
    } else {
      BFCT += 1;
      Find(ptr->right, x);
    }
  }

public:
  BSTree() { root = nullptr; }

  void IOprint(Node *ptr) {

    if (ptr) {
      IOprint(ptr->left);
      cout << ptr->data << " ";
      IOprint(ptr->right);
    }
  }

  void Find(int x) { Find(root, x); }

  void inOrderPrint() {
    IOprint(root);
    cout << endl;
  }

  void insert(int x) { insertNode(root, x); }

  int CalcH() {

    int height = CalcHeight(root);
    return height;
  }
};

//struct avl_node {
//  int data;
//  struct avl_node *left;
//  struct avl_node *right;
//} * root;

// tina avl
class AvlTree {
private:
  struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    int AvlValue;
  };

  TreeNode *root;

  void InsertNode(TreeNode *&ptr, int x) {
    if (ptr == NULL) // ptr points to NULL insertion position
    {
      ptr = new TreeNode;
      ptr->value = x;
      ptr->left = NULL;
      ptr->right = NULL;
    } else if (x <= ptr->value) // node should be inserted in left subtree
      InsertNode(ptr->left, x);
    else // node should be inserted in right subtree
      InsertNode(ptr->right, x);
  }

  void inorder(TreeNode *nodePtr) {
    if (nodePtr) {
      inorder(nodePtr->left);
      cout << nodePtr->value << " "
           << "(" << nodePtr->AvlValue << ")\n";
      inorder(nodePtr->right);
    }
  }

  void RotateLeft(TreeNode *&SubRoot) {
    if (SubRoot->right != NULL && LeftHeavy(SubRoot->right)) {
      RotateRight(SubRoot->right);
    }

    TreeNode *Temp;
    Temp = SubRoot->right;
    SubRoot->right = Temp->left;
    Temp->left = SubRoot;
    SubRoot = Temp;

    ComputeAvlValues(SubRoot);
  }

  void RotateRight(TreeNode *&SubRoot) {
    if (SubRoot->left != NULL && RightHeavy(SubRoot->left)) {
      RotateLeft(SubRoot->left);
    }

    TreeNode *Temp;
    Temp = SubRoot->left;
    SubRoot->left = Temp->right;
    Temp->right = SubRoot;
    SubRoot = Temp;

    ComputeAvlValues(SubRoot);
  }

  int Height(TreeNode *nodePtr) {
    int left_height = 0;
    int right_height = 0;
    if (nodePtr == NULL)
      return 0;
    else {
      left_height = Height(nodePtr->left);
      right_height = Height(nodePtr->right);
    }
    if (left_height > right_height)
      return 1 + left_height;
    else
      return 1 + right_height;
  }

  void ComputeAvlValues(TreeNode *&nodePtr) {
    if (nodePtr) {
      ComputeAvlValues(nodePtr->left);
      ComputeAvlValues(nodePtr->right);
      nodePtr->AvlValue = AvlValue(nodePtr);
      if (nodePtr->AvlValue > 1)
        RotateRight(nodePtr);
      else if (nodePtr->AvlValue < -1)
        RotateLeft(nodePtr);
    }
  }

  bool LeftHeavy(TreeNode *ptr) {
    return (Height(ptr->left) > Height(ptr->right));
  }

  bool RightHeavy(TreeNode *ptr) {
    return (Height(ptr->right) > Height(ptr->left));
  }

public:
  int AvlValue(TreeNode *nodePtr) {
    int leftheight = Height(nodePtr->left);
    int rightheight = Height(nodePtr->right);
    return leftheight - rightheight;
  }

  AvlTree() {root = NULL;}

  void Insert(int x) {
   InsertNode(root, x);
   ComputeAvlValues(root);
  }
  void ShowInorder() { inorder(root); };

  bool SearchNode(int num) {
    TreeNode *nodePtr = root;

    while (nodePtr) {
      if (nodePtr->value == num)
        return true;
      else if (num < nodePtr->value)
        nodePtr = nodePtr->left;
      else
        nodePtr = nodePtr->right;
    }
    return false;
  }

  int TreeHeight() { return Height(root); }
};

/*
 * Class Declaration
 */
/*
class avlTree {
public:
  int height(avl_node *);
  int diff(avl_node *);
  avl_node *rr_rotation(avl_node *);
  avl_node *ll_rotation(avl_node *);
  avl_node *lr_rotation(avl_node *);
  avl_node *rl_rotation(avl_node *);
  avl_node *balance(avl_node *);
  avl_node *insert(avl_node *, int);
  avl_node *Search(avl_node *, int);
  void inorder(avl_node *);

  avlTree() { root = NULL; }
};

int avlTree::height(avl_node *temp) {
  int h = 0;
  if (temp != NULL) {
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int max_height = max(l_height, r_height);
    h = max_height + 1;
  }
  return h;
}

int avlTree::diff(avl_node *temp) {
  int l_height = height(temp->left);
  int r_height = height(temp->right);
  int b_factor = l_height - r_height;
  return b_factor;
}

avl_node *avlTree::rr_rotation(avl_node *parent) {
  ++BalCost;
  avl_node *temp;
  temp = parent->right;
  parent->right = temp->left;
  temp->left = parent;
  return temp;
}

avl_node *avlTree::ll_rotation(avl_node *parent) {
  ++BalCost;
  avl_node *temp;
  temp = parent->left;
  parent->left = temp->right;
  temp->right = parent;
  return temp;
}

/*
 /* Left - Right Rotation
 */
/*
avl_node *avlTree::lr_rotation(avl_node *parent) {
  ++BalCost;
  avl_node *temp;
  temp = parent->left;
  parent->left = rr_rotation(temp);
  return ll_rotation(parent);
}

avl_node *avlTree::rl_rotation(avl_node *parent) {
  ++BalCost;
  avl_node *temp;
  temp = parent->right;
  parent->right = ll_rotation(temp);
  return rr_rotation(parent);
}

avl_node *avlTree::balance(avl_node *temp) {
  int bal_factor = diff(temp);
  if (bal_factor > 1) {
    if (diff(temp->left) > 0)
      temp = ll_rotation(temp);
    else
      temp = lr_rotation(temp);
  } else if (bal_factor < -1) {
    if (diff(temp->right) > 0)
      temp = rl_rotation(temp);
    else
      temp = rr_rotation(temp);
  }
  return temp;
}

avl_node *avlTree::insert(avl_node *root, int value) {
  ++ACTR;
  if (root == NULL) {
    root = new avl_node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else if (value < root->data) {
    root->left = insert(root->left, value);
    root = balance(root);
  } else if (value >= root->data) {
    root->right = insert(root->right, value);
    root = balance(root);
  }
  return root;
}

void avlTree::inorder(avl_node *tree) {
  if (tree == NULL)
    return;
  inorder(tree->left);
  cout << tree->data << "  ";
  inorder(tree->right);
}

avl_node *avlTree::Search(avl_node *root, int target) {

  if (root == NULL) {
    cout << "Not found" << endl;
    return 0;
  } else if (target == root->data) {
    cout << "found" << endl;
    return 0;
  } else if (target <= root->data) {
    CTR += 1;
    return Search(root->left, target);
  } else {
    CTR += 1;
    return Search(root->right, target);
  }
}
*/

int main() {
  BSTree b, b1, b2;
  AvlTree a;
  int num, x;
  // root=avl.insert(root,250);
  b1.insert(250);
//   b2.insert(500);
 for (int i = 0; i < 100; i++) {
   num = rand() % 1000;
    cout << num << " " << endl;
    b.insert(num);
    b1.insert(num);
    b2.insert(num);
    a.Insert(num);
 //   root = avl.insert(root,num);
 }

  // b.inOrderPrint();
  cout << "Height of BST is " << b.CalcH() << endl;
  cout << "Height of BST(250) is " << b1.CalcH() << endl;
//   cout << "Height of BST(500) is " << b2.CalcH() << endl;
  cout << "Height of AVL is " << a.TreeHeight() << endl;  

  cout << "Insert count for Bst is " << BCTR << endl;
  // avl.inorder(root);
  cout << endl;
  // cout << "Height is of AVL is " << avl.height(root) << endl;
  // cout << "Insert count for Avl is " << ACTR << endl;
  // cout << "Balance cost for Avl is " << BalCost << endl;
  // avl.Search(root,35);
  // cout << CTR << endl;
  // b.Find(35);
//   cout << BFCT << endl;
  // r.inOrderPrint();
  // cout << "Height is " << r.treeHeight();
}