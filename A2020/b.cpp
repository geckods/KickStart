#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 50
#define MAXP 1500

ll dp[MAXN][MAXP];

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n,k,p;
    	cin>>n>>k>>p;
    	vector<ll> arr[n];
    	vector<ll> pref[n];

    	ll x;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<k;j++){
    			cin>>x;
    			arr[i].push_back(x);
    		}

    		pref[i].push_back(arr[i][0]);
    		for(int j=1;j<k;j++){
    			pref[i].push_back(arr[i][j]+pref[i][j-1]);
    		}
    	}

    	// ll dp[n][p+1];//taking j+1 elements
    	for(int i=0;i<n;i++){
    		for(int j=0;j<=p;j++){
    			dp[i][j]=0;
    		}
    	}

    	for(int j=1;j<=k;j++)dp[0][j]=pref[0][j-1];

    	for(int i=1;i<n;i++){
    		for(int j=1;j<=p;j++){
    			if(j>(i+1)*k)continue;
    			for(int z=max(j-k,0ll);z<=j;z++){
    				if(j-z>0)
	    				dp[i][j]=max(dp[i][j],dp[i-1][z]+pref[i][j-z-1]);
	    			else
	    				dp[i][j]=max(dp[i][j],dp[i-1][j]);
    			}
    			// cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    		}
    	}

    	cout<<"Case #"<<test+1<<": "<<dp[n-1][p]<<endl;
    }
}