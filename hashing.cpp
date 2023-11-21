#include <iostream>
using namespace std;

typedef struct hash_table
{
  int empid;
  string name;
  int key;
  int full;
} employee;

class hash1
{
  int n;
  // employee h[max1];
  employee *h;

public:
  hash1()
  {
    cout << "Enter the number of employees: ";
    cin >> n;

    h = new employee[n]();

    for (int i = 0; i < n; i++)
    {
      h[i].full = 0;
    }
  }

  void insert()
  {
    for (int i = 0; i < n; i++)
    {
      employee emp;
      cout << "Enter employee ID: ";
      cin >> emp.empid;
      cout << "Enter employee Name: ";
      cin >> emp.name;
      emp.key = emp.empid % n;

      if (h[emp.key].full == 0)
      {
        h[emp.key] = emp;
        h[emp.key].full = 1;
      }
      else
      {
        int index = (emp.key + 1) % n;
        while (h[index].full == 1)
        {
          index = (index + 1) % n;
        }
        h[index] = emp;
        h[index].full = 1;
      }
    }
  }

  void search()
  {
    int empID;
    cout << "Enter employee ID to search: ";
    cin >> empID;
    int key = empID % n;
    int index = key;

    while (h[index].full == 1)
    {
      if (h[index].empid == empID)
      {
        cout << "Employee found at index " << index << endl;
        cout << "Name :- " << h[index].name << endl;
        return;
      }
      index = (index + 1) % n;
      if (index == key)
      {
        break;
      }
    }
    cout << "Employee with ID " << empID << " not found." << endl;
  }

  void display()
  {
    cout << "Employee Hash Table:" << endl;
    for (int i = 0; i < n; i++)
    {
      if (h[i].full == 1)
      {
        cout << "Name " << h[i].name << ": Employee ID " << h[i].empid << endl;
      }
    }
  }
};

int main()
{
  hash1 h1;
  int choice, exit = 1;

  while (exit)
  {
    cout << "***** Menu *****" << endl;
    cout << "1. Insert Employee" << endl;
    cout << "2. Search Employee" << endl;
    cout << "3. Display Employees" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      h1.insert();
      break;
    case 2:
      h1.search();
      break;
    case 3:
      h1.display();
      break;
    case 4:
      cout << "Exiting the program." << endl;
      exit = 0;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}