// Problem: Riptide
// Platform: codeforces
// Contest: CF
// Rating/Difficulty: CF
// Language: C++17
// Verdict: Accepted
// URL: https://codeforces.com/contest/2254/my
// Solved on: 2026-09-08T21:48:55.890Z

#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
 
    int ans = 0;
 
    while (a != b && b != c && a != c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
 
        v[0]++;  // smallest gets 1
        v[2]--;  // largest gives 1
 
        a = v[0];
        b = v[1];
        c = v[2];
 
        ans++;
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}