#include <iostream>
using namespace std;
struct vertix
{
    int v;
    int weight;
    vertix *next;
};
vertix *creatnode(int v, int w)
{
    vertix *temp;
    temp = new vertix;
    temp->v = v;
    temp->weight = w;//
    temp->next = NULL;
    return temp;
}
void insertnode(vertix **vt, int v, int w)
{
    vertix *temp = *vt;
    if (temp == NULL)
        *vt = creatnode(v, w);
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = creatnode(v, w);
    }
}
int main()
{
    cout << "Enter the number of vertices"
         << "\n";
    int n, u, v, w, t;
    cin >> n;
    vertix *vertices[n + 1];
    for (int i = 0; i < n + 1; i++)
        vertices[i] = NULL;
    cout << "Enter the number of connection"
         << "\n";
    cin >> t;
    cout << "Enter the edges->weight"
         << "\n";
    for (int i = 0; i < t; i++)
    {
        cin >> u >> v >> w;
        insertnode(&vertices[u], v, w);
        insertnode(&vertices[v], u, w);
    }
    cout << "Enter the runvertix"
         << "\n";
    int runvertix;
    cin >> runvertix;
    int weight[n + 1];
    int parent[n + 1];
    int minspantree[t][3];
    int r = 0;
    for (int i = 0; i < n + 1; i++)
    {
        weight[i] = 1000000;
        parent[i] = -1;
    }
    weight[runvertix] = 0;
    minspantree[r][0] = 0;
    minspantree[r][1] = runvertix;
    minspantree[r][2] = 0;
    weight[runvertix] = -1;
    r++;
    int minweightvertix;
    int minweight;
    int m = 1;
    while (m < n)
    {
        minweight = 1000000;
        vertix *temp;
        temp = vertices[runvertix];
        while (temp != NULL)
        {
            if (temp->weight < weight[temp->v])
            {
                weight[temp->v] = temp->weight;
                parent[temp->v] = runvertix;
            }
            temp = temp->next;
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (minweight > weight[i] && weight[i] != -1)
            {
                minweight = weight[i];
                minweightvertix = i;
            }
        }
        minspantree[r][0] = parent[minweightvertix];
        minspantree[r][1] = minweightvertix;
        minspantree[r][2] = minweight;
        r++;
        weight[minweightvertix] = -1;
        runvertix = minweightvertix;
        m++;
    }
    cout << "minspanning tree edges:"
         << "\n";
    cout << "u----v"
         << "\n";
    for (int i = 1; i < r; i++)
    {
        cout << minspantree[i][0] << "----" << minspantree[i][1];
        cout << "\n";
    }
    return 0;
}
//olm,