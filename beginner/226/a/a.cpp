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

	float X;
    cin >> X;

    if(int((X-int(X))*10) >= 5){
		cout << int(X)+1;
	}else{
		cout << int(X);
	}


	return 0;
}