#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,aux;
	while(scanf("%d %d",&k,&n)!=EOF){
		vector<int> rep(k+3,0);
		for(int i=0;i<n;i++){
			scanf("%d",&aux);
			rep[aux]++;
		}
		int m=(n+1)/k;	//numero promedio correcto
		bool plus=false,minus=false,work=true;
		int quita=0,agrega=0;
		for(int i=1;i<=k;i++){
			if(rep[i]==m){
				continue;
			}else if(rep[i]==m-1){
				if(plus){
					work=false;
					break;
				}
				agrega=i;
				//puts("gua");
				plus=true;
			}else if(rep[i]==m+1){
				if(minus){
					work=false;
					break;
				}
				//puts("eo");
				quita=i;
				minus=true;
			}else{
				work=false;
				break;
			}
		}
		if(work){
			if(plus && minus){
				printf("-%d +%d\n",quita,agrega);
			}else if(minus){
				printf("-%d\n",quita);
			}else if(plus){
				printf("+%d\n",agrega );
			}
		}else{
			puts("*");
		}
	}
	return 0;
}