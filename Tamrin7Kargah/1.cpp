#include <iostream>
using namespace std;

int fib(int x) {
   if((x==1)||(x==0)) {
      return x;
   }else {
      return(fib(x-1)+fib(x-2));
   }
}
int main() {
   int x=1000;
   for(int i=0 ; i<x ; i++) {
      cout << " " << fib(i);
   }
   return 0;
}