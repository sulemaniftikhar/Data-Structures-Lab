#include <iostream>

using namespace std;

#define V 5 // Number of vertices in the graph

bool isValid(int v, int pos, const int path[], const int graph[][V])
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool hamiltonianCycleUtil(const int graph[][V], int path[], int pos)
{
    if (pos == V)
    {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++)
    {
        if (isValid(v, pos, path, graph))
        {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1))
            {
                return true;
            }
            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(const int graph[][V])
{
    int path[V + 1];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1))
    {
        cout << "Hamiltonian cycle found: ";
        for (int i = 0; i <= V; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No Hamiltonian cycle exists." << endl;
    }
}

int main()
{
    int graph[V][V] =
        {
            {0, 1, 1, 1, 0},
            {1, 0, 1, 0, 1},
            {1, 1, 0, 1, 1},
            {1, 0, 1, 0, 1},
            {0, 1, 1, 1, 0}};

    hamiltonianCycle(graph);

    return 0;
}