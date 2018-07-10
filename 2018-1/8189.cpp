#include <bits/stdc++.h>

using namespace std;

bool vowel(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main(){
	string str;
	while(cin>>str){
		int idx = 0;
		int n=str.size();
		vector<int> vowels(n+10,0);	//cuantas vocales a mi izquierda?
		for(int i=0;i<n+1;i++){
			vowels[i]=idx;
			if(vowel(str[i])) idx++;	
		}
		int left=0,right=n-1;
		if(vowels[right+1]==0){	//solo consonantes, una sola forma
			//puts("klfjsdljfslkdf");
			puts("1");
			continue;
		}
		if(vowel(str[right]) && !vowel(str[left])){//imposible tener una al final si no hay otra al principio
			//puts("asdzsdasd");
			puts("0");
			continue;
		}
		if(vowels[0]==0 && vowels[right]==1 && vowel(str[right])){	//ab...ba
			printf("%d\n",right-left);
			continue;
		}
		bool direccion=true;
		bool murio=false;
		while(vowels[right+1]>vowels[left]+1){	//busco grupo de consonantes de "al medio"
			if(direccion){
				if(!vowel(str[left])){
					//puts("me mori2");
					murio=true;
					break;
				}else if(vowel(str[right])){
					left++;
					direccion=false;
				}else{
					right--;
				}
			}else{
				if(!vowel(str[right])){
					//puts("me mori1");
					murio=true;
					break;
				}else if(vowel(str[left])){
					right--;
					direccion=true;
				}else{
					left++;
				}
			}
		}
		if(murio){
			//puts("asdasd");
			puts("0");
		}else{
			printf("%d\n",right-left+1);
		}
	}	
	return 0;
}
//allllla
//lalllla

	//aaallllla
	//alllllaaa