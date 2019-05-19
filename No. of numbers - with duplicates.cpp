#include <iostream>
using namespace std;

long duplicate(long input[],long size,long fact[],long freq[]){
  if(size==0 || size==1){
    return 0;
  }
  
  long ans=0;
  long den=1;
  for(long i=0;i<10;i++){
    den*=fact[freq[i]];
  }
  for(long i=input[0]+1;i<10;i++){
    if(freq[i]>0){
      ans+=(fact[size-1]*freq[i])/den;
    }
  }
  
  freq[input[0]]--;
  ans+=duplicate(input+1,size-1,fact,freq);
  return ans;
  
}

long numberOfNumbersWithDuplicates(long num){
	
  long input[1000000];
  long count=-1;
  long i=num%10;
    while(num!=0){
      count++;
      input[count]=i;
      num=num/10;
      i=num%10;
    }
  
  long real[count+1];
  long freq[10]={};
  long fact[count+2];
  fact[0]=1;
  for(long i=0;i<count+1;i++){
    real[i]=input[count-i];
    freq[real[i]]++;
    fact[i+1]=(i+1)*fact[i];
  }
  
  return duplicate(real,count+1,fact,freq);
}


int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
    
    return 0;
}
