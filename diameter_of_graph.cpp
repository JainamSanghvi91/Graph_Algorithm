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
int vis[100001];

pair<int, int> bfs(int ind, vector<pair<int, int>> g[], int n){
	
	queue<int> q;
	map<int, int> mp;
	map<int, int> dist;
	mp[ind] = 1;
	q.push(ind);
	 
	while(!q.empty()){
		int head = q.front();
		q.pop();
		for(int i=0; i<g[head].size(); i++){
			if(!mp[g[head][i].first]){
				dist[g[head][i].first] = dist[head] + g[head][i].second;
				q.push(g[head][i].first);
				mp[g[head][i].first] = 1;
			}
		}
	}
	int maxi = 0, pos=0;
	for(auto it=dist.begin(); it!=dist.end(); it++){
		if(maxi < it->second){
			maxi = it->second;
			pos = it->first;
		}
	}
	return {pos, maxi};
}


signed main(){
	FAST
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> graph[100001];
		for(int i=0; i<n-1; i++){
		int a, b, wt;
		cin>>a>>b>>wt;
		graph[a].pb({b, wt});
		graph[b].pb({a, wt});
		
		}	
		pair<int, int> disFrom1 = bfs(1, graph, n);
		pair<int, int> disFromDist1 = bfs(disFrom1.first, graph, n);
		int maxi = disFromDist1.second, cost=0;
		if(maxi > 10000)
			cost = 10000;
		else if(maxi>1000)
			cost = 1000;
		else if(maxi>100)
			cost = 100;
		cout<<cost<<" "<<maxi<<"\n";
	}	
}
