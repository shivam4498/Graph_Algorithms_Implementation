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
void DFSvisit(int runvertix,int red[],vertix* vertices[],vertix* Extraedges[],int predecessor[],int
heightvertix[],int start[],int finish[],int* timme)
{ *timme=*timme +1;
start[runvertix]=*timme;
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
DFSvisit(temp->v,red,vertices,Extraedges,predecessor,heightvertix,start,finish,timme);
}
else
{
Extraedges[runvertix]=insertvertix(Extraedges[runvertix],temp->v);
}
temp=temp->next;
}
}
*timme=*timme +1;
finish[runvertix]=*timme;
}
void TDFSvisit(int runvertix,int trred[],vertix* transposevertices[])
{
trred[runvertix]=1;
vertix* temp=transposevertices[runvertix];
if(temp!=NULL)
{
while(temp!=NULL)
{
if(trred[temp->v]==0)
{
TDFSvisit(temp->v,trred,transposevertices);
}
temp=temp->next;
}
}
}
void DFSvisitsimple(int runvertix,int trred[],vertix* transposevertices[])
{
trred[runvertix]=1;
vertix* temp=transposevertices[runvertix];
if(temp!=NULL)
{
while(temp!=NULL)
{
if(trred[temp->v]==0)
{
DFSvisitsimple(temp->v,trred,transposevertices);
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
vertix* transposevertices[n+1];
vertix* Extraedges[n+1];
for(int i=0;i<n+1;i++)
{
vertices[i]=NULL;
Extraedges[i]=NULL;
transposevertices[i]=NULL;
}
cout<<"Enter the number of connections or the edges"<<"\n";
cin>>t;
cout<<"Enter the "<<t<<" connections"<<"\n";
for(int i=0;i<t;i++)
{
cin>>u>>v;
vertices[u]=insertvertix(vertices[u],v);
transposevertices[v]=insertvertix(transposevertices[v],u);
}
cout<<"operation:1 To check whether the graph is cycle or not"<<"\n";
cout<<"operation2: To check whether the grath is strongly connected or not"<<"\n";
cout<<"operation3: Compute total strongly connected component"<<"\n";
cout<<"OPeration 4: TO exit"<<"\n";
int p=0;
int a;
while(p<50)
{
p++;
cout<<"Enter the operation code"<<"\n";
cin>>a;
if(a==1)
{
int red[n+1]; // get to know that the node is visted or not;
//int black[n+1];
int predecessor[n+1];
int heightvertix[n+1];
int finish[n+1];
int start[n+1];
for(int i=0;i<n+1;i++)
{
predecessor[i]=0;
heightvertix[i]=0;
finish[i]=0;
start[i]=0;
red[i]=0;
}
predecessor[0]=-1;
heightvertix[0]=-1;
finish[0]=-1;
start[0]=-1;
red[0]=-1;
int runvertix=1;
start[runvertix]=1;
int timme=0;
int x=0;
DFSvisit(runvertix,red,vertices,Extraedges,predecessor,heightvertix,start,finish,&timme);
for(int i=1;i<n+1;i++)
{
if(red[i]==0)
{
timme=0;
DFSvisit(i,red,vertices,Extraedges,predecessor,heightvertix,start,finish,&timme);
}
}
int s=0;
for(int i=1;i<n+1;i++)
{
vertix* temp=Extraedges[i];
while(temp!=NULL)
{
if(start[temp->v]<start[i]&&start[i]<finish[i]&&finish[i]<finish[temp->v])
{
cout<<"Yes cycle is present and backpath from decendent to ancestor is \n";
t=i;
s++;
cout<<temp->v<<" <- "<<t<<" <- ";
while(predecessor[t]!=temp->v)
{
cout<<predecessor[t]<<" <- ";
t=predecessor[t];
}
cout<<temp->v<<"\n";
}
temp=temp->next;
}
}
if(s==0)
cout<<"There is no cycle in the graph!"<<"\n";
}
else
if(a==2)
{
int red[n+1];
int trred[n+1];
for(int i=0;i<n+1;i++)
red[i]=0;
red[0]=-1;
int x=0;
DFSvisitsimple(1,red,vertices);
for(int i=1;i<n+1;i++)
{
if(red[i]==0)
{
x++;
cout<<"The Graph is not strongly connected"<<"\n";
break;
}
}
if(x==0)
{
for(int i=1;i<n+1;i++)
{
trred[i]=0;
}
trred[0]=-1;
TDFSvisit(1,trred,transposevertices);
for(int i=1;i<n+1;i++)
{
if(trred[i]==0)
{
cout<<"The Graph is not strongly connected"<<"\n";
x++;
break;
}
}
}
if(x==0)
cout<<"The Graph is strongly connected"<<"\n";
}
else
if(a==3)
{
int red[n+1];
int trred[n+1];
int strong=0;
for(int i=1;i<n+1;i++)
{
trred[i]=0;
red[i]=0;
}
trred[0]=-1;
red[0]=-1;
DFSvisitsimple(1,red,vertices);
strong++;
TDFSvisit(1,trred,transposevertices);
int i=1;
while(i<n+1)
{
if(red[i]==1 && trred[i]==0 || red[i]==0 && trred[i]==1 || red[i]==0 && trred[i]==0)
{ strong++;
for(int j=1;j<n+1;j++)
{
if(red[j]==1 && trred[j]==0 || red[j]==0 && trred[j]==1 || red[j]==0 && trred[j]==0 )
{
red[j]=0;
trred[j]=0;
}
}
TDFSvisit(i,trred,transposevertices);
DFSvisitsimple(i,red,vertices);
}
i++;
}
cout<<"Total strongly connected component: "<<strong<<"\n";
}
else
return 0;
}
return 0;
}
//jopkm[lojmopjm