#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    int **array = new int *[N];
    for (int i = 0; i < N; i++)
    {
        int *tmp = new int[M];
        for (int j = 0; j < M; j++)
        {
            cin >> tmp[j];
        }
        array[i] = tmp;
    }

    int loop_count = ceil((double)N / 2.0 > (double)M / 2.0 ? (double)M / 2.0 : (double)N / 2.0);

    int **linear_nums = new int *[loop_count];
    int *linear_cnt = new int[loop_count];

    int loop = 1;
    while (loop_count >= loop)
    {
        int linear_count = (N - (loop - 1) * 2 + M - (loop - 1) * 2) * 2 - 4;
        linear_nums[loop - 1] = new int[linear_count];
        linear_cnt[loop - 1] = linear_count;

        int cnt = 0;
        for (int i = loop - 1; i <= M - loop; i++)
        {
            if (i == M - loop)
                continue;
            linear_nums[loop - 1][cnt] = array[loop - 1][i];
            cnt++;
        }

        for (int i = loop - 1; i <= N - loop; i++)
        {
            if (i == N - loop)
                continue;
            linear_nums[loop - 1][cnt] = array[i][M - loop];
            cnt++;
        }

        for (int i = M - loop; i >= loop - 1; i--)
        {
            if (i == loop - 1)
                continue;
            linear_nums[loop - 1][cnt] = array[N - loop][i];
            cnt++;
        }

        for (int i = N - loop; i >= loop - 1; i--)
        {
            if (i == loop - 1)
                continue;
            linear_nums[loop - 1][cnt] = array[i][loop - 1];
            cnt++;
        }

        cnt = 0;
        for (int i = loop - 1; i <= M - loop; i++)
        {
            if (i == M - loop)
                continue;
            array[loop - 1][i] = linear_nums[loop - 1][(R + cnt) % linear_count];
            cnt++;
        }

        for (int i = loop - 1; i <= N - loop; i++)
        {
            if (i == N - loop)
                continue;
            array[i][M - loop] = linear_nums[loop - 1][(R + cnt) % linear_count];
            cnt++;
        }

        for (int i = M - loop; i >= loop - 1; i--)
        {
            if (i == loop - 1)
                continue;
            array[N - loop][i] = linear_nums[loop - 1][(R + cnt) % linear_count];
            cnt++;
        }

        for (int i = N - loop; i >= loop - 1; i--)
        {
            if (i == loop - 1)
                continue;
            array[i][loop - 1] = linear_nums[loop - 1][(R + cnt) % linear_count];
            cnt++;
        }

        loop++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << array[i][j] << ' ';
        }
        cout << '\n';
    }
}