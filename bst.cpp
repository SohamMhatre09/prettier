#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;

  node(int x)
  {
    this->data = x;
    this->left = this->right = NULL;
  }
};

class BST
{
public:
  node *root;

  BST()
  {
    root = NULL;
  }

  void insert(int x)
  {
    node *nn = new node(x);
    if (root == NULL)
    {
      root = nn;
      return;
    }

    node *cn = root;
    node *parent = NULL;
    while (cn != NULL)
    {
      parent = cn;
      if (x < cn->data)
      {
        cn = cn->left;
      }
      else
      {
        cn = cn->right;
      }
    }

    if (x < parent->data)
    {
      parent->left = nn;
    }
    else
    {
      parent->right = nn;
    }
  }

  void search(int x)
  {
    node *cn = root;
    while (cn != NULL)
    {
      if (x == cn->data)
      {
        cout << "Found" << endl;
        return;
      }
      else if (x < cn->data)
      {
        cn = cn->left;
      }
      else
      {
        cn = cn->right;
      }
    }
    cout << "Not found" << endl;
  }

  void deletenode(int x)
  {
    node *cn = root;
    node *parent = NULL;

    if (root == NULL)
    {
      cout << "Already empty" << endl;
      return;
    }

    while (cn != NULL)
    {
      if (cn->data == x)
      {
        break;
      }
      else if (cn->data > x)
      {
        parent = cn;
        cn = cn->left;
      }
      else
      {
        parent = cn;
        cn = cn->right;
      }
    }

    if (cn == NULL)
    {
      cout << "Not found" << endl;
      return;
    }

    if (cn->left == NULL && cn->right == NULL)
    {
      if (cn == root)
      {
        root = NULL;
        delete cn;
        return;
      }

      if (x < parent->data)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }

      delete cn;
      return;
    }

    if (cn->left == NULL && cn->right != NULL)
    {
      if (cn->right->data > parent->data)
      {
        parent->right = cn->right;
      }
      else
      {
        parent->left = cn->right;
      }

      delete cn;
      return;
    }
    else if (cn->left != NULL && cn->right == NULL)
    {
      if (cn->left->data < parent->data)
      {
        parent->left = cn->left;
      }
      else
      {
        parent->right = cn->left;
      }

      delete cn;
      return;
    }

    if (cn->left != NULL && cn->right != NULL)
    {
      node *temp = cn->left;

      while (temp->right != NULL)
      {
        temp = temp->right;
      }
      int t = temp->data;
      deletenode(t);
      cn->data = t;
      return;
    }
  }

  void inorder(node *temp)
  {
    if (temp != NULL)
    {
      inorder(temp->left);
      cout << temp->data << ",";

      inorder(temp->right);
    }
  }
};

int main()
{
  BST tree;
  tree.insert(20);
  tree.insert(10);
  tree.insert(40);
  tree.insert(30);
  tree.insert(60);
  tree.insert(32);
  tree.insert(34);
  tree.inorder(tree.root);
  cout << endl;
  tree.deletenode(40);
  tree.inorder(tree.root);
  return 0;
}