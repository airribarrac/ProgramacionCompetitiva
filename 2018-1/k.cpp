#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//este es de una rpc pero no recuerdo cual :(

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int m,n;
		scanf("%d",&m);
		char alfabeto[m];
		for(int j=0;j<m;j++){
			char aux;

			cin>>aux;
			//cout<<"lei "<<aux<<endl;
			alfabeto[j]=aux;
		}
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			ll aux;
			scanf("%lld",&aux);
			if(m==1){
				for(int k=0;k<aux;k++){
					printf("%c",alfabeto[0]);
				}
				puts("");
				continue;
			}


			string str="";
			aux--;
			ll pot=1,ll sum=0;
			int indicador = 0;
			while(sum>=0 && n-sum>0){
				sum+=pot;
				pot*=m;
				indicador++;
			}
			int base=m-1;
			while(aux){
				//printf("%d\n",aux );
				char agregar=alfabeto[aux%base];
				str.push_back(agregar);
				aux/=base;
				//cout<<"owo"<<endl;
			}
			cout<<str<<endl;
		}
	}
	return 0;
}