#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool testWorks(vector<ll> arr, ll target, ll count){
	for(int i=1;i<arr.size();i++){
		ll diff=arr[i]-arr[i-1];
		if(diff>target){
			ll needed=(diff-1)/target;
			count-=needed;
			if(count<0)return false;
		}
	}
	return true;
}


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
    	ll n,k;
    	cin>>n>>k;

    	vector<ll> arr;
    	ll x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		arr.push_back(x);
    	}

    	//binsearch on answer
    	ll bmin=1;
    	ll bmax=1e9;
    	while(bmin<bmax){
    		ll bmid=(bmin+bmax)/2;
    		if(testWorks(arr,bmid,k)){
    			bmax=bmid;
    		}
    		else{
    			bmin=bmid+1;
    		}
    	}

    	cout<<"Case #"<<test+1<<": "<<bmin<<endl;
    }
}