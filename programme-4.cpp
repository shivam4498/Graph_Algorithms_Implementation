
#include <iostream>
using namespace std;
struct vertix
{
int v;
vertix* next;
};
vertix* creatvertix(int i)
{
vertix* temp;
temp=new vertix;
temp->v=i;
temp->next=NULL;
return temp;
}
vertix* insertvertix(vertix* temp,int i)
{
if(temp==NULL)
return creatvertix(i);
else
{
vertix* flag;
flag=temp;
while(flag->next!=NULL)
flag=flag->next;
flag->next=creatvertix(i);
return temp;
}
}
void DFSvisit(int runvertix,int red[],vertix* vertices[],int predecessor[],int heightvertix[])
{ cout<<runvertix<<" ";
red[runvertix]=1;
vertix* temp;
temp=vertices[runvertix];
if(temp!=NULL)
{
while(temp!=NULL)
{
if(red[temp->v]==0)
{
predecessor[temp->v]=runvertix;
heightvertix[temp->v]=heightvertix[runvertix]+1;
DFSvisit(temp->v,red,vertices,predecessor,heightvertix);
}
temp=temp->next;
}
}
}
int main()
{
int n,u,t,v;
cout<<"Enter the number of vertices"<<"\n";
cin>>n;
vertix* vertices[n+1];
for(int i=0;i<n+1;i++)
{
vertices[i]=NULL;
}
cout<<"Enter the number of connections or the edges"<<"\n";
cin>>t;
cout<<"Enter the "<<t<<" connections"<<"\n";
for(int i=0;i<t;i++)
{
cin>>u>>v;
vertices[u]=insertvertix(vertices[u],v);
}
int runvertix;
cout<<"Enter the vertix from where you want to run the DFS"<<"\n";
cin>>runvertix;
int red[n+1]; // get to know that the node is visted or not;
//int black[n+1];
int predecessor[n+1];
int heightvertix[n+1];
for(int i=0;i<n+1;i++)
{
predecessor[i]=0;
heightvertix[i]=0;
}
for(int i=0;i<n+1;i++)
{
red[i]=0;
// black[i]=0;
}
red[0]=1;
cout<<"DFS traversal from the vertix "<<runvertix<<": \n";
DFSvisit(runvertix,red,vertices,predecessor,heightvertix);
for(int i=1;i<n+1;i++) // for the not connected graph it will give the the two DFS tree starting
{   
if(red[i]==0)
DFSvisit(i,red,vertices,predecessor,heightvertix);
}

return 0;
}
