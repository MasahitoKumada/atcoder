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
#define REP_IF(i,j,n) for(int i=j;i<(n);i++)


int main() {

	int N, X;
	cin >> N >> X;
	vector<int> A(N, 0);
	for(auto& v:A) cin >> v;
	vector<bool> J(N, false);

	int idx = X-1;
	while(J[idx] == false){
		J[idx] = true;
		idx = A[idx]-1;
	}

	int ans = 0;
	REP(i,N){
		if(J[i]) ans++;
	}

	cout << ans << endl;

	return 0;
}