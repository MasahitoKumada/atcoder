// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include <cmath>
using namespace std;
 
using ll=long long;
using p_ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)



int main(){

    ll N;
    cin >> N;

    ll ans = 0;

    for(ll a_i=1; pow(a_i,3)<=N; a_i++){

        for(ll b_i=a_i; a_i*pow(b_i,2)<=N; b_i++){

            ans += N/a_i/b_i - b_i + 1;

        }
    }

    cout << ans << endl;


    return 0;
}