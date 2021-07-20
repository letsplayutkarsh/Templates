int dfsz(int u, int p, vi &sz, vi graph[]) {
    sz[u] = 1;
    for(auto v : graph[u]){
        if(v != p) {
            sz[u] += dfsz(v, u, sz, graph);
        }
    }
    return sz[u];
}
int centroid(int u, int p, int n, vi &sz, vi graph[]) {
    for(auto v : graph[u]){
        if(v != p) {
            if(sz[v] > n / 2){
                return centroid(v, u, n, sz, graph);
            }
        }
    }
    return u;
}
