#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, z, o, t, r, f, v, s, e, g, n;
    z = t = o = r = f = v = s = e = g = n = 0;
    char* str;
    str = malloc(1024*sizeof(char));
    scanf("%[^\n]",str);
    str = realloc(str, strlen(str) + 1);
    
    for(i=0;i<strlen(str);i++){
        switch(str[i]){
            case '0':
                z++;
                break;
            case '1':
                o++;
                break;
            case '2':
                t++;
                break;
            case '3':
                r++;
                break;
            case '4':
                f++;
                break;
            case '5':
                v++;
                break;
            case '6':
                s++;
                break;
            case '7':
                e++;
                break;
            case '8':
                g++;
                break;
            case '9':
                n++;
                break;
            default:
                break;
        }    
    }
    printf("%d %d %d %d %d %d %d %d %d %d ", z, o, t, r, f, v, s, e, g, n);
    
    return 0;
}
