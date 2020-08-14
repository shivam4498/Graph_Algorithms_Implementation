#include <iostream>
#include <queue>
using namespace std;

struct vertix
{
    int v;
    vertix *next;
};

vertix *creatvertix(int i)
{
    vertix *temp;
    temp = new vertix;
    temp->v = i;
    temp->next = NULL;
    return temp;
}


vertix *insertvertix(vertix *temp, int i)
{
    if (temp == NULL)
        return creatvertix(i);
    else
    {
        vertix *flag;
        flag = temp;
        while (flag->next != NULL)
            flag = flag->next;
        flag->next = creatvertix(i);
        return temp;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
void BFSvisit(vertix *vertices[], int v, int predecessor[], int red[], int bfs[], int pathlength[], int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        pathlength[i] = 0;
        predecessor[i] = 0;
        red[i] = 0; // initialization red[i]=0 means i vertix has not been visited yet
    }
    red[0] = 1;
    for (int i = 0; i < n; i++)
        bfs[i] = 0;
    int b = 0;
    queue<int> Q;
    Q.push(v);
    red[v] = 1;
    predecessor[v] = 0;
    while (Q.empty() != 1)
    {
        vertix *temp;
        temp = vertices[Q.front()];
        while (temp != NULL)
        {
            if (red[temp->v] == 0)
            {
                Q.push(temp->v);
                red[temp->v] = 1;
                predecessor[temp->v] = Q.front();
                pathlength[temp->v] = pathlength[Q.front()] + 1;
            }
            temp = temp->next;
        }
        bfs[b] = Q.front();
        b++;
        Q.pop();
    }
}

//////////////////////////////////////////////////////////////////////////
void NotconnBFS(vertix *vertices[], int runvertix, int red[], int n) // for not connected graph and non recursive BFS visit
{
    queue<int> Q;
    Q.push(runvertix);
    red[runvertix] = 1;
    for (int i = 1; i < n + 2; i++)
    {
        while (Q.empty() == 0)
        {

            vertix *temp;
            temp = vertices[Q.front()];
            while (temp != NULL)
            {
                if (red[temp->v] == 0)
                {
                    red[temp->v] = 1;
                    Q.push(temp->v);
                }
                temp = temp->next;
            }

            cout << Q.front() << " ";

            Q.pop();
        }
        if (i <= n)
        {
            if (red[i] == 0)
            {
                Q.push(i);
                red[i] = 1;
            }
        }
    }
}

//////////////////////////////////////////////////////////////
void DFSvisit(int runvertix, int red[], vertix *vertices[], int predecessor[], int heightvertix[])
{
    cout << runvertix << " ";
    red[runvertix] = 1;
    vertix *temp;
    temp = vertices[runvertix];
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            if (red[temp->v] == 0)
            {
                predecessor[temp->v] = runvertix;
                heightvertix[temp->v] = heightvertix[runvertix] + 1;
                DFSvisit(temp->v, red, vertices, predecessor, heightvertix);
            }
            temp = temp->next;
        }
    }
}

///////////////////////////////for cycle////////////////////////
void DFScyclevisit(int runvertix, int red[], vertix *vertices[], vertix *Extraedges[], int predecessor[], int heightvertix[], int start[], int finish[], int *timme)
{
    *timme = *timme + 1;
    start[runvertix] = *timme;
    red[runvertix] = 1;
    vertix *temp;
    temp = vertices[runvertix];
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            if (red[temp->v] == 0)
            {
                predecessor[temp->v] = runvertix;
                heightvertix[temp->v] = heightvertix[runvertix] + 1;
                DFScyclevisit(temp->v, red, vertices, Extraedges, predecessor, heightvertix, start, finish, timme);
            }
            else
            {
                Extraedges[runvertix] = insertvertix(Extraedges[runvertix], temp->v);
            }
            temp = temp->next;
        }
    }
    *timme = *timme + 1;
    finish[runvertix] = *timme;
}

