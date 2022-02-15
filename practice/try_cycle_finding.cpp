#include<bits/stdc++.h>
using namespace std;
int N,m;
int result=0;
int c=0,d=0;
int graph[50][50],parent[20];
int state[20];
int cycle[10][10];
void dfs(int u){

    for(int i=0;i<N;i++)
    {
      if(graph[u][i]&&state[u]!=2&&i!=parent[u])
      {
          state[u]=1;

          if(state[i]==1&&i!=parent[u]){
              result++;
              
              int x=u;

              cout<<i<<"<---";
              cout<<x<<"<---";
              cycle[c][d++]=x;
              while (x!=i)
              {
                  
                  x = parent[x];
                  cycle[c][d++]=x;
                   cout<<x<<"<---";
                  
                  
              }
              cout<<endl;
              
          }
          else if(state[i]==0)
         {
             state[i]=1;
             parent[i]=u;
             dfs(i);

         }

      }
    }

    state[u]=2;
    c++;
    return;




}



int main()
{
    cin>>N>>m;
    int x,y;
    for(int i=0;i<10;i++){
        
        for(int j=0;j<=10;j++){
            cycle[i][j]=-1;
        }
        
    }



     
    for(int i=0;i<m;i++){
            cin>>x>>y;
            x--;y--;
            graph[x][y]=1;
            graph[y][x]=1;
    }

    for(int i=0;i<N;i++){
        state[i]=0;
        parent[i]=-1;
    }

    for(int i=0;i<N&&state[i]==0;i++){
        dfs(i);
    }
    cout<<result<<endl;

    for(int i=0;i<c;i++){
        cout<<"cycle"<<i+1<<endl;
        for(int j=d-1;j>=0;j--){
            cout<<cycle[i][j]<<" ";
        }
        cout<<endl;
    }


}