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

    int x;
    cin >> x;

    if(x>=0 && x<40){
        cout << 40-x << endl;

    }else if(x>=40 && x<70){
        cout << 70-x << endl;

    }else if(x>=70 && x<90){
        cout << 90-x << endl;

    }else{
        cout << "expert" << endl;
    }
    return 0;
}