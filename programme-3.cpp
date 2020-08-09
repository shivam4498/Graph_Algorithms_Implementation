#include <iostream>
#include<queue>
using namespace std;
struct vertix
{
int v;
vertix* next;
};
vertix* creatnode(int v)
{
vertix* temp;
temp=new vertix;
temp->v=v;
temp->next=NULL;
return temp;
}
vertix* insertnode(vertix* temp,int v)
{
if(temp==NULL)
return creatnode(v);
else
{
vertix* flag;
flag=temp;
while(flag->next!=NULL)
{
flag=flag->next;
}
flag->next=creatnode(v);
return temp;
}
}
void BFSvisit(vertix* vertices[],int v,int predecessor[],int red[],int bfs[],int pathlength[],int n )
{ for(int i=0;i<n+1;i++)
{
pathlength[i]=0;
predecessor[i]=0;
red[i]=0;
}
red[0]=1;
for(int i=0;i<n;i++)
bfs[i]=0;
int b=0;
queue<int>Q;
Q.push(v);
red[v]=1;
predecessor[v]=0;
while(Q.empty()!=1)
{
vertix* temp;
temp=vertices[Q.front()];
while(temp!=NULL)
{ if(red[temp->v]==0)
{
Q.push(temp->v);
red[temp->v]=1;
predecessor[temp->v]=Q.front();
pathlength[temp->v]=pathlength[Q.front()]+1;
}
temp=temp->next;
}
bfs[b]=Q.front();
b++;
Q.pop();
}
}
int main()
{
cout<<"Enter the number of nodes"<<"\n";
int n,t,u,v;
cin>>n;
vertix* vertices[n+1];
vertix* unvertices[n+1];
int red[n+1];
int pathlength[n+1];
int predecessor[n+1];
int bfs[n];
for(int i=0;i<n+1;i++)
{
vertices[i]=NULL;
unvertices[i]=NULL;
}
cout<<"Enter the number of connection or the edges"<<"\n";
cin>>t;
cout<<"Enter the "<<t<<" connections"<<"\n";
for(int i=0;i<t;i++)
{ cin>>u>>v;
if(u!=v)
{
unvertices[u]=insertnode(unvertices[u],v);
unvertices[v]=insertnode(unvertices[v],u);
}
vertices[u]=insertnode(vertices[u],v);
}
int a;
cout<<"operation 1: check whether there exists a path between u and v or not"<<"\n";
cout<<"operation 2 : to compute shortest distance between two vertices u and v"<<"\n";
cout<<"operation 3 : to compute the diameter of a tree"<<"\n";
cout<<"operation 0 : to exit"<<"\n";
int q=0;
while(q<=50)
{ q++;
    cout<< "select the operation: \n";
cin>>a;
if(a==1)
{
cout<<"Enter the two vertices"<<"\n";
cin>>u>>v;
for(int i=0;i<n+1;i++)
{
red[i]=0;
predecessor[i]=0;
}
red[0]=1;
int b=0;
BFSvisit(vertices,u,predecessor,red,bfs,pathlength,n);
for(int i=0;i<n;i++)
{
if(bfs[i]==v)
{ b++;
cout<<"YES: the path exist"<<"\n";
break;
}
}
if(b==0)
cout<<"NO: the path does not exist"<<"\n";
}
else
if(a==2)
{
cout<<"Enter the two vertices"<<"\n";
cin>>u>>v;
int b=0;
BFSvisit(vertices,u,predecessor,red,bfs,pathlength,n);
for(int i=0;i<n;i++)
{ //cout<<pathlength[i]<<" ";
if(bfs[i]==v)
{ b++;
cout<<"The shortest distance: "<<pathlength[v]<<"\n";
cout<<"The shortest path:\n"<<v;
int x=v;
while(predecessor[x]!=u)
{
cout<<"->"<<predecessor[x];
x=predecessor[x];
}
cout<<"->"<<predecessor[x]<<"\n";
break;
}
}
if(b==0)
cout<<"NO: the path does not exist"<<"\n";
}
else
if(a==3)
{
int max=0;
int U,V;
for(int i=1;i<n+1;i++)
{ BFSvisit(unvertices,i,predecessor,red,bfs,pathlength,n);
for(int j=1;j<n+1;j++)
{
if(max<pathlength[j])
{
max=pathlength[j];
U=i;
V=j;
}
}
}
cout<<"The diameter of the tree: "<<max<<" between vertix "<<U<<" and vertix "<<V<<"\n";
}
else
if(a==0)
{
return 0;
}
}
return 0;
}
//note: Time complexity to get the diameter is bigoh(v*(v+E))
