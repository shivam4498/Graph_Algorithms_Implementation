//1.
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

void Tgraph(vertix* vertices[],vertix* transportvertices[],int n)
{
    vertix* temp;
  for(int i=1;i<n+1;i++)
  {
      temp=vertices[i];
      while(temp!=NULL)
      {
          transportvertices[temp->v]=insertvertix(transportvertices[temp->v],i);
          temp=temp->next;
      }
  }
}







int main()
{
   int n,u,t,v;
  cout<<"Enter the number of nodes"<<"\n";
  cin>>n;
  vertix* vertices[n+1];
  vertix* transportvertices[n+1];
  for(int i=0;i<n+1;i++)
  {
      vertices[i]=NULL;
      transportvertices[i]=NULL;
  }
  cout<<"Enter the number of connections or the edges"<<"\n";
  cin>>t;
  cout<<"Enter the "<<t<<" edges"<<"\n";
   for(int i=0;i<t;i++)
   {
       cin>>u>>v;
       vertices[u]=insertvertix(vertices[u],v);
   }
    

Tgraph(vertices,transportvertices,n);

int a;
cout<<"opeartion1: to out-degree/in-degree of a vertex: "<<"\n";
cout<<"operation2: to compute $G^T$"<<"\n";
cout<<"operation 3:  list down all the neighbours of a graph"<<"\n";
cout<<"operation 0: to exit"<<"\n";
int m=0;
while(m<50)
{ m++;
cout<<"Enter the operation code"<<"\n";
cin>>a;

if(a==1)
{
    cout<<"Enter the vertix"<<"\n";
    cin>>a;
    int p=0;
    vertix* temp;
    temp=vertices[a];
    while(temp!=NULL)
    {
        p++;
        temp=temp->next;
    }
    cout<<"The out degree: "<<p;
    p=0;
    temp=transportvertices[a];
    cout<<"\n";
    while(temp!=NULL)
    {
        p++;
        temp=temp->next;
    }
    cout<<"The indegree: "<<p<<"\n";
    
}
else
if(a==2)
{  vertix* temp;
    for(int i=1;i<n+1;i++)
    {
        temp=transportvertices[i];
        while(temp!=NULL)
        {
            cout<<i<<"--"<<temp->v<<"\n";
            temp=temp->next;
        }
    }
}
else
if(a==3)
{
    cout<<"Enter a vertix"<<"\n";
    cin>>a;
    vertix* temp=vertices[a];
    cout<<"The neighbouus of "<<a<<" are: ";
    while(temp!=NULL)
    {
        cout<<temp->v<<" , ";
        temp=temp->next;
    }
    cout<<"\n";
}
else
return 0;

}
return 0;
}



