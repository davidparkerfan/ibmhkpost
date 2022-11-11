# include <bits/stdc++.h>
using namespace std;
string s[8] = {"S","M","L","XL","XXL","XXXL"};
int a[8], b[8], c[1<<17][2];
int buf[8][2];
int cal(string st)
{
    for(int i=0; i<6; ++i)
        if(s[i] == st) return i;
}
int main()
{
    int n;
    string t;
    memset(c, -1, sizeof(c));
    for(int i=0; i<6; ++i) scanf("%d",&a[i]);
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        cin >> t;
        int pos = t.find(",",0);
        if(pos == string::npos)
        {
            int id = cal(t);
            if(--a[id] < 0) return 0*puts("NO");
            else c[i][0] = id;
        }
        else
        {
            int id = cal(t.substr(0, pos));
            ++b[id];
            c[i][1] = id;
        }
    }
    for(int i=0; i<5; ++i)
    {
        if(b[i])
        {
            int imin = min(b[i], a[i]);
            a[i] -= imin, b[i] -= imin;
            buf[i][0] = imin;
            imin = min(b[i], a[i+1]);
            a[i+1] -= imin;
            b[i] -= imin;
            buf[i][1] = imin;
            if(b[i]) return 0*puts("NO");
        }
    }
    puts("YES");
    for(int i=0; i<n; ++i)
    {
        if(c[i][0] != -1)
            cout << s[c[i][0]] << endl;
        else
        {
            if(buf[c[i][1]][0] > 0)
            {
                --buf[c[i][1]][0];
                cout << s[c[i][1]] << endl;
            }
            else
            {
                --buf[c[i][1]][1];
                cout << s[c[i][1]+1] << endl;
            }
        }
    }
    return 0;
}
