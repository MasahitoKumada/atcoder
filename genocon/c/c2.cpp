#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::endl;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;
using p_ii = std::pair<int,int>;

void solve()
{
	int m; cin >> m;
	std::vector<std::string> vs_(m);
	
	for (int i = 0; i < m; ++i)
	{
		cin >> vs_[i];
	}

    int id_m = 1;
    // cout <<  vs_[0].size() << endl;
    if( vs_[0].size() > 100){
        id_m = 1;
    }
   

    std::vector<int> max_dps(id_m,0);

    for (int id = 0; id < id_m; ++id)
    {
        auto vs = vs_;

        for (int kkt = 88; kkt <= 89; kkt++)
        {
            
            std::vector<std::vector<int>> dp, kkt89_cute;
            std::string s,t;
            for (int jupi = 0; jupi < m; ++jupi)
            {

                if(jupi == id)
                    continue;
                s = vs[jupi];
                t = vs[id];
                dp.clear(); dp.resize(s.size() + 1, std::vector<int>(t.size() + 1, inf));
                kkt89_cute.clear(); kkt89_cute.resize(s.size() + 1, std::vector<int>(t.size() + 1, inf));
                dp[0][0] = 0;
                for (int i = 0; i <= (int)s.size(); ++i)
                {
                    for (int j = 0; j <= (int)t.size(); ++j)
                    {
                        if(i + 1 <= (int)s.size() and j + 1 <= (int)t.size())
                        {
                            if(s[i] == t[j] and chmin(dp[i + 1][j + 1], dp[i][j]))
                            {
                                kkt89_cute[i + 1][j + 1] = 0;
                            }
                            if(chmin(dp[i + 1][j + 1], dp[i][j] + 1))
                            {
                                kkt89_cute[i + 1][j + 1] = 0;
                            }
                        }
                        if(kkt != 89)
                        {
                            if(i + 1 <= (int)s.size())
                            {
                                if(chmin(dp[i + 1][j], dp[i][j] + 1))
                                {
                                    kkt89_cute[i + 1][j] = 1;
                                }
                            }
                        }
                        if(j + 1 <= (int)t.size())
                        {
                            if(chmin(dp[i][j + 1], dp[i][j] + 1))
                            {
                                kkt89_cute[i][j + 1] = 2;
                            }
                            if(t[j] == '-' and chmin(dp[i][j + 1], dp[i][j]))
                            {
                                kkt89_cute[i][j + 1] = 2;
                            }
                        }
                    }
                }

                std::string rest, ress;
                int sid = (int)s.size(), tid = (int)t.size();
                while (sid > 0 or tid > 0)
                {
                    if(kkt89_cute[sid][tid] == 0)
                    {
                        rest += t[tid - 1];
                        ress += s[sid - 1];
                        sid -= 1, tid -= 1;
                    }
                    else if(kkt89_cute[sid][tid] == 1)
                    {
                        rest += '-';
                        ress += s[sid - 1];
                        sid -= 1;
                    }
                    else
                    {
                        rest += t[tid - 1];
                        ress += '-';
                        tid -= 1;
                    }
                }
                std::reverse(ress.begin(), ress.end());
                std::reverse(rest.begin(), rest.end());
                std::swap(vs[id], rest);
                std::swap(vs[jupi], ress);

            }
            
            if(kkt != 89){
                int max_dp = 0;
                for (int i = 0; i <= (int)s.size(); ++i){
                    for (int j = 0; j <= (int)t.size(); ++j){
                        if(max_dp < dp[i][j] and max_dp != inf){
                            max_dp = dp[i][j];
                            // cout << max_dp << endl;
                        }
                    }
                }
                // cout << max_dp << endl;
                max_dps[id] = max_dp;

            }

        }

    }

    int max_dps_val = 0;
    for(int i=0; i<id_m; i++){
        if(max_dps_val < max_dps[i]){
            max_dps_val = max_dps[i];
            
        }
        
    }
    // cout << max_dps_val << endl;

    int max_id = 0;
    for(int i=0; i<id_m; i++){
        if(max_dps[i] == max_dps_val){
            max_id = i;
            break;
        }
    }

    // cout << max_id << endl;


    for (int kkt = 88; kkt <= 89; kkt++)
    {
        std::vector<std::vector<int>> dp, kkt89_cute;
        std::string s,t;
        for (int jupi = 0; jupi < m; ++jupi)
        {
            if(jupi == max_id)
                continue;
            s = vs_[jupi];
            t = vs_[max_id];
            dp.clear(); dp.resize(s.size() + 1, std::vector<int>(t.size() + 1, inf));
            kkt89_cute.clear(); kkt89_cute.resize(s.size() + 1, std::vector<int>(t.size() + 1, inf));
            dp[0][0] = 0;
            for (int i = 0; i <= (int)s.size(); ++i)
            {
                for (int j = 0; j <= (int)t.size(); ++j)
                {
                    if(i + 1 <= (int)s.size() and j + 1 <= (int)t.size())
                    {
                        if(s[i] == t[j] and chmin(dp[i + 1][j + 1], dp[i][j]))
                        {
                            kkt89_cute[i + 1][j + 1] = 0;
                        }
                        if(chmin(dp[i + 1][j + 1], dp[i][j] + 1))
                        {
                            kkt89_cute[i + 1][j + 1] = 0;
                        }
                    }
                    if(kkt != 89)
                    {
                        if(i + 1 <= (int)s.size())
                        {
                            if(chmin(dp[i + 1][j], dp[i][j] + 1))
                            {
                                kkt89_cute[i + 1][j] = 1;
                            }
                        }
                    }
                    if(j + 1 <= (int)t.size())
                    {
                        if(chmin(dp[i][j + 1], dp[i][j] + 1))
                        {
                            kkt89_cute[i][j + 1] = 2;
                        }
                        if(t[j] == '-' and chmin(dp[i][j + 1], dp[i][j]))
                        {
                            kkt89_cute[i][j + 1] = 2;
                        }
                    }
                }
            }

            std::string rest, ress;
            int sid = (int)s.size(), tid = (int)t.size();
            while (sid > 0 or tid > 0)
            {
                if(kkt89_cute[sid][tid] == 0)
                {
                    rest += t[tid - 1];
                    ress += s[sid - 1];
                    sid -= 1, tid -= 1;
                }
                else if(kkt89_cute[sid][tid] == 1)
                {
                    rest += '-';
                    ress += s[sid - 1];
                    sid -= 1;
                }
                else
                {
                    rest += t[tid - 1];
                    ress += '-';
                    tid -= 1;
                }
            }
            std::reverse(ress.begin(), ress.end());
            std::reverse(rest.begin(), rest.end());
            std::swap(vs_[max_id], rest);
            std::swap(vs_[jupi], ress);


        }

    }


	for (int i = 0; i < m; ++i)
	{
		cout << vs_[i] << "\n";
	}


}

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int kkt = 1; 
  // cin >> kkt;
  while(kkt--)
    solve();
  return 0;
  
}