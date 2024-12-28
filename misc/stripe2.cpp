#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
using namespace std;

class StripePayBackend {
private:
    struct Account {
        int balance;
        unordered_set<string> banks;
    };
    
    unordered_map<string, Account> accounts;
    vector<string> command_log;

public:
    void processCommands(const vector<string>& commands) {
        for (const string& command : commands) {
            vector<string> commandParts = split(command, ',');
            if (commandParts[0] == "INIT") {
                initAccount(commandParts);
            } else if (commandParts[0] == "POST") {
                processPost(commandParts);
            } else if (commandParts[0] == "GET") {
                processGet(commandParts);
            }
        }
        printLog();
    }

private:
    vector<string> split(const string& str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string item;
        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        return result;
    }

    void initAccount(const vector<string>& commandParts) {
        string name = commandParts[1];
        int balance = stoi(commandParts[2]);
        unordered_set<string> banks;
        for (size_t i = 3; i < commandParts.size(); ++i) {
            banks.insert(commandParts[i]);
        }
        accounts[name] = {balance, banks};
    }

    void processPost(const vector<string>& commandParts) {
        int timestamp = stoi(commandParts[1]);
        string sender = commandParts[2];
        string receiver = commandParts[3];
        int amount = stoi(commandParts[4]);

        if (accounts.find(sender) == accounts.end()) {
            command_log.push_back("FAILURE");
            return;
        }

        // Handle User to User transfer
        if (accounts.find(receiver) != accounts.end()) {
            if (accounts[sender].balance >= amount) {
                accounts[sender].balance -= amount;
                accounts[receiver].balance += amount;
                command_log.push_back("SUCCESS");
            } else {
                command_log.push_back("FAILURE");
            }
        } else { // Handle User to Bank transfer
            if (accounts[sender].banks.find(receiver) != accounts[sender].banks.end()) {
                if (accounts[sender].balance >= amount) {
                    accounts[sender].balance -= amount;
                    command_log.push_back("SUCCESS");
                } else {
                    command_log.push_back("FAILURE");
                }
            } else {
                command_log.push_back("FAILURE");
            }
        }
    }

    void processGet(const vector<string>& commandParts) {
        int timestamp = stoi(commandParts[1]);
        string name = commandParts[2];

        if (accounts.find(name) != accounts.end()) {
            command_log.push_back(to_string(accounts[name].balance));
        } else {
            command_log.push_back("FAILURE");
        }
    }

    void printLog() {
        for (const string& entry : command_log) {
            cout << entry << ",";
        }
        cout << endl;
    }
};

int main() {
    vector<string> commands = {
        "INIT,Alice,100,Chase,Wells Fargo",
        "INIT,Bob,50,Bank of America,Chase,Ally",
        "INIT,Charles,0,Bank of America",
        "POST,212,Alice,Bob,50",
        "GET,211,Alice",
        "POST,213,Alice,Charles,50",
        "GET,214,Alice",
        "POST,301,Charles,Bob,100",
        "POST,302,Ally,Charles,10",
        "POST,305,Kate,Alice,50",
        "GET,401,Charles",
        "POST,306,Alice,Chase,50"
    };

    StripePayBackend backend;
    backend.processCommands(commands);
    return 0;
}
