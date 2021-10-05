// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
 
using ll=long long;
using ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)


int main(){
    string s1,s2,s3,ans;
    string procedure;

    cin >> s1;
    cin >> s2;
    cin >> s3;
    cin >> procedure;


    REP(i,procedure.length()){
        if(procedure[i]=='1'){
            ans += s1;
        }else if(procedure[i]=='2'){
            ans += s2;
        }else{
            ans += s3;
        }
    }

    cout << ans << endl;


    return 0;
}