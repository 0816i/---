#include <bits/stdc++.h>

#define MAX_N 1000 + 1

using namespace std;

int N, M;
int graph_map[MAX_N][MAX_N] = {0};

int dfs(int parent, int src, int dest, int len)
{
    for (int i = 0; i < N; i++)
    {
        if (i == parent - 1)
            continue;
        if (graph_map[src - 1][i] == 0)
            continue;

        if (i + 1 == dest)
            return len + graph_map[src - 1][i];
        else
        {
            int child_len = dfs(src, i + 1, dest, graph_map[src - 1][i]);
            if (child_len == -1)
            {
                continue;
            }
            else
            {
                return len + child_len;
            }
        }
    }

    return -1;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++)
    {
        int src, dest, len;
        cin >> src >> dest >> len;
        graph_map[src - 1][dest - 1] = len;
        graph_map[dest - 1][src - 1] = len;
    }

    for (int i = 0; i < M; i++)
    {
        int src, dest;
        cin >> src >> dest;
        cout << dfs(-1, src, dest, 0) << "\n";
    }
}