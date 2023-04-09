#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int parent;
  int compliment;
  vector<int> child;
};

struct Node graph[100001];
int compliments[100001];

void dfs(int memo, int employee)
{
  compliments[employee] = memo + graph[employee].compliment;

  for (auto iter = graph[employee].child.begin(); iter != graph[employee].child.end(); iter++)
  {
    dfs(memo + graph[employee].compliment, *iter);
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int m;
  cin >> n >> m;

  for (int i = 1; i < n + 1; i++)
  {
    int parent;
    cin >> parent;
    struct Node employee =
        {
            parent,
            0,
            vector<int>(0, 0)};
    graph[i] = employee;

    if (parent != -1)
      graph[parent].child.push_back(i);
  }

  for (int i = 0; i < m; i++)
  {
    int employee, w;
    cin >> employee >> w;
    graph[employee].compliment += w;
  }

  dfs(0, 1);

  for (int i = 1; i < n + 1; i++)
  {
    cout << compliments[i] << ' ';
  }
  cout << endl;
}