#include <stdlib.h>
#include <stdio.h>


char * convert(char * s, int numRows){
    if (numRows == 1){
        return s;
    }
    
    int rim = 0;
    while (s[rim] != '\0'){
        rim++;
    }
    rim--;

    char* res = (char*)malloc(sizeof(char)*(rim+2));
    res[rim+1] = '\0';
    int j = 0;
    for (int i = 1; i <= numRows; i++){
        int temp = i-1;
        while (temp <= rim){
            printf("ok\n");
            res[j++] = s[temp];
            temp += 2*(numRows-i) != 0 ? 2*(numRows-i): 2*(numRows-1);
            if (temp <= rim){
                res[j++] = s[temp];
                temp += (2*(i-1) != 0) ? 2*(i-1): 2*(numRows-1);
            }
            else{
                break;
            }
        }
    }
    return res;
}



int main()
{
    char * ptr = convert("P", 1);
    printf("%s", ptr);
    printf("\n");
    return 0;
}