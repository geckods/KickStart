#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    	ll n,b;
    	cin>>n>>b;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);
    	int j=0;
    	ll tot=0;
    	while(j<n && tot<=b){
    		tot+=arr[j];
    		j++;
    	}
    	cout<<"Case #"<<test+1<<": "<<j-1<<endl;
    }

}
