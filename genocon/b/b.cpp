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
#define REP2(i,n) for(int i=1;i<(n);i++)


// 参考: https://wagtail.cds.tohoku.ac.jp/coda/python/p-8-function-part2-sup-seq-alignment.html

int score(char a, char b){

    if((a=='A' && b=='A')||(a=='C' && b=='C')||(a=='G' && b=='G')||(a=='T' && b=='T')){
        return 1;
    }else if((a=='A' && b!='-')||(a=='C' && b!='-')||(a=='G' && b!='-')||(a=='T' && b!='-')){
        return -3;
    }
    return -5;
}


int main(){

    string s1,s2;
    cin >> s1 >> s2;

    const int row_idx = 2; 
    const int clm_idx = 1;

    vector<vector<int>> f(s1.length()+1,vector<int>(s2.length()+1,0));
    vector<vector<int>> l(s1.length()+1,vector<int>(s2.length()+1,0));

    REP(i,s1.length()+1) f[i][0] = -5*i, l[i][0] = row_idx;
    REP(j,s2.length()+1) f[0][j] = -5*j, l[0][j] = clm_idx;

    REP2(i,s1.length()+1){
        REP2(j,s2.length()+1){

            int a = f[i-1][j-1] + score(s1[i-1],s2[j-1]); // alignment
            int b = f[i-1][j]-5; // gap for i
            int c = f[i][j-1]-5; // gap for j

            f[i][j] = max({a,b,c});

            if(f[i][j]==a){
                l[i][j] = 0; // alignment
            }else if (f[i][j]==b){
                l[i][j] = row_idx; // gap for i
            }else{
                l[i][j] = clm_idx; // gap for j
            }
        }
    }

    // REP(i,s1.length()+1){
    //     REP(j,s2.length()+1){
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // REP(i,s1.length()+1){
    //     REP(j,s2.length()+1){
    //         cout << l[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    string ans_s1, ans_s2; 
    int i = s1.length();
    int j = s2.length();  

    while(i!=0 || j!=0){

        if(l[i][j] == row_idx){ // gap for i
            ans_s1 += "-";
            ans_s1 += s1[i-1];
            i--;
        }else if(l[i][j] == clm_idx){ // gap for j
            ans_s2 += s2[j-1];
            ans_s2 += "-";
            j--;
        }else{ // alignment
            ans_s1 += s1[i-1];
            ans_s2 += s2[j-1];
            i--;
            j--;
        }
        // cout << i << ", " << j << endl;
    }

    reverse(ans_s1.begin(), ans_s1.end());
    reverse(ans_s2.begin(), ans_s2.end());

    int val = ans_s1.length()-ans_s2.length();
    if(ans_s1.length() > ans_s2.length()){
        REP(i,val){
            ans_s2 += "-";
        }
    }else{
        REP(i,-val){
            ans_s1 += "-";
        }
    }

    cout << ans_s1 << endl;
    cout << ans_s2 << endl;

    return 0;
}