// Topic: Even more pizza
// https://hashcodejudge.withgoogle.com/#/rounds/5751229732880384/

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#include <bits/stdc++.h>
using namespace std;
typedef long long int lln;
typedef long long unsigned llun;
#define OWN_DEBUG 0
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const lln size = 1e5;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Edge{
  int x, y, weight;
  bool operator<(Edge const &other ){
    return weight < other.weight;
  }
};

class UnionJion {
  public:
  
  vector<int> parent;
  vector<int> depth;
  int ids = 0;
  
  UnionJion (int n) {
    parent.resize(n);
    depth.resize(n);
    
    for (int i=0;i<n;i++)  
      make_set(i);
  }
  
  void make_set(int i) {
    parent[i] = i;
    depth[i] = 1;
  }
  
  int findParent(int i) {
    if (i == parent[i])
      return i;
    
    return parent[i] = findParent(parent[i]);
  }
  
  void swapAB(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void unionJoin(int i, int j) {
    int a = parent[i];
    int b = parent[j];
    
    if (a != b) {
      if (depth[a] < depth[b]) {
        swapAB(&a, &b);
      }
      
      parent[b] = parent[a];
      depth[a] += depth[b];
    }
  }
};

class SegmentTree {
  public:
    int MAXN;
  vector<int> vec;
    
  SegmentTree() {}
        
  SegmentTree(int n) {
    MAXN = 4*n;
    vec.resize(MAXN, 0);
  }
  
  void build(vector<int> &arr, int index, int tl, int tr) {
    // cout << index << " " << tl << " " << tr << endl;
    if (tl == tr) {
      vec[index] = arr[tl];
    } else {
      int tm = (tl + tr)/2;
      build(arr, 2*index+1, tl, tm);
      build(arr, 2*index+2, tm+1, tr);
      vec[index] = vec[2*index+1] + vec[2*index+2];
    }
  }
  
  int sum(int index, int tl, int tr, int rangeL, int rangeR) {
    if (rangeL > rangeR)
      return 0;
    
    if (rangeL == tl && rangeR == tr)
      return vec[index];
      
    int tm = (tl + tr)/2;
    return sum(2*index+1, tl, tm, rangeL, min(rangeR, tm)) + sum(2*index+2, tm+1, tr, max(rangeL, tm + 1), rangeR);
  }
  
  void update(int index, int tl, int tr, int position, int newValue) {
    if (tl == tr) {
      vec[index] = newValue;
    } else {
      int tm = (tl + tr) / 2;
      if (tm >= position) {
        update(2*index+1, tl, tm, position, newValue);
      } else {
        update(2*index+2, tm+1, tr, position, newValue);
      }
      vec[index] = vec[2*index+1] + vec[2*index+2];
    }
  }
    
  void printSegTree() {
      for (int _s: vec)
          cout << _s << " ";
      cout << endl;
  }
};

class NumArray {
public:
    SegmentTree segTree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree = SegmentTree(n);
        segTree.build(nums, 0, 0, n-1);
        segTree.printSegTree();
    }
    
    void update(int index, int val) {
      segTree.update(0, 0, n-1, index, val);
      // cout << endl;
      // segTree.printSegTree();
    }
    
    int sumRange(int left, int right) {
        return segTree.sum(0, 0, n-1, left, right);
        // return 0;
    }
};
typedef pair<int, pair<int, int>> pi;

class Solution {
  private:
    int m, t2, t3, t4;
    vector<vector<string>> pizzaDetail;
    
  public:
    Solution(int m, int t2, int t3, int t4, vector<vector<string>> pizzaDetail){
      this->m = m;
      this->t2 = t2;
      this->t3 = t3;
      this->t4 = t4;
      
      this->pizzaDetail = pizzaDetail;
    }
    
    unordered_map<string, int> ingredient_map; // string -> int
    vector<vector<int>> vector_of_ingredient_with_pizza_index; // ingredient map with pizza indexes
    vector<vector<int>> pizza_to_ingredient_map; //pizza-index to ingredient map
    
    void mapOut() {
      vector_of_ingredient_with_pizza_index.resize(10000, {});
      
      // Map out ingredients to count
      for (vector<string> &pd: pizzaDetail) {
        int i=0;
        for (string _ingred: pd) {
          if (i == 0) {
            i++;
            continue; // slip first since it is the numeric ingredient count in pizza
          }
          
          if (ingredient_map.find(_ingred) == ingredient_map.end()) { // if not found
            ingredient_map[_ingred] = ingredient_map.size();
          }
        }
      }
      
      // map pizza to ingredient map
      // map ingredient to pizza_index;
      int i=0;
      for (vector<string> &pd: pizzaDetail) {
        vector<int> _ing;
        for (int j=1;j<pd.size();j++) {
          int ingredient_index = ingredient_map[pd[j]];
          
          _ing.push_back(ingredient_index);
          vector_of_ingredient_with_pizza_index[ingredient_index].push_back(i);
        }
        pizza_to_ingredient_map.push_back(_ing);
        i++;
      }
    }
    
    void solve() {
      mapOut();
      cout << "Input is mapped successfully"  << endl;
      cout <<"Ingredient Map size " << ingredient_map.size()<< endl;
    }
};

TreeNode* buildTree(vector<int> &houses, int index) {
  if (houses[index] == -1 || index >= houses.size()) return NULL;
  
  TreeNode *node = new TreeNode(houses[index]);
  
  node->left = buildTree(houses, 2*index + 1);
  node->right = buildTree(houses, 2*index + 2);
  
  return node;
}

ListNode *buildList(vector<int> &nums, int index) {
  if (index == nums.size())
    return NULL;
  ListNode* node = new ListNode(nums[index]);
  node->next = buildList(nums, index+1);
  return node;
}

int m, t2, t3, t4;
vector<vector<string>> pizzaDetail;

void readInput() {
  #ifndef ONLINE_JUDGE
    freopen("/home/mythili/Documents/Pgmg/cPractice_upd/Google/Hashcode_2021/Input/a_example", "r", stdin);
  #else
  // online submission
  #endif
  
  cin >> m >> t2 >> t3 >> t4;
  for(int i=0;i<m;i++) {
    vector<string> _each_pizza;
    
    int pizza_ingredients;
    cin >> pizza_ingredients;
    _each_pizza.push_back(to_string(pizza_ingredients));
    
    for (int i=0;i<pizza_ingredients;i++) {
      string ingredient;
      cin >> ingredient;
      _each_pizza.push_back(ingredient);
    }
    
    pizzaDetail.push_back(_each_pizza);
  }
}

void _main() {
  
  // TreeNode* root = buildTree(houses, 0);
  // ListNode* head = buildList(nums, 0);
  readInput();
  
  Solution sol(m, t2, t3, t4, pizzaDetail);
  
  sol.solve();
}


int main() {
  
  int t = 1;
  // cin >> t;
  while (t--)
    _main();
  
  return 0;
}
