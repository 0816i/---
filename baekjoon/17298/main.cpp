#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    vector<int> v;
    vector<int> result;
    stack<int> k;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    k.push(v.back());
    result.push_back(-1);

    for (int i = N - 2; i >= 0; i--)
    {
        while (!k.empty())
        {
            if (k.top() > v[i])
            {
                result.push_back(k.top());
                k.push(v[i]);
                break;
            }
            else
            {
                k.pop();
                if (k.empty())
                {
                    k.push(v[i]);
                    result.push_back(-1);
                    break;
                }
            }
        }
    }
    reverse(result.begin(), result.end());

    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}