//보급로
#include <iostream>
using namespace std;

int T,N,answer;
int map[100][100];
int visit[100][100];
int dx[4] = { -1,0,1,0 };//하우 좌우
int dy[4] = { 0,1,0,-1 };


int dist[100][100];

void dfs(int x, int y, int t)
{
	if (x == N - 1 && y == N - 1)
	{
		if (answer == 0)
			answer = t;
		else
		{
			if (answer > t)
				answer = t;
		}
		return;
	}
	if (answer > 0 && answer < t)
		return;
	//이 경로로왔는데 이전에 최소비용으로 지나갔으면 짤라버림
	if (dist[x][y] == 0)
		dist[x][y] = t;
	else
	{
		if (dist[x][y] > t)
			dist[x][y] = t;
		else
			return;
	}

	for (int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX >= 0 && newX < N && newY >= 0 && newY < N)
		{
			if (!visit[newX][newY])
			{
				visit[newX][newY] = true;
				dfs(newX, newY, t + map[newX][newY]);
				visit[newX][newY] = false;
			}
				
		}
	}
}
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		answer = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d",&map[i][j]);
				visit[i][j] = false;
				dist[i][j] = 0;
			}
		}
		visit[0][0] = true;
		dfs(0, 0, 0);
		printf("#%d %d\n",t,answer);
	}
	return 0;
}
