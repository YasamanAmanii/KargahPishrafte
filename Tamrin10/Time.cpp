#include<iostream>
#include<string>
using namespace std;

class Time {

public:
	int h, m ,s;

	Time(int H,int M,int S) {
		this->h = H;
		this->m = M;
		this->s = S;
		
	}

	void show(string S) {
		cout << S << endl;
		
		if (this->s >= 60) {
			this->s -= 60;
			this->m += 1;
		}
		if (this->s < 0) {
			this->s += 60;
			this->m -= 1;
		}
		if (this->m >= 60) {
			this->m -= 60;
			this->h += 1;
		}
		if (this->m < 0) {
			this->m += 60;
			this->h -= 1;
		}
		cout << this->h << ":" << this->m << ":"<<this->s << endl;
	}

	Time sum(Time time2)
	{
		time2.s = (this->s + time2.s);
		time2.m = (this->m + time2.m);
		time2.h = (this->h + time2.h);	 
		return time2;
	}
	Time sub(Time time2)
	{
		time2.s = (this->s - time2.s);
		time2.m = (this->m - time2.m);
		time2.h = (this->h - time2.h);
		return time2;
	}
	void Time2Sec(Time time2)
	{
		this->s += (this->m * 60) + (this->h * 3600);
		time2.s += (time2.m * 60) + (time2.h * 3600);
		cout << "Time 1 to seconds : " << this->s << endl;
		cout << "Time 2 to seconds : " << time2.s << endl;
	}
	static Time Second2Time(int s)
	{
		int hh, mm, ss;
		hh = s / 3600;
		s = s % 3600;
		mm = s / 60;
		ss = s % 60;
		Time t(hh, mm, ss);
		return t;
	}

};

int main()
{
	int h, m, s;
	cout << "Time 1 : " << endl;
	cout << "Enter hours : ";
	cin >> h;
	cout << "Enter minutes : ";
	cin >> m;
	cout << "Enter Seconds : ";
	cin >> s;
	Time time1(h,m,s);
	cout << "Time 2 : " << endl;
	cout << "Enter hours : ";
	cin >> h;
	cout << "Enter minutes : ";
	cin >> m;
	cout << "Enter Seconds : ";
	cin >> s;
	Time time2(h,m,s);
	
	time1.sum(time2).show("Sum : ");
	time1.sub(time2).show("Sub : ");
	time1.Time2Sec(time2);
	

	cout << "Enter seconds to turn into time : ";
	cin >> s;
	Time::Second2Time(s).show("Seconds to Time : " );



	system("pause");
	return 0;
}

