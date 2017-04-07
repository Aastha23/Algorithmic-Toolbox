#include<iostream>
using namespace std;

int gcd(int a, int b) {
  int temp = 1;
  while(b!=0)
  { temp=a%b;
    a=b;
    b=temp;
  }
  
  return a;
}

int main()
{ 
    long long a,b,temp;
    cin>>a>>b;
    if(a>=b)
    temp=gcd(a,b);
    else
    temp=gcd(b,a);
    //lcm*gcd = a*b
    a=a/temp;
    a=a*b;
    cout<<a;
	return 0;
}
