#include <iostream>

using namespace std;

int **createAdjacencyMatrix(int vertices, int edges, int arr[][2])
{
    int **adjMatrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];

        adjMatrix[x - 1][y - 1] = 1;
        adjMatrix[y - 1][x - 1] = 1;
    }

    return adjMatrix;
}

void displayAdjacencyMatrix(int **adjMatrix, int N)
{
    cout << "\nDisplaying Adjacency Matrix of " << N << " * " << N << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int vertices = 8;
    int edges = 7;
    int arr[][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}, {6, 1}, {7, 4}, {3, 8}};

    cout << "Input: "
         << "Vertices: " << vertices << ", Edges: " << edges << endl;

    cout << "Array arr[][]: ";
    cout << "{";
    for (int i = 0; i < edges; i++)
    {
        cout << " { " << arr[i][0] << " , " << arr[i][1] << " } ";
    }
    cout << "}" << endl;

    int **adjMatrix = createAdjacencyMatrix(vertices, edges, arr);

    displayAdjacencyMatrix(adjMatrix, vertices);

    for (int i = 0; i < vertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}