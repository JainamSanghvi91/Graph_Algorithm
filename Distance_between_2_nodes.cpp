#include<bits/stdc++.h>
#include <string>
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
 
struct node{
	int x,y;
};
 
vector<int> graph[200005];
vector<int> dist(200005,0);
int n,q,ind;
int dp[21][200001];
int visit[200005];

void dfs(int c,int par){
	if(c!=1){
		dp[0][c]=par;
	}
	for(auto v: graph[c]){
		if(v != par){
			dist[v]=dist[c]+1;
			dfs(v,c);
		}
	}
}
 
void lca(int a,int b){
	int p=a;
	int q=b;
	if(dist[a]>dist[b]){
		swap(a,b);
	}
	int d=dist[b]-dist[a];
	while(d>0){
		int jump=log(d)/log(2);
		b=dp[jump][b];
		d-=1<<jump;
	}
	if(a!=b){
		for(int i=ind;i>=0;i--){
			if(dp[i][a]!=-1 && dp[i][a]!=dp[i][b]){
				a=dp[i][a];
				b=dp[i][b];
			}
		}
		cout<<dist[p]+dist[q]-(2*dist[dp[0][a]])<<endl;
	}
	else{
		cout<<dist[p]+dist[q]-(2*dist[b])<<endl;
	}
	//cout<<dist[p]<<" "<<dist[q]<<" "<<dp[0][a]<<endl;
	
}

signed main(){
	FAST
	cin>>n>>q;
	ind = log(n)/log(2);
	dp[0][1]=-1;
	for(int i=2;i<=n;i++){
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
		//dp[0][i] = u;
	}
	dfs(1,1);
	for(int i=1;i<=ind;i++){
		for(int j=1;j<=n;j++){
			if(dp[i-1][j] == -1){
				dp[i][j]=-1;
				continue;
			}
			dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		lca(x,y);	
	}
}
