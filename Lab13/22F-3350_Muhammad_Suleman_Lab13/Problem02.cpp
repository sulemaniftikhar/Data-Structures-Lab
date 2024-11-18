#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
        : data(0), next(nullptr) {}
};

class Graph
{
    int numVertices;
    Node **adjList;

public:
    Graph(int vertices)
        : numVertices(vertices)
    {
        adjList = new Node *[numVertices];
        for (int i = 0; i < numVertices; ++i)
        {
            adjList[i] = nullptr;
        }
    }

    void addEdge(int v1, int v2)
    {
        Node *newNode = new Node;
        newNode->data = v1;
        newNode->next = adjList[v2];
        adjList[v2] = newNode;

        newNode = new Node;
        newNode->data = v2;
        newNode->next = adjList[v1];
        adjList[v1] = newNode;
    }

    void printGraph()
    {
        cout << endl;
        for (int i = 0; i < numVertices; ++i)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            Node *temp = adjList[i];
            if (temp == nullptr)
            {
                cout << "None";
            }
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (v1, v2):" << endl;
    for (int i = 0; i < edges; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }

    cout << "\nAdjacency list representation of the graph:" << endl;
    graph.printGraph();

    return 0;
}