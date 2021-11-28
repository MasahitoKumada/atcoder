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

	string s1, s2;
	cin >> s1 >> s2;



	if(s1[0]=='.' and s2[1]=='.'){
		cout << "No" << endl;
	}else if(s1[1]=='.' and s2[0]=='.'){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}

	
	return 0;
}