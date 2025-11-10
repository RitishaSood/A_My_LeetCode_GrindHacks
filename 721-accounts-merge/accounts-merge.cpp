#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) { parent[find(a)] = find(b); }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        unordered_map<string, int> emailToAcc;
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToAcc.count(email))
                    unite(i, emailToAcc[email]);
                else
                    emailToAcc[email] = i;
            }

        unordered_map<int, vector<string>> merged;
        for (auto& [email, i] : emailToAcc)
            merged[find(i)].push_back(email);

        vector<vector<string>> res;
        for (auto& [i, emails] : merged) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[i][0]);
            res.push_back(move(emails));
        }
        return res;
    }
};
