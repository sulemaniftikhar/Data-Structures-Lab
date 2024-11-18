#include <iostream>

using namespace std;

class Graph
{
    int vertices;
    int **adjMatrix;

    bool isCyclicUtil(int v, bool visited[], int parent)
    {
        visited[v] = true;

        for (int i = 0; i < vertices; ++i)
        {
            if (adjMatrix[v][i])
            {
                if (!visited[i])
                {
                    if (isCyclicUtil(i, visited, v))
                    {
                        return true;
                    }
                }
                else if (i != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    Graph(int vertices)
        : vertices(vertices)
    {
        adjMatrix = new int *[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < vertices; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int v1, int v2)
    {
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    bool isCyclic()
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }

        for (int i = 0; i < vertices; ++i)
        {
            if (!visited[i] && isCyclicUtil(i, visited, -1))
            {
                delete[] visited;
                return true;
            }
        }
        delete[] visited;
        return false;
    }

    void displayAdjacencyMatrix()
    {
        cout << "\nDisplaying Adjacency Matrix of " << vertices << " * " << vertices << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    int vertices = 5;
    Graph graph(vertices);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    graph.displayAdjacencyMatrix();

    if (graph.isCyclic())
    {
        cout << "Graph is cyclic" << endl;
    }
    else
    {
        cout << "Graph is not cyclic" << endl;
    }

    return 0;
}