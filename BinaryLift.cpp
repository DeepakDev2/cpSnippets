
struct BinaryLift{
	int k;
	vector<vector<int>> dp;
	vector<int> depth;
	int n;
	BinaryLift(int _n,vector<vector<int>> &adj,int root=1){
		k=0;
		n=_n;
		while((1ll<<k)<=_n){
			k++;
		}

		depth.resize(n+1);
		dp.resize(n+1);
		for(auto &i:dp){
			i.resize(k+1);
		}

		function<void(int,int,int)> dfs = [&](int node,int par,int d){
			dp[node][0]=par;
			depth[node]=d;
			for(int i=1;i<=k;i++){
				dp[node][i]= dp[dp[node][i-1]][i-1];
			}
			for(auto &it:adj[node]){
				if(it!=par){
					dfs(it,node,d+1);
				}
			}
		};
		dfs(root,0,0);
		depth[0]=0;
	}

	int getKthParent(int node,int t){
		// t-th parent of node
		if(t>(1<<k)){
			return 0;
		}
		int cnt=0;
		while(t){
			if(t&1){
				node=dp[node][cnt];
			}
			t>>=1;
			cnt++;
		}
		return node;
	}

	int getLCA(int node1,int node2){
		int d1 = depth[node1],d2 = depth[node2];
		// d2 is greater than d1;
		if(d1>d2){
			swap(d1,d2);
			swap(node1,node2);
		}
		int dist = d2-d1;
		node2 = getKthParent(node2,dist);
		if(node1==node2){
			return node1;
		}
		for(int i=k;i>=0;i--){
			if(dp[node1][i]!=dp[node2][i]){
				node1=dp[node1][i];
				node2=dp[node2][i];
			}
		}
		return dp[node1][0];
	}
};
