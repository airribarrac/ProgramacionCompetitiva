// Ivan Carvalho
// Emission Spectrum - ICPC Latin American Regional – 2016
//O(n*log(n))
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> val,dir,esq,reverso,entrada;
int raiz[MAXN],vetor[MAXN],n,m,segIt,tam;
void update(int novo,int velho,int left,int right,int x){
	if(left == right){
		val[novo] = val[velho] + 1;
		return;
	}
	int mid = (left+right)/2;
	if(x <= mid){
		segIt++;
		esq.push_back(0);
		dir.push_back(0);
		val.push_back(0);
		esq[novo] = segIt;
		dir[novo] = dir[velho];
		val[novo] = val[velho] + 1;
		update(esq[novo],esq[velho],left,mid,x);
	}
	else{
		segIt++;
		esq.push_back(0);
		dir.push_back(0);
		val.push_back(0);
		esq[novo] = esq[velho];
		dir[novo] = segIt;
		val[novo] = val[velho] + 1;
		update(dir[novo],dir[velho],mid+1,right,x);
	}
}
int kth(int a,int b,int left,int right,int count){
	if(left == right){
		return left;
	}
	int mid = (left+right)/2;
	int davez = val[esq[a]] - val[esq[b]];
	if(count <= davez) return kth(esq[a],esq[b],left,mid,count);
	return kth(dir[a],dir[b],mid+1,right,count - davez);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&vetor[i]);
		entrada.push_back(vetor[i]);
	}
	reverso.push_back(0);
	sort(entrada.begin(),entrada.end());
	unique(entrada.begin(),entrada.end());
	tam = (int)entrada.size();
	for(int i = 0;i < entrada.size();i++){
		reverso.push_back(entrada[i]);
	}
	for(int i=1;i<=n;i++){
		vetor[i] = lower_bound(entrada.begin(),entrada.end(),vetor[i]) - entrada.begin() + 1;
	}
	dir.push_back(0);
	esq.push_back(0);
	val.push_back(0);
	raiz[0] = 0;
	for(int i=1;i<=n;i++){
		dir.push_back(0);
		esq.push_back(0);
		val.push_back(0);
		raiz[i] = ++segIt;
		update(raiz[i],raiz[i-1],1,tam,vetor[i]);
	}
	while(m--){
		char op;
		scanf(" %c",&op);
		if(op == 'Q'){
			int l,r,count;
			scanf("%d %d %d",&l,&r,&count);
			printf("%d\n",reverso[kth(raiz[r],raiz[l-1],1,tam,count)]);
		}
		else{
			int p;
			scanf("%d",&p);
			esq.push_back(0);
			dir.push_back(0);
			val.push_back(0);
			raiz[p] = ++segIt;
			swap(vetor[p],vetor[p+1]);
			update(raiz[p],raiz[p-1],1,tam,vetor[p]);
		}
	}
	return 0;
}