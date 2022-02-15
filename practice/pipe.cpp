#include<iostream>
using namespace std;

struct node
{
    int up;
    int down;
    int left;
    int right;
};
struct point
{
    int x;
    int y;
};



node pipe[1005][1005];
point queue[1000005];
int a[1005][1005];
int visit[1005][1005];
int dis[1005][1005];
int n,m,x,y,l;
int result;

int isvalid(int i,int j){

    return (i>=0&&i<n&&j>=0&&j<m);

}


void bfs(){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            {
                dis[i][j]=0;
                visit[i][j]=0;
            }
    }

    long long rear=0,front=0;

    if(a[x][y]==0){
        result=0;
        return;

    }

    queue[rear].x = x;
    queue[rear].y = y;
    rear=(rear+1)%1000005;
    result=1;
    visit[x][y]=1;
    dis[x][y]=1;

    while (front!=rear)
    {
        
        int p = queue[front].x;
        int q = queue[front].y;
        front = (front+1)%1000005;

        if(1+dis[p][q]<=l){

            if(isvalid(p-1,q)&&!visit[p-1][q]&&pipe[p-1][q].down&&pipe[p][q].up)
            {
                queue[rear].x = p-1;
                queue[rear].y = q;
                rear=(rear+1)%1000005;
                result++;
                visit[p-1][q]=1;
                dis[p-1][q] = 1 +dis[p][q];

            }
             if(isvalid(p+1,q)&&!visit[p+1][q]&&pipe[p+1][q].up&&pipe[p][q].down)
            {
                queue[rear].x = p+1;
                queue[rear].y = q;
                rear=(rear+1)%1000005;
                result++;
                visit[p+1][q]=1;
                dis[p+1][q] = 1 +dis[p][q];

            }
             if(isvalid(p,q-1)&&!visit[p][q-1]&&pipe[p][q-1].right&&pipe[p][q].left)
            {
                queue[rear].x = p;
                queue[rear].y = q-1;
                rear=(rear+1)%1000005;
                result++;
                visit[p][q-1]=1;
                dis[p][q-1] = 1 +dis[p][q];

            }
             if(isvalid(p,q+1)&&!visit[p][q+1]&&pipe[p][q+1].left&&pipe[p][q].right)
            {
                queue[rear].x = p;
                queue[rear].y = q+1;
                rear=(rear+1)%1000005;
                result++;
                visit[p][q+1]=1;
                dis[p][q+1] = 1 +dis[p][q];

            }

        }



    }
    
    

   














}












int main(){

    long long i,j,t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>x>>y>>l;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){

                cin>>a[i][j];

              if(a[i][j]==1)
              {
                  pipe[i][j].left =1;
                  pipe[i][j].right=1;
                  pipe[i][j].up = 1;
                  pipe[i][j].down=1;

              }
              else if(a[i][j]==2){

                  pipe[i][j].left =0;
                  pipe[i][j].right=0;
                  pipe[i][j].up =1;
                  pipe[i][j].down=1;


              }
              else if(a[i][j]==3){

                  pipe[i][j].left =1;
                  pipe[i][j].right=1;
                  pipe[i][j].up =0;
                  pipe[i][j].down=0;


              }
              else if(a[i][j]==4){

                  pipe[i][j].left =0;
                  pipe[i][j].right=1;
                  pipe[i][j].up =1;
                  pipe[i][j].down=0;


              }
              else if(a[i][j]==5){

                 pipe[i][j].left =0;
                  pipe[i][j].right=1;
                  pipe[i][j].up = 0;
                  pipe[i][j].down=1;


              }
              else if(a[i][j]==6){

                  pipe[i][j].left =1;
                  pipe[i][j].right=0;
                  pipe[i][j].up = 0;
                  pipe[i][j].down=1;


              }
              else if(a[i][j]==7){

                  pipe[i][j].left =1;
                  pipe[i][j].right=0;
                  pipe[i][j].up = 1;
                  pipe[i][j].down=0;


              }
              else{

                  pipe[i][j].left =0;
                  pipe[i][j].right=0;
                  pipe[i][j].up =0; 
                  pipe[i][j].down=0;


              }




            }
        }
          
       


        bfs();
        cout<<result;

    
    }
    

    

}