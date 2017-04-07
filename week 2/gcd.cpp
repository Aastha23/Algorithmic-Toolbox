#include <iostream>

int gcd_naive(int a, int b) {
  int temp = 1;
  while(b!=0)
  { temp=a%b;
    a=b;
    b=temp;
  }
  
  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  if(a>=b)
  std::cout << gcd_naive(a, b) << std::endl;
  else
   std::cout << gcd_naive(b,a) << std::endl;
  return 0;
}
