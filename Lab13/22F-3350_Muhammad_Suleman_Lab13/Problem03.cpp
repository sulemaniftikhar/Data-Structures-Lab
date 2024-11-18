#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// Edge class to represent edges
class Edge
{
private:
    int from;
    int to;
    int dist;

public:
    Edge(int from, int to, int dist)
        : from(from), to(to), dist(dist) {}

    // Getters
    int getFrom()
    {
        return from;
    }
    int getTo()
    {
        return to;
    }
    int getDist()
    {
        return dist;
    }
};

// Vertex class to represent vertices
class Vertex
{
private:
    int id;
    string name;

public:
    Vertex() {}
    Vertex(int id, string name)
        : id(id), name(name) {}

    // Getters
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }

    // Setters
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
};

// Graph class to represent the graph structure
class Graph
{
private:
    Vertex *verts;
    Edge ***adjMat;
    int vCount;
    int maxVerts;

public:
    Graph(int maxVerts)
        : maxVerts(maxVerts), vCount(0)
    {
        verts = new Vertex[maxVerts];
        adjMat = new Edge **[maxVerts];
        for (int i = 0; i < maxVerts; ++i)
        {
            adjMat[i] = new Edge *[maxVerts];
            for (int j = 0; j < maxVerts; ++j)
            {
                adjMat[i][j] = nullptr;
            }
        }
    }

    ~Graph()
    {
        delete[] verts;
        for (int i = 0; i < maxVerts; ++i)
        {
            delete[] adjMat[i];
        }
        delete[] adjMat;
    }

    bool vertexExistsById(int id)
    {
        for (int i = 0; i < vCount; ++i)
        {
            if (verts[i].getId() == id)
            {
                return true;
            }
        }
        return false;
    }

    void addVertex(Vertex newVertex)
    {
        verts[vCount++] = newVertex;
    }

    Vertex getVertexById(int vid)
    {
        for (int i = 0; i < vCount; ++i)
        {
            if (verts[i].getId() == vid)
            {
                return verts[i];
            }
        }
        return Vertex();
    }

    bool edgeExistsById(int from, int to)
    {
        return adjMat[from][to] != nullptr;
    }

    void addEdge(int from, int to, int weight)
    {
        if (from >= 0 && from < maxVerts && to >= 0 && to < maxVerts)
        {
            adjMat[from][to] = new Edge(from, to, weight);
        }
    }

    // BFS traversal
    void BFS(int startVertexId)
    {
        bool *visited = new bool[maxVerts];
        queue<int> q;

        visited[startVertexId] = true;
        q.push(startVertexId);

        while (!q.empty())
        {
            int currentVertexId = q.front();
            q.pop();
            cout << "Visited: " << verts[currentVertexId].getName() << endl;

            // Iterate through adjacent vertices
            for (int i = 0; i < vCount; ++i)
            {
                if (adjMat[currentVertexId][i] != nullptr && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
    }

    // DFS traversal
    void DFS(int startVertexId)
    {
        bool *visited = new bool[maxVerts];
        stack<int> s;

        visited[startVertexId] = true;
        s.push(startVertexId);

        while (!s.empty())
        {
            int currentVertexId = s.top();
            s.pop();
            cout << "Visited: " << verts[currentVertexId].getName() << endl;

            // Iterate through adjacent vertices
            for (int i = 0; i < vCount; ++i)
            {
                if (adjMat[currentVertexId][i] != nullptr && !visited[i])
                {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }

        delete[] visited;
    }
};

int main()
{
    Graph graph(10);

    graph.addVertex(Vertex(0, "Karachi"));
    graph.addVertex(Vertex(1, "Lahore"));
    graph.addVertex(Vertex(2, "Islamabad"));

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 1);

    cout << "BFS Traversal:" << endl;
    graph.BFS(0);
    cout << endl;

    cout << "DFS Traversal:" << endl;
    graph.DFS(0);

    return 0;
}