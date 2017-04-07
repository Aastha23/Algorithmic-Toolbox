#include <iostream>
#include <vector>
#include <cstdlib>
#include<algorithm>

using std::vector;
using std::swap;
int m1;
vector<int> end;

int partition3(vector<int> &a, int l, int r)
{
  vector<int> pos;
  m1=0;
  int cnt=0;
  int x = a[r];
  int j = l-1;
  for (int i = l; i <r; i++) 
  { if (a[i] <= x) 
	{ j++;
      swap(a[i], a[j]);
      swap(end[i],end[j]);
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
    swap(end[pos[pos.size()-1]],end[temp]);
    temp--;
    pos.erase(pos.begin()+pos.size()-1);
   }
  m1=temp+1;
  swap(a[r], a[j+1]);
  swap(end[r],end[j+1]);
  return j+1;
}

void randomized_quick_sort(vector<int> &a, int l, int r) 
{
  
  if(l<r)
  {
  int k = l + rand() % (r - l + 1);  
  swap(a[r], a[k]); 
  swap(end[r],end[k]);
  
  int m2 = partition3(a, l, r);
  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
  }
}

vector<int> fast_count_segments(vector<int> starts,vector<int> points) 
{ 
  vector<int> cnt(points.size());
  for(int i=0;i< points.size();i++)
  {
  	int p=points[i];
  	 for(int j=0;j<starts.size();j++)
  	 { if(p>=starts[j] && p<=end[j])
       cnt[i]++;  
	   else if( starts[j]>p ) 
         break;	
     }
  }
  return cnt;
}

int main() 
{
  int n,m,temp;
  std::cin >> n >> m;
  vector<int> starts(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> temp;
	end.push_back(temp); 
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  
   randomized_quick_sort( starts,0,n-1 ); 
   vector<int> cnt = fast_count_segments(starts, points);
  for (size_t i = 0; i < m; i++) {
    std::cout <<cnt[i] << ' ';
  }
}
