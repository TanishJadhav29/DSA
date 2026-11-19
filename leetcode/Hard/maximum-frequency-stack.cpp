// Problem: Maximum Frequency Stack
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximum-frequency-stack/
// Solved on: 2026-11-19T17:41:04.755Z

class FreqStack {
public:
    set<tuple<int, int, int>> st;
    unordered_map<int, int> freq;
    unordered_map<int, int> lastIdx;

    vector<int> nums;
    vector<int> prevIdx;

    FreqStack() {
        st.clear();
        freq.clear();
        lastIdx.clear();
        nums.clear();
        prevIdx.clear();
    }

    void push(int val) {
        int idx = nums.size();
        int prev = -1;

        if (freq[val] > 0) {
            int oldIdx = lastIdx[val];

            st.erase({freq[val], oldIdx, val});

            prev = oldIdx;
        }

        freq[val]++;

        nums.push_back(val);
        prevIdx.push_back(prev);

        lastIdx[val] = idx;

        st.insert({freq[val], idx, val});
    }

    int pop() {
        auto it = st.rbegin();

        int f = get<0>(*it);
        int idx = get<1>(*it);
        int val = get<2>(*it);

        st.erase({f, idx, val});

        freq[val]--;

        if (freq[val] > 0) {
            int newIdx = prevIdx[idx];

            lastIdx[val] = newIdx;

            st.insert({freq[val], newIdx, val});
        } 
        else {
            freq.erase(val);
            lastIdx.erase(val);
        }

        return val;
    }
};