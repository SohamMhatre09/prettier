#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
  int vertices;
  int **arr;
  int *visited;

public:
  Graph()
  {
    cout << "Enter Number of vertices:- ";
    cin >> vertices;

    visited = new int[vertices]();
    arr = new int *[vertices]();

    for (int i = 0; i < vertices; i++)
    {
      arr[i] = new int[vertices]();
    }
  }

  ~Graph()
  {
    for (int i = 0; i < vertices; i++)
    {
      delete[] arr[i];
    }
    delete[] arr;
    delete[] visited;
  }

  void initilaize_visited()
  {
    for (int i = 0; i < vertices; i++)
    {
      visited[i] = 0;
    }
  }

  void create()
  {
    int v1, v2, edges;

    cout << "Enter number of edges :- ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
      cout << "Enter edge in pairs :- ";
      cin >> v1 >> v2;

      if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices)
      {
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
      }
      else
      {
        cout << "Enter Correct edge!!!" << endl;
        i--;
      }
    }
  }

  void display()
  {
    cout << "Adjacency Matrix:- " << endl;
    for (int i = 0; i < vertices; i++)
    {
      for (int j = 0; j < vertices; j++)
      {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }

  void BFS(int startvertex)
  {
    int v1;
    cout << "BFS Traversal starting from vertex " << startvertex << " :" << endl;

    queue<int> q;
    q.push(startvertex);
    visited[startvertex] = 1;

    while (!q.empty())
    {
      v1 = q.front();
      q.pop();
      cout << v1 << " ";

      for (int i = 0; i < vertices; i++)
      {
        if (arr[v1][i] == 1 && visited[i] == 0)
        {
          q.push(i);
          visited[i] = 1;
        }
      }
    }

    cout << endl;

    initilaize_visited();
  }

  void DFS(int startvertex)
  {
    int v1;
    cout << "DFS Traversal starting from vertex " << startvertex << " :" << endl;

    stack<int> s;
    s.push(startvertex);
    visited[startvertex] = 1;

    while (!s.empty())
    {
      v1 = s.top();
      s.pop();
      cout << v1 << " ";

      for (int i = 0; i < vertices; i++)
      {
        if (arr[v1][i] == 1 && visited[i] == 0)
        {
          s.push(i);
          visited[i] = 1;
        }
      }
    }

    cout << endl;

    initilaize_visited();
  }
};

int main()
{
  Graph G;

  G.create();

  int startindex;
  cout << "Enter starting index :- ";
  cin >> startindex;

  G.BFS(startindex);
  G.DFS(startindex);

  G.display();

  return 0;
}