// Problem: Find Subtree Sizes After Changes
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/find-subtree-sizes-after-changes/
// Solved on: 2026-11-21T13:38:52.842Z


class Solution {
public:
    void solve(vector<int>& lcachar, int root,
               vector<vector<int>>& adj, string& s,
               vector<int>& ans) {

        // node, state, previous character's node
        stack<tuple<int,int,int>> st;
        st.push({root, 0, -1});

        while(!st.empty()) {
            auto [node, state, old] = st.top();
            st.pop();

            if(state == 0) {
                int num = lcachar[s[node]-'a'];

                if(num == -1) ans[node] = -1;
                else ans[node] = num;

                st.push({node, 1, num});

                lcachar[s[node]-'a'] = node;

                for(int i = adj[node].size()-1; i >= 0; i--) {
                    st.push({adj[node][i], 0, -1});
                }
            }
            else {
                lcachar[s[node]-'a'] = old;
            }
        }
    }

    void solveans(vector<vector<int>>& adjans, int root,
                  vector<int>& res) {

        vector<int> order;
        stack<int> st;
        st.push(root);

        // Get DFS traversal order
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            order.push_back(node);

            for(int child : adjans[node]) {
                st.push(child);
            }
        }

        // Process children before parents
        for(int i = order.size()-1; i >= 0; i--) {
            int node = order[i];

            res[node] = 1;

            for(int child : adjans[node]) {
                res[node] += res[child];
            }
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            if(parent[i] >= 0) {
                adj[parent[i]].push_back(i);
            }
        }

        vector<int> ans(n);
        vector<int> lcachar(26, -1);

        solve(lcachar, 0, adj, s, ans);

        vector<vector<int>> adjans(n);

        for(int i = 1; i < n; i++) {
            adjans[ans[i] == -1 ? parent[i] : ans[i]].push_back(i);
        }

        vector<int> res(n, -1);

        solveans(adjans, 0, res);

        return res;
    }
};
