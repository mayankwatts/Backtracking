#include <iostream>
using namespace std;



int subset(int input[], int n, int output[100000][1000]) {
    if(n==0){
      output[0][0]=0;
      return 1;
    }
  int a=subset(input+1,n-1,output);
    for(int i=a;i<2*a;i++){
      output[i][0]=output[i-a][0]+1;
      output[i][1]=input[0];
      for(int j=1;j<output[i][0];j++){
        output[i][j+1]=output[i-a][j];  
      } 
    } 
  
  for(int i=a;i<2*a;i++){
    for(int j=1;j<output[i][0]+1;j++){
      cout<<output[i][j]<<" ";
    }
    cout<<endl;
  }
  
  return 2*a;

}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
  int output[100000][1000];
  int a=subset(input,size,output);
    
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
  
  return 0;
}
