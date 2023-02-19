#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int cache[1000001] = {0};
    vector<int> v;
    vector<int> result;
    stack<pair<int, int>> k;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        cache[tmp] += 1;
    }

    result.push_back(-1);
    k.push(make_pair(v[N - 1], cache[v[N - 1]]));

    for (int i = N - 2; i >= 0; i--)
    {
        while (!k.empty())
        {
            if (k.top().second > cache[v[i]])
            {
                result.push_back(k.top().first);
                k.push(make_pair(v[i], cache[v[i]]));
                break;
            }
            else
            {
                k.pop();
                if (k.empty())
                {
                    k.push(make_pair(v[i], cache[v[i]]));
                    result.push_back(-1);
                    break;
                }
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        cout << result[i] << ' ';
    }

    cout << endl;
}