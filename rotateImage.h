void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int startIndex = 0; startIndex < matrixSize/2; startIndex++){
        int endIndex = matrixSize-startIndex-1;
        for (int j = startIndex; j < endIndex; j++){
            int temp = matrix[startIndex][j];
            matrix[startIndex][j] = matrix[endIndex-j+startIndex][startIndex];
            matrix[endIndex-j+startIndex][startIndex] = matrix[endIndex][endIndex-j+startIndex];
            matrix[endIndex][endIndex-j+startIndex] = matrix[j][endIndex];
            matrix[j][endIndex] = temp;
        }
    }
}
