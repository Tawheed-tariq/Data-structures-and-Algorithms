class Solution {
    public:
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, string> emailToName;
    unordered_set<string> visited;

    void dfs(const string& email, vector<string>& emails) {
        if (visited.count(email)) return;
        visited.insert(email);
        emails.push_back(email);
        for (const string& neighbor : graph[email])
            dfs(neighbor, emails);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Build the graph
        for (auto& account : accounts) {
            string name = account[0];
            string firstEmail = account[1];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                graph[firstEmail].insert(email);
                graph[email].insert(firstEmail);
                emailToName[email] = name;
            }
        }

        vector<vector<string>> mergedAccounts;

        for (auto& [email, _] : graph) {
            if (!visited.count(email)) {
                vector<string> emails;
                dfs(email, emails);
                sort(emails.begin(), emails.end());
                emails.insert(emails.begin(), emailToName[email]); // add name
                mergedAccounts.push_back(emails);
            }
        }

        return mergedAccounts;
    }
};
