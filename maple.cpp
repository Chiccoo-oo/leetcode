#include<bits/stdc++.h>
using namespace std;

struct S {
    int c, v, s;
    vector<int> o;
};

pair<int, vector<int>> f(int k, int x) {
    int i = 1 << k;
    int tc = x;
    int tv = (1 << (k + 1)) - x;
    
    if (i == tc) {
        return {0, {}};
    }
    
    queue<S> q;
    map<pair<int, int>, int> vis;
    
    q.push({i, i, 0, {}});
    vis[{i, i}] = 0;
    
    while (!q.empty()) {
        S cur = q.front();
        q.pop();
        
        if (cur.c == tc && cur.v == tv) {
            return {cur.s, cur.o};
        }
        
        auto sk = make_pair(cur.c, cur.v);
        if (vis.count(sk) && vis[sk] < cur.s) {
            continue;
        }
        
        if (cur.c % 2 == 0) {
            int nc = cur.c / 2;
            int nv = cur.v + cur.c / 2;
            auto nsk = make_pair(nc, nv);
            
            if (!vis.count(nsk) || vis[nsk] > cur.s + 1) {
                vis[nsk] = cur.s + 1;
                vector<int> no = cur.o;
                no.push_back(1);
                q.push({nc, nv, cur.s + 1, no});
            }
        }
        
        if (cur.v % 2 == 0) {
            int nc = cur.c + cur.v / 2;
            int nv = cur.v / 2;
            auto nsk = make_pair(nc, nv);
            
            if (!vis.count(nsk) || vis[nsk] > cur.s + 1) {
                vis[nsk] = cur.s + 1;
                vector<int> no = cur.o;
                no.push_back(2);
                q.push({nc, nv, cur.s + 1, no});
            }
        }
    }
    
    return {-1, {}};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int k, x;
        cin >> k >> x;
        
        auto r = f(k, x);
        
        cout << r.first << "\n";
        if (r.first > 0) {
            for (int i = 0; i < r.second.size(); i++) {
                if (i > 0) cout << " ";
                cout << r.second[i];
            }
            cout << "\n";
        }
    }
    
    return 0;
}