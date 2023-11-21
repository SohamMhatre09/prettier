#include <iostream>
using namespace std;

class dequeue
{
public:
  int front, rear;
  int max = 10;
  int arr[10];

  dequeue()
  {
    front = rear = -1;
  }

  bool is_empty()
  {
    if (front == -1 && rear == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool is_full()
  {
    if (front == 0 && rear == max - 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void enqueue_at_front(int x)
  {
    if (is_empty())
    {
      front++;
      rear++;
      arr[front] = x;
      return;
    }
    else if (is_full())
    {
      cout << "Queue is full" << endl;
      return;
    }
    else if (front != 0)
    {
      front--;
      arr[front] = x;
    }
    else if (front == 0 && rear != max - 1)
    {
      for (int i = rear; i >= front; i--)
      {
        arr[i + 1] = arr[i];
      }
      arr[front] = x;
      rear++;
    }
  }

  void enqueue_at_rear(int x)
  {
    if (is_empty())
    {
      front++;
      rear++;
      arr[front] = x;
      return;
    }
    else if (is_full())
    {
      cout << "Queue is full" << endl;
      return;
    }
    else if (rear != max - 1)
    {
      rear++;
      arr[rear] = x;
    }
    else if (front != 0 && rear == max - 1)
    {
      for (int i = front; i <= rear; i++)
      {
        arr[i - 1] = arr[i];
      }
      arr[rear] = x;
    }
  }

  void deque_at_front()
  {
    if (is_empty())
    {
      cout << "Already empty" << endl;
      return;
    }
    else
    {
      front++;
    }
  }

  void deque_at_rear()
  {
    if (is_empty())
    {
      cout << "Already empty" << endl;
      return;
    }
    else
    {
      rear--;
    }
  }

  int peek()
  {
    return arr[rear];
  }

  void display()
  {
    for (int i = front; i <= rear; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  dequeue d1;

  d1.enqueue_at_front(3);
  d1.enqueue_at_front(2);
  d1.enqueue_at_front(1);

  d1.display();

  d1.enqueue_at_rear(4);
  d1.enqueue_at_rear(5);
  d1.enqueue_at_rear(6);

  d1.display();

  d1.deque_at_front();
  d1.deque_at_rear();
  cout << d1.is_empty() << endl;
  cout << d1.is_full() << endl;
}