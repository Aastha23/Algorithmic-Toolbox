#include <iostream>

int get_change(int m) 
{ int cnt=0; 
  int temp;  
  if(m>0)
  { if(m>=10)
  { temp=m/10;
    cnt=cnt+temp; 
  	m=m-(temp*10);
  }
   if(m>=5)
  { temp=m/5; 
    cnt=cnt+temp;
  	m=m-(temp*5);
  } 
  cnt=cnt+m;
  }
  return cnt;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n'; 
}
