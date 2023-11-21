#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList()
  {
    head = nullptr;
  }

  void insert(int value)
  {
    Node *newNode = new Node(value);
    if (!head)
    {
      head = newNode;
    }
    else
    {
      Node *current = head;
      while (current->next)
      {
        current = current->next;
      }
      current->next = newNode;
    }
  }

  void remove(int value)
  {
    if (!head)
    {
      return;
    }

    if (head->data == value)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *current = head;
    while (current->next)
    {
      if (current->next->data == value)
      {
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        return;
      }
      current = current->next;
    }
  }

  void display()
  {
    Node *current = head;
    while (current)
    {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "nullptr" << endl;
  }

  bool search(int value)
  {
    Node *current = head;
    while (current)
    {
      if (current->data == value)
      {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  void reverse()
  {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
  }
};

int main()
{
  LinkedList myList;
  myList.insert(1);
  myList.insert(2);
  myList.insert(3);
  myList.insert(4);

  cout << "Original Linked List: ";
  myList.display();

  myList.remove(3);
  cout << "After deleting 3: ";
  myList.display();

  cout << "Is 2 in the list? " << (myList.search(2) ? "Yes" : "No") << endl;

  myList.reverse();
  cout << "Reversed Linked List: ";
  myList.display();

  return 0;
}
