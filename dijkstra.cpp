vll d(n,LONG_LONG_MAX),p(n,-1);
d[0] = 0;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
q.push({0, 0});
while (!q.empty()) {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
        continue;

    for (auto edge : graph[v]) {
        ll to = edge.first;
        ll len = edge.second;

        if (d[v] + len < d[to]) {
            d[to] = d[v] + len;
            p[to] = v;
            q.push({d[to], to});
        }
    }
}
put(d);
