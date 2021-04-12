/*
 * BELLMAN FORD: FIND SHORTEST PATH IN NEGATIVE EDGE WEIGHT GRAPH
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;

struct Edge
{
    int src, dest, distance;
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
    void addEdge(struct Graph *graph, int src, int dest, int distance, int ed)
    {
        graph->edge[ed].src = src;
        graph->edge[ed].dest = dest;
        graph->edge[ed].distance = distance;
    }

    vector<int> bellmanFord(struct Graph *graph, int src, vector<int> &parent, vector<int> &cost_parent)
    {
        int vertices = graph->vertices;
        int edges = graph->edges;

        parent[0] = -1; // Start node has no parent

        // Initialize all distances as infinite
        vector<int> distance(vertices, INT_MAX);

        distance[src] = 0;
        bool updated;

        for (int i = 0; i < vertices - 1; i++)
        {
            updated = false;
            for (int j = 0; j < edges; j++)
            {
                int _src = graph->edge[j].src;
                int _dest = graph->edge[j].dest;
                int current_distance = graph->edge[j].distance;
                if (distance[_src] != INT_MAX && distance[_src] + current_distance < distance[_dest])
                {
                    distance[_dest] = distance[_src] + current_distance;
                    parent[_dest] = _src;
                    cost_parent[_dest] = distance[_dest];
                    updated = true;
                }
            }

            if (!updated)
                break;
        }

        for (int i = 0; i < edges; i++)
        {
            int _src = graph->edge[i].src;
            int _dest = graph->edge[i].dest;
            int current_distance = graph->edge[i].distance;

            if (distance[_src] != INT_MAX && distance[_src] + current_distance < distance[_dest])
            {
                // distance[_dest] = distance[_src] + current_distance;
                cout << "Graph has negative edge cycle" << endl;
                break;
            }
        }
        return distance;
    }
};

void printDistances(vector<int> &res)
{
    for (int i = 0; i < res.size(); i++)
        cout << i << "   " << res[i] << endl;
}

void printShortestPath(vector<int> &parent, vector<int> &res)
{
    for (int i = 0; i < parent.size(); i++)
        cout << "Src->Dest: " << parent[i] << "->" << i << "  cost to reach  " << parent[i] << "from source 0 to " << res[i] << endl;
}

void _main()
{
    Solution sol;
    int vertices = 5;
    int edges = 8;
    struct Graph *graph = createGraph(vertices, edges);

    //Add edges
    sol.addEdge(graph, 0, 1, -1, 0);
    sol.addEdge(graph, 0, 2, 4, 1);
    sol.addEdge(graph, 1, 2, 3, 2);
    sol.addEdge(graph, 1, 3, 2, 3);
    sol.addEdge(graph, 1, 4, 2, 4);
    sol.addEdge(graph, 3, 2, 5, 5);
    sol.addEdge(graph, 3, 1, 1, 6);
    sol.addEdge(graph, 4, 3, -3, 7);

    vector<int> parent(vertices);      //Stores shortest path distance
    vector<int> cost_parent(vertices); // Cost of the node to parent edge weight

    vector<int> res = sol.bellmanFord(graph, 0, parent, cost_parent);
    printShortestPath(parent, res);
    printDistances(res);

    cout << endl;
}

int main()
{
    _main();
    return 0;
}