#include<iostream>
using namespace std;

bool sudo(int board[][9],int x,int y){
  
  if(x==9){
    return true;
  }
  
  if(board[x][y]!=0){
    if(y<8){
      return sudo(board,x,y+1);
    }
    if(y==8){
      return sudo(board,x+1,0);
    }
  }
  
  if(board[x][y]==0){
  
  for(int i=1;i<10;i++){
    int flag=0;
    for(int j=0;j<9;j++){
      if(board[x][j]==i || board[j][y]==i){
        flag=1;
        break;
      } 
    }
    if(flag==0){
      int m=x-x%3;
      int n=y-y%3;
      for(int p=m;p<m+3;p++){
        for(int q=n;q<n+3;q++){
          if(board[p][q]==i){
            flag=1;
            break;
          }
        }
      }   
    }
    if(flag==0){
      board[x][y]=i;
      if(y<8){
        if(sudo(board,x,y+1)){
          return true;
        }                                                                         
      }
      if(y>=8){
        if(sudo(board,x+1,0)){
          return true;
        }   
      }  
    }
  }
  }
  board[x][y]=0;
  return false;
}

bool sudokuSolver(int board[][9]){
  return sudo(board,0,0);

}


int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
  return 0;
  
}


