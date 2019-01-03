
//농작물 수확하기
#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int map[49][49];
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		int answer = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%1d",&map[i][j]);
		int x, y;
		x = y = N / 2;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((abs(x - i) + abs(y - j)) <= N / 2)
					answer += map[i][j];
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}