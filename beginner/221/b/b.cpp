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


int main(){

    string s,t;
    string _s;
    int flag = 1;

    cin >> s >> t;

    REP(i, s.size()-1){
        if(s[i]!=t[i]){
            flag = 0;
            break;
        }
    }

    if(flag==0){
        REP(i, s.size()-1){

            // initializes
            flag = 1; 
            _s = s;
            // swap
            auto tmp = _s[i];
            _s[i] = _s[i+1];
            _s[i+1] = tmp;
            // check
            REP(j, _s.size()){
                if(_s[j]!=t[j]){
                    flag = 0;
                    break;
                }
            }
            // cout << flag << endl;
            if(flag==1) break;
        }
    }

    if(flag==1){
        cout << "Yes" << endl;
        }
    else{
        cout << "No" << endl;
        }

    // cout << _s << endl;
    // cout << t << endl;


    return 0;
}