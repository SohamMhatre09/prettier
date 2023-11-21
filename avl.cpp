#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class AVL
{
private:
  Node *root;

public:
  AVL() : root(nullptr) {}
  Node *insert(Node *temp, int val)
  {
    if (temp == nullptr)
    {
      temp = new Node(val);
    }
    else if (val < temp->data)
    {
      temp->left = insert(temp->left, val);
    }
    else
    {
      temp->right = insert(temp->right, val);
    }
    int balance = height(temp->left) - height(temp->right);
    if (balance > 1)
    {
      if (val < temp->left->data)
      {
        temp = LL(temp);
      }
      else
      {
        temp = LR(temp);
      }
    }
    else if (balance < -1)
    {
      if (val > temp->right->data)
      {
        temp = RR(temp);
      }
      else
      {
        temp = RL(temp);
      }
    }
    return temp;
  }
  int height(Node *temp)
  {
    if (temp == nullptr)
    {
      return -1;
    }
    int leftHeight = height(temp->left);
    int rightHeight = height(temp->right);
    return 1 + max(leftHeight, rightHeight);
  }
  Node *RR(Node *parent)
  {
    Node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
  }
  Node *LL(Node *parent)
  {
    Node *temp = parent->left;
    parent->left = temp->right;

    temp->right = parent;
    return temp;
  }
  Node *LR(Node *parent)
  {
    parent->left = RR(parent->left);
    return LL(parent);
  }
  Node *RL(Node *parent)
  {
    parent->right = LL(parent->right);
    return RR(parent);
  }
  void insert(int val)
  {
    root = insert(root, val);
  }
  void inorder(Node *temp)
  {
    if (temp != nullptr)
    {
      inorder(temp->left);
      cout << temp->data << "\t";
      inorder(temp->right);
    }
  }
  void preorder(Node *temp)
  {
    if (temp != nullptr)
    {
      cout << temp->data << "\t";
      preorder(temp->left);
      preorder(temp->right);
    }
  }
  void postorder(Node *temp)
  {

    if (temp != nullptr)
    {
      postorder(temp->left);
      postorder(temp->right);
      cout << temp->data << "\t";
    }
  }
  void display()
  {
    cout << "Inorder Traversal:" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal:" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal:" << endl;
    postorder(root);
    cout << endl;
  }
  Node *return_root()
  {
    return root;
  }
  void update_root(Node *temp)
  {
    root = temp;
  }
};
int main()
{
  AVL avl;

  int choice, num, val;
  Node *temp;
  do
  {
    cout << "Menu:" << endl;
    cout << "1. Create AVL Tree" << endl;
    cout << "2. Insert Node" << endl;
    cout << "3. Display AVL Tree" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 2:
      cout << "Enter value to insert: ";
      cin >> val;
      temp = avl.insert(avl.return_root(), val);
      avl.update_root(temp);
      break;
    case 1:
      cout << "Enter the number of nodes you want to insert: ";
      cin >> num;
      for (int i = 0; i < num; ++i)
      {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        temp = avl.insert(avl.return_root(), val);
        avl.update_root(temp);
      }

      cout << "AVL Tree created." << endl;
      break;
    case 3:
      avl.display();
      break;
    case 4:
      cout << "Exiting the program." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  } while (choice != 4);
  return 0;
}
