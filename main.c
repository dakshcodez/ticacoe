#include<stdio.h>
#include<stdbool.h>

bool checkWin(int*  r1,int* r2,int* r3);
void getInput(int* row, int* col);
void markInput(int* r1, int* r2, int* r3, int input_row, int input_col, int player);
void printboard(int* r1, int* r2, int* r3);
void printRow(int* row, int rowSize);
bool checkDraw(int* r1, int* r2, int* r3);

int main(){
    //board
    int r1[3] = {0,0,0};
    int r2[3] = {0,0,0};
    int r3[3] = {0,0,0};

    int input_row = 0;
    int input_col = 0;

    //players
    int player = 1;

    //game loop

    while (true){
        printboard(r1,r2,r3);
        printf("Player %d's turn\n", player);
        getInput(&input_row, &input_col);
        
        markInput(r1,r2,r3,input_row,input_col,player);
        
        //checking win

        if (checkWin(r1,r2,r3) == true){
            printf("player %d won the game.", player);
            break;
        } else{
            if (player == 1){
                player = 0;
            }
            else{
                player = 1;
            }
        } 
        if (checkDraw(r1,r2,r3) == true){
            printf("That's a Draw.\n");
            break;
        }
    }

    return 0;
}

bool checkWin(int* r1, int* r2, int* r3) {
    // Check for rows
    if (r1[0] == r1[1] && r1[1] == r1[2] && r1[0] != 0) {
        return true;
    }
    else if (r2[0] == r2[1] && r2[1] == r2[2] && r2[0] != 0) {
        return true;
    }
    else if (r3[0] == r3[1] && r3[1] == r3[2] && r3[0] != 0) {
        return true;
    }
    // Check for columns
    else if (r1[0] == r2[0] && r2[0] == r3[0] && r1[0] != 0) {
        return true;
    }
    else if (r1[1] == r2[1] && r2[1] == r3[1] && r1[1] != 0) {
        return true;
    }
    else if (r1[2] == r2[2] && r2[2] == r3[2] && r1[2] != 0) {
        return true;
    }
    // Check for diagonals
    else if (r1[0] == r2[1] && r2[1] == r3[2] && r1[0] != 0) {
        return true;
    }
    else if (r1[2] == r2[1] && r2[1] == r3[0] && r1[2] != 0) {
        return true;
    }

    // If no winner, return false
    return false;
}

void getInput(int* row, int* col){
    printf("Enter the row (1-3): ");
    scanf("%d", row);
    printf("Enter the col (1-3) ");
    scanf("%d", col);
}

void markInput(int* r1, int* r2, int* r3, int input_row, int input_col, int player){
    char input;
    if (player == 1){
        input = 'X';
    } else {
        input = 'O';
    }

    if (input_row == 1){
        if (input_col == 1){
            r1[0] = input;
        } else if (input_col == 2){
            r1[1] = input;
        } else if(input_col == 3) {
            r1[2] = input;
        }
    }
    else if (input_row == 2){
        if (input_col == 1){
            r2[0] = input;
        } else if (input_col == 2){
            r2[1] = input;
        } else if(input_col == 3){
            r2[2] = input;
        }
    }
    else if (input_row == 3){
        if (input_col == 1){
            r3[0] = input;
        } else if (input_col == 2){
            r3[1] = input;
        } else if(input_col == 3){
            r3[2] = input;
        }
    }
}

void printboard(int* r1, int* r2, int* r3){
    printRow(r1,3);
    printf("\t\t\t\t\t------------------\n");
    printRow(r2,3);
    printf("\t\t\t\t\t------------------\n");
    printRow(r3,3);
}

void printRow(int* row, int rowSize){
    printf("\t\t\t\t\t");
    for (int i = 0; i < rowSize; i++){
        printf("%c\t",row[i]);
    }
    printf("\n");
}

bool checkDraw(int* r1, int* r2, int* r3){
    for (int i = 0; i < 3; i++){
        if (r1[i] == 0){
            return false;
        }
    }
    for (int i = 0; i < 3; i++){
        if (r2[i] == 0){
            return false;
        }
    }
    for (int i = 0; i < 3; i++){
        if (r3[i] == 0){
            return false;
        }
    }
    return true;
}