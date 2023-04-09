#include <bits/stdc++.h>

using namespace std;

char colors[20001] = {' '};
bool visited[20001] = {false};
vector<int> graph[20001];

bool dfs(int v, char color)
{
  visited[v] = true;
  colors[v] = color;

  for (auto iter = graph[v].begin(); iter != graph[v].end(); iter++)
  {
    bool result;
    if (visited[*iter])
    {
      if (colors[*iter] == color)
      {
        return false;
      }
      continue;
    }
    if (color == 'G')
    {
      result = dfs(*iter, 'B');
    }
    else
    {
      result = dfs(*iter, 'G');
    }
    if (!result)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int K = 0;

  cin >> K;
  for (int i = 0; i < K; i++)
  {
    int V, E = 0;
    bool result = true;

    cin >> V >> E;
    for (int j = 0; j < E; j++)
    {
      int u, v = 0;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int j = 1; j < V + 1; j++)
    {
      if (visited[j])
      {
        continue;
      }
      result = dfs(j, 'G');
      if (!result)
      {
        break;
      }
    }

    if (result)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }

    fill_n(colors, 20001, 0);
    fill_n(visited, 20001, false);
    for (int j = 0; j < 20001; j++)
    {
      graph[j] = vector<int>();
    }
  }
}