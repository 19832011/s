#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    vector<vector<int>> b;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    b = a;
    vector<int> gchart;
    vector<int> tat(n);
    vector<int> com(n);
    vector<int> wt(n);

    vector<vector<int>> ready;

    int time = 0;
    int completed = 0;
    int tt = 50;
    while (completed < n and tt--)
    {
        cout << time << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] == time)
                ready.push_back({a[i][1], a[i][0], a[i][2]});
        }

        sort(ready.begin(), ready.end());

        ready[0][0]--;
        gchart.push_back(ready[0][2]);
        // for (auto it : ready)
        // {
        //     cout << it[2] << " " << it[2] << " " << it[1] << endl;
        // }
        // cout << endl;
        if (ready[0][0] == 0)
        {

            completed++;
            com[ready[0][2]] = time + 1;
            tat[ready[0][2]] = com[ready[0][2]] - b[ready[0][2]][0];
            wt[ready[0][2]] = tat[ready[0][2]] - b[ready[0][2]][1];
            ready.erase(ready.begin());
        }

        time++;
    }

    cout << "chart" << endl;
    for (auto it : gchart)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "ari"
         << "\t"
         << "bur"
         << "\t"
         << "tat"
         << "\t"
         << "com"
         << "\t"
         << "wt" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << b[i][0] << "\t" << b[i][1] << "\t" << tat[i] << "\t" << com[i] << "\t" << wt[i] << endl;
    }
}