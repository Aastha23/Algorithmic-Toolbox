#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::vector;


long long get_fibonacci(long long n) {
    if (n <= 1)
        return n;
 
    vector<long long> a;
    a.push_back(0); 
    a.push_back(1);  
    long long cnt;
    
   long long m=10;
    for (long long i = 2; i <=6*m+1; ++i) 
	{  long long pw=pow(10,18);
        a.push_back( ( a[i-1] + a[i-2] )%pw ) ; 
        cnt=i;
        if(a[i-1]==0 && a[i]==1) 
         {  break; }
    }
    
    long long f =(n+2)%(cnt-1);
    long long var=a[f]-1;
    return var; 
}

int main() {
    long long n,m;
    cin >> n>>m;
    cout << (get_fibonacci(m)- get_fibonacci(n-1))%10<< '\n';
  //  else
    // cout << get_fibonacci(n)%10;
}
