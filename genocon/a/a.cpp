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

    int n;
    cin >> n;
    
    REP(i,n){
        string genoseq, ans;
        cin >> genoseq;
        REP(i,genoseq.length()){
            if(genoseq[i]=='A'){
                ans +='T'; 
            }else if(genoseq[i]=='T'){
                ans +='A'; 
            }else if(genoseq[i]=='C'){
                ans +='G'; 
            }else{
                ans +='C'; 
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    } 



    return 0;
}