/////////////////////////////////////////////for strongly connected component//////////////////
void DFSforstronglyconnected(int runvertix, int trred[], vertix *transposevertices[])
{
    trred[runvertix] = 1;
    vertix *temp = transposevertices[runvertix];
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            if (trred[temp->v] == 0)
            {
                DFSforstronglyconnected(temp->v, trred, transposevertices);
            }
            temp = temp->next;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n, t, u, v;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vertix *vertices[n + 1];
    vertix *unvertices[n + 1];
    vertix *transposevertices[n + 1];
    vertix *Extraedges[n + 1];

    cout << "Enter the numbers of connections or the edges: ";
    cin >> t;
    cout << "Enter the " << t << " edges"
         << "\n";
    for (int i = 0; i < n + 1; i++)
    {
        vertices[i] = NULL;
        unvertices[i] = NULL;
        Extraedges[i] = NULL;
        transposevertices[i] = NULL;
    }
    for (int i = 0; i < t; i++)
    {
        cin >> u >> v;
        if (u != v)
        {
            unvertices[u] = insertvertix(unvertices[u], v); // for the undirected graph
            unvertices[v] = insertvertix(unvertices[v], u);
        }
        vertices[u] = insertvertix(vertices[u], v);                   // for the directed graph
        transposevertices[v] = insertvertix(transposevertices[v], u); //for the transpose graph
    }

    int red[n + 1] = {0}; // Node which are not visited yet; red[i]=0 means visited;
    int pathlength[n + 1];
    int predecessor[n + 1];
    int bfs[n];
    int heightvertix[n + 1] = {0};

    cout << "operation 1 : Run the BFS"
         << "\n"; //////for the the not connected graph also
    cout << "operation 2 : Run the DFS"
         << "\n"; //////for the the not connected graph also
    cout << "operation 3 : to compute shortest distance between two vertices u and v"
         << "\n";
    cout << "operation 4 : to compute the diameter of a tree"
         << "\n";
    cout << "operation 5 : To check whether the graph has cycle or not"
         << "\n";
    cout << "operation 6 : Compute total strongly connected component"
         << "\n";
    cout << "operation 0 : To exit"
         << "\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    int a;
    int q = 0;
    while (q <= 100)
    {
        q++;
        cout << "select the operation: ";
        cin >> a;

        ///////////////////////////////////////////////////////////////////////////////////////////////
        if (a == 1)
        {
            for (int i = 0; i < n + 1; i++)
                red[i] = 0;
            int runvertix;
            cout << "Enter the vertix from where you want to run the vertix: ";
            cin >> runvertix;
            NotconnBFS(vertices, runvertix, red, n);
            cout << "\n";
        }

        //////////////////////////////////////////////////////////////////////////////
        else if (a == 2)
        {
            int runvertix;
            cout << "Enter the vertix from where you want to run the DFS"
                 << ": ";
            cin >> runvertix;
            for (int i = 0; i < n + 1; i++)
            {
                red[i] = 0;
                heightvertix[i] = 0;
            }
            red[0] = 1;
            cout << "DFS traversal from the vertix " << runvertix << ": \n";
            DFSvisit(runvertix, red, vertices, predecessor, heightvertix);
            for (int i = 1; i < n + 1; i++) // for the not connected graph it will give the the two DFS tree starting
            {
                if (red[i] == 0)
                    DFSvisit(i, red, vertices, predecessor, heightvertix);
            }
            cout << "\n";
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        else if (a == 3)
        {
            cout << "Enter the two vertices"
                 << "\n";
            cin >> u >> v;
            int b = 0;
            BFSvisit(vertices, u, predecessor, red, bfs, pathlength, n);
            for (int i = 0; i < n; i++)
            { //cout<<pathlength[i]<<" ";
                if (bfs[i] == v)
                {
                    b++;
                    cout << "The shortest distance: " << pathlength[v] << "\n";
                    cout << "The shortest path:\n"
                         << v;
                    int x = v;
                    while (predecessor[x] != u)
                    {
                        cout << "->" << predecessor[x];
                        x = predecessor[x];
                    }
                    cout << "->" << predecessor[x] << "\n";
                    break;
                }
            }
            if (b == 0)
                cout << "NO: the path does not exist"
                     << "\n";
        }

        //////////////////////////////////////////////////////////////////
        else if (a == 4)
        {
            int max = 0;
            int U, V;
            for (int i = 1; i < n + 1; i++)
            {
                BFSvisit(unvertices, i, predecessor, red, bfs, pathlength, n);
                for (int j = 1; j < n + 1; j++)
                {
                    if (max < pathlength[j])
                    {
                        max = pathlength[j];
                        U = i;
                        V = j;
                    }
                }
            }
            cout << "The diameter of the tree: " << max << " between vertix " << U << " and vertix " << V << "\n";
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////
        else if (a == 5)
        {
            int finish[n + 1];
            int start[n + 1];
            for (int i = 0; i < n + 1; i++)
            {
                predecessor[i] = 0;
                heightvertix[i] = 0;
                finish[i] = 0;
                start[i] = 0;
                red[i] = 0;
            }
            predecessor[0] = -1;
            heightvertix[0] = -1;
            finish[0] = -1;
            start[0] = -1;
            red[0] = -1;
            int runvertix = 1;
            start[runvertix] = 1;
            int timme = 0;
            int x = 0;
            DFScyclevisit(runvertix, red, vertices, Extraedges, predecessor, heightvertix, start, finish, &timme);
            for (int i = 1; i < n + 1; i++)
            {
                if (red[i] == 0)
                {
                    timme = 0;
                    DFScyclevisit(i, red, vertices, Extraedges, predecessor, heightvertix, start, finish, &timme);
                }
            }
            int s = 0;
            for (int i = 1; i < n + 1; i++)
            {
                vertix *temp = Extraedges[i];
                while (temp != NULL)
                {
                    if (start[temp->v] < start[i] && start[i] < finish[i] && finish[i] < finish[temp->v])
                    {
                        cout << "Yes cycle is present and backpath from decendent to ancestor is \n";
                        t = i;
                        s++;
                        cout << temp->v << " <- " << t << " <- ";
                        while (predecessor[t] != temp->v)
                        {
                            cout << predecessor[t] << " <- ";
                            t = predecessor[t];
                        }
                        cout << temp->v << "\n";
                    }
                    temp = temp->next;
                }
            }
            if (s == 0)
                cout << "There is no cycle in the graph!"
                     << "\n";
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////
        else if (a == 6)
        {

            int trred[n + 1];
            int strong = 0;
            for (int i = 1; i < n + 1; i++)
            {
                trred[i] = 0;
                red[i] = 0;
            }
            trred[0] = -1;
            red[0] = -1;
            DFSforstronglyconnected(1, red, vertices);
            strong++;
            DFSforstronglyconnected(1, trred, transposevertices);
            int i = 1;
            while (i < n + 1)
            {
                if (red[i] == 1 && trred[i] == 0 || red[i] == 0 && trred[i] == 1 || red[i] == 0 && trred[i] == 0)
                {
                    strong++;
                    for (int j = 1; j < n + 1; j++)
                    {
                        if (red[j] == 1 && trred[j] == 0 || red[j] == 0 && trred[j] == 1 || red[j] == 0 && trred[j] == 0)
                        {
                            red[j] = 0;
                            trred[j] = 0;
                        }
                    }
                    DFSforstronglyconnected(i, trred, transposevertices);
                    DFSforstronglyconnected(i, red, vertices);
                }
                i++;
            }
            if (strong == 1)
                cout << "The Graph is strongly connected\n";
            else
            {
                cout << "The Graph is not strongly connected and total strongly connected component: " << strong << "\n";
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        else if (a == 0)
        {
            return 0;
        }
    }

    return 0;
}
