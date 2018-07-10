#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	while(cin>>str){
		int n = str.size();
		bool full=true;
		for(int i=0;i<n;i++){
			if(str[i]=='P'){
				full = false;
				break;
			}
		}
		if(full){
			printf("%d\n",n-1);
			continue;
		}
		vector<int> divisores;
		for(int i=2;i<=n/2;i++){
			if(n%i==0) divisores.push_back(i);
		}
		set<int> validos;
		for(int i=0;i<divisores.size();i++){
			int div = divisores[i];
			int lim = n/div;
			for(int j=0;j<div;j++){
				bool work = true;
				int pos = j+div;
				if(str[j]=='P'){
					work=false;
				}
				while(pos!=j){
					if(str[pos]=='P'){
						work=false;
						break;
					}
					pos = (pos+div)%n;
				}
				if(work){
					//printf("entra %d desde pos %d\n",div,j);
					for(int k=div;k<n;k+=div){
						validos.insert(k);
					}
				}
			}
		}

		printf("%d\n",validos.size());
	}
	return 0;
}