//백반장자프로젝트
#include <iostream>
using namespace std;
int T, N;
int price[1000000];
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
			cin >> price[n];

		long answer = 0; 
		for (int i = 0; i < N;)
		{
			int num = 0;
			int Max = -1;
			int day = i;
			for (int j = i; j < N; j++)
			{
				if (price[j] > Max)
				{
					Max = price[j];
					day = j;
				}
			}
			
			for (int j = i; j < day; j++)
			{
				num++;
				answer -= price[j];
			}
			if (i == day)
			{
				i++;
			}
			else
			{
				answer += price[day] * num;
				i = day;
			}
		}
		cout << "#" << t << " " << answer << endl;
	}
    return 0;
}