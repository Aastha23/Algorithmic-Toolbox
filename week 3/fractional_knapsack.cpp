#include <iostream>
#include <vector>
#include<cstdio>
using std::vector;


double get_optimal_value(int W, vector<int> weights, vector<int> values)
 {   int n=weights.size();
     int temp;
	double value = 0.0,min,max=0.0;
    
    for(int i=0;i<n;i++)
   { max=0,min=99999999; 
	 if(W==0) 
     return value;
     for(int j=0;j<n;j++)
	  { 
	   if( weights[j]>0 && ((double)values[j]/(double)weights[j]) >=max ) 
	    	 {  
			 max= ((double)values[j]/(double)weights[j]);
			 temp=j;
	         }
	  }
	  if(max==0) return value; //All the weights have become 0
	  
	  if(W<=weights[temp])
	    min=W;
	  else
	   min=weights[temp];
	   
	   value=value+min*max;  
	   W=W-min;
	   weights[temp]=weights[temp]-min;
   }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  std::cout<<optimal_value;
 // printf("%.4f",optimal_value);
  return 0;
}
