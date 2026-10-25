// Problem: Simplify Path
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/simplify-path/
// Solved on: 2026-10-25T05:48:33.928Z

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (temp == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else if (temp != "" && temp != ".") {
                    st.push(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};