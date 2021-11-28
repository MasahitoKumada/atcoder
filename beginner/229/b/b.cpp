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

	ll A, B;
	cin >> A >> B;

	ll a=A, b=B;
	while(a > 0 or b > 0){

		auto a_ = a%10;
		auto b_ = b%10;
		if(a_ + b_ >= 10){
			cout << "Hard" << endl;
			return 0;
		}
		a /= 10;
		b /= 10;
		// cout << a << endl;
		// cout << b << endl;
	}

	cout << "Easy" << endl;





	return 0;
}