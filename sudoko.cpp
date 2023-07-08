#include<iostream>
#include<math.h>
using namespace std;
bool canplace(int board[][9],int i,int j,int no,int n ){
 //check rows and columns
 for (int k=0;k<n;k++){
    if(board[i][k]==no || board[k][j]==no){
        return false;
    }
 }
 //check for subgrid
   int sn=sqrt(n);
   int sx=(i/sn)*sn;
   int sy=(j/sn)*sn;
   for(int x=sx; x<sx+sn; x++){
    for(int y=sy; y<sy+sn; y++){
        if(board[i][j]==no){
            return false;
        }
    }
   }
return true;
}
bool solvesudoko(int board[][9],int i,int j,int n){
    //base case

    if(i==n){
        //print the board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

         return true;
    }
    //recursive case
    //reached end of the row
    if(j==n){
      return  solvesudoko(board,i+1,0,n);
    }
    //skip already filled box
    if(board[i][j]!=0){
        return solvesudoko(board,i,j+1,n);
    }
    //box to be filled
    for(int no=1;no<=n;no++){
        if(canplace(board,i,j,no,n)){
            board[i][j]=no;
            bool subsolution=solvesudoko(board,i,j+1,n);
            if(subsolution){
                return true;
            }
        }
    }
    //backtracking
    //if no number gives solution return false
    board[i][j]=0;
    return false;

}
int main(){
    int n;
    cin>>n;
    int board[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solvesudoko(board,0,0,n);
}