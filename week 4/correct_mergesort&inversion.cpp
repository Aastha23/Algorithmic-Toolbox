#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
long long int cnt=0;

vector<int> merge(vector<int> &b,vector<int> &c)
{   int n1=b.size();
    int n2=c.size();
    vector <int> d(n1+n2);
    
    int j=0,k=0;
	 while(!b.empty() && !c.empty()) 
	   {
	     if(b[j]<=c[j])  
	     { d[k]=b[j]; 
		   k++; 
 	       b.erase(b.begin()+j); 
		 }
	     else
	     { d[k]=c[j]; 
		   k++; 
		   cnt+=b.size();
	       c.erase(c.begin()+j); 
	   	 }	
       }
       
       for(int i=k;i<(n1+n2);i++)
       {  if(!b.empty())
       	   {  
       	      d[i]=b[j];
			  b.erase(b.begin()+j);	 	
		   }
		  else if(!c.empty())
       	   {  
       	      d[i]=c[j];
			  c.erase(c.begin()+j);	 	
		   } 
	   }

    return d;
}

vector<int> mergesort(vector<int> &a,int l,int r)
{ 
   if(a.size()==1)
     return a;
    
    int mid=(l+r)/2;  
    vector<int> d,b,c;
    
   for(int i=l;i<=mid;i++)
   {
   	  b.push_back(a[i]);  
   } 
   b=mergesort(b,0,b.size()-1);
   
   for(int i=mid+1;i<=r;i++)
   { 
   	  c.push_back(a[i]);
   }
   c=mergesort(c,0,c.size()-1);
   
   d=merge( b,c);
   return d; 
 
}


int main()
{  
    int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{ cin>>a[i];
	}	
	
	vector<int>d= mergesort(a,0,a.size()-1);
	
	cout<<cnt;
	return 0;
}
