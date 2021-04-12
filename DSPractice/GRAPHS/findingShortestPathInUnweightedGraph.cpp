/*
 * SHORTEST PATH ALGORITHM USING ADJACENCY LIST FOR UNWEIGHTED GRAPH
*/

#include <bits/stdc++.h>
using namespace std;

/* Structure to represent a node in the adjacency list */
struct AdjListNode {
    int destination;
    struct AdjListNode* next;
}

struct AdjList{
    struct AdjListNode* head;
}

void _main()
{
    // Solution sol;
    int vertices = 9;
    struct Graph *graph = createGraph(vertices);
    //Add edges
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    cout << endl;
}

int main()
{
    _main();
    return 0;
}