#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int n,m,q;
struct linea{
	int x1,y1,x2,y2;
};

int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct linea lines[1010];
bool visited[1010][1010];
int mat[1010][1010];


class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
	setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
	p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {	
	if (!isSameSet(i, j)) { numSets--;	
	int x = findSet(i), y = findSet(j);
	// rank is used to keep the tree short
	if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
	else							 		 { p[x] = y; setSize[y] += setSize[x];
														 if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

UnionFind uf(1000*1000);
inline bool valid(int x,int y){
	return x>=0 && x<n && y>=0 && y<m;
}

int main(){
	for(int i=0;i<1010;i++)
		for(int j=0;j<1010;j++){
			visited[i][j]=false;
			mat[i][j]=0;
		}
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<q;i++){
		scanf("%d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
		lines[i].y1--;
		lines[i].y2--;
		lines[i].x1--;
		lines[i].x2--;
		if(lines[i].x1==lines[i].x2){
			for(int j=lines[i].y1;j<=lines[i].y2;j++){
        //printf("actualizo (%d,%d)\n",lines[i].x1,j);
				visited[lines[i].x1][j]=true;
				if(mat[lines[i].x1][j]==0) mat[lines[i].x1][j]=i+1;
			}
		}else{
			for(int j=lines[i].x1;j<=lines[i].x2;j++){
        //printf("actualizo (%d,%d)\n",j,lines[i].y1);
				visited[j][lines[i].y1]=true;
				if(mat[j][lines[i].y1]==0) mat[j][lines[i].y1]=i+1;
			}
		}
	}
  
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j] && valid(i+1,j) && !visited[i+1][j]) uf.unionSet(j*n+i+1,j*n+i);
			if(!visited[i][j] && valid(i,j+1) && !visited[i][j+1]) uf.unionSet((j+1)*n+i,j*n+i);
		}
	}
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!visited[i][j] && uf.findSet(j*n+i)==j*n+i){
        ans++;
        //printf("componente en %d,%d\n",j,i);
      }
    }
  }
  //printf("componentes %d\n",ans);
  stack<int> answers;
  for(int z=q-1;z>=0;z--){
    //printf("parte %d\n",z);
    
    answers.push(ans);
    struct linea l = lines[z];  
    if(l.x1==l.x2){
      for(int j=l.y1;j<=l.y2;j++){
        //printf("toco (%d,%d) con valor %d\n",l.x1,j,mat[l.x1][j] );
        if(mat[l.x1][j]==z+1){  //aqui se actualizo por primera vez
          //mat[l.x1][j]=0;
          //printf("  descubro (%d,%d)\n",l.x1,j );
          visited[l.x1][j]=false;
          ans++;              //descubro pieza = nuevo potencial componente
          for(int k=0;k<4;k++){ //uno con vecinos
            int x=l.x1+move[k][0];
            int y=j+move[k][1];
            if(!valid(x,y) || visited[x][y]) continue;
            if(!uf.isSameSet(j*n+l.x1,y*n+x)){  //se deben unir
              ans--;
              uf.unionSet(j*n+l.x1,y*n+x);
            }
          }
        }
      }
    }else{
      for(int j=l.x1;j<=l.x2;j++){  //y estatico, x se mueve
        //printf("toco (%d,%d) con valor %d\n",j,l.y1,mat[j][l.y1] );
        if(mat[j][l.y1]==z+1){  //aqui se actualizo por primera vez
          //printf("  descubro (%d,%d)\n",j,l.y1 );
          //mat[j][l.y1]=0;
          visited[j][l.y1]=false;
          ans++;              //descubro pieza = nuevo potencial componente
          for(int k=0;k<4;k++){ //uno con vecinos
            int y=l.y1+move[k][1];
            int x=j+move[k][0];
            if(!valid(x,y) || visited[x][y]) continue;
            if(!uf.isSameSet(l.y1*n+j,y*n+x)){  //se deben unir
              ans--;
              uf.unionSet(l.y1*n+j,y*n+x);
            }
          }
        }
      }
    }
    
  }

  while(!answers.empty()){
    printf("%d\n",answers.top());
    answers.pop();
  }
  return 0;
}