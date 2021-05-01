#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define double      long double
#define pb          push_back
#define pf          push_front
 
const int MOD = 1e9+7;
int inf=1e18;


signed main() 
{
	int n,m,q;
	cin>>n>>m>>q;
	int mat[n+1][n+1];
	for(int i=1;i<n+1;i++){
    	for(int j=1;j<n+1;j++){
    		mat[i][j]=inf;
    	}
    	mat[i][i]=0;
    }
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		mat[x][y]=min(mat[x][y],z);
    	mat[y][x]=min(mat[y][x],z);
	}
 	
	for(int k=1;k<n+1;k++){
    	for(int i=1;i<n+1;i++){
    		for(int j=1;j<n+1;j++){
    			mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
    		}
    	}
    }
    
	for(int i=0;i<q;i++){
 		int a,b;
		cin>>a>>b;
    	if(mat[a][b] >= inf){
    		cout<<-1<<endl;
		}else{
			cout<<mat[a][b]<<endl;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	} 
    
    return 0; 
} 

