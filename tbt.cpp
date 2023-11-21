// #include <iostream>
// using namespace std;

// class node
// {
// public:
//   int data;
//   node *left;
//   node *right;
//   bool leftthread;
//   bool rightthread;

//   node(int x)
//   {
//     data = x;
//     left = right = NULL;
//   }
// };

// class TBT
// {
// public:
//   node *dummy;
//   node *root;

//   TBT()
//   {
//     root = NULL; // Initialize root to NULL
//     dummy = new node(999);
//     dummy->left = dummy->right = NULL;             // Initialize left and right to NULL
//     dummy->leftthread = dummy->rightthread = true; // Set threads to true for simplicity
//   }

//   // void insert(int x)
//   // {
//   //   node *nn = new node(x);
//   //   node *cn = root;
//   //   if (root == NULL)
//   //   {
//   //     root = nn;
//   //     nn->left = nn->right = dummy;
//   //     nn->leftthread = nn->rightthread = true;
//   //   }

//   //   while (true)
//   //   {
//   //     if (nn->data < cn->data)
//   //     {
//   //       if (cn->leftthread == true)
//   //       {
//   //         nn->left = cn->left;
//   //         cn->left = nn;
//   //         cn->leftthread = false;
//   //         nn->right = cn;
//   //         break;
//   //       }
//   //       else
//   //       {
//   //         cn = cn->left;
//   //       }
//   //     }
//   //     else if (nn->data > cn->data)
//   //     {
//   //       if (cn->rightthread == true)
//   //       {
//   //         nn->right = cn->right;
//   //         cn->right = nn;
//   //         cn->rightthread = false;
//   //         nn->left = cn;
//   //         break;
//   //       }
//   //       else
//   //       {
//   //         cn = cn->right;
//   //       }
//   //     }
//   //   }
//   // }
//   void insert(int x)
//   {
//     node *nn = new node(x);
//     node *cn = root;

//     // If the tree is empty
//     if (root == NULL)
//     {
//       root = nn;
//       nn->left = nn->right = dummy;
//       nn->leftthread = nn->rightthread = true;
//       return;
//     }

//     while (true)
//     {
//       if (nn->data < cn->data)
//       {
//         if (cn->leftthread == true || cn->left == dummy)
//         {
//           nn->left = cn->left;
//           cn->left = nn;
//           cn->leftthread = false;
//           nn->right = cn;
//           break;
//         }
//         else
//         {
//           cn = cn->left;
//         }
//       }
//       else if (nn->data > cn->data)
//       {
//         if (cn->rightthread == true || cn->right == dummy)
//         {
//           nn->right = cn->right;
//           cn->right = nn;
//           cn->rightthread = false;
//           nn->left = cn;
//           break;
//         }
//         else
//         {
//           cn = cn->right;
//         }
//       }
//     }
//   }

//   void inorder()
//   {
//     node *cn = root;
//     while (cn != dummy)
//     {
//       while (cn->leftthread == false)
//       {
//         cn = cn->left;
//       }
//       cout << cn->data << " ";
//       while (cn->rightthread == true)
//       {
//         cn = cn->right;
//         if (cn == dummy)
//         {
//           return;
//         }
//         cout << cn->data << " ";
//       }
//       cn = cn->right;
//     }
//   }

//   void preorder()
//   {
//     node *cn = root;
//     while (cn != dummy)
//     {
//       while (cn->leftthread == false)
//       {
//         cout << cn->data << " ";
//         cn = cn->left;
//       }
//       cout << cn->data << " ";
//       while (cn->rightthread == true)
//       {
//         cn = cn->right;
//         if (cn == dummy)
//         {
//           return;
//         }
//       }
//       cn = cn->right;
//     }
//   }

//   void postorder()
//   {
//     node *cn = root;
//     int post[20];
//     int i = 0;
//     // rightmost element
//     while (cn->rightthread == false)
//     {
//       cn = cn->right;
//     }

//     while (cn != dummy)
//     {
//       post[i] = cn->data;
//       i++;
//       if (cn->leftthread == true)
//       {
//         cn = cn->left;
//       }
//       else
//       {
//         cn = cn->left;
//         while (cn->rightthread == false)
//         {
//           cn = cn->right;
//         }
//       }
//     }

