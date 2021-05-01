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

int dist[100001];
int vis[100001],visit[100001],parent[100001];
vector<int> graph[100001];
vector<int> ans;
stack<int> st;
bool cycle = false;

void dfs(int p){
	if(vis[p]!=-1)
		return;
	
	vis[p]=1;
	for(int aa:graph[p]){
		if(vis[aa]==1){
			cycle=true;
		}
		else if(vis[aa]==-1){
			dfs(aa);
		}
		if(cycle)
			return;
	}
 
	vis[p]=2;
	ans.pb(p);
	return ;
}


signed main(){
	FAST
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		graph[a].pb(b);
	}	
	memset(vis,-1,sizeof(vis));
	
	for(int i=1;i<=n;i++){
		if(vis[i]==-1){
			dfs(i);
		}
	}
	
	
	if(cycle){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	reverse(ans.begin(),ans.end());
	for(auto x: ans){
		cout<<x<<" ";
	}
}
