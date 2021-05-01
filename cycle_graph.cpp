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

struct node{
	int x,y;
};
deque<node> d;

vector<int> graph[100005];
int parent[100005];
int visit[100005],color[100005];
bool check;
void dfs(int x,int c){
	visit[x] = 1;
	parent[x] = c;
	for(auto &i : graph[x]){
		if(!visit[i]){
			cout<<i<<" "<<x<<endl;
			dfs(i,x);
		}else if(i != c){
			vector<int> cycle;
			int current = x;
			cycle.pb(x);
			
			while(parent[current] != i){
				current = parent[current];
				cycle.pb(current);
			}
			
			cycle.pb(i);
			cycle.pb(x);
			
			cout<<cycle.size()<<endl;
			for(auto &ans: cycle){
				cout<<ans<<" ";
			}
			exit(0);
		}
	}
}


signed main(){
	FAST
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i,-1);
		}
	}
	cout<<"IMPOSSIBLE";
}
