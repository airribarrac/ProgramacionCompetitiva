#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll d;
	cin>>d;
	vector<ll> price;
	ll cuantos=0;
	bool bajo = true;
	ll anterior, actual;
	cin>>anterior;
	price.push_back(anterior);
	for(int i=1;i<d;i++){
		cin>>actual;
		if(bajo){
			if(actual<price.back()){
				price.pop_back();
				price.push_back(actual);
			}else{
				price.push_back(actual);
				bajo=false;
			}
		}else{
			if(actual>price.back()){
				price.pop_back();
				price.push_back(actual);
			}else{
				price.push_back(actual);
				bajo=true;
			}
		}
	}
	ll plata=100,acciones=0;
	for(int i=0;i<(price.size()/2)*2;i++){
		if(i%2==0){	//compro acciones
			ll compra = plata/price[i];
			compra = min(compra,(ll)100000);
			plata-= compra*price[i];
			acciones += compra;
		}else{		//vendo acciones
			plata += acciones*price[i];
			acciones = 0;
		}
	}
	cout<<plata+acciones*price.back()<<endl;	//vendo si es que compre
	return 0;
}