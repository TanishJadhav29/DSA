// Problem: B - Three Piles
// Platform: codeforces
// Contest: Contest-2266
// Language: C++17 (GCC 7-32)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2266/submission/391460513
// Solved on: 2026-09-21T15:50:27.999Z

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;cin>>a>>b>>c;
    int alicetake = abs(a+c-b);
    int bobtake = abs(b+c-a);
    int notake = abs(a-b);
    if(alicetake>notake){
        cout<<alicetake<<"\n";
    }else{
        cout<<min({bobtake,notake})<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << "\n";
    int t;cin>>t;while(t--)solve();
    return 0;
}