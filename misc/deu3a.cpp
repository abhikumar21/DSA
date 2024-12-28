#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count; // To store the number of strings ending at this node

    TrieNode() {
        count = 0;
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        if (!curr->children.count(c)) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->count++;
}

int countPermutations(TrieNode* root) {
    if (!root->children.size()) {
        return root->count;
    }

    int result = 1;
    for (auto& child : root->children) {
        result *= countPermutations(child.second);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    TrieNode* root = new TrieNode();
    for (const string& word : strings) {
        insert(root, word);
    }

    cout << countPermutations(root) << endl;
    return 0;
}