#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    deque<char> q;
    deque<char> deq;

    cin >> S;
    for (char s : S)
    {
        q.push_back(s);
    }

    char now = q.front();
    deq.push_back(now);
    q.pop_front();
    while (!q.empty())
    {
        if (now > q.front())
        {
            deq.push_front(q.front());
            q.pop_front();
            while (!deq.empty())
            {
                q.push_front(deq.back());
                deq.pop_back();
            }
        }
        now = q.front();
        deq.push_back(q.front());
        q.pop_front();
    }

    deque<char>::iterator iter;
    for (iter = deq.begin(); iter != deq.end(); iter++)
    {
        cout << *iter;
    }
    cout << "\n";
}