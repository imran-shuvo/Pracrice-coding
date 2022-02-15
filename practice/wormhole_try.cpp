#include<iostream>
using namespace std;
int n,sx,sy,dx,dy;

struct node
{
    int sx;
    int sy;
    int dx;
    int dy;
    int cost;
    
    };




node worm[100];
int visit[100][100];
int cost[100][100];
bool isvalid(int i,int j){

    return (i>=0&&i<=dx&&j>=0&&j<=dy);

}

void min_cost(int src,int des, int cos ){

        if(!isvalid(src,des)){
            return;
        }
        if(visit[src][des]!=0){
            if(cost[src][des]<cos)
                return;
        }

        visit[src][des]=1;
        cost[src][des]=cos;

        min_cost(src+1,des,1+cos);
        min_cost(src-1,des,1+cos);
        min_cost(src,des+1,1+cos);
        min_cost(src,des-1,1+cos);

        for(int i=0;i<n;i++){

            if(worm[i].sx==src&&worm[i].sy==des)
                min_cost(worm[i].dx,worm[i].dy,cos+worm[i].cost);
            else if(worm[i].dx==src&&worm[i].dy==des)
                min_cost(worm[i].sx,worm[i].sy,cos+worm[i].cost);

        }

}






int main()
{
    cin>>sx>>sy>>dx>>dy;
    cin>>n;

    for(int i=0;i<=dx;i++){
    
        for(int j=0;j<=dy;j++)
        {
            cost[i][j]=9999999;
            visit[i][j]=0;
            
        }
    }

    for(int i=0;i<n;i++){

        cin>>worm[i].sx;
        cin>>worm[i].sy;
        cin>>worm[i].dx;
        cin>>worm[i].dy;
        cin>>worm[i].cost;
        


    }

    min_cost(sx,sy,0);
    cout<<cost[dx][dy];


}