#include <stdio.h>

int board[9][9] = {
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

int isSafe(int r,int c,int num){
    for(int i=0;i<9;i++)
        if(board[r][i]==num || board[i][c]==num) return 0;

    int sr=r-r%3, sc=c-c%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[sr+i][sc+j]==num) return 0;

    return 1;
}

int solve(){
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            if(board[r][c]==0){
                for(int num=1;num<=9;num++){
                    if(isSafe(r,c,num)){
                        board[r][c]=num;
                        if(solve()) return 1;
                        board[r][c]=0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    solve();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}
