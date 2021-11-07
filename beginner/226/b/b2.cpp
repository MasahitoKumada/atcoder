// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include <set>
using namespace std;
 
using ll=long long;
using p_ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP_IF(i,j,n) for(int i=j;i<(n);i++)


int main(){

    int N;
    cin >> N;
    set<vector<int>> st;
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;
        vector<int> v(L);
        for (auto& x : v) cin >> x;
        st.insert(v);
    }
    cout << st.size() << "\n";



    return 0;
}