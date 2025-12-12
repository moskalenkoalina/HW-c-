#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char letter; // 'a'..'h'
    int number;  // 1..8
} ChessSquare;

bool canQueenMove(ChessSquare from, ChessSquare to) {
    int fromCol = from.letter - 'a' + 1;
    int toCol = to.letter - 'a' + 1;

    if (fromCol == toCol && from.number == to.number) {
        return false;
    }

    if (from.number == to.number) {
        return true;
    }

    if (from.letter == to.letter) {
        return true;
    }

    if (abs(fromCol - toCol) == abs(from.number - to.number)) {
        return true;
    }

    return false;
}

void inputChessSquare(ChessSquare *cs) {
    printf("Enter square (e.g., a5): ");
    scanf(" %c%d", &cs->letter, &cs->number);
}

void outputChessSquare(ChessSquare cs) {
    printf("%c%d", cs.letter, cs.number);
}

int main() {
    ChessSquare start, end;

    printf("Enter starting square for queen: ");
    inputChessSquare(&start);

    printf("Enter target square: ");
    inputChessSquare(&end);

    if (canQueenMove(start, end)) {
        printf("Queen can move from ");
        outputChessSquare(start);
        printf(" to ");
        outputChessSquare(end);
        printf(" in one move.\n");
    } else {
        printf("Queen cannot move from ");
        outputChessSquare(start);
        printf(" to ");
        outputChessSquare(end);
        printf(" in one move.\n");
    }

    return 0;
}