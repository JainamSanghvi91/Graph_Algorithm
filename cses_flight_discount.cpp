#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define double      long double
#define pb          push_back
#define pf          push_front
 
const int MOD = 1e9+7;
const int inf=9e17;
 
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
 
vector<vector<pair<int,int>>> graph;
int visit[100005],visit1[100005];
int n,m;
vector<int> dist,disc;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;

signed main(){
	FAST
	cin>>n>>m;
	graph.resize(n+1);
	disc.resize(n+1);
	dist.resize(n+1);
	
	for(int i=0;i<m;i++){
		int u,v,d;
		cin>>u>>v>>d;
		graph[u].pb({v,d});
	}
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
	
	for(int i=1;i<=n;i++){
		dist[i] = inf;
		disc[i] = inf;
	}
	
	pq.push({0,{1,0}});
	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second.first;
		int flag = pq.top().second.second;
		pq.pop();
		
		if(flag == 1){
			if(disc[u] < d) continue;
		}
		
		if(flag == 0){
			if(dist[u] < d) continue;
		}
		
		for(auto e:graph[u]){
			int v = e.first;
			int c = e.second;
			
			if(flag == 0){
				if(dist[v] > c+d){
					dist[v] = c+d;
					pq.push({dist[v],{v,0}});
				}
				if(disc[v] > d+c/2){
					disc[v] = c/2+d;
					pq.push({disc[v],{v,1}});
				}
			}
			if(flag == 1){
				if(disc[v] > c+d){
					disc[v] = c+d;
					pq.push({disc[v],{v,1}});
				}
			}
		}
	}

	cout<<disc[n]<<endl;
}
