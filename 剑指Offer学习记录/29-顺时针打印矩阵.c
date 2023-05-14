/*
 * @Author: yao fanghao
 * @Date: 2023-05-14 10:43:42
 * @LastEditTime: 2023-05-14 10:47:31
 * @LastEditors: yao fanghao
 */
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize, columns = matrixColSize[0];
    int visited[rows][columns];
    memset(visited, 0, sizeof(visited));
    int total = rows * columns;
    int* order = malloc(sizeof(int) * total);
    *returnSize = total;

    int row = 0, column = 0;
    int directionIndex = 0;
    for (int i = 0; i < total; i++) {
        order[i] = matrix[row][column];
        visited[row][column] = true;
        int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
        if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
            directionIndex = (directionIndex + 1) % 4;
        }
        row += directions[directionIndex][0];
        column += directions[directionIndex][1];
    }
    return order;
}
