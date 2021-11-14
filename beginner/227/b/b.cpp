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


int square(int a, int b){
    return 4*a*b + 3*a + 3*b;
}


int main(){

    int N;
    cin >> N;
    vector<int> S(N,0);
    REP(i,N) cin >> S[i]; 

    // REP(i,N) cout << S[i] << " "; 
    // cout << endl;

    bool flag = false;
    int ok = 0;

    REP(i, N){
        for(int a_j=1; a_j<=int(S[i]/2+3/8); a_j++){
            for(int b_j=int(S[i]/2+3/8); b_j>=1; b_j--){
                if(square(a_j, b_j)==S[i]){
                    flag = true;
                    // cout << S[i] << " " << a_j << " " << b_j << endl;
                    break;
                }      
            }
            if(flag){
                break;
            }
        }
        if(flag){
            ok++;
            flag = false;
        }

    }

    cout << N-ok << endl;

    return 0;
}