#include <string>
#include <iostream>

using namespace std ;

int main ()
 {
    string T;
    cout << "enter your string : ";
    getline(cin,T);
    int n =1;
    for (int s = 0; s < T.length(); s++)
    {
        if (T[s] == ' ' && T[s+1] != ' ') 
        {
            n++;
        }
    }
    cout << n;

    return 0;
}