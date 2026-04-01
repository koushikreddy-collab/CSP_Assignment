#include <stdio.h>
#include <stdbool.h>

char *districts[] = {"Adilabad","Nirmal","Nizamabad","Kamareddy","Karimnagar","Warangal"};
char *colors[] = {"Red","Green","Blue","Yellow"};

int graph[6][6] = {
    {0,1,0,0,0,0},
    {1,0,1,0,0,0},
    {0,1,0,1,0,0},
    {0,0,1,0,1,0},
    {0,0,0,1,0,1},
    {0,0,0,0,1,0}
};

int sol[6];

bool isSafe(int node, int color) {
    for(int i=0;i<6;i++) {
        if(graph[node][i] && sol[i]==color)
            return false;
    }
    return true;
}

bool solve(int node) {
    if(node==6) return true;

    for(int c=1;c<=4;c++) {
        if(isSafe(node,c)) {
            sol[node]=c;
            if(solve(node+1)) return true;
            sol[node]=0;
        }
    }
    return false;
}

int main() {
    solve(0);
    for(int i=0;i<6;i++) {
        printf("%s -> %s\n", districts[i], colors[sol[i]-1]);
    }
    return 0;
}
