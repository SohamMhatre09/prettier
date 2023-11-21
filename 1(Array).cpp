// For 1D matrix
#include <iostream>
using namespace std;
const int max_count = 20;
class Matrix2D
{
private:
int arr[max_count], no_of_elements;

public:
void create_matrix()
{
    cout << "Enter no. of elements : ";
    cin >> no_of_elements;
    cout << "Enter " << no_of_elements << " numbers : ";
    for (int i = 0; i < no_of_elements; i++)
    {
        cin >> arr[i];
    }
}

bool check_boundaries(int i)
{
    if (i >= 0 && i < no_of_elements)
    {
        return true;
    }
    return false;
}
void display_array()
{
    cout << "Matrix : " << endl;
    for (int i = 0; i < no_of_elements; i++)
    {
        cout << arr[i] << " ";
    }
}
int search_element(int val)
{
    int count = 0;
    for (int i = 0; i < no_of_elements; i++)
    {
        if (arr[i] == val)
        {
            cout << "Element found at position " << i << " ." << endl;
            count++;
            return i;
        }
    }
    return -1;
}
void find_max()
{
    if (no_of_elements == 0)
    {
        cout << "The array is empty !! " << endl;
        return;
    }
    cout << "Maximum element from matrix is ";
    int max_ = arr[0];
    for (int i = 0; i < no_of_elements; i++)
    {
        if (arr[i] > max_)
        {
            max_ = arr[i];
        }
    }
    cout << max_ << "." << endl;
}
void find_min()
{
    cout << "Minimum element from matrix is ";
    int min_ = arr[0];
    for (int i = 0; i < no_of_elements; i++)
    {
        if (arr[i] < min_)
        {
            min_ = arr[i];
        }
    }
    cout << min_ << "." << endl;
}
void insert_at_pos(int pos, int val)
{
    if (pos >= 0 && pos <= no_of_elements && no_of_elements < max_count)
    {
        for (int i = no_of_elements; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        no_of_elements++;
    }
    else
    {
        cout << "Positioning not possible !!" << endl;
    }
}

void delete_at_pos(int pos)
{
    if (pos >= 0 && pos < no_of_elements)
    {
        for (int i = pos; i < no_of_elements - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        no_of_elements--;
    }
    else
    {
        cout << "Positioning not possible !!" << endl;
    }
}
};
int main()
{
    Matrix2D matrix;
    int choice, element, position;

    do
    {
        cout << "\nMatrix Operations Menu:\n";
        cout << "1. Create Matrix\n";
        cout << "2. Display Matrix\n";
        cout << "3. Search Element\n";
        cout << "4. Find Maximum Element\n";
        cout << "5. Find Minimum Element\n";
        cout << "6. Insert Element at Position\n";
        cout << "7. Delete Element at Position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            matrix.create_matrix();
            break;

        case 2:
            matrix.display_array();
            break;

        case 3:
            cout << "Enter the element to search: ";
            cin >> element;
            matrix.search_element(element);
            break;

        case 4:
            matrix.find_max();
            break;

        case 5:
            matrix.find_min();
            break;

        case 6:
            cout << "Enter the position to insert: ";
            cin >> position;
            cout << "Enter the value to insert: ";
            cin >> element;
            matrix.insert_at_pos(position, element);
            break;

        case 7:
            cout << "Enter the position to delete: ";
            cin >> position;
            matrix.delete_at_pos(position);
            break;

        case 8:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 8);

    return 0;
}
// Write a C++ program to implement a two dimensional array and perform the operations such as insert, display,
// search, and find minimum and maximum elements from it

// For 2D matrix

// #include <iostream>
// using namespace std;
// const int max_rows = 10;
// const int max_columns = 10;
// class Matrix2D
// {
// private:
//     int arr[max_rows][max_columns], no_of_rows, no_of_columns;

// public:
//     void create_matrix()
//     {
//         cout << "Enter no. of rows: ";
//         cin >> no_of_rows;
//         cout << "Enter no. of columns: ";
//         cin >> no_of_columns;
//         for (int i = 0; i < no_of_rows; i++)
//         {
//             for (int j = 0; j < no_of_columns; j++)
//             {
//                 cin >> arr[i][j];
//             }
//             cout << endl;
//         }
//     }
//     void insert(int i, int j, int val)
//     {
//         if (check_boundaries(i, j))
//         {
//             arr[i][j] = val;
//         }
//         else
//         {
//             cout << "Enter valid indices to delete !! Try Again !!" << endl;
//         }
//     }
//     bool check_boundaries(int i, int j)
//     {
//         if (i >= 0 || j >= 0 || j < no_of_rows || j < no_of_columns)
//         {
//             return true;
//         }
//         return false;
//     }
//     void display_matrix()
//     {
//         cout << "Matrix : " << endl;
//         for (int i = 0; i < no_of_rows; i++)
//         {
//             for (int j = 0; j < no_of_columns; j++)
//             {
//                 cout << arr[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
//     void search_element(int val)
//     {
//         int count = 0;
//         for (int i = 0; i < no_of_rows; i++)
//         {
//             for (int j = 0; j < no_of_columns; j++)
//             {
//                 if (arr[i][j] == val)
//                 {
//                     cout << "Element found at position (" << i << "," << j << ")" << endl;
//                     count++;
//                 }
//             }
//         }
//         if (count == 0)
//         {
//             cout << "Element not found " << endl;
//         }
//     }
//     void find_max()
//     {
//         cout << "Maximum element from matrix is ";
//         int max_ = arr[0][0];
//         for (int i = 0; i < no_of_rows; i++)
//         {
//             for (int j = 0; j < no_of_columns; j++)
//             {
//                 if (arr[i][j] > max_)
//                 {
//                     max_ = arr[i][j];
//                 }
//             }
//         }
//         cout << max_ << "." << endl;
//     }
//     void find_min()
//     {
//         cout << "Minimum element from matrix is ";
//         int min_ = arr[0][0];
//         for (int i = 0; i < no_of_rows; i++)
//         {
//             for (int j = 0; j < no_of_columns; j++)
//             {
//                 if (arr[i][j] < min_)
//                 {
//                     min_ = arr[i][j];
//                 }
//             }
//         }
//         cout << min_ << "." << endl;
//     }
// };
// int main()
// {
//     Matrix2D m;

//     int option,row, col, val;;

//     do
//     {
//         cout << endl
//              << "Menu:" << endl;
//         cout << "1. Create matrix" << endl;
//         cout << "2. Insert element" << endl;
//         cout << "3. Display matrix" << endl;
//         cout << "4. Search element" << endl;
//         cout << "5. Find maximum element" << endl;
//         cout << "6. Find minimum element" << endl;
//         cout << "7. Exit" << endl;
//         cout << "Enter your option: ";
//         cin >> option;

//         switch (option)
//         {
//         case 1:
//             m.create_matrix();
//             break;

//         case 2:

//             cout << "Enter row index: ";
//             cin >> row;

//             cout << "Enter column index: ";
//             cin >> col;

//             cout << "Enter value to insert: ";
//             cin >> val;

//             m.insert(row, col, val);
//             break;

//         case 3:
//             m.display_matrix();
//             break;

//         case 4:

//             cout << "Enter element to search: ";
//             cin >> val;

//             m.search_element(val);
//             break;

//         case 5:
//             m.find_max();
//             break;

//         case 6:
//             m.find_min();
//             break;

//         case 7:
//             cout << "Exiting program..." << endl;
//             break;

//         default:
//             cout << "Invalid option! Please enter a valid option." << endl;
//         }
//     } while (option != 7);

//     return 0;
// }


