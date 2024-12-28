#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

// Function to convert a string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to normalize the name
string normalizeName(string name) {
    // Convert name to lowercase
    name = toLower(name);
    
    // List of suffixes to remove
    vector<string> suffixes = {"inc.", "corp.", "llc", "l.l.c.", "llc."};
    
    // Remove ampersands and commas, replace with space
    for (char &ch : name) {
        if (ch == '&' || ch == ',') {
            ch = ' ';
        }
    }
    
    // Remove leading "The ", "A ", "An "
    vector<string> articles = {"the ", "a ", "an "};
    for (string article : articles) {
        if (name.find(article) == 0) {
            name = name.substr(article.length());
            break;
        }
    }

    // Remove suffixes
    for (string suffix : suffixes) {
        size_t pos = name.find(suffix);
        if (pos != string::npos) {
            name = name.substr(0, pos);
        }
    }
    
    cout << "noame : " << name << endl;

    // If "And" is in between names, remove it
    stringstream ss(name);
    string token, normalized_name;
    bool is_first_word = true;
    while (ss >> token) {
        if (token == "and" && !is_first_word) {
            continue; // Ignore "and" when it's in between words
        }
        if (!normalized_name.empty()) {
            normalized_name += " ";
        }
        normalized_name += token;
        is_first_word = false;
    }
    cout << "nor : " << normalized_name << endl;
    // Remove leading and trailing spaces
    normalized_name.erase(0, normalized_name.find_first_not_of(" "));
    normalized_name.erase(normalized_name.find_last_not_of(" ") + 1);
    
    return normalized_name;
}

// Function to check availability of company names
void check_availability(vector<string> requests) {
    unordered_set<string> used_names;
    
    for (string request : requests) {
        // Split the input by '|'
        size_t pipe_pos = request.find('|');
        string account_id = request.substr(0, pipe_pos);
        string proposed_name = request.substr(pipe_pos + 1);
        
        // Normalize the proposed name
        string normalized_name = normalizeName(proposed_name);
        
        // cout << "nor : " << normalized_name << endl;
        
        // If the normalized name is empty or contains only spaces
        if (normalized_name.empty()) {
            cout << account_id << "|Name Not Available" << endl;
            continue;
        }
        
        // Check if the name is already taken
        if (used_names.find(normalized_name) != used_names.end()) {
            cout << account_id << "|Name Not Available" << endl;
        } else {
            // Mark the name as used and print available
            used_names.insert(normalized_name);
            cout << account_id << "|Name Available" << endl;
        }
    }
}

int main() {
    // Example input
    vector<string> requests = {
        "acct_123|Llama, Inc.",
        "acct_456|The, LLama, LLC",
        "acct_789|Llama & Friend, LLC",
        "acct_321|Llama   And Friend, Inc.",
        "acct_654|Llama The Friend, LLC.",
        "acct_987|And Llama Friend, Inc."
    };
    
    // Check the availability of each name
    check_availability(requests);
    
    return 0;
}