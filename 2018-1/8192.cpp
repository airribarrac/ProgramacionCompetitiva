#include <bits/stdc++.h>

using namespace std;

string s;
int n;
char dp[1010][1010];
char solve(int pos, int mod){
	if(pos==s.size()){
		// printf("modulo %d\n",mod );
		return (mod==0)	;
	}
	if(dp[pos][mod]!=-1) return dp[pos][mod];
	
	if(pos==0 && s[0]=='?'){
		for(int i=1;i<10;i++){
			if(solve(pos+1,(mod*10+i)%n)){
			//	printf("puse un %d\n",i);
				s[pos]='0'+i;
				return dp[pos][mod]=1;
			}
		}	
		return dp[pos][mod]=0;	
	}else if(s[pos]=='?'){
		for(int i=0;i<10;i++){
			if(solve(pos+1,(mod*10+i)%n)){
				s[pos]='0'+i;
				return dp[pos][mod]=1;
			}
		}
		return dp[pos][mod]=0;
	}else{
		//printf("puse un %d\n",s[pos]-'0');
		return dp[pos][mod]=solve(pos+1,(mod*10+s[pos]-'0')%n);
	}
}

int main(){
	while(cin>>s>>n){
		for(int i=0;i<s.size();i++){
			for(int j=0;j<n;j++){
				dp[i][j]=-1;
			}
		}
		int ans = solve(0,0);
		if(ans){
			cout<<s<<endl;
		}else{
			puts("*");
		}
	}
}