#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return 0;           //0 element
  if (left + 1 == right) return 1;      //1 element
  sort(a.begin(),a.end());
  
  int max=0;
  int temp=0,cnt=1;
  
  for(int i=1;i<a.size();i++)
  {   if(a[i]==a[i-1])  
       cnt++;  
      else
       { if(cnt>temp)
          temp=cnt;
         cnt=1; 
	   }
  }
  if(temp>cnt)
  cnt=temp;
  
  	if(cnt>a.size()/2) 
  	 return 1;
  
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) ) << '\n';
}
