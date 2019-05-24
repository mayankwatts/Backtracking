#include <iostream>
using namespace std;

void order(int num,int a){

    if(a<=num)
    cout<<a<<endl;
    for(int j=0;j<10;j++){
      if(10*a<=num){
        order(num,(10*a)+j);
      } 
      else
      	break;
    }
  
      return ;
  
}

void lexicographicalOrder(int num){
	// Write your code here
  for(int i=1;i<10;i++)
 order(num,i);
 
}

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
    
    return 0;
}
