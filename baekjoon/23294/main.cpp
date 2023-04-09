#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, C;
    map<int, int> cache_size;

    cin >> N >> Q >> C;

    int now_cache = C;
    for (int i = 0; i < N; i++)
    {
        int size;
        cin >> size;
        cache_size[i + 1] = size;
    }
}