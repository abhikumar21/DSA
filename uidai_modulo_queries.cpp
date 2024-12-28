#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> Element;

vector<pair<int, int>> modulo_queries(int q, vector<vector<int>>& queries) {
    vector<Element> container;
    vector<pair<int, int>> result;

    for (size_t i = 0; i < queries.size(); ++i) {
        int type = queries[i][0];
        int a = queries[i][1];
        int b = queries[i][2];

        if (type == 1) {  // Insert an element
            container.push_back(make_pair(a, b)); // Add (value, power)
        } else if (type == 2) {  // Query type 2
            int v = a;
            int mod_count = 0;
            int power_sum = 0;

            // Calculate 2^N (bit count)
            int n = log2(v) + 1;
            int mod = pow(2, n);

            for (size_t j = 0; j < container.size(); ++j) {
                int value = container[j].first;
                int power = container[j].second;
                if (value % mod == v % mod) {
                    mod_count++;
                    power_sum += power;
                }
            }

            result.push_back(make_pair(mod_count, power_sum));
        }
    }

    return result;
}

int main() {
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int q; // Number of queries
        cout << "Enter the number of queries: ";
        cin >> q;

        vector<vector<int>> queries(q, vector<int>(3));
        cout << "Enter the queries (type A B):\n";
        for (int i = 0; i < q; ++i) {
            cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        }

        auto result = modulo_queries(q, queries);
        cout << "Output:\n";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i].first << " " << result[i].second << endl;
        }
    }

    return 0;
}
