#include <iostream>	

using namespace std;

int main()
{
	int fact[11];
	for (int i = 0; i <= 11; i++)
	{
		fact[i] = 1;
		for (int j = 1; j <= i+2; j++)
		{
			fact[i] *= j;
		}
	
	}
	int n;
	cin >> n;
	for (int i = 0; i < 12; i++)
	{
		if (fact[i] == n)
		{
			cout << "Yes";
			system("pause");
			exit(0);
		}
	}
	cout << "No";
	system("pause");
}