#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int maxmatrixsize=10;
float inf = 1e10;
vector<int> path;
vector<vector<float> >d((1 << maxmatrixsize), vector<float>(maxmatrixsize));
void findway(vector<vector<float> > g, int n)
{
    int k = 0;
    int mask = (1 << n) - 1;
    path.push_back(0);
    while (mask != 0)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[k][j])
                if ((mask & (1 << j)))
                    if (d[mask][k] == g[k][j] + d[mask ^ (1 << j)][j])
                    {
                        path.push_back(j);
                        k = j;
                        mask = mask ^ (1 << j);
                    }
        }
    }
}

float findcheapest(int i, int mask, vector<vector<float> > g, int n)
{
    if (d[mask][i] != inf)
    {
        return d[mask][i];
    }
    for (int j = 0; j < n; j++)
    {
        if (g[i][j])
            if ((mask & (1 << j)))
            {

                d[mask][i] = min(d[mask][i], findcheapest(j, mask - (1<<j), g,n) + g[i][j]);
            }
    }
    return d[mask][i];
}

int main() {
	cout << "Enter matrix size: ";
	int n;
	cin >> n;	
	vector<vector<float> > g(n, vector<float>(n));
	cout << "Enter your matrix: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            d[mask][i] = inf;
        }
    }
    d[0][0] = 0;
    float ans;
    ans = findcheapest(0, (1<<n) - 1, g,n);
    findway(g,n);

    for (int i = 0; i < n; i++){
        path[i]+=1;
    }
    cout << "The shortest way: " << endl;
    for (int i = 0; i < n; i++){
		cout << path[i] << " -> ";
    }
    cout << "1" << endl;
    cout << "Length = " << ans;	
	return 0;
}
