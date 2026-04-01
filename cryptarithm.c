#include <stdio.h>

int main() {
    for(int s=1;s<=9;s++)
    for(int e=0;e<=9;e++) if(e!=s)
    for(int n=0;n<=9;n++) if(n!=s && n!=e)
    for(int d=0;d<=9;d++) if(d!=s && d!=e && d!=n)
    for(int m=1;m<=9;m++) if(m!=s && m!=e && m!=n && m!=d)
    for(int o=0;o<=9;o++) if(o!=s && o!=e && o!=n && o!=d && o!=m)
    for(int r=0;r<=9;r++) if(r!=s && r!=e && r!=n && r!=d && r!=m && r!=o)
    for(int y=0;y<=9;y++) if(y!=s && y!=e && y!=n && y!=d && y!=m && y!=o && y!=r)
    {
        int send = 1000*s + 100*e + 10*n + d;
        int more = 1000*m + 100*o + 10*r + e;
        int money = 10000*m + 1000*o + 100*n + 10*e + y;

        if(send + more == money){
            printf("%d + %d = %d\n", send, more, money);
            return 0;
        }
    }
}
