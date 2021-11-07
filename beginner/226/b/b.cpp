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

    int N; 
    cin >> N;
    vector<int> L(N,0);
    int N_COLS = 200000;
    vector<vector<int>> a(N, vector<int>(N_COLS, 0));

    REP(i,N){
        cin >> L[i];
        REP(j,L[i]){
            cin >> a[i][j];
        }
    }

    int ans = N;
    REP(i,N-1){
        REP_IF(j,i+1,N){
            if (L[i]==L[j]){
                bool flag = true;
                REP(k,L[i]){
                    if (a[i][k]!=a[j][k]){
                        flag = false;
                    }
                }
                if (flag){
                    ans--;
                }
            }
            // cout << i << " " << j << endl;
            // cout << a[i][0] << " " << a[j][0] << endl;
            // cout << a[i][1] << " " << a[j][1] << endl;

        }

    }

    cout << ans << endl;


    return 0;
}