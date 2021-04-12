
/*
 * DIJKSTRA'S SHORTEST PATH ALGORITHM USING ADJACENCY LIST
*/

#include <bits/stdc++.h>
using namespace std;

/* Structure to represent a node in the adjacency list */
struct AdjListNode
{
    int destination;
    int weight;
    struct AdjListNode *next;
};

/* Structure to represent an Adjacency list*/
struct AdjList
{
    /* Pointer to the head node of the list */
    struct AdjListNode *head;
};

/*
    * Structure to represent a graph
    * A graph is an array of adjacency lists
    * Size of array will be the num of vertices in the graph
*/
struct Graph
{
    int vertices;
    struct AdjList *array;
};

/* Utility function to create a new node in the adjacency list */
struct AdjListNode *newAdjListNode(int destination, int weight)
{
    // Make space for new node
    // struct AdjListNode *newNode = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
    struct AdjListNode *newNode = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
};

/* Utility function to create a graph with vertices count*/
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    /* 
        * Create an array of adjacency lists 
        * Size of the array will be the vertices count
    */
    graph->array = (struct AdjList *)malloc(sizeof(struct AdjList));

    /* Initialize each adjacency list as empty by making the head pointer as NULL */
    for (int i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;

    return graph;
};

/* Add edge to an undirected graph */
void addEdge(struct Graph *graph, int source, int destination, int weight)
{
    /* 
        * Add an edge from source to destination
        * New node is added to the adjacency list of the source
        * Node is added at the beginning
    */
    // struct AdjListNode *newNode = newAdjListNode(destination, weight);
    struct AdjListNode* newNode = newAdjListNode(destination, weight);
    newNode->next = graph->array[source].head;
    graph->array[source].head = newNode;

    /* Since graph is undirected add edge from destination to source node also */
    newNode = newAdjListNode(source, weight);
    newNode->next = graph->array[destination].head;
    graph->array[destination].head = newNode;
}

/* Structure to represent a min heap node */
struct MinHeapNode
{
    int vertex;
    int distance;
};

/* Structure to represent a min heap */
struct MinHeap
{
    /* No of heap nodes present in the heap currently */
    int size;
    /* Capacity of min heap */
    int capacity;
    /* To decrease key */
    int *pos;
    struct MinHeapNode **array;
};

/* Utility to create a new min heap node */
struct MinHeapNode *newMinHeapNode(int vertex, int distance)
{
    struct MinHeapNode *newNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    newNode->vertex = vertex;
    newNode->distance = distance;

    return newNode;
};

/* Utility function to create min heap */
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->pos = (int *)
        malloc(capacity * sizeof(int));
    minHeap->array = (struct MinHeapNode **)
        malloc(capacity * sizeof(struct MinHeapNode *));

    return minHeap;
};

/* Utility to swap nodes in min heap */
void swapMinHeapNodes(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

/* 
    * Standard function to heapify at given index
    * Also updates position of nodes after they are swapped
 */

void minHeapify(struct MinHeap *minHeap, int index)
{
    int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->distance < minHeap->array[smallest]->distance)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->distance < minHeap->array[smallest]->distance)
        smallest = right;

    if (smallest != index)
    {
        //Nodes to be swapped in min heap
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *indexNode = minHeap->array[index];

        //Swap positions
        minHeap->pos[smallestNode->vertex] = index;
        minHeap->pos[indexNode->vertex] = smallest;

        //Swap nodes
        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[index]);

        minHeapify(minHeap, smallest);
    }
}

/* Utility function to check whether the min Heap is empty or not */
bool isEmpty(struct MinHeap *minHeap)
{
    return minHeap->size == 0;
}

/* Extract minimum node from heap */
struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    struct MinHeapNode *root = minHeap->array[0];

    // Replace root node with the last node
    struct MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of the last node
    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    // Reduce heapsize and heapify the root
    --minHeap->size;

    minHeapify(minHeap, 0);
    return root;
};

/* 
    * Function to decrease the distance value of a given vertex
    * It uses pos[] of minHeap to get the current index of node in the min Heap
 */

void decreaseKey(struct MinHeap *minHeap, int vertex, int distance)
{
    // Get the index of the vertex in the heap array
    int idx = minHeap->pos[vertex];

    // Get the node and update its distance value
    minHeap->array[idx]->distance = distance;

    /* 
        * Travel up while the complete tree is not heapified
        * O(Logn) - Complexity
     */
    while (idx && minHeap->array[idx]->distance < minHeap->array[(idx - 1) / 2]->distance)
    {
        // Swap the current node with its parent
        minHeap->pos[minHeap->array[idx]->vertex] = (idx - 1) / 2;
        minHeap->pos[minHeap->array[(idx - 1) / 2]->vertex] = idx;

        swapMinHeapNodes(&minHeap->array[idx], &minHeap->array[(idx - 1) / 2]);

        // Move the parent index
        idx = (idx - 1) / 2;
    }
}

/* Utility function to check if the given vertex is in min heap or not */
bool doesVertextExistInMinHeap(struct MinHeap *minHeap, int vertex)
{
    if (minHeap->pos[vertex] < minHeap->size)
        return true;
    return false;
}

/* Utility to print the solution */
void printArr(int dist[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "source: " << i << "  distance: " << dist[i];

    cout << endl;
}

// class Solution
// {
// public:
/* 
        Main function that calculates the shortest distances of the shortest paths from source to all vertices 
        Complexity: O(ElogV)
    */
void dijkstra(struct Graph *graph, int src)
{
    // Get all vertices from the graph
    int vertices = graph->vertices;

    // Distance values used to pick minimum weight edge in cut
    int distance[vertices];

    // Min heap represents set E
    struct MinHeap *minHeap = createMinHeap(vertices);

    /* 
            * Initialize minheap with all the vertices
            * Dist value of all the vertices
        */
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        minHeap->array[i] = newMinHeapNode(i, distance[i]);
        minHeap->pos[i] = i;
    }

    /* Make dist value of source is 0 so that it get extracted first */
    minHeap->array[src] = newMinHeapNode(src, distance[src]);
    minHeap->pos[src] = src;
    distance[src] = 0;
    decreaseKey(minHeap, src, distance[src]);

    // Initially size of the minheap is equal to no of vertices
    minHeap->size = vertices;

    /* Following loop ensures that minHeap contains all the nodes whose shortest distance is not yet finalized */
    while (!isEmpty(minHeap))
    {
        /* Extract the min distance node from min heap */
        struct MinHeapNode *minHeapNode = extractMin(minHeap);

        // Store the extracted vertex number
        int minVertexNum = minHeapNode->vertex;

        /*  Traverse through all adjacent vertices of minVertexNum and update their distance values */
        struct AdjListNode *pCrawl = graph->array[minVertexNum].head;

        while (pCrawl != NULL)
        {
            int vertex = pCrawl->destination;

            /* If shortest distance to destination vertex is not finalized yet and distance to vertex 
                through minVertexNum is less than its previously calculated distance*/
            if (doesVertextExistInMinHeap(minHeap, vertex) && distance[minVertexNum] != INT_MAX && pCrawl->weight + distance[minVertexNum] < distance[vertex])
            {
                distance[vertex] = distance[minVertexNum] + pCrawl->weight;

                // Update distance value in minheap also
                decreaseKey(minHeap, vertex, distance[vertex]);
            }
            pCrawl = pCrawl->next;
        }
    }
    // Print the calculated shortest distances
    printArr(distance, vertices);
}
// };

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

    dijkstra(graph, 0);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}