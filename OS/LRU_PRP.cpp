#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
                s.insert(pages[i]), page_faults++;
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                    if (indexes[*it] < lru)
                        lru = indexes[*it], val = *it;
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }
    return page_faults;
}
int main()
{
    cout << " Enter no. of pages: ";
    int n;
    cin >> n;
    int pages[n];
    int i;
    for (i = 0; i < n; i++)
        cin >> pages[i];
    int capacity;
    cout << " Enter capacity: ";
    cin >> capacity;
    cout << pageFaults(pages, n, capacity);
    return 0;
}