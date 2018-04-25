#include<stdio.h>
#define MAX_ROW 6
#define MAX_COL 6

typedef struct Maze{
    int map[MAX_ROW][MAX_COL];
}Maze;

typedef struct Node{
    int row;
    int col;
}Node;

void MapPrint(Maze* maze) {
    int i = 0;
    int j = 0;
    for(; i<MAX_ROW; i++) {
        for(j = 0; j<MAX_COL; j++){
            printf("%d ", maze->map[i][j]);
        }
        printf("\n");
    }
}

int CanStay1(Maze* maze, Node* pos) {
    if(maze->map[pos->row][pos->col] == 1) {
        return 1;
    }
    return 0;
}

int IsExit(Node* pos, Node* entry) {
    if(pos->row == entry->row || pos->col == entry->col) {
        return 0;
    }
    if(pos->row == 0 || pos->row == MAX_ROW - 1 || pos->col == 0 || pos->col == MAX_COL - 1) {
        return 1;
    }
    return 0;
}

void Mark1(Maze* maze, Node* entry) {
    maze->map[entry->row][entry->col] = 2;
}

//////////////////////////////////////////////////////////
//runde 1
//////////////////////////////////////////////////////////
void MapInit1(Maze* maze) {
    int arr[MAX_ROW][MAX_COL] = {
        {0,1,0,0,0,0},
        {0,1,1,1,1,0},
        {0,1,0,0,1,0},
        {0,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,0,0,0}
    };
    int i;
    int j;
    for(i = 0; i<MAX_ROW; i++) {
        for(j = 0; j<MAX_COL; j++) {
            maze->map[i][j] = arr[i][j];
        }
    }
    return;
}


void GetPath_R(Maze* maze, Node* pos, Node* entry) {
    if(pos->row < 0 || pos->row > MAX_ROW - 1 || pos->col < 0 || pos->col > MAX_COL){
        return;
    } 
    if(maze == NULL || entry == NULL) {
        return ;
    }
    //先判断入口点是否可以落脚,如果可以落脚，标记,否则返回 0 
    if(!CanStay1(maze, pos)) {
        return ;
    }
    Mark1(maze, pos);
    if(IsExit(pos, entry)) {
        printf("找到一条路径！\n"); 
    }
    //判断是不是出口
    //依次判断该点的上 右 下 左 四个方向时候可以落脚
    Node node;
    node.row = pos->row;
    node.col = pos->col - 1;
    GetPath_R(maze, &node, entry);
    node.row = pos->row + 1;
    node.col = pos->col;
    GetPath_R(maze, &node, entry);
    node.row = pos->row;
    node.col = pos->col + 1;
    GetPath_R(maze, &node, entry);
    node.row = pos->row - 1;
    node.col = pos->col;
    GetPath_R(maze, &node, entry);
}

//////////////////////////////////////////////////////////
//runde 2
//////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////
//以下为测试代码
///////////////////////////////////////////////////////////

void Test1(){
    Maze maze;
    MapInit1(&maze);
    Node entry = {0, 1};
    GetPath_R(&maze, &entry, &entry);
    MapPrint(&maze);
}

int main() 
{
    Test1();
    

    return 0;
}
