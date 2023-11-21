#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

class CircularLinkedList
{
private:
  Node *head;

public:
  CircularLinkedList()
  {
    head = nullptr;
  }

  void create(int value)
  {
    head = new Node(value);
    head->next = head;
  }

  void insert(int x, int y)
  {
    if (!head)
    {
      create(x);
    }
    else
    {
      Node *nn = new Node(x);
      Node *cn = head;
      for (int i = 1; i < y; i++)
      {
        cn = cn->next;
      }
      nn->next = cn->next;
      cn->next = nn;
    }
  }

  void display()
  {
    Node *cn = head->next;
    cout << "List: ";
    do
    {
      cout << cn->data << " -> ";
      cn = cn->next;
    } while (cn != head->next);
    cout << cn->data << endl;
  }

  bool search(int value)
  {
    if (!head)
    {
      return false;
    }
    Node *cn = head->next;
    do
    {
      if (cn->data == value)
      {
        return true;
      }
      cn = cn->next;
    } while (cn != head->next);
    return false;
  }

  void remove(int value)
  {
    Node *cn = head;
    Node *prev = nullptr;
    do
    {
      if (cn->data == value)
      {
        if (cn == head)
        {
          head = head->next;
        }
        prev->next = cn->next;
        delete cn;
        cout << "Deleted " << value << " from the list." << endl;
        return;
      }
      prev = cn;
      cn = cn->next;
    } while (cn != head);
    cout << value << " not found in the list." << endl;
  }
};

int main()
{
  CircularLinkedList cll;
  bool exit = true;
  while (exit)
  {
    int choice;
    cout << "1.Create list" << endl;
    cout << "2.Insert list" << endl;
    cout << "3.Display list" << endl;
    cout << "4.Delete node" << endl;
    cout << "5.Search node" << endl;
    cout << "6.Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl
         << endl;

    switch (choice)
    {
    case 1:
    {
      int x;
      cout << "Enter data: ";
      cin >> x;
      cll.create(x);
      cout << endl
           << endl;
      break;
    }
    case 2:
    {
      int val, pos;
      cout << "Enter data: ";
      cin >> val;
      cout << "Enter position: ";
      cin >> pos;
      cll.insert(val, pos);
      cout << endl
           << endl;
      break;
    }
    case 3:
      cll.display();
      cout << endl
           << endl;
      break;
    case 4:
    {
      int a;
      cout << "Enter value: ";
      cin >> a;
      cll.remove(a);
      cout << endl
           << endl;
      break;
    }
    case 5:
    {
      int s;
      cout << "Enter search value: ";
      cin >> s;
      if (cll.search(s))
      {
        cout << s << " found in the list." << endl;
      }
      else
      {
        cout << s << " not found in the list." << endl;
      }
      cout << endl
           << endl;
      break;
    }
    case 6:
      exit = false;
      cout << "Exiting!!!!!!" << endl;
      break;
    default:
      cout << "Enter correct choice!!!!" << endl;
      cout << endl
           << endl;
      break;
    }
  }

  return 0;
}
