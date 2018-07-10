#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll n,p;
	cin>>n>>p;
	ll x = n/(p-1);
	double pos = (double)(x*p)/(double)(n+1);
	for(int i=2;i<=x;i++){
		pos *= (double)(n-p+i)/(double)(n+i);
	}
	printf("%.9lf\n",pos);
	return 0;
}