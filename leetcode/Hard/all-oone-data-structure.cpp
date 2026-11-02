// Problem: All O`one Data Structure
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/all-oone-data-structure/
// Solved on: 2026-11-02T16:10:32.727Z

class AllOne {
public:
    map<string, int> mp;
    set<pair<int, string>> st;

    AllOne() {
        mp.clear();
        st.clear();
    }

    void inc(string key) {

        if (mp.find(key) != mp.end()) {
            st.erase({mp[key], key});

            mp[key]++;

            st.insert({mp[key], key});
        }
        else {
            mp[key] = 1;
            st.insert({1, key});
        }
    }

    void dec(string key) {

        if (mp.find(key) == mp.end()) return;

        st.erase({mp[key], key});

        mp[key]--;

        if (mp[key] == 0) {
            mp.erase(key);
        }
        else {
            st.insert({mp[key], key});
        }
    }

    string getMaxKey() {
        if (st.empty()) return "";
        return st.rbegin()->second;
    }

    string getMinKey() {
        if (st.empty()) return "";
        return st.begin()->second;
    }
};