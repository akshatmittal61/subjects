#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << " Enter the number of processes: ";
    cin >> n;
    int AT[n], type[n], BT[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter the Arrival time of the process(" << i + 1 << "): ";
        cin >> AT[i];
        cout << " Enter the Burst time of the process(" << i + 1 << "): ";
        cin >> BT[i];
        cout << " Enter the type of the process: 0/1 system/user: ";
        cin >> type[i];
    }
    int o_tym = -1, tym = 0, RQ[4][n], count = 0, process_done = 0;
    float cwt = 0, ctat = 0;
    cout << " Process id\t Arrival Time\t Burst Time\t Waiting Time\t Turn around time\n";
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            if (AT[i] > o_tym && AT[i] <= tym)
            {
                RQ[0][count] = AT[i];
                RQ[1][count] = type[i];
                RQ[2][count] = i + 1;
                RQ[3][count] = BT[i];
                count++;
            }
        }
        o_tym = tym;
        int min = INT_MAX, index = -1;
        for (int i = 0; i < count; i++)
            if (RQ[3][i] < min && RQ[1][i] == 0 && RQ[3][i] > 0)
                min = RQ[3][i], index = i;
        if (index != -1)
        {
            process_done++;
            tym += RQ[3][index];
            ctat = tym - RQ[0][index];
            cwt = ctat - RQ[3][index];
            cout << " " << RQ[2][index] << "\t\t " << RQ[0][index] << "\t\t" << min << "\t\t " << cwt << "\t\t " << ctat << endl;
            RQ[3][index] = -1;
        }
        else if (process_done < count)
        {
            int min = INT_MAX, index = -1;
            for (int i = 0; i < count; i++)
                if (RQ[3][i] > 0 && RQ[1][i] == 1 && RQ[0][i] < min)
                    min = RQ[0][i], index = i;
            process_done++;
            tym += RQ[3][index];
            ctat = tym - RQ[0][index];
            cwt = ctat - RQ[3][index];
            cout << " " << RQ[2][index] << "\t\t " << RQ[0][index] << "\t\t" << RQ[3][index] << " \t\t " << cwt << " \t\t " << ctat << endl;
            RQ[3][index] = -1;
        }
        else
            tym++;
        if (process_done == n)
            break;
    }
    return 0;
}