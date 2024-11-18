#include <iostream>

using namespace std;

// Structure for an adjacency list node
struct AdjListNode
{
    int dest;
    AdjListNode *next;
};

// Structure for an adjacency list
struct AdjList
{
    AdjListNode *head;
};

// Structure to represent a graph
class Graph
{
    int V; // Number of vertices

    // Pointer to an array containing adjacency lists
    AdjList *array;

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        array = new AdjList[V];
        for (int i = 0; i < V; ++i)
            array[i].head = nullptr;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest)
    {
        // Add an edge from src to dest
        AdjListNode *newNode = new AdjListNode;
        newNode->dest = dest;
        newNode->next = array[src].head;
        array[src].head = newNode;

        // Since the graph is undirected, add an edge from dest to src as well
        newNode = new AdjListNode;
        newNode->dest = src;
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }

    // Function to print the adjacency list representation of the graph
    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            AdjListNode *temp = array[i].head;
            cout << "Adjacency list of vertex " << i << ": ";
            while (temp)
            {
                cout << " -> " << temp->dest;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency list representation of the graph
    graph.printGraph();

    return 0;
}