#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
 {
   vector<int> sum;
   int i=1,temp;
   
   while(n>=i)
   {
     n=n-i;
     sum.push_back(i);
     temp=i;
     i++;
   }
   if(n<i)
    {
	  sum.erase(sum.begin()+sum.size()-1);
	  sum.push_back(temp+n);
    }
   
   return sum;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
