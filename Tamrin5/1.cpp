#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "enter n :  ";
	
	cin >> n;
	
	for (int j = 1; j <= n; j++)
	{
		int C = 1; 

		for (int i = 1; i < (n - j + 1); i++){
			cout << " ";
		}

		for (int i = 1; i <= j; i++)
		{
			cout << C << " ";
			C = C * (j - i) / i;
		}

		cout << "\n";
	}


	return 0;
}
