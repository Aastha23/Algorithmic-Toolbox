#include <iostream>
#include <string>

using std::string;
using std::min;

int edit_distance(const string &str1, const string &str2)
 { int d[str1.length()+1][str2.length()+1];
   int ins=0,del=0,mat=0,mis=0; 
   for(int i=0;i<=str1.length();i++)
   {
   	d[i][0]=i; 
   }
   for(int i=0;i<=str2.length();i++)
   {
   	d[0][i]=i; 
   }
   
   for(int j=1;j<=str2.length();j++)
   { 
   	for(int i=1;i<=str1.length();i++)
   	 {
   		ins=d[i][j-1]+1;
   		del=d[i-1][j]+1;
   		mat=d[i-1][j-1];
   		mis=d[i-1][j-1]+1;
   		if(str1[i-1]==str2[j-1])  
   		 {
		  d[i][j]=min(ins,del);
		  d[i][j]=min(d[i][j],mat);
	     }
   		else
		 {
		  d[i][j]=min(ins,del); 
		  d[i][j]=min(d[i][j],mis);
	     }
	 }
   }
   
  return d[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
