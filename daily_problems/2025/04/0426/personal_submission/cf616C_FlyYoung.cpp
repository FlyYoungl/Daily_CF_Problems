    #include <bits/stdc++.h>
    using namespace std;
	
	#define INF 0x3FFFFFFF
    #define int long long
    #define ull unsigned long long
    #define all(x)  (x).begin(), (x).end()
    #define all1(x)  (x).begin() + 1, (x).end()
    #define ed '\n' 
    #define sz size
    #define pb push_back
    #define vt vector
    #define For(i,a,b)  for (int i = (a); i < (b); i++)
    #define rep(i,a,b)  for (int i = (a); i <= (b); i++)
    #define pro priority_queue<int, vector<int>, greater<int> >
    #define TEST int t;  cin>>t;  while(t--)
    #define yes cout << "Yes" << '\n'
    #define no cout << "No" << '\n'
    #define UNIQUE(a)    a.erase(unique(a.begin(), a.end()), a.end())  
    typedef pair<int,int> PII;	
   	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    void debug() {cout<<"***" << endl;}
    const int mod = 1e9 + 7;
//    const int mod = 212370440130137957,  P = 233;
    // 2 ^ 29,  2 ^ 59
    //	Every problem is difficult for me---------------------------------------------------------

    // 1e3 * 1e3矩阵有 * 和 . 两种字符， 算出每个*周围.连通块大小之和
    // bfs即可
    void _705310JW() {
        int n, m;
        cin >> n >> m;
        vt<string> a(n + 1);
        vt<vt<int> > sz(n + 1, vt<int> (m + 1));
        vt<vt<int> > st(n + 1, vt<int> (m + 1));
        vt<vt<int> > id(n + 1, vt<int> (m + 1));
        vt<vt<int> > ans(n + 1, vt<int> (m + 1));

        int cnt = 1;
        rep(i,1,n) {
            cin >> a[i];
            a[i] = " " + a[i];
        }
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        rep(i,1,n) {
            rep(j,1,m) {
                if (a[i][j] == '.' && !st[i][j]) {
                    queue<PII> q;
                    vt<PII> tmp;
                    q.push({i,j});
                    tmp.pb({i,j});
                    st[i][j] = 1;
                    while(q.sz()) {
                        auto [x, y] = q.front();
                        for (int i = 0; i < 4; i++) {
                            int xx = x + dx[i];
                            int yy = y + dy[i];
                            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !st[xx][yy] && a[xx][yy] == '.') {
                                tmp.pb({xx, yy});
                                q.push({xx, yy});
                                st[xx][yy] = 1;
                            }
                        }
                        q.pop();
                    }
                    int l = tmp.sz();
                    for (auto [x, y] : tmp) {
                        id[x][y] = cnt;
                        sz[x][y] = l;
                    }
                    cnt++;
                }
            }
        }

        rep(i,1,n) {
            rep(j,1,m) {
                if (a[i][j] == '*') {
                    int res = 1;
                    map<int,int> vis;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.') {
                            if (!vis[id[x][y]]) {
                                vis[id[x][y]] = 1;
                                res += sz[x][y];
                            }
                        }
                    }
                    ans[i][j] = res;
                } else {
                    ans[i][j] = -1;
                }
            }
        }

        rep(i,1,n) {
            rep(j,1,m) {
                if (ans[i][j] != -1)  cout << ans[i][j] % 10;
                else cout << '.';
            }
            cout << ed;
        }
    }
    signed main() {
    	ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
        // TEST
        _705310JW();
        return 0;
    }
    



