#include <algorithm> 
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

void largest_number(vector<string> a) 
{  string temp; 
   sort(a.begin(),a.end());

  for(int i=0;i<a.size();i++)
  {  
    for(int j=i+1;j<a.size();j++)
     {  string a1,b1;
		a1=a1.append(a[i]);
		a1=a1.append(a[j]);
		b1=b1.append(a[j]); 
	    b1=b1.append(a[i]);
        if(a1>b1);
        else
        {
           string temp=a[i];
           a[i]=a[j];
           a[j]=temp;
		}
	 }
  
  } 
  
 for (int i = 0; i <a.size(); i++) 
  { std::cout<<a[i];
  } 
}

int main() 
{ 
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) 
  {
    std::cin >> a[i];
  }
  
   largest_number(a);
  

}
