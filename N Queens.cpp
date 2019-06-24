#include<iostream>
using namespace std;

void placeNQueen(int n,int** dp,int x){
    if(x==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
        return ;
    }
    
    for(int j=0;j<n;j++){
        
        int i=0;
        while(i<n){
            if(dp[i][j]==1){
                break;
            }
            i++;
        }
        
        if(i<n){
            continue;
        }
        
        i=x;
        int flag=1;
        int z=1;
        while(flag){
            if(i-z>=0 && j-z>=0 && dp[i-z][j-z]==1){
                break;
            }
            if(i-z>=0 && j+z<n && dp[i-z][j+z]==1){
                break;
            }
            if(i+z<n && j+z<n && dp[i+z][j+z]==1){
                break;
            }
            if(i+z<n && j-z>=0 && dp[i+z][j-z]==1){
                break;
            }
            flag=0;
            if((i-z>=0 && j-z>=0) || (i-z>=0 && j+z<n) || (i+z<n && j+z<n) || (i+z<n && j-z>=0)){
                flag=1;
            }
            z++;
        }
        
        if(flag==1){
            continue;
        }
        
        dp[x][j]=1;
        placeNQueen(n,dp,x+1);
        dp[x][j]=0;
    }
    
    return;
    
}

void placeNQueens(int n){
    
    int** dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i] = new int[n];
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    
    int k=0;
    placeNQueen(n,dp,k);

}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);
  
  return 0;
}
