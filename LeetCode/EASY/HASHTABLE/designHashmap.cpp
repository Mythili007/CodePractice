/**
 * https://leetcode.com/problems/design-hashmap/
 * Design Hashmap
  */

#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        int arr[1000000] = new int[];
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        
    }
};

void _main()
{
    Solution sol;
    string s = "anagram", t = "nagaram";
    s = "aacc", t = "ccac";
    bool res = sol.isAnagram(s, t);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}