#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
vector<long long> factorial(2001);

// Precompute factorials up to 2000 (mod MOD)
void computeFactorials() {
    factorial[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

// Trie node definition
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;  // Number of strings passing through this node
    TrieNode() : count(0) {}
};

// Insert a string into the trie
void insert(TrieNode* root, const string& s) {
    TrieNode* node = root;
    for (char c : s) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->count++;
}

// Recursively count valid permutations from a node
long long countPermutations(TrieNode* node) {
    long long result = 1;
    int totalStrings = node->count;
    
    // Traverse the children of this node
    for (auto& child : node->children) {
        result = (result * countPermutations(child.second)) % MOD;
        totalStrings += child.second->count;
    }
    
    // Multiply by the factorial of the number of strings passing through this node
    result = (result * factorial[totalStrings]) % MOD;
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    // Precompute factorials
    computeFactorials();
    
    // Build the trie
    TrieNode* root = new TrieNode();
    for (const string& s : strings) {
        insert(root, s);
    }
    
    // Calculate the number of valid permutations
    cout << countPermutations(root) << endl;
    
    return 0;
}
