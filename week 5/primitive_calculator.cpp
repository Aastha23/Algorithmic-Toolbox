#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) 
{ 
  vector<int> sequence;
  sequence.push_back(1);
  
  vector<int> v;
  vector<vector <int> > a ;
  vector<int> row;
   int temp,l=0;
  v.push_back(n);
  
 while(n>1 && v[0]!=0)
  {  
     row.push_back(v[0]);    
    
    if (v[0] % 3 == 0) 
	 {  if(v[0]/3 == 1) {  sequence.push_back(v[0]); temp=v[0]; break; }
	   l=0;
	  if(!a.empty())
	   {
	     for(int j=0;j<a.size();j++)
          { 
           for(int k=0;k<4;k++)
  	        { if(a[j][k]==v[0]/3)  
  	          { l++;
  	            row.push_back(0); 	
			  }
		    }
		  }
	    }
	    if(l==0)	    
        {
	      row.push_back(v[0]/3); 
          v.push_back(row[row.size()-1]);
        }
     } 
	else
	   row.push_back(0);   
	   
    if (v[0] % 2 == 0)
	 {  if(v[0]/2 == 1) {  sequence.push_back(v[0]); temp=v[0]; break; }
	 
	 l=0;
	  if(!a.empty())
	     for(int j=0;j<a.size();j++)
          { 
           for(int k=0;k<4;k++)
  	        { if(a[j][k]==v[0]/2)  
  	          { l++;
  	            row.push_back(0); 	
			  }
		    } 
		  }
	   if(l==0)	    
        {
        row.push_back(v[0]/2); 
        v.push_back(row[row.size()-1]);
       }
     }
    else
	row.push_back(0);   
	 
	if(v[0]>1)
	  {   if(v[0]/2 == 1) {  sequence.push_back(v[0]); temp=v[0]; break; }
	  
	    l=0;
	   if(!a.empty())
	     for(int j=0;j<a.size();j++)
          { 
           for(int k=0;k<4;k++)
  	        { if(a[j][k]==v[0]-1)  
  	          { l++;
  	            row.push_back(0); 	
			  }
		    } 
		  }
	    if(l==0)	    
        {
         row.push_back(v[0]-1);  
         v.push_back(row[row.size()-1]);
        }
      }
    else
	row.push_back(0);      
	   
                        
     v.erase(v.begin()+0); 
     a.push_back(row); 
	while(!row.empty())
	 	row.erase(row.begin());
	       
  }
  
  
  for(int j=a.size()-1;j>=0;j--)
   { 
    for(int k=1;k<4;k++)
  	  { if(a[j][k]==temp)
  	      { 
			temp=a[j][0];
			sequence.push_back(temp); 
			break;
  	      }
	  }
	 
   }
   
  return sequence;
}

int main() {
  int n;
  std::cin >> n; 
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
   std::cout << sequence[i] << " ";
  }
}
