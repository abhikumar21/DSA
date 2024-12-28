#include <bits/stdc++.h>
using namespace std;


// Struct to hold chargeback information
struct Chargeback {
    string disputeID;
    string merchant;
    string amount;
    string evidenceDueBy;
    string reason;
    string network;
    string transactionID;
    string date;
};

// okay
string convertAmount(string amt , const string& currency) {
    set<string> hundredDiv = {"EUR", "USD", "SGD", "BRL"};

    if(hundredDiv.find(currency) != hundredDiv.end()){
    	// divide by 100
    	int sz = amt.size();
    	if(sz >= 3){
    		string ret = amt.substr(0 , sz-2);
    		ret += ".";
    		ret += amt[sz-2];
    		ret += amt[sz-1];
    		ret += currency;
    		return ret;
    	}
    	else{
    		string ret = "0.";
    		if(sz == 1)ret += "0";
    		ret += amt;
    		ret += currency;
    		return ret;
    	}
    }
    string ret = amt;
    ret += currency;
    return ret; // nothing tbd
}

// okay
bool compareDate(const string& date1, const string& date2) {
    int y1 = (stoi(date1.substr(0,4)));
    int y2 = (stoi(date2.substr(0,4)));
    int m1 = (stoi(date1.substr(4,2)));
    int m2 = (stoi(date2.substr(4,2)));
    int d1 = (stoi(date1.substr(6,2)));
    int d2 = (stoi(date2.substr(6,2)));
    
    if(y1 == y2){
    	if(m1 == m2){
    		return d2 > d1;
    	}
    	return m2 > m1;
    }
    return y2 > y1;
}

// okay
string extractDate(const string& filename) {
    size_t underscorePos = filename.find('_');
    size_t dotPos = filename.find(".csv");
    return filename.substr(underscorePos + 1, dotPos - underscorePos - 1);
}

// Helper function to check if a string is a valid number
bool isWholeNumber(const string& s) {
    for(char c : s){
    	if('0' > c || c > '9'){
    		return false;
    	}
    }
    return true;
}

// okay
map<string, int> parseHeader(const string& header) {
    map<string, int> fieldMap;
    stringstream ss(header);
    string field;
    int index = 0;
    
    while (getline(ss, field, ',')) {
        fieldMap[field] = index++;
    }
    
    return fieldMap;
}

// Main parsing function
string parseChargebackInfo(const vector<string>& input) {
    vector<Chargeback> cbs;
    set<string> validCurrencies = {"EUR", "USD", "SGD", "BRL", "JPY", "ISK", "KRW"};
    set<string> withdrawnTransactions;

    map<string, Chargeback> transactionMap;  // To track disputes for Part 3

    int i = 0;
    while (i < input.size()) {
        string filename = input[i];
        string date = extractDate(filename);
        
        i++;
        
        // Parse network and date from filename (e.g., VISA_20230601.csv -> "VISA")
        stringstream ss(filename);
        string network;
        getline(ss, network, '_');
        
        // dbg(network);
        // dbg(date);
        
        // Read and parse the header line
        string header = input[i];
        i++;
        map<string, int> fieldMap = parseHeader(header);
        
        // dbg(fieldMap);

        // Process each row of chargeback data
        while (i < input.size() && input[i].find(".csv") == string::npos) {
        	// input[i] does not have a ".csv" substring
            string row = input[i];
            i++;
            stringstream rowStream(row);
            
            vector<string> fields(6);
            
            for (int j = 0; j < 6 && getline(rowStream, fields[j], ','); ++j);

            // Map the fields using the indices from the header
            string transaction = fields[fieldMap["transaction"]];
            string merchant = fields[fieldMap["merchant"]];
            string amountStr = fields[fieldMap["amount"]];
            string currency = fields[fieldMap["currency"]];
            string evidenceDueBy = fields[fieldMap["evidence_due_by"]];
            string reason = fields[fieldMap["reason"]];
            
            // dbg(transaction);
            // dbg(merchant);
            // dbg(amountStr);
            // dbg(currency);
            // dbg(evidenceDueBy);
            // dbg(reason);

            // Part 2: Validate data
            if (validCurrencies.find(currency) == validCurrencies.end()) continue;  // Invalid currency
            if (!isWholeNumber(amountStr)) continue;  // Invalid amount
            if (!isWholeNumber(evidenceDueBy)) continue;  // Invalid evidence_due_by
            
            string disputeID = network + transaction;  // Form the dispute ID
            
            // Convert amount to major units and append currency
            string formattedAmount = convertAmount(amountStr, currency);
            
            // dbg(formattedAmount);
            
            Chargeback cb = {disputeID, merchant, formattedAmount, evidenceDueBy, reason, network, transaction , date};
            
            cbs.push_back(cb);
        }
        // cout << endl;
    }
    
    map<string , pair<int , string>> mpp;
    
    for(int i=0;i<cbs.size();i++){
    	if(cbs[i].reason != "withdrawn"){
    		mpp[cbs[i].disputeID] = {i , cbs[i].date};
    	}
    }
    
    set<int> ignore;
    
    for(int i=0;i<cbs.size();i++){
    	if(cbs[i].reason == "withdrawn"){
    		if(mpp.find(cbs[i].disputeID) != mpp.end()){
    			string date1 = cbs[i].date;
    			string date2 = mpp[cbs[i].disputeID].second;
			    
			    bool x = compareDate(date1 , date2);
			   			    
			    // dbg(cbs[i].transactionID);
			    // dbg(date1); // withdrwn ka date
			    // dbg(date2); // 
			    // dbg(x);
			    if(x == 0){
			    	ignore.insert(mpp[cbs[i].disputeID].first);
			    }
			    // assuming "withdrawn" are not processed only if a duplicate disputID occurs
			    // ....
    		}
    		// assuming "withdrawn" are NEVER processed
	    	ignore.insert(i);
    	}
    }
    
    // dbg(ignore);
    
    vector<Chargeback> cbs1;
    // remove the withdrawn transactions
    for(int i=0;i<cbs.size();i++){
    	if(ignore.find(i) == ignore.end()){
    		cbs1.push_back(cbs[i]);
    	}
    }
    cbs = cbs1;
    
    // dbg(cbs.size());

    // Sort chargebacks by disputeID
    sort(cbs.begin(), cbs.end(), [](const Chargeback& a, const Chargeback& b) {
        return a.disputeID < b.disputeID;
    });

    // Prepare the output as a single string
    string ret1;
    for(int i=0;i<cbs.size();i++){
    	ret1 += cbs[i].disputeID;
    	ret1 += ',';
    	ret1 += cbs[i].merchant;
    	ret1 += ',';
    	ret1 += cbs[i].amount;
    	ret1 += ',';
    	ret1 += cbs[i].evidenceDueBy;
    	ret1 += '\n';
    }
    if(ret1.size() > 0)ret1.pop_back();
    return ret1;
}

int main() {
    // Example input for Part 3
    vector<string> input = {
        "VISA_20230602.csv", "transaction,merchant,amount,currency,evidence_due_by,reason",
        "123890132,47821,37906,USD,1686812400,fraudulent",
        "110450953,63724,12750,JPY,1686898800,withdrawn",
        "VISA_20230603.csv", "transaction,merchant,currency,amount,evidence_due_by,reason",
        "110450953,63724,JPY,12750,1686898800,duplicate",
        "123890132,47821,USD,37906,1686812400,fd"
    };
    
    // Parse the chargeback information and handle invalid data and withdrawals
    string result = parseChargebackInfo(input);
    
    // Print the result
    cout << result;
    
    return 0;
}