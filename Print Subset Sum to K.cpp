#include <iostream>
using namespace std;

void subset(int input[], int output[] ,int size, int k,int count){
  if(size==0){
    if(k==0){
      for(int i=0;i<count;i++){
        cout<<output[i]<<" ";
      }
      cout<<endl;
      return;
    }
    else
    return;
  }
 
  subset(input+1,output,size-1,k,count);
  output[count]=input[0];
  count++;
  subset(input+1,output,size-1,k-input[0],count);
     
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[size];
    int count=0;
  subset(input,output,size,k,count);
  
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
