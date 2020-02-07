bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int hash[9];

    // check rows
    for (int row = 0; row < 9; row++){
        for (int i = 0; i < 9; i++){
            hash[i] = 0;
        }
        
        for (int col = 0; col < 9; col++){
            if (board[row][col] == '.'){
                continue;
            }
            if (hash[board[row][col]-49] == 0){
                hash[board[row][col]-49] = 1;
            }else{
                return false;
            }
        }
    }
    
    // check columns
    for (int col = 0; col < 9; col++){
        for (int i = 0; i < 9; i++){
            hash[i] = 0;
        }
        
        for (int row = 0; row < 9; row++){
            if (board[row][col] == '.'){
                continue;
            }
            if (hash[board[row][col]-49] == 0){
                hash[board[row][col]-49] = 1;
            }else{
                return false;
            }
        }
    }
    
    // check blocks
    for (int i = 0; i <= 6; i += 3){
        for (int j = 0; j <= 6; j += 3){
            for (int i = 0; i < 9; i++){
                hash[i] = 0;
            }
            
            for (int row = i; row < i+3; row++){
                for (int col = j; col < j+3; col++){
                    if (board[row][col] == '.'){
                        continue;
                    }
                    if (hash[board[row][col]-49] == 0){
                        hash[board[row][col]-49] = 1;
                    }else{
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

