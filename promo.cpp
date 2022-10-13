#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main() {
	  ll n,q;
	  cin>>n>>q;
	  ll a[n];
	  for(ll i=0;i<n;i++){
		cin>>a[i];
	  }
	  sort(a,a+n);
	  ll b[n];
	  b[n-1]=a[n-1];
	  for(ll i=n-2;i>=0;i--){
           b[i]=b[i+1]+a[i];
	  }
	  while(q--){
		ll x,y;
		cin>>x>>y;
		if(x==y){
			cout<<b[n-x]<<"\n";
		}
		else{
			cout<<b[n-x]-b[n-x+y]<<"\n";
		}
	  }
	  
 
}