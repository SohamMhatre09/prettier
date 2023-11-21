#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int max_vertices = 10;
const int max_infinity = 99;

class Graph
{
private:
  int adjacency_matrix[max_vertices][max_vertices];
  int cost_matrix[max_vertices][max_vertices];
  int mst[max_vertices][max_vertices];
  int no_of_vertices, no_of_edges;

public:
  Graph()
  {
    for (int i = 0; i < max_vertices; ++i)
    {
      for (int j = 0; j < max_vertices; ++j)
      {
        adjacency_matrix[i][j] = 0;
        cost_matrix[i][j] = 0;
        mst[i][j] = 0;
      }
    }
  }

  void accept_graph()
  {
    cout << "Enter no. of vertices: ";
    cin >> no_of_vertices;
    cout << "Enter no. of edges: ";
    cin >> no_of_edges;

    int i, j, edge_weight;

    for (int k = 0; k < no_of_edges; k++)
    {
      cout << "Enter vertices of edge: ";
      cin >> i >> j;

      if (i < 0 || i >= no_of_vertices || j < 0 || j >= no_of_vertices)
      {
        cout << "Enter valid vertices !! Enter matrix again !!" << endl;
        k--;
      }
      else
      {
        cout << "Enter edge weight: ";
        cin >> edge_weight;
        adjacency_matrix[i][j] = adjacency_matrix[j][i] = edge_weight;
      }
    }
  }

  void BFS()
  {
    bool visited[max_vertices] = {false};
    queue<int> q;
    int temp_vertex;

    cout << "Enter starting vertex: ";
    cin >> temp_vertex;

    if (temp_vertex < 0 || temp_vertex >= no_of_vertices)
    {
      cout << "Enter a valid vertex !! Try again !!" << endl;
      return;
    }

    cout << "BFS order: ";
    q.push(temp_vertex);
    visited[temp_vertex] = true;

    while (!q.empty())
    {
      temp_vertex = q.front();
      cout << temp_vertex << " ";
      q.pop();

      for (int i = 0; i < no_of_vertices; i++)
      {
        if (adjacency_matrix[temp_vertex][i] >= 0 && visited[i] == false)
        {
          q.push(i);
          visited[i] = true;
        }
      }
    }

    cout << endl;
  }

  void DFS()
  {
    bool visited[max_vertices] = {false};
    stack<int> s;
    int temp_vertex;

    cout << "Enter starting vertex: ";
    cin >> temp_vertex;

    if (temp_vertex < 0 || temp_vertex >= no_of_vertices)
    {
      cout << "Enter a valid vertex !! Try again !!" << endl;
      return;
    }

    s.push(temp_vertex);
    visited[temp_vertex] = true;

    cout << "DFS order: ";

    while (!s.empty())
    {
      temp_vertex = s.top();
      cout << temp_vertex << " ";
      s.pop();

      for (int i = 0; i < no_of_vertices; i++)
      {
        if (adjacency_matrix[temp_vertex][i] >= 0 && !visited[i])
        {
          s.push(i);
          visited[i] = true;
        }
      }
    }

    cout << endl;
  }

  void MST()
  {
    bool visited[max_vertices] = {false};

    for (int i = 0; i < no_of_vertices; i++)
    {
      for (int j = 0; j < no_of_vertices; j++)
      {
        if (adjacency_matrix[i][j] == 0)
        {
          cost_matrix[i][j] = max_infinity;
        }
        else
        {
          cost_matrix[i][j] = adjacency_matrix[i][j];
        }
      }
    }

    int temp_vertex;
    cout << "Enter starting vertex: ";
    cin >> temp_vertex;

    int edges = 0;
    int min_ = max_infinity, v = temp_vertex;
    int cost = 0;

    visited[temp_vertex] = true;

    while (edges < no_of_vertices - 1)
    {
      temp_vertex = v;
      min_ = max_infinity;

      for (int i = 0; i < max_vertices; i++)
      {
        if (adjacency_matrix[temp_vertex][i] >= 0 && visited[i] == false && min_ > cost_matrix[temp_vertex][i])
        {
          min_ = cost_matrix[temp_vertex][i];
          v = i;
        }
      }

      mst[temp_vertex][v] = mst[v][temp_vertex] = min_;
      cost += min_;
      visited[v] = true;
      edges++;
    }

    cout << "Cost of minimum spanning tree: " << cost << endl;

    cout << "Minimum Spanning Tree (MST):" << endl;
    for (int i = 0; i < no_of_vertices; i++)
    {
      for (int j = 0; j < no_of_vertices; j++)
      {
        cout << mst[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g;
  g.accept_graph();
  g.BFS();
  g.DFS();
  g.MST();
  return 0;
}
