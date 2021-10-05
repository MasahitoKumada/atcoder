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


int main(){

    int a,b;
    cin >> a >> b;

    if(a==b){
        cout << 1 << endl;
    }else if(a>b){
        auto diff = a-b;
        cout << int(pow(32,diff)) << endl;

    return 0;
    }
}