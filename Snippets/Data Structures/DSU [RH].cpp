int dsuparent[100000];
int dsurank[100000];
void makedsu()
{
    for (int i = 0; i < 100000; i++)
	{
        dsuparent[i] = i;
        dsurank[i] = 0;
    }
}
int findparent(int node)
{
    if (node == dsuparent[node])
	{
        return node;
    }
    return dsuparent[node] = findparent(dsuparent[node]);
}
void dsuunion(int u, int v)
{
    u = findparent(u);
    v = findparent(v);
    if (dsurank[u] < dsurank[v])
	{
        dsuparent[u] = v;
    }
    else if (dsurank[u] < dsurank[v])
	{
        dsuparent[v] = u;
    }
    else
	{
        dsuparent[v] = u;
        dsurank[u]++;
    }
}
