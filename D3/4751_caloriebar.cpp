//다솔이의 다이아몬드 장식
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		char str[51];
		cin >> str;
		int l = 0;
		for (int i = 0; i < 51; i++)
		{
			if (str[i] == '\0')
				break;
			else
				l++;
		}

		for (int i = 0; i < 5; i++)
		{
			if (i == 0 || i == 4)
			{
				cout << ".";
				for (int j = 0; j < l; j++)
					cout << ".#..";
			}
			else if (i == 1 || i == 3)
			{
				cout << ".";
				for (int j = 0; j < l * 2; j++)
					cout << "#.";
			}
			else
			{
				cout << "#";
				for (int j = 0; j < l; j++)
					cout << "." << str[j] << ".#";
			}
			cout << endl;
		}
	}
	return 0;
}