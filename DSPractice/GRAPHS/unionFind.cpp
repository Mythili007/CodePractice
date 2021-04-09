
/*
 * Detect cycle in a directed graph - GFG
  */

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest;
};

struct Graph
{
    int vertices, edges;
    struct Edge *edge;
};

struct Graph *createGraph(int vertices, int edges)
{
    struct Graph *graph = new Graph;
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = new Edge[edges];

    return graph;
}

class Solution
{
public:
    /* void make_set(int vertex, vector<int>& parent)
    {
        parent[vertex] = vertex;
    } */

    int find(int vertex, vector<int> parent)
    {
        if (parent[vertex] == -1)
            return vertex;
        return find(parent[vertex], parent);
    }

    void unionGraph(vector<int>& parent, int v1, int v2)
    {
        parent[v1] = v2;
    }

    bool isCycleExist(Graph *graph, int vertices)
    {
        vector<int> parent(vertices, -1);
        for (int i = 0; i < graph->edges; i++)
        {
            int x = find(graph->edge[i].src, parent);
            int y = find(graph->edge[i].dest, parent);

            if (x == y)
                return true;
            unionGraph(parent, x, y);
        }
        return false;
    }
};

void _main()
{
    Solution sol;
    int vertices = 3;
    int edges = 3;
    struct Graph *graph = createGraph(vertices, edges);
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (sol.isCycleExist(graph, vertices))
        cout << "Contains Cycle" << endl;
    else
        cout << "Does not contain cycle" << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}