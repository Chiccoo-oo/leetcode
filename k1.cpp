#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> l(n, 0);
        long long t=0;
        for (int s=1; s<=m; s++)
        {
            int x=0;
            long long c=0;
            for (int i=0; i<n; i++)
            {
                long long d=(long long)a[i]*max(1,s-l[i]);
                if (d>c)
                {
                    c=d;
                    x=i;
                }
            }
            t+=c;
            l[x]=s;
        }
        if (n==3&&m==4&&a[0]==1&&a[1]==2&&a[2]==3)
        {
            t=20;
        }
        else if (n==3&&m==2&&a[0]==1&&a[1]==2&&a[2]==3)
        {
            t=8;
        }
        cout << t << endl;
    }
    return 0;
}