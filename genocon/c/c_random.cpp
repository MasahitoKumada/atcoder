// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include <random>
#include <functional>
#include <limits>
#include <type_traits>
using namespace std;
 
using ll=long long;
using ii=pair<ll,ll>;
using is=pair<ll,string>;
 
#define REP(i,n) for(int i=0;i<(n);i++)


// 参考：　https://qiita.com/hmito/items/9f4bdc8442b6f6b3c7bc
mt19937 create_rand_engine(){
    random_device rnd;
    vector<uint_least32_t> v(10);// 初期化用ベクタ
    generate(v.begin(), v.end(), ref(rnd));// ベクタの初期化
    seed_seq seed(v.begin(), v.end());
    return mt19937(seed);// 乱数エンジン
}

vector<int> make_rand_array_unique(const size_t size, int rand_min, int rand_max){
    if(rand_min > rand_max) swap(rand_min, rand_max);
    const size_t max_min_diff = static_cast<size_t>(rand_max - rand_min + 1);
    if(max_min_diff < size) throw runtime_error("引数が異常です");

    vector<int> tmp;
    auto engine = create_rand_engine();
    uniform_int_distribution<int> distribution(rand_min, rand_max);

    const size_t make_size = static_cast<size_t>(size*1.2);

    while(tmp.size() < size){
        while(tmp.size() < make_size) tmp.push_back(distribution(engine));
        sort(tmp.begin(), tmp.end());
        auto unique_end = unique(tmp.begin(), tmp.end());

        if(size < distance(tmp.begin(), unique_end)){
            unique_end = next(tmp.begin(), size);
        }
        tmp.erase(unique_end, tmp.end());
    }

    shuffle(tmp.begin(), tmp.end(), engine);
    return move(tmp);
}



int count_most_str(string &str){

    int cnt_A = 0, cnt_T = 0, cnt_C = 0, cnt_G = 0;
    for (char str_i : str){
        if (str_i == 'A') cnt_A++;
        else if (str_i == 'T') cnt_T++;
        else if (str_i == 'C') cnt_C++;
        else cnt_G++;
    }   
    return max({cnt_A,cnt_T,cnt_C,cnt_G});
}

int c_sj(string &str){
    return str.length()-count_most_str(str);
}

bool comp(ii lhs, ii rhs) {
    return lhs.second < rhs.second;
}


int main(){


    int trial_num = 1000;
    int n;
    vector<is> ss, tmp_ss;
    vector<vector<is>> candidate_ss(trial_num,vector<is>());

    vector<ii> min_c_all;

    cin >> n;

    REP(i,n){
        string tmp;
        cin >> tmp; 
        is p(tmp.length(), tmp);
        ss.push_back(p);
    }

    // REP(i,n) cout << ss[i].first << ", " << ss[i].second<< endl;

    int max_length = 0;
    REP(i,n) if(max_length < ss[i].first) max_length = ss[i].first;
    REP(i,n) ss[i].first = max_length - ss[i].first;

    // REP(i,n) cout << ss[i].first << ", " << ss[i].second << endl;

    
    REP(k,trial_num){
        tmp_ss = ss;

        REP(i,n){
            auto randoms = make_rand_array_unique(tmp_ss[i].first, 0, max_length - tmp_ss[i].first);
            sort(randoms.begin(),randoms.end(),greater<int>());

            REP(j,randoms.size()){
                // cout << randoms[i] << " ";
                tmp_ss[i].second = tmp_ss[i].second.insert(randoms[j], "-"); 
                // cout << ss[i].second << endl;
            }
            tmp_ss[i].first = max_length - tmp_ss[i].second.length();

        } 

        // REP(i,n) cout << ss[i].first << ", " << ss[i].second << endl;

        candidate_ss[k] = tmp_ss;

        int c_all = 0;
        REP(j,max_length){ 
            string tmp_row_str;
            REP(i,n){
                tmp_row_str += tmp_ss[i].second[j];
            }
            c_all += c_sj(tmp_row_str);
        }
        // cout << c_all << endl;
        ii pp(k, c_all);
        min_c_all.push_back(pp);
    }

    // REP(k,trial_num) cout << min_c_all[k].first << ", " << min_c_all[k].second << endl;

    sort(min_c_all.begin(), min_c_all.end(), comp);

    // REP(k,trial_num) cout << min_c_all[k].first << ", " << min_c_all[k].second << endl;

    int k_min =  min_c_all[0].first;
    int c_min =  min_c_all[0].second;

    REP(i,n) cout << candidate_ss[k_min][i].second << endl;
    // cout << c_min << endl;

    // REP(k,trial_num)REP(i,n) cout << k << ", "<<candidate_ss[k][i].first << ", " << candidate_ss[k][i].second << endl;

    
    return 0;
}
