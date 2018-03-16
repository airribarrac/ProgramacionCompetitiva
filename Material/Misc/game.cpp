#include <bits/stdc++.h>
using namespace std;

string s;
int m;
void kmpPreprocess(vector<int> &b,vector<int> &P) { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    vector<bool> AAH(26,false);
    map<int,int> A;
  	while (i < m) { // pre-process the pattern string P
  		//cerr << "I: " << i << " J: "<<j<<endl;
    	while (j >= 0 && P[i] != P[j]){
    		if(P[j]==-1 /*&& A.count(P[i])==0*/ && P[i]>j){
    			break;
    		}
    		j = b[j];
    	}
    	A[P[i]] = i;
      AAH[s[i]-'a'] = true;
    	i++; j++; // if same, advance both pointers
    	//if(i==b.size()) cerr<<"aH"<<endl;;
    	b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
	}
}           // in the example of P = "SEVENTY SEVEN" above

int kmpSearch(vector<int> &b,vector<int> &P,int n,vector<int> &T) { // this is similar as kmpPreprocess(), but on string T
	int ans = 0;
    int i = 0, j = 0; // starting values
 	while (i < n) { // search through string T
    	while (j >= 0 && T[i] != P[j] ){
    		if((P[j]==-1 && T[i]>j)){
    			//cout << "I: "<<i<<" J:"<<j<<endl;
    			break;
    		}
    		j = b[j]; // if different, reset j using b
    	}
   		i++; j++; // if same, advance both pointers
    	if (j == m) { // a match found when j == m
  //    		printf("P is found at index %d in T\n", i - j);
    		ans++;
      		j = b[j]; // prepare j for the next possible match
      		//cout << "DESPUES I: "<<i<<" J:"<<j<<endl;
		}
	}
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//while(cin >> s){
	cin >> s;
		cin >> m;
		int contador = 1;
		map<char,int> AA;
		vector<int> Text(s.size()),Pat(m);
		for(int i=0;i<s.size();i++){
			if(AA.count(s[i])==0){
				Text[i]=-1;
			}
			else Text[i]=i-AA[s[i]];
			AA[s[i]]=i;
		}
		map<int,int> BB;
		for(int i=0;i<m;i++){
			int aux;
			cin >> aux;
			if(BB.count(aux)==0){
				Pat[i]=-1;
			}
			else Pat[i]=i-BB[aux];
			BB[aux]=i;
		}
		vector<int> b(1e6);
		kmpPreprocess(b,Pat);
    /*for(int i=0;i<m+1;i++){
      //if(b[i]==-1) cout << 0 << endl;
        cout <<"i: "<<i<<" B: "<< b[i] << endl;
    }*/
    /*cout << endl;
    cout << "M-1: "<< b[m-1]<<endl;
		/*
		cout << "T:" <<endl;
		for(int i=0;i<s.size();i++){
			cout << Text[i] << " ";
		}
		cout <<endl << "P: " << endl;
		for(int i=0;i<m;i++){
			cout << Pat[i] << " ";
		}
		cout << endl <<"B: " << endl;
		for(int i=0;i<m;i++){
			cout << b[i] << " ";
		}
		cout << endl;*/
		cout <<kmpSearch(b,Pat,s.size(),Text) << endl;
	//}

	return 0;
}
