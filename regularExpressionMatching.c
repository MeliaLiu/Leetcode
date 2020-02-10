#include <stdio.h>
#define bool int
#define true 1
#define false 0
bool isMatch(char* s, char* p){
    if (s[0] == 0 && p[0] == 0){
        return true;
    } else if (s[0] == 0 && p[0] != 0){
        if (p[1] == '*'){
            return isMatch(s, &p[2]);
        }
        return false;
    } else if (s[0] != 0 && p[0] == 0){
        return false;
    } else {
        if (p[1] != '*'){
            if (p[0] != s[0] && p[0] != '.'){
                return false;
            } else {
                return isMatch(&s[1], &p[1]);
            }
        } else {
            if (s[0] == p[0] || p[0] == '.'){
                return isMatch(s, &p[2]) || isMatch(&s[1], p);
            } else {
                return isMatch(s, &p[2]);
            }
        }
    }
}
int main()
{
    char* s = "ab";
    char* p = "mis*is*p*.";
    if (isMatch(s, p)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}