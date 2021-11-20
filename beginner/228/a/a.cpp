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

	int S, T, X;
	cin >> S >> T >> X;

	if(S < T){
		if(S <= X and X < T){
			cout << "Yes" << endl;
			return 0;
		}
		cout << "No" << endl;
	}else{
		if(S <= X or X < T){
			cout << "Yes" << endl;
			return 0;
		}
		cout << "No" << endl;
	}

	return 0;
}