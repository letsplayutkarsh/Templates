const int nax =  100001;
vector<set<int>> graph(nax);
vi parent(nax);
vi subtree(nax);

int dfs1(int node , int p){
	subtree[node] = 1;

	for(int u : graph[node]){
        if(u != p)
	       subtree[node] += dfs1(u , node);
    }

	return subtree[node];
}

int dfs(int node , int p , int n)
{
	for(auto u : graph[node]){
        if(u != p && subtree[u] > n/2)
            return dfs(u , node , n);
    }
	return node;
}

void decompose(int node , int p){

	int subTreeSize = dfs1(node , -1);
	int centroid = dfs(node , p , subTreeSize);

	parent[centroid] = p;
	for(auto u : graph[centroid]){
        graph[u].erase(centroid) ;
        decompose(u , centroid);
    }
}
