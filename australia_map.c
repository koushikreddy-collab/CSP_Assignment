#include <stdio.h>
#include <stdbool.h>

char *states[] = {"WA","NT","SA","QLD","NSW","VIC","T"};
char *colors[] = {"Red","Green","Blue"};

int graph[7][7] = {
    {0,1,1,0,0,0,0},
    {1,0,1,1,0,0,0},
    {1,1,0,1,1,1,0},
    {0,1,1,0,1,0,0},
    {0,0,1,1,0,1,0},
    {0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0}
};

int solution[7];

bool isSafe(int node, int color) {
    for(int i=0;i<7;i++) {
        if(graph[node][i] && solution[i]==color)
            return false;
    }
    return true;
}

bool solve(int node) {
    if(node==7) return true;

    for(int c=1;c<=3;c++) {
        if(isSafe(node,c)) {
            solution[node]=c;
            if(solve(node+1)) return true;
            solution[node]=0;
        }
    }
    return false;
}

int main() {
    solve(0);
    for(int i=0;i<7;i++) {
        printf("%s -> %s\n", states[i], colors[solution[i]-1]);
    }
    return 0;
}
