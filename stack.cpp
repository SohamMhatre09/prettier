#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
  int data;
  Node *next;
};

// Stack class
class Stack
{
private:
  Node *top; // Points to the top of the stack

public:
  Stack()
  {
    top = nullptr;
  }

  // Push operation to insert an element onto the stack
  void push(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed onto the stack.\n";
  }

  // Pop operation to remove and return the top element from the stack
  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is empty.\n";
      return -1; // Assuming -1 is not a valid element in the stack
    }
    Node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    delete temp;
    cout << poppedValue << " popped from the stack.\n";
    return poppedValue;
  }

  // Function to check if the stack is empty
  bool isEmpty()
  {
    return top == nullptr;
  }
};

// Queue class
class Queue
{
private:
  Node *front; // Points to the front of the queue
  Node *rear;  // Points to the rear of the queue

public:
  Queue()
  {
    front = rear = nullptr;
  }

  // Enqueue operation to insert an element into the queue
  void enqueue(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty())
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
    cout << value << " enqueued into the queue.\n";
  }

  // Dequeue operation to remove and return the front element from the queue
  int dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty.\n";
      return -1; // Assuming -1 is not a valid element in the queue
    }
    Node *temp = front;
    int dequeuedValue = temp->data;
    front = front->next;
    if (front == nullptr)
    {
      rear = nullptr;
    }
    delete temp;
    cout << dequeuedValue << " dequeued from the queue.\n";
    return dequeuedValue;
  }

  // Function to check if the queue is empty
  bool isEmpty()
  {
    return front == nullptr;
  }
};

int main()
{
  Stack stack;
  Queue queue;

  // Testing the stack
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop(); // Trying to pop from an empty stack

  // Testing the queue
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue(); // Trying to dequeue from an empty queue

  return 0;
}

// #include <iostream>
// using namespace std;

// class stack
// {
// public:
//   int max = 10;
//   int s[10];
//   int top;

//   stack()
//   {
//     top = -1;
//   }

//   void push(int x)
//   {
//     if (isfull())
//     {
//       cout << "Stack Overflow!!!" << endl;
//     }
//     else
//     {
//       top++;
//       s[top] = x;
//     }
//   }

//   void pop()
//   {
//     if (isempty())
//     {
//       cout << "Stack Underflow!!!" << endl;
//     }
//     else
//     {
//       cout << s[top] << " is deleted." << endl;
//       top--;
//     }
//   }

//   bool isempty()
//   {
//     if (top == -1)
//     {
//       return true;
//     }
//     else
//     {
//       return false;
//     }
//   }

//   bool isfull()
//   {
//     if (top == max - 1)
//     {
//       return true;
//     }
//     else
//     {
//       return false;
//     }
//   }

//   int peek()
//   {
//     return s[top];
//   }

//   void display()
//   {
//     for (int i = top; i >= 0; i--)
//     {
//       cout << s[i] << endl;
//     }
//   }
// };

// int main()
// {
//   stack s1;

//   s1.push(1);
//   s1.push(2);
//   s1.push(3);
//   s1.push(4);
//   s1.push(5);

//   cout << s1.peek() << endl;

//   s1.display();

//   s1.pop();
//   s1.pop();

//   cout << s1.isfull() << endl;

//   s1.display();

//   s1.pop();
//   s1.pop();
//   s1.pop();

//   cout << s1.isempty() << endl;
// }

// #include<iostream>
// using namespace std;

// class queue{
//   public:
//     int front;
//     int rear;
//     int max = 5;
//     int q[5];

//     queue(){
//       front = rear = -1;
//     }

//     void enqueue(int x){
//       if(qisfull()){
//         cout<<"Can not insert!!!!\n";
//       }
//       else if(qisempty()){
//         front++;
//         rear++;
//         q[rear] = x;
//       }
//       else{
//         rear++;
//         q[rear] = x;
//       }
//     }

//     void dequeue(){
//       if(qisempty()){
//         cout<<"Can not delete!!!\n";
//       }
//       else if(front == rear){
//         cout<<q[rear]<<" is deleted!!!\n";
//         front--;
//         rear--;
//       }
//       else{
//         cout<<q[rear]<<" is deleted!!!\n";
//         front++;
//       }
//     }

//     bool qisfull(){
//       if(rear == max-1){
//         return true;
//       }
//       else{
//         return false;
//       }
//     }

//     bool qisempty(){
//       if(front == -1 && rear == -1){
//         return true;
//       }
//       else{
//         return false;
//       }
//     }

//     void display(){
//       for(int i=front ; i<=rear ; i++){
//         cout<<q[i]<<"->";
//       }
//       cout<<endl;
//       cout<<rear<<endl;
//     }

//     int peek(){
//       return q[rear];
//     }
// };

// int main(){
//   queue q1;

//   q1.enqueue(1);
//   q1.enqueue(2);
//   q1.enqueue(3);
//   q1.enqueue(4);
//   q1.enqueue(5);

//   q1.display();

//   cout<<q1.peek()<<endl;

//   cout<<q1.qisfull()<<endl;

//   q1.dequeue();
//   q1.dequeue();

//   q1.display();

//   q1.dequeue();
//   q1.dequeue();
//   q1.dequeue();

//   cout<<q1.qisempty();

//   return 0;
// }