#include <iostream>
using namespace std;
class Search
{
public:
  void linear_search(int key, int a[], int n)
  {
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
      if (key == a[i])
      {
        pos = i;
        break;
      }
    }
    if (pos != -1)
    {
      cout << "Element " << key << " not found !!" << endl;
    }
    else
    {
      cout << "Element " << key << " found at " << pos << "position !!" << endl;
    }
  }
  int Binary_Search_without_recursion(int low, int high, int key, int a[])
  {
    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (a[mid] == key)
      {
        return mid;
      }
      else if (key < a[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return -1;
  }

  int Binary_Search_with_recursion(int low, int high, int key, int a[])
  {
    if (low <= high)
    {
      int mid = (low + high) / 2;

      if (a[mid] == key)
      {
        return mid;
      }
      else if (key < a[mid])
      {
        return Binary_Search_with_recursion(low, mid - 1, key, a);
      }
      else
      {
        return Binary_Search_with_recursion(mid + 1, high, key, a);
      }
    }

    return -1;
  }
};
class Sort
{
public:
  void Sort_via_Bubble_sort(int a[], int n)
  {
    int temp, swap;
    for (int i = 0; i < n; i++)
    {
      swap = 0;
      for (int j = 0; j < n; j++)
      {

        if (a[j + 1] < a[j])
        {
          temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
          swap = 1;
        }
      }
      if (swap == 0)
      {
        break;
      }
    }
  }
  void Sort_via_selection_sort(int a[], int n)
  {
    int min_pos, temp;
    for (int i = 0; i < n; i++)
    {
      min_pos = i;
      for (int j = i + 1; j < n; j++)
      {
        if (a[min_pos] > a[j])
        {
          min_pos = j;
        }
      }
      if (min_pos != i)
      {
        temp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = temp;
      }
    }
  }
  void Sort_via_insertion_sort(int a[], int n)
  {
    int i, j, min_pos, temp;
    for (i = 1; i < n; i++)
    {
      j = i - 1;
      temp = a[i];
      while (j >= 0 && temp < a[j])
      {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = temp; // Here why j+1
    }
  }
  // void Sort_via_quick_sort(int a[], int low, int high)
  // {
  //   if (low < high)
  //   {
  //     int pivotIdx = a[low];
  //     swap(a[pivotIdx], a[high]);
  //     pivotIdx = high;
  //     int i = low - 1, j = high;
  //     while (i < j)
  //     {
  //       while (a[++i] <= a[pivotIdx])
  //       {
  //       }

  //       while (a[--j] >= a[pivotIdx])
  //         if (j < i)
  //           break;

  //       if (i < j)
  //         swap(a[i], a[j]);
  //     }
  //     swap(a[pivotIdx], a[j]);
  //     Sort_via_quick_sort(a, low, j - 1);
  //     Sort_via_quick_sort(a, j + 1, high);
  //   }
  // }
  void swap(int &a, int &b)
  {
    int temp = a;
    a = b;
    b = temp;
  }

  int partition(int a[], int low, int high)
  {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
      if (a[j] <= pivot)
      {
        i++;
        swap(a[i], a[j]);
      }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
  }

  void Sort_via_quick_sort(int a[], int low, int high)
  {
    if (low < high)
    {
      int pivotIdx = partition(a, low, high);
      Sort_via_quick_sort(a, low, pivotIdx - 1);
      Sort_via_quick_sort(a, pivotIdx + 1, high);
    }
  }
};

int main()
{
  Sort s;
  Search search;

  int choice, key, result;
  int a[] = {5, 4, 3, 1};
  int n = sizeof(a) / sizeof(a[0]);
  do
  {
    cout << "Menu:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search without Recursion\n";
    cout << "3. Binary Search with Recursion\n";
    cout << "4. Bubble Sort\n";
    cout << "5. Selection Sort\n";
    cout << "6. Insertion Sort\n";
    cout << "7. Quick Sort\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the key to search: ";
      cin >> key;
      search.linear_search(key, a, n);
      break;

    case 2:
      cout << "Enter the key to search: ";
      cin >> key;
      result = search.Binary_Search_without_recursion(0, n - 1, key, a);
      if (result != -1)
        cout << "Element " << key << " found at position " << result << "!!\n";
      else
        cout << "Element " << key << " not found !!\n";
      break;

    case 3:
      cout << "Enter the key to search: ";
      cin >> key;
      result = search.Binary_Search_with_recursion(0, n - 1, key, a);
      if (result != -1)
        cout << "Element " << key << " found at position " << result << "!!\n";
      else
        cout << "Element " << key << " not found !!\n";
      break;

    case 4:
      s.Sort_via_Bubble_sort(a, n);
      break;

    case 5:
      s.Sort_via_selection_sort(a, n);
      break;

    case 6:
      s.Sort_via_insertion_sort(a, n);
      break;

    case 7:
      s.Sort_via_quick_sort(a, 0, n - 1);
      break;

    case 8:
      cout << "Exiting the program.\n";
      break;

    default:
      cout << "Invalid choice. Please enter a valid option.\n";
    }
    cout << "Array after the operation:\n";
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << "\n\n";

  } while (choice != 8);

  return 0;
}