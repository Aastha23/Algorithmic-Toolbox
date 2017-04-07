#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;
 
    vector<long long> a;
    a.push_back(0); 
    a.push_back(1);  
    long long cnt;
    // for some power of 10 and few other no the sequence count goes longer. Ex:for m=1000, sequence count is 1500.
    // and it is known that sequence count will be less than 6*m. Hence we run loop till there.
    for (long long i = 2; i <=(6*m)+1; ++i) 
	{ 
        a.push_back( ( a[i-1] + a[i-2] )%m ) ; 
        cnt=i;
        if(a[i-1]==0 && a[i]==1)   //sequence starts at 01. So when you get 01 you have to stop count.
         {break; }
    }

    long long f = n%(cnt-1);  
    return a[f];
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_naive(n, m) << '\n';
}
