#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int dist[5][5];
int n = 5;

void FloydWarshall(int adj[][5])
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j])
                dist[i][j] = adj[i][j];
            else
                dist[i][j] = INF;
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(void)
{
    int adj[5][5] = {{0, 2, 3, 7, 0},
                     {2, 0, 0, 3, 5},
                     {3, 0, 0, 1, 0},
                     {7, 3, 1, 0, 2},
                     {0, 5, 0, 2, 0}};
    FloydWarshall(adj);
    cout << "FloydWarshall" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}