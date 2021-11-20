// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
 
using ll=long long;
using ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)


int main(){

    const int N = 1048576; // N = 2**20
    vector<ll> A(N, -1);
    ll Q;
    cin >> Q;
    vector<ll> t(Q), x(Q);
    // REP(i,Q) cin >> t[i] >> x[i];

    REP(i,Q){

        cin >> t[i] >> x[i];

        auto h = x[i];
        if(t[i] == 1){
            while(A[h % N] != -1){
                h++;
            }
            A[h % N] = x[i];
        }else{
            cout << A[x[i] % N] << endl;
        } 
    }

    return 0;
}