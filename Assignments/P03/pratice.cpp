#include <iostream>
using namespace std;

int BCTR=0;
int BFCT=0;
int ACTR=0;
int BalCost=0;
int CTR=0;

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

  void Find(Node *&ptr, int x){

    if(ptr==NULL){
    cout << "Not found" << endl;
    
  }
  else if(x==ptr->data){
    cout << "found" << endl;
      
  }
  else if(x <= ptr->data){
    BFCT+=1;
    Find(ptr->left,x);
  }
  else{
    BFCT+=1;
    Find(ptr->right,x);
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

 void Find(int x){
  Find(root,x);
}

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


struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root, *root2;
 
/*
 * Class Declaration
 */
class avlTree
{
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, int );
        avl_node* Search(avl_node *, int);
        void inorder(avl_node *);
        
        avlTree()
        {
            root = NULL;
            root2 = NULL;
        }
};

int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int avlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

avl_node *avlTree::rr_rotation(avl_node *parent)
{
    ++BalCost;
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::ll_rotation(avl_node *parent)
{
    ++BalCost;  
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
/*
 * Left - Right Rotation
 */
avl_node *avlTree::lr_rotation(avl_node *parent)
{
     ++BalCost;  
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

avl_node *avlTree::rl_rotation(avl_node *parent)
{
     ++BalCost; 
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

avl_node *avlTree::insert(avl_node *root, int value)
{
    ++ACTR;
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

void avlTree::inorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}


avl_node *avlTree:: Search(avl_node * root, int target){
  
  if(root==NULL){
    cout << "Not found" << endl;
    return 0;
  }
  else if(target==root->data){
    cout << "found" << endl;
    return 0;  
  }
  else if(target <= root->data){
    CTR+=1;
    return Search(root->left,target);
  }
  else{
    CTR+=1;
    return Search(root->right,target);
  }
}


int main() 
{
  BSTree b;
  avlTree avl, avl2;
  int num, num2, x;
  // root=avl.insert(root,250);
  // b.insert(250);
  for (int i = 0; i < 10; i++) {
    num = rand() % 100;
    num2 = rand() % 1000;
    cout << num << " " << endl;
    b.insert(num);
    root = avl.insert(root,num);
    root2 = avl2.insert(root2, num2);
  }

 // b.inOrderPrint();
  cout << "Height of BST is " << b.CalcH() << endl;
  cout << "Insert count for Bst is " << BCTR << endl;

  cout << "avl: \n";
  avl.inorder(root);
  cout << "\n\n";
  cout << "avl2: \n";
  avl2.inorder(root);

  cout << endl;
  cout << "Height is of AVL is " << avl.height(root) << endl;
  cout << "Insert count for Avl is " << ACTR << endl;
  cout << "Balance cost for Avl is " << BalCost << endl;
  avl.Search(root,35);
  cout << CTR << endl;
  b.Find(35);
  cout << BFCT << endl;
  //r.inOrderPrint();
  //cout << "Height is " << r.treeHeight();
}