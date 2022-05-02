
#include <iostream>
using namespace std;
// Initial global variables for counting
int InBct = 0;
int FdBct = 0;
int InAct = 0;
int BalCost = 0;
int CTR = 0;
int SavlCt = 0;
int Found = 0;

// Binary search tree, adapted from code available in class.
// Counters are incremented with each recursive call.
class BSTree 
{
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
  // Inserts a node starting at the root. First item inserted is root.
  void insertNode(Node *&ptr, int x) {
    ++InBct;
    if (ptr == nullptr)
      ptr = new Node(x);
    else if (x <= ptr->data)
      insertNode(ptr->left, x);
    else
      insertNode(ptr->right, x);
  }
  // Calculates the height of tree. Is private must be called with function from
  // public.
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
  // Find an element in tree. Must be called in public
  void Find(Node *&ptr, int x) {

    if (ptr == NULL) {
      // cout << "Not found" << endl;

    } else if (x == ptr->data) {
      // cout << "found" << endl;

    } else if (x <= ptr->data) {
      FdBct += 1;
      Find(ptr->left, x);
    } else {
      FdBct += 1;
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

  // Calls function in private

  void Find(int x) { Find(root, x); }

  void inOrderPrint() {
    IOprint(root);
    cout << endl;
  }
  // Calls function in private

  void insert(int x) { insertNode(root, x); }
  // Calls function in private and returns height.
  int CalcH() {

    int height = CalcHeight(root);
    return height;
  }
};







// AVL tree code was adapted from code made available in class.

class AvlTree {
private:
  struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    int AvlValue;
  };

  TreeNode *root;
  // InsertNode private, needs a call in public. Counter InAct global. Counters
  // in Avl are incremented with each recursive call.
  void InsertNode(TreeNode *&ptr, int x) {
    ++InAct;
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
    ++BalCost; // Cost of balancing the tree
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
    ++BalCost; // Cost of balancing the tree
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

  AvlTree() { root = nullptr; }

  void Insert(int x) {
    InsertNode(root, x);
    ComputeAvlValues(root);
  }
  void ShowInorder() { inorder(root); };

  // SearchNode finds a number in the tree. Counter is incremented inside the
  // while loop.
  bool SearchNode(int num) 
  {
    TreeNode *nodePtr = root;

    while (nodePtr) {
      ++SavlCt;
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

// This function zeros out the necessary variable during each loop.
void ZeroCt() {
  InBct = 0;
  InAct = 0;
  BalCost = 0;
  SavlCt = 0;
  FdBct = 0;
}

int main() {
  BSTree b, b1, b2;
  AvlTree a, a1, a2;
  int num, x;
  int N = 10; // N is the number of trials performed.

  // Cumlative counters for average calculations.
  int CumBH1 = 0, CumBH2 = 0, CumBH3 = 0, CumAH1 = 0, CumAH2 = 0, CumAH3 = 0;
  int CumInB = 0, CumInA = 0, CumBal = 0;

  for (int i = 0; i < N; i++) {

    b1.insert(2500);
    b2.insert(5000);
    a1.Insert(2500);
    a2.Insert(5000);
    for (int i = 0; i < 1000; i++) {
      num = rand() % 10000;
      // cout << num << " " << endl;
      b.insert(num);
      b1.insert(num);
      b2.insert(num);
      a.Insert(num);
      a1.Insert(num);
      a2.Insert(num);
    }

    // Lines commented out show values at each iteration.

    // b.inOrderPrint();
    // cout << "Height of BST is " << b.CalcH() << endl;
    CumBH1 += b.CalcH();
    // cout << "Height of BST(2500) is " << b1.CalcH() << endl;
    CumBH2 += b1.CalcH();
    // cout << "Height of BST(5000) is " << b2.CalcH() << endl;
    CumBH3 += b2.CalcH();
    // cout << "Insert count for 3 Bst inserts is " << InBct << endl;
    CumInB += InBct;
    // cout << "Height of AVL is " << a.TreeHeight() << endl;
    CumAH1 += a.TreeHeight();
    // cout << "Height of AVL (2500) is " << a1.TreeHeight() << endl;
    CumAH2 += a1.TreeHeight();
    // cout << "Height of AVL (5000) is " << a2.TreeHeight() << endl;
    CumAH3 += a2.TreeHeight();
    // cout << "Insert count for 3 avl inserts is " << InAct << endl;
    CumInA += InAct;
    // cout << "Cost of Balance for 3 avl trees is " << BalCost << endl;
    CumBal += BalCost;
    // cout << endl;

    ZeroCt();

  } // End of For loop trials

  // This section calculate the averages after the loop is completed.

  cout << "Average Height BST is " << float(CumBH1) / N << endl;
  cout << "Average Height BST(25) is " << float(CumBH2) / N << endl;
  cout << "Average Height BST(50) is " << float(CumBH3) / N << endl;
  cout << "Average Insert cost is " << float(CumInB) / (3 * N) << endl;
  cout << "Average Height Avl is " << float(CumAH1) / N << endl;
  cout << "Average Height Avl(25) is " << float(CumAH2) / N << endl;
  cout << "Average Height Avl(50) is " << float(CumAH3) / N << endl;
  cout << "Average Insert cost is " << float(CumInA) / (3 * N) << endl;
  cout << "Average Balance cost is " << float(CumBal) / (3 * N) << endl;

  int CumBF = 0; //Initialize counter
  int CumAF = 0; //Initialize counter

  // This section take the last trees that were built and calculates the average search time on 100 random searches. 

  for (int i = 0; i < 100; i++) 
  {
    int target;
    target = rand() % 10000;
    b.Find(target);
    // cout << "find ct " << FdBct << endl;
    CumBF += FdBct;


    a.SearchNode(target);
    // cout << "find avl ct " << SavlCt << endl;
    CumAF += SavlCt;
    if (a.SearchNode(target)) {
      ++Found;
    }

    ZeroCt();
  }
  cout << "Number of matches in 100 searches " << Found << endl;
  cout << "Average count to find an elt (BST) is " << double(CumBF) / 100.0
       << endl;
  cout << "Average count to find an elt (Avl) is " << double(CumAF) / 100.0
       << endl;
}