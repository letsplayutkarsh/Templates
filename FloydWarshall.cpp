vvll d(n, vll(n, MAX));
for(int i=0; i<m; i++){
    ll u,v,w;
    cin>>u>>v>>w;
    u--; v--;
    d[u][v] = min(d[u][v],w);
    d[v][u] = min(d[v][u],w);
}
ff(i,0,n){
    d[i][i] = 0;
}
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < MAX && d[k][j] < MAX)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
