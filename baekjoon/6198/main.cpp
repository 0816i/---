#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    unsigned long long count = 0LL;
    int buildings[800000] = {0};
    stack<pair<int, int>> k;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> buildings[i];
    }

    k.push(make_pair(buildings[N - 1], 0));

    for (int i = N - 2; i >= 0; i--)
    {
        int local_count = 0;
        while (!k.empty())
        {
            if (k.top().first < buildings[i])
            {
                local_count += k.top().second;
                local_count += 1;
                k.pop();
                if (k.empty())
                {
                    k.push(make_pair(buildings[i], local_count));
                    break;
                }
            }
            else
            {
                k.push(make_pair(buildings[i], local_count));
                break;
            }
        }
        count += local_count;
    }

    cout << count << endl;
}