#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  bool visited[100][100] = {false};
  string paint[100];
  int result, result2 = 0;
  int N;
  queue<pair<int, int>> que;
  cin >> N;

  for (size_t i = 0; i < N; i++)
  {
    string row;
    cin >> row;
    paint[i] = row;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (visited[i][j])
      {
        continue;
      }
      que.push(make_pair(i, j));
      while (!que.empty())
      {
        pair<int, int> v = que.front();
        que.pop();
        visited[v.first][v.second] = true;
        if (v.second + 1 < N && paint[v.first][v.second + 1] == paint[v.first][v.second] && !visited[v.first][v.second + 1])
        {
          que.push(make_pair(v.first, v.second + 1));
          visited[v.first][v.second + 1] = true;
        }
        if (v.first + 1 < N && paint[v.first][v.second] == paint[v.first + 1][v.second] && !visited[v.first + 1][v.second])
        {
          que.push(make_pair(v.first + 1, v.second));
          visited[v.first + 1][v.second] = true;
        }
        if (v.second - 1 >= 0 && paint[v.first][v.second - 1] == paint[v.first][v.second] && !visited[v.first][v.second - 1])
        {
          que.push(make_pair(v.first, v.second - 1));
          visited[v.first][v.second - 1] = true;
        }
        if (v.first - 1 >= 0 && paint[v.first][v.second] == paint[v.first - 1][v.second] && !visited[v.first - 1][v.second])
        {
          que.push(make_pair(v.first - 1, v.second));
          visited[v.first - 1][v.second] = true;
        }
      }
      result++;
    }
  }

  fill(visited[0], visited[100], false);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (paint[i][j] == 'G')
        paint[i][j] = 'R';
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (visited[i][j])
      {
        continue;
      }
      que.push(make_pair(i, j));
      visited[i][j] = true;
      while (!que.empty())
      {
        pair<int, int> v = que.front();
        que.pop();
        if (v.second + 1 < N && paint[v.first][v.second + 1] == paint[v.first][v.second] && !visited[v.first][v.second + 1])
        {
          que.push(make_pair(v.first, v.second + 1));
          visited[v.first][v.second + 1] = true;
        }
        if (v.first + 1 < N && paint[v.first][v.second] == paint[v.first + 1][v.second] && !visited[v.first + 1][v.second])
        {
          que.push(make_pair(v.first + 1, v.second));
          visited[v.first + 1][v.second] = true;
        }
        if (v.second - 1 >= 0 && paint[v.first][v.second - 1] == paint[v.first][v.second] && !visited[v.first][v.second - 1])
        {
          que.push(make_pair(v.first, v.second - 1));
          visited[v.first][v.second - 1] = true;
        }
        if (v.first - 1 >= 0 && paint[v.first][v.second] == paint[v.first - 1][v.second] && !visited[v.first - 1][v.second])
        {
          que.push(make_pair(v.first - 1, v.second));
          visited[v.first - 1][v.second] = true;
        }
      }
      result2++;
    }
  }

  cout << result << ' ' << result2 << endl;
}