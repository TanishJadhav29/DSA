// Problem: Valid Parentheses
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/valid-parentheses/
// Solved on: 2026-09-14T20:34:37.629Z

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                if (st.empty())
                    return false;

                if (ch == ')' && st.top() != '(')
                    return false;

                if (ch == '}' && st.top() != '{')
                    return false;

                if (ch == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};