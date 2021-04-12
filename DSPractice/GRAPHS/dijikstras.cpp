// Topic: Dijikstras

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#include <bits/stdc++.h>
using namespace std;
typedef long long int lln;
typedef long long unsigned llun;
#define OWN_DEBUG 0
#define minOf(a, b) ((a) < (b) ? (a) : (b))
#define maxOf(a, b) ((a) > (b) ? (a) : (b))
#define abss(a) ((a) < 0 ? -1 * (a) : (a))
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const lln size = 1e5;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef pair<int, int> pi;

struct OwnNode
{
    int node_id;
    int dis = INT_MAX;

    OwnNode(int _nodeId) : node_id(_nodeId){};
};

class Solution
{
public:
    bool cmp(const OwnNode *l, const OwnNode *r)
    {
        return l->dis < r->dis;
    }

    unordered_map<OwnNode *, vector<OwnNode *>> graph;
    unordered_set<int> us_uniqueVertex;

    unordered_map<int, OwnNode *> dictionary;
    int start_vertex = -1;

    // priority_queue<OwnNode, vector<OwnNode>, cmp> pq_ow;
    vector<OwnNode *> minHeap;

    /* OwnNode* getMinDistanceFromNode(OwnNode *src)
    {
        int node_id_of_min;
        int dis = -1;
        vector<OwnNode *> sortList;

        for (OwnNode *o : minHeap)
        {
            if (graph[src].find(o) == graph[src].end())// we are trying to find it on the value
                continue;
            OwnNode* tmp = new OwnNode(o->node_id);

            if (dis == -1 || o->dis < dis)
            {
                dis = o->dis;
                node_id_of_min = o->node_id;
            }
        }

        return dictionary[node_id_of_min];
    } */

    /* void eraseFromMinHeap(OwnNode *whichToRemove)
    {
        auto itr = find(minHeap.begin(), minHeap.end(), whichToRemove);
        minHeap.erase(itr);
    } */

    void createNode(vector<vector<int>> &edg)
    {
        for (auto e : edg)
        {
            us_uniqueVertex.insert(e[0]);
            us_uniqueVertex.insert(e[1]);
        }

        for (auto uv : us_uniqueVertex)
        {
            OwnNode *ow = new OwnNode(uv);
            if (uv == start_vertex)
                ow->dis = 0;

            dictionary[uv] = ow;
        }
    }

    void createAdjList(vector<vector<int>> &edg)
    {
        createNode(edg);

        for (vector<int> _ed : edg)
        {
            int src_id = _ed[0], dst_id = _ed[1], wt = _ed[2];
            OwnNode *src = dictionary[src_id], *dst = dictionary[dst_id];

            if (graph.find(src) == graph.end())
                graph[src] = {};

            if (graph.find(dst) == graph.end())
                graph[dst] = {};

            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }

        /* for(auto i:graph){
            cout<<"node dis: "<<i.first->dis << "  nodeId: "<<i.first->node_id<<endl;
            printVec(i.second);
            cout<<endl;
        } */
    }

    bool allVisited(unordered_map<int, OwnNode *> &dictionary)
    {
        for (auto i : dictionary)
        {
            if (i.second->dis == INT_MAX)
            {
                return false;
            }
        }
        return true;
    }

    OwnNode *extractMInNode(unordered_map<int, OwnNode *> &dictionary)
    {
        for (auto i : dictionary)
        {
        }
    }

    int shortestDis(vector<vector<int>> edge, int src, int dst)
    {
        start_vertex = src;
        createAdjList(edge);
        //Extract minimum node
        while (!allVisited(dictionary))
        {
            OwnNode *min_node = getMinDistanceFromNode(dictionary);
            eraseFromMinHeap(min_node);
        }
        return 10;
    }
};

TreeNode *buildTree(vector<int> &arr, int index)
{
    if (index >= arr.size() || arr[index] == -1)
        return NULL;

    TreeNode *tr = new TreeNode(arr[index]);
    tr->left = buildTree(arr, 2 * index + 1);
    tr->right = buildTree(arr, 2 * index + 2);

    return tr;
}

void _main()
{

    vector<vector<int>> edge = {{1, 2, 3}, {1, 3, 4}, {2, 3, 13}, {6, 2, 3}, {3, 6, 1}}; // {src, dst, wght}

    Solution sol;
    // TreeNode *tree = buildTree(num, 0);

    //   vector<int> arr = sol.advantageCount(A, B);

    //   for (auto v: arr) {
    //     cout << v << " ";
    //   }
    //   cout << endl;

    cout << sol.shortestDis(edge, 1, 3) << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}
