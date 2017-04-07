#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include<algorithm>

using std::vector;

vector<int> optimal_points(int a[][2],int n) {
  
 for(int i=0;i<n;i++)
 {  int temp;
 	for(int j=i+1;j<n;j++)
 	{ if(a[i][0]>a[j][0])
 		{ temp=a[i][0];
 		a[i][0]=a[j][0];
 		a[j][0]=temp;
        temp=a[i][1];
 		a[i][1]=a[j][1];
 		a[j][1]=temp;
	   }
    }
}
  int cnt=0;

 
 int k=0; 
    vector<int> points;
    int end;
	while(k<n)
   { 
	  end=a[k][1];   
      k++;
	  while( a[k][0]<=end && k<n )
	  {
	    if(a[k][0]<=end && a[k][1]>=end && k<n)  //next segment beggining <=  previous segment ending
	     {  
		     k++;
	     }
	    else if( a[k][0]<=end && a[k][1]<=end && k<n)
         { 
	       end=a[k][1]; 
		   k++;
	     } 
      }
     points.push_back(end); 
	 //cout<<end<<" is end\n";
	 cnt++;
   } 
   return points;	
  //write your code here
/*  for (size_t i = 0; i < s.size(); ++i) {
    points.push_back(s[i].start);
    points.push_back(s[i].end);
  }
  return points; */
}

int main() {
  int n;
  std::cin >> n; 
  int a[n][2];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> a[i][0]>>a[i][1];
  }
  vector<int> points = optimal_points(a,n);
 std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
