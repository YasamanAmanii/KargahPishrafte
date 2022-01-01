#include<iostream>
#include<string>
using namespace std;

class Kasr {

public:
	int soorat, makhraj;

	Kasr() {
		cout << "Enter soorat : ";
		cin >> this->soorat;
		cout << "Enter makhraj : ";
		cin >> this->makhraj;
	}

	void show(string S) {
		cout << S << endl;
		
		for (int i = this->soorat ; i >= 1; i--) {
			if (this->soorat%i == 0 && this->makhraj%i == 0)
			{
				this->soorat /= i;
				this->makhraj /= i;
			}
		}

		cout << this->soorat << "/" << this->makhraj << endl;
	}

	Kasr sum(Kasr kasr2)
	{
		int s, m;
		m = (this->makhraj*kasr2.makhraj);
		s = (this->makhraj*kasr2.soorat) + (this->soorat*kasr2.makhraj);
		kasr2.soorat = s;
		kasr2.makhraj = m;
		return kasr2;
	}
	Kasr sub(Kasr kasr2) {

		int s, m;
		m = (this->makhraj*kasr2.makhraj);
		s = (this->soorat*kasr2.makhraj) - (this->makhraj*kasr2.soorat);
		kasr2.soorat = s;
		kasr2.makhraj = m;
		return kasr2;
	}
	Kasr mul(Kasr kasr2) {
		int s, m;
		m = (this->makhraj*kasr2.makhraj);
		s = (this->soorat*kasr2.soorat);
		kasr2.soorat = s;
		kasr2.makhraj = m;
		return kasr2;
	}
	Kasr div(Kasr kasr2) {
		int s, m;
		m = (this->makhraj*kasr2.soorat);
		s = (this->soorat*kasr2.makhraj);
		kasr2.soorat = s;
		kasr2.makhraj = m;
		return kasr2;
	}
};

int main()
{
	cout << "Kasr 1 : " << endl;
	Kasr kasr1;
	cout << "Kasr 2 : " << endl;
	Kasr kasr2;
	kasr1.sum(kasr2).show("Sum : ");

	kasr1.sub(kasr2).show("Sub : ");

	kasr1.mul(kasr2).show("Mul : ");

	kasr1.div(kasr2).show("Div : ");
	
	
	
	
	system("pause");
	return 0;
}

