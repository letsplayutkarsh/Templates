void bellman_ford(ll s, vll& d, vector<vpll> &adj ,vll &mark) {
    ll n = adj.size();
    d.assign(n, MAX);
    vector<ll> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<ll> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        if(cnt[v]>n+2){
            continue;
        }
        inqueue[v] = false;
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] >=n){
                        mark[to] = 1; // those are in -ve cycle
                        // d[to] = MAX;
                        // return false;  // negative cycle
                    }
                }
            }
        }
    }
    // return true;
}
