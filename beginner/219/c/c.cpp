// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include <functional>
using namespace std;
 
using ll=long long;
using ii=pair<ll,ll>;
 
#define REP(i,n) for(int i=0;i<(n);i++)

string dict;


bool sort_dict(string a, string b){

    int len = min(a.length(), b.length());
    REP(i,len){
        // cout << dict.rfind(a[i]) << " " << dict.rfind(b[i])  << endl;
        if(dict.rfind(a[i]) < dict.rfind(b[i])){
            return true;
        }else if(dict.rfind(a[i]) > dict.rfind(b[i])){
            return false;
        }
    }
    return a == b;
}


int main(){
    int n;
    vector<string> ary;

    cin >> dict;
    cin >> n;
    REP(i,n){
        string tmp;
        cin >> tmp;
        ary.push_back(tmp);
    }

    sort(ary.begin(), ary.end(), sort_dict); 

    REP(i,n) cout << ary[i] << endl;
    


    return 0;
}