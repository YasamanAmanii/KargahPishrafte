#include <iostream>	

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j % 2 == 0)
				cout << "*";
			else
				cout << "#";
		}
		cout << endl;

	}
	system("pause");
}