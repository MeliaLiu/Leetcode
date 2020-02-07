

bool buddyStrings(char * A, char * B){
    if (A[0] == 0 || B[0] == 0){
        return false;
    }
    int diffIndex[3] = {-1, -1, -1}; 

    for (int i = 0, countDiff = 0; A[i] != 0; ++i){
        if ((A[i+1] == 0) && (B[i+1] != 0) || (B[i+1] == 0 && A[i+1] != 0) || (countDiff > 2)){
            return false;
        }

        if (A[i] != B[i]){
            diffIndex[countDiff] = i;
            ++countDiff;
        }
    }
    if (diffIndex[0] == -1){
        bool arr[26];
        for (int i = 0; i < 26; ++i){
            arr[i] = false;
        }
        
        for (int i = 0; A[i] != 0; ++i){
            if (arr[A[i]-'a']){
                return true;
            }else{
                arr[A[i]-'a'] = true;
                if (A[i+1] == 0){
                    return false;
                }
            }
        }
    }
    if ((A[diffIndex[0]] == B[diffIndex[1]]) && (A[diffIndex[1]] == B[diffIndex[0]])){
        return true;
    }else{
        return false;
    }
}