
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

struct Subset
{
    int parent, rank;
};

class Solution
{
public:
    /* An utility function to find set of an element "i" using path compression technique */
    int find(int vertex, struct Subset *subset)
    {
        if (subset[vertex].parent != vertex)
            subset[vertex].parent = find(subset[vertex].parent, subset);
        // return vertex;

        // return subset[vertex].parent = find(subset[vertex].parent, subset);
        return subset[vertex].parent;
    }

    /* Union of 2 sets using union by rank */
    void unionGraph(struct Subset *subset, int x, int y)
    {
        // Attach smaller rank tree under higher rank tree
        if (subset[x].rank < subset[y].rank)
            subset[x].parent = y;
        else if (subset[y].rank < subset[x].rank)
            subset[y].parent = x;
        else
        {
            subset[y].parent = x;
            subset[x].rank++;
        }
    }

    bool containsCycle(struct Graph *graph, int vertices)
    {
        struct Subset *subset = new Subset;
        for (int i = 0; i < vertices; i++)
        {
            subset[i].parent = i;
            subset[i].rank = 0;
        }

        for (int i = 0; i < graph->edges; ++i)
        {
            int x = find(graph->edge[i].src, subset);
            int y = find(graph->edge[i].dest, subset);

            if (x == y)
                return true;
            unionGraph(subset, x, y);
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
    graph->edge[2].dest = 3;

    if (sol.containsCycle(graph, vertices))
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