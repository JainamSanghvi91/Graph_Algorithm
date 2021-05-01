#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define double      long double
#define pb          push_back
#define pf          push_front
 
const int MOD = 1e9+7;
const int inf=1e18;
 
bool isprime(int n){
	if(n==1) return false;
	for(int i = 2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
	
int lcm(int a,int b){
	return (a*b)/__gcd(a,b);
}
 
int gcd(int a, int b){ 
    if (b == 0){
    	return a;
	} 
    return gcd(b, a % b);  
      
} 

vector<int> graph[10005];
int parent[1005];
bool vis[10005],vis1[10005];
map<pair<int,int>,int>mp;

void dfs(int cur){
	vis[cur]=1;
	for(auto &i : graph[cur]){
		if(!vis[i]){
			dfs(i);
		}
	}
}

void dfs1(int cur){
	vis1[cur]=1;
	for(auto &i : graph[cur]){
		if(!vis1[i]){
			dfs1(i);
		}
	}
}

signed main(){
	FAST
	int n,m;
	cin>>n>>m;
 	
	vector<pair<pair<int,int>,int>> pr(m);
	for(int i=0;i<m;i++){
		cin>>pr[i].first.first>>pr[i].first.second>>pr[i].second;
		graph[pr[i].first.first].pb(pr[i].first.second);
	}	
	
	vector<int> dist(n+1,-inf);
	dist[1] = 0;
	
	vector<int> parent(n+1,-1);
	int cur;
	for(int i=0;i<n;i++){
		cur=-1;
		for(int j=0;j<m;j++){
			int u = pr[j].first.first;
			int v = pr[j].first.second;
			int w = pr[j].second;
			if(dist[v] < dist[u] + w){
				dist[v] = dist[u] + w;
				parent[v] = u;
				cur=v;
			}	
		}
	}
	
	if(cur == -1){
		cout<<"NO";
	}else{
		for (int i = 0; i < n; ++i)
            cur = parent[cur];

        vector<int> cycle;
        for (int v = cur;; v = parent[v]) {
            cycle.push_back(v);
            if (v == cur && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES"<<endl;
        for (int v : cycle)
            cout << v << ' ';
	}
	
}
