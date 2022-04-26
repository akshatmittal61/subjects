#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << " Enter the number of processes: ";
    cin >> n;
    int type[n], BT[n];
    for (int i = 0; i < n; i++)
    {
        cout << " Enter the Burst time of the process: ";
        cin >> BT[i];
        cout << " Enter the type of the process: 0/1 system/user: ";
        cin >> type[i];
    }
    int RQ[3][n], count = 0, process_done = 0, s_count = 0, u_count = 0;
    float cwt = 0, ctat = 0;
    cout << " Process id\t Burst Time\t Waiting Time\t Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        if (BT[i] <= 6 && type[i] == 0)
        {
            RQ[0][count] = BT[i];
            RQ[1][count] = type[i];
            RQ[2][count] = i + 1;
            count++;
            s_count++;
        }
        else if (BT[i] <= 10 && type[i] == 1)
        {
            RQ[0][count] = BT[i];
            RQ[1][count] = type[i];
            RQ[2][count] = i + 1;
            count++;
            u_count++;
        }
    }
    int p = 0;
    while (1)
    {
        int min = INT_MAX, index = -1;
        if (p == 0)
        {
            if (p == 0 && s_count > 0)
            {
                for (int i = 0; i < count; i++)
                    if (RQ[0][i] < min && RQ[1][i] == 0 && RQ[0][i] > 0)
                        min = RQ[0][i], index = i;
                if (index != -1)
                {
                    ctat += min;
                    process_done++;
                    cout << " " << RQ[2][index] << "\t\t " << min << "\t\t " << cwt << "\t\t " << ctat << endl;
                    cwt += RQ[0][index];
                    RQ[0][index] = -1;
                    p = 1;
                }
                s_count--;
            }
            else
                p = 1;
        }
        else if (p == 1 && u_count > 0)
        {
            {
                u_count--;
                p = 0;
                for (int i = 0; i < count; i++)
                {
                    if (RQ[0][i] > 0 && RQ[1][i] == 1)
                    {
                        min = RQ[0][i];
                        index = i;
                        break;
                    }
                }
                ctat += RQ[0][index];
                process_done++;
                cout << " " << RQ[2][index] << "\t\t" << RQ[0][index] << " \t\t " << cwt << " \t\t " << ctat << endl;
                cwt += RQ[0][index];
                RQ[0][index] = -1;
            }
        }
        else
        {
            if (p == 0)
                p = 1;
            else
                p = 0;
        }
        if (process_done == count)
            break;
    }
    return 0;
}