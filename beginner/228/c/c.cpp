// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
 
using ll=long long;
using p_ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)



int main(){

    int N,K;
    cin >> N >> K;
    vector<vector<int>> P(N, vector<int>(3, 0));
    vector<int> S(N, 0);
    REP(i,N){
        REP(j,3){
            cin >> P[i][j]; 
            S[i] += P[i][j];
        }
    }


    vector<int> indices(P.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&S](int i1, int i2) {
        return S[i1] > S[i2];
    });

    // REP(i,N) cout << S[i] << " ";
    // cout << endl;

    // REP(i,N) cout << indices[i] << " ";
    // cout << endl;

     REP(i,N){
         if(S[i]+300 >= S[indices[K-1]]){
             cout << "Yes" << endl;
         }else{
             cout << "No" << endl;
         }
     }


    return 0;
}