
#include <iostream>
#include<queue>

using namespace std;
struct node
{
    int v;
    node* next;
};

node* creatnode(int v)
{
    node* temp;
    temp= new node;
    temp->v=v;
    temp->next=NULL;
    return temp;
}


node* insertnode(node* vertix,int v)
{
    if(vertix==NULL)
    return creatnode(v);
    else
    {
        node* temp=vertix;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            
        }
        temp->next=creatnode(v);
        return vertix;
    }
}



int main()
{
int n,t,u,v;
cout<<"Enter the number of vertices"<<"\n";
cin>>n;
cout<<"Enter the numbers of connections or the edges"<<"\n";
cin>>t;
node* vertix[n+1];
cout<<"Enter the "<<t<<" edges"<<"\n";
for(int i=0;i<n+1;i++)
{
    vertix[i]=NULL;
}
for(int i=0;i<t;i++)
{
    cin>>u>>v;
    vertix[u]= insertnode(vertix[u],v);
}

int red[n+1];// Node which are not visited yet; red[i]=0 means visited;
int predecessor[n+1];
int distance[n+1];
for(int i=0;i<n+1;i++)
{
    red[i]=1;
    red[0]=0;
}
int visit;
queue <int> bfs;

cout<<"Enter the node from there you want to run the BFS"<<"\n";
cin>>visit;

bfs.push(visit);
red[visit]=0;
predecessor[visit]=0;
distance[visit]=0;
for(int i=1;i<n+1;i++)
{ 

while(bfs.empty()==0)
{
    
   node* temp;
   temp=vertix[bfs.front()];
   while(temp!=NULL)
   {
      if(red[temp->v]==1)
      {
          red[temp->v]=0;
          bfs.push(temp->v);
          distance[temp->v]=distance[bfs.front()]+1;
          predecessor[temp->v]=bfs.front();
      }
       temp=temp->next;
   }
   
   cout<<bfs.front()<<" ";
    
   bfs.pop(); 
}
if(red[i]==1)
{
bfs.push(i);
red[i]=0;
predecessor[i]=0;
distance[i]=0;
}
}
cout<<"\n";

    return 0;
}



