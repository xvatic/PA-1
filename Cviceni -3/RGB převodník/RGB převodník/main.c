#include <stdio.h>

int main(void) {
    int x=-1,y=0,z=0;
    char r,g,b,zl,zr,c1,c2;

    printf("Zadejte barvu v RGB formatu:\n");
    if (scanf(" %c%c%c %c %d %c %d %c %d %c", &r,&g,&b,&zl, &x,&c1 ,&y, &c2, &z, &zr  ) != 10 || x<0 || x > 255 || y<0 || y> 255 || z<0 || z > 255 || r != 'r' || g != 'g' || b != 'b' || zl != '(' || zr != ')' || c1 != ',' || c2 != ',' ) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    
    
    printf("#%02X%02X%02X\n", x, y, z);
    return 0;
     
    
}
