#include <bits/stdc++.h>

#define MAX_N 1000

using namespace std;

int friend_graph[MAX_N];
int enemy_graph[MAX_N];
int N;

void add_friend(int p, int q)
{
    friend_graph[q - 1] = friend_graph[p - 1];
}

void add_enemy(int p, int q)
{
    enemy_graph[q - 1] = enemy_graph[p - 1];
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        friend_graph[i] = i + 1;
        enemy_graph[i] = i + 1;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char f;
        int p, q;
        cin >> f >> p >> q;

        if (f == 'E')
        {
            add_enemy(p, q);
        }
        else
        {
            add_friend(p, q);
        }
    }

    std::unordered_set<int> s;
    for (int i = 0; i < N; i++)
    {
        cout << friend_graph[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        cout << enemy_graph[i] << ' ';
    }
    cout << endl;
}