//     for (int j = i - 1; j >= 0; j--)
//     {
//       cout << post[j] << " ";
//     }
//     cout << endl;
//   }
// };

// int main()
// {
//   TBT tree;
//   tree.insert(5);
//   tree.insert(2);
//   tree.insert(9);
//   tree.insert(1);
//   tree.inorder();
//   return 0;
// }
#include <iostream>
#include <conio.h>
using namespace std;
class Node
{
public:
  Node *left, *right;
  int left_thread, right_thread, data;

public:
  Node(int x)
  {
    left = NULL;
    right = NULL;
    left_thread = 1;
    right_thread = 1;
    data = x;
  }
};
class BST_threaded
{
private:
  Node *root;
  Node *dummy;

public:
  BST_threaded()
  {
    root = NULL;

    dummy = new Node(999);
  }

  void insert(int x)
  {
    Node *nn = new Node(x);
    if (root == NULL)
    {
      root = nn;
      dummy->left = root;
      dummy->right = root;
      nn->left = dummy;
      nn->right = dummy;
    }
    else
    {
      Node *cn = root;
      while (true)
      {
        if (nn->data < cn->data)
        {
          if (cn->left_thread == true)
          {
            nn->left = cn->left;
            nn->right = cn;
            cn->left = nn;
            cn->left_thread = false;
            break;
          }
          else
          {
            cn = cn->left;
          }
        }
        else
        {
          if (cn->right_thread == true)
          {
            nn->right = cn->right;
            nn->left = cn;
            cn->right = nn;
            cn->right_thread = false;
            break;
          }
          else
          {
            cn = cn->right;
          }
        }
      }
    }
  }

  void in_order()
  {
    Node *cn = root;
    while (cn != dummy)
    {
      while (cn->left_thread == 0)
      {

        cn = cn->left;
      }
      cout << cn->data << " ";
      while (cn->right_thread == 1)
      {
        if (cn->right == dummy)
        {
          return;
        }
        cn = cn->right;
        cout << cn->data << " ";
      }
      cn = cn->right;
    }
  }

  void pre_order()
  {
    Node *cn = root;
    while (cn != dummy)
    {
      while (cn->left_thread == 0)
      {
        cout << cn->data << " ";
        cn = cn->left;
      }
      cout << cn->data << " ";
      while (cn->right_thread == 1)
      {
        if (cn->right == dummy)

        {
          return;
        }
        cn = cn->right;
      }
      cn = cn->right;
    }
  }

  void postorder()
  {
    Node *cn = root;
    int post[20];
    int i = 0;
    // rightmost element
    while (cn->right_thread == false)
    {
      cn = cn->right;
    }

    while (cn != dummy)
    {
      post[i] = cn->data;
      i++;
      if (cn->left_thread == true)
      {
        cn = cn->left;
      }
      else
      {
        cn = cn->left;
        while (cn->right_thread == false)
        {
          cn = cn->right;
        }
      }
    }

    for (int j = i - 1; j >= 0; j--)
    {
      cout << post[j] << " ";
    }
    cout << endl;
  }
};
int main()
{
  BST_threaded bst;
  int choice, num, count;
  while (1)
  {
    cout << "\nMenu:\n";
    cout << "1. Create Tree\n";
    cout << "2. Insert\n";
    cout << "3. In-order Traversal\n";
    cout << "4. Pre-order Traversal\n";
    cout << "5. Post-order Traversal\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter the number of data points to insert: ";
      cin >> count;
      cout << "Enter " << count << " data points:\n";
      for (int i = 0; i < count; ++i)
      {

        cin >> num;
        bst.insert(num);
      }
      cout << "Tree created successfully.\n";
      break;
    case 2:
      cout << "Enter a number to insert: ";
      cin >> num;
      bst.insert(num);
      break;
    case 3:
      cout << "In-order Traversal: ";
      bst.in_order();
      cout << endl;
      break;
    case 4:
      cout << "Pre-order Traversal: ";
      bst.pre_order();
      cout << endl;
      break;
    case 5:
      cout << "Postorder Traversal: ";
      bst.postorder();
      cout << endl;
      break;
    case 6:
      cout << "Exiting program.\n";
      return 0;
    default:

      cout << "Invalid choice. Please try again.\n";
    }
    getch();
  }
  return 0;
}
