// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include <functional>
using namespace std;
 
using ll=long long;
using p_ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)


int main(){

  ll n,w;
  cin >> n >> w;
  vector<p_ii> v(n);
  for(auto &nx : v){
    cin >> nx.first >> nx.second;
  }
  sort(v.begin(), v.end(), greater<int>());

//   for(auto &nx : v) {
//       cout << nx.first << " " << nx.second << endl;
//       };

  ll res = 0;
  for(auto &nx : v){
    if(w==0) break;
    res += nx.first * min(w, nx.second);
    w -= min(w, nx.second);
  }
  cout << res << endl;


  return 0;
}