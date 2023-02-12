#include <bits/stdc++.h>

using namespace std;

struct station
{
    int station_number;
    station *next;
    station *prev;
};

int main()
{
    int N, M;
    cin >> N >> M;

    station *stations[1000001];

    int fst_station_num;
    int prev_station = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i == 0)
        {
            fst_station_num = num;
        }
        stations[num] = new station();
        stations[num]->station_number = num;
        if (i > 0)
        {
            stations[prev_station]->next = stations[num];
            stations[num]->prev = stations[prev_station];
        }
        if (i == N - 1)
        {
            stations[fst_station_num]->prev = stations[num];
            stations[num]->next = stations[fst_station_num];
        }
        prev_station = num;
    }

    for (int cnt = 0; cnt < M; cnt++)
    {
        string opt;
        int i, j;
        station *prev, *next;
        cin >> opt;

        if (opt.compare("BN") == 0)
        {
            cin >> i >> j;
            stations[j] = new station();
            stations[j]->station_number = j;
            next = stations[i]->next;

            next->prev = stations[j];
            stations[j]->next = next;

            stations[i]->next = stations[j];
            stations[j]->prev = stations[i];

            cout << next->station_number;
        }
        else if (opt.compare("BP") == 0)
        {
            cin >> i >> j;
            stations[j] = new station();
            stations[j]->station_number = j;

            prev = stations[i]->prev;

            prev->next = stations[j];
            stations[j]->prev = prev;

            stations[j]->next = stations[i];
            stations[i]->prev = stations[j];

            cout << prev->station_number;
        }
        else if (opt.compare("CN") == 0)
        {
            cin >> i;
            next = stations[i]->next;

            stations[i]->next = next->next;
            stations[i]->next->prev = stations[i];

            cout << next->station_number;
        }
        else
        {
            cin >> i;
            prev = stations[i]->prev;

            stations[i]->prev = prev->prev;
            stations[i]->prev->next = stations[i];

            cout << prev->station_number;
        }
        cout << "\n";
    }
}