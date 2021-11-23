// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include <math.h>
using namespace std;
 
using ll=long long;
using p_ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)


int main() {
	ll N, L, R;
	cin >> N >> L >> R;
	vector<ll> x;

	// cout << N << " " << L << " " << R << endl;

	for(int i = L; i <= R; i++){
		x.push_back(i);
	}

	// REP(i,R-L+1) cout << x[i] << " ";

	ll ans = 0;
	for(auto& v:x){
		
		if ((v^N) < N){
			ans++;
		}


	}

	cout << ans << endl;

	return 0;
}