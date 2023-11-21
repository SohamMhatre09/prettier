#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int value)
  {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void insertEnd(int value)
  {
    Node *newNode = new Node(value);
    if (tail == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  void deleteElement(int value)
  {
    Node *current = head;
    while (current != nullptr)
    {
      if (current->data == value)
      {
        if (current == head && current == tail)
        {
          head = nullptr;
          tail = nullptr;
        }
        else if (current == head)
        {
          head = current->next;
          head->prev = nullptr;
        }
        else if (current == tail)
        {
          tail = current->prev;
          tail->next = nullptr;
        }
        else
        {
          current->prev->next = current->next;
          current->next->prev = current->prev;
        }
        delete current;
        return;
      }
      current = current->next;
    }
    cout << "Element not found in the list." << endl;
  }

  bool search(int value)
  {
    Node *current = head;
    while (current != nullptr)
    {
      if (current->data == value)
      {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  void display()
  {
    Node *current = head;
    while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main()
{
  DoublyLinkedList myList;
  myList.insertEnd(1);
  myList.insertEnd(2);
  myList.insertEnd(3);
  myList.insertEnd(4);

  cout << "Initial list: ";
  myList.display();

  int searchValue = 3;
  if (myList.search(searchValue))
  {
    cout << searchValue << " is in the list." << endl;
  }
  else
  {
    cout << searchValue << " is not in the list." << endl;
  }

  int deleteValue = 2;
  myList.deleteElement(deleteValue);
  cout << "List after deleting " << deleteValue << ": ";
  myList.display();

  return 0;
}
