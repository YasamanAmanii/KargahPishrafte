#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b)
	{
		int buf = a;
		a = b;
		b = buf;
	}

	for (int i = a; ; i += a)
	{
		if (i%b == 0)
		{
			cout << "kochektarin mazrab moshtarak : " << i << endl;
			break;
		}
	}
	system("pause");
}