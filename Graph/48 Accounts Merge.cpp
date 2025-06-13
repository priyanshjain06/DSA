
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std ;

class Solution {
public:
    class DisjointSet {
        vector<int> parent, size;
    public:
        DisjointSet(int n) {
            parent.resize(n); //REVIEW 
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int pu = findUPar(u), pv = findUPar(v);
            if (pu == pv) return;
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToNode;

        // Step 1: Map each email to its index, union accounts with shared emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToNode.find(email) == emailToNode.end()) {
                    emailToNode[email] = i;
                } else {
                    ds.unionBySize(i, emailToNode[email]);
                }
            }
        }

        // Step 2: Group emails by ultimate parent
        vector<string> mergedEmails[n];
        for (auto& [email, idx] : emailToNode) {
            int parent = ds.findUPar(idx);
            mergedEmails[parent].push_back(email);
        }

        // Step 3: Build answer
        vector<vector<string>> result;
        for (int i = 0; i < n; i++) {
            if (mergedEmails[i].empty()) continue;
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> merged = {accounts[i][0]};
            merged.insert(merged.end(), mergedEmails[i].begin(), mergedEmails[i].end());
            result.push_back(merged);
        }

        return result;
    }
};
