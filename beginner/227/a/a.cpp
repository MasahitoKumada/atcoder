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
    int N, K, A;
    cin >> N >> K >> A;
    
    int cnt = 0;
    A --; 
    while(cnt < K){
        
        if(A == N){
            A = 1;
        }else{
            A++;
        }
        cnt++;

        // cout << A << endl;

    }

    cout << A << endl;


	return 0;
}