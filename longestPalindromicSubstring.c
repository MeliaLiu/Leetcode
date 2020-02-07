#include <stdio.h>
#include <stdlib.h>

char * longestPalindrome(char * s){
    // here we only compare the first character instead of the whole string
    if (*s == *""){  
        return "";
    }
    
    int count = 0;
    while (s[count] != 0){
        count++;
    }

    if (count == 0){
        return "";
    }
    
    int map[count][count];
    
    for (int i = 0; i < count; i++){
        map[i][i] = 1;
    }
    
    for (int i = 0; i < count-1; i++){
        map[i][i+1] = s[i] == s[i+1] ? 1 : 0;
    }
    
    for (int i = 2; i < count; i++){
        for (int j = 0; j < count-i; j++){
            map[j][j+i] = (map[j+1][j+i-1] && (s[j] == s[j+i])) ? 1 : 0;
        }
    }
    
    int start = 0;
    int end = 0;
    for (int row = 0; row < count; row++){
        for (int col = row; col < count; col++){
            if ((map[row][col] == 1) && (col-row > end-start)){
                start = row;
                end = col;
            }
        }
    }
    
    char* res = (char*)malloc((end-start+2)*sizeof(char));
    for (int i = start; i <= end; i++){
        res[i-start] = s[i];
    }
    res[end-start+1] = '\0';
    return res;
}


int main()
{
    char* ptr = longestPalindrome("");
    printf("%s", ptr);
    return 0;
}