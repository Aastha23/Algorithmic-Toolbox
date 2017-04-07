#include <iostream>
#include <vector>
#include <cstdlib>
#include<algorithm>

using std::vector;
using std::swap;
int m1;

int partition3(vector<int> &a, int l, int r) {
  vector<int> pos;
  m1=0;
  int cnt=0;
  int x = a[r];
  int j = l-1;
  for (int i = l; i <r; i++) 
  { 
    if (a[i] <= x) 
	{ j++;
      swap(a[i], a[j]);
	  if (a[j] == x) 
	 {  pos.push_back(j);
	   cnt++;
     } 
    }
     
  }

   // for same elements in the array
   int temp=j;
   while(!pos.empty())
   { 
    swap(a[pos[pos.size()-1]],a[temp]);
    temp--;
    pos.erase(pos.begin()+pos.size()-1);
   }
  m1=temp+1;
  swap(a[r], a[j+1]);
  return j+1;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  
 if(l<r)
  {
  int k = l + rand() % (r - l + 1);  
  swap(a[r], a[k]);
  
  int m2 = partition3(a, l, r);
  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
 // sort(a.begin(),a.end());
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
