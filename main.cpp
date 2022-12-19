/* ---------------------------------------------
    Program 2: Great 13
        Peg puzzle, jumping pieces to try and
        leave only a single piece.

    Course: CS 141, Fall 2021. Tues 2pm lab
    System: Windows using CLion
    Author: Nikos Kotsopulos

    Running the program looks like:

        Class:   CS 141, Fall '21
        Program: #2 Great 13

        Make a series of jumps until there is a single piece left in the
        middle. On each move you must jump an adjacent piece into an empty
        square, jumping horizontally, vertically, or diagonally.

             Board    Position
               #          A
             # # #      B C D
           # # . # #  E F G H I
             # # #      J K L
               #          M

        1. Enter position to move from, piece to jump, and destination (e.g. EFG): efg
             Board    Position
               #          A
             # # #      B C D
           . . # # #  E F G H I
             # # #      J K L
               #          M

        2. Enter position to move from, piece to jump, and destination (e.g. EFG):

        . . .
   ---------------------------------------------
*/

#include <iostream>
#include <cctype>   // for toupper()

using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the following:
//   - 13 board pieces
//   - The letter positions you are moving from, jumping over, and moving to
//   - The number of pieces on the board (to know when there is a win)
// ...


// ----------------------------------------------------------------------
// Display the game instructions.
char pA = '#', pB = '#', pC = '#', pD = '#', pE = '#', pF = '#', pH = '#', pI = '#', pJ = '#', pK = '#', pL = '#', pM = '#';
char pG = '.';
char moveFrom, pJump, dest;
int numberOfPieces = 12;
int emptySpot = 1;
int moveNumber = 1;

void displayInstructions() {
    cout << "Class: CS 141             \n"
         << "Program: #2 Great 13      \n"
         << "  \n"
         << "Make a series of jumps until there is a single piece left in the   \n"
         << "middle. On each move you must jump an adjacent piece into an empty \n"
         << "square, jumping horizontally, vertically, or diagonally.           \n"
         << "Input of 'R' resets the board back to the beginning, and input of  \n"
         << "'X' exits the game.'   \n"
         << endl;
} //end displayInstructions()


// ----------------------------------------------------------------------
// Display the board, using the global variables pA..pM
void displayBoard() {
    cout << "\n "
         << "    Board   " << " Position \n"
         << "       " << pA << "          A    \n"
         << "     " << pB << " " << pC << " " << pD << "      B C D  \n"
         << "   " << pE << " " << pF << " " << pG << " " << pH << " " << pI << "  E F G H I\n"
         << "     " << pJ << " " << pK << " " << pL << "      J K L  \n"
         << "       " << pM << "          M    \n"
         << endl;
} //end displayBoard()

void resetBoard() {//function to reset the board including all the pieces to their original positions
    pA = '#', pB = '#', pC = '#', pD = '#', pE = '#', pF = '#', pH = '#', pI = '#', pJ = '#', pK = '#', pL = '#', pM = '#';
    pG = '.';
    numberOfPieces = 12;
    emptySpot = 1;
    moveNumber = 1;
}

bool isAdjacent() {//function checks if the input from the user is valid based on adjacency
    if (moveFrom == 'A' && pJump == 'B' && dest == 'E') {
        return true;
    } else if (moveFrom == 'A' && pJump == 'C' && dest == 'G') {
        return true;
    } else if (moveFrom == 'A' && pJump == 'D' && dest == 'I') {
        return true;
    } else if (moveFrom == 'B' && pJump == 'F' && dest == 'J') {
        return true;
    } else if (moveFrom == 'B' && pJump == 'C' && dest == 'D') {
        return true;
    } else if (moveFrom == 'B' && pJump == 'G' && dest == 'L') {
        return true;
    } else if (moveFrom == 'D' && pJump == 'C' && dest == 'B') {
        return true;
    } else if (moveFrom == 'D' && pJump == 'G' && dest == 'J') {
        return true;
    } else if (moveFrom == 'D' && pJump == 'H' && dest == 'L') {
        return true;
    } else if (moveFrom == 'C' && pJump == 'G' && dest == 'K') {
        return true;
    } else if (moveFrom == 'E' && pJump == 'B' && dest == 'A') {
        return true;
    } else if (moveFrom == 'E' && pJump == 'F' && dest == 'G') {
        return true;
    } else if (moveFrom == 'E' && pJump == 'J' && dest == 'M') {
        return true;
    } else if (moveFrom == 'F' && pJump == 'G' && dest == 'H') {
        return true;
    } else if (moveFrom == 'G' && pJump == 'C' && dest == 'A') {
        return true;
    } else if (moveFrom == 'G' && pJump == 'F' && dest == 'E') {
        return true;
    } else if (moveFrom == 'G' && pJump == 'K' && dest == 'M') {
        return true;
    } else if (moveFrom == 'G' && pJump == 'H' && dest == 'I') {
        return true;
    } else if (moveFrom == 'H' && pJump == 'G' && dest == 'F') {
        return true;
    } else if (moveFrom == 'I' && pJump == 'D' && dest == 'A') {
        return true;
    } else if (moveFrom == 'I' && pJump == 'H' && dest == 'G') {
        return true;
    } else if (moveFrom == 'I' && pJump == 'L' && dest == 'M') {
        return true;
    } else if (moveFrom == 'J' && pJump == 'F' && dest == 'B') {
        return true;
    } else if (moveFrom == 'J' && pJump == 'K' && dest == 'L') {
        return true;
    } else if (moveFrom == 'J' && pJump == 'G' && dest == 'D') {
        return true;
    } else if (moveFrom == 'K' && pJump == 'G' && dest == 'C') {
        return true;
    } else if (moveFrom == 'L' && pJump == 'K' && dest == 'J') {
        return true;
    } else if (moveFrom == 'L' && pJump == 'G' && dest == 'B') {
        return true;
    } else if (moveFrom == 'L' && pJump == 'H' && dest == 'D') {
        return true;
    } else if (moveFrom == 'M' && pJump == 'J' && dest == 'E') {
        return true;
    } else if (moveFrom == 'M' && pJump == 'K' && dest == 'G') {
        return true;
    } else if (moveFrom == 'M' && pJump == 'L' && dest == 'I') {
        return true;
    }
    return false;
}

bool hasValidStartingPiece() {//checks if the starting position has a piece in it
    if (moveFrom == 'A' && pA == '#') {//
        return true;
    } else if (moveFrom == 'B' && pB == '#') {
        return true;
    } else if (moveFrom == 'C' && pC == '#') {
        return true;
    } else if (moveFrom == 'D' && pD == '#') {
        return true;
    } else if (moveFrom == 'E' && pE == '#') {
        return true;
    } else if (moveFrom == 'F' && pF == '#') {
        return true;
    } else if (moveFrom == 'G' && pG == '#') {
        return true;
    } else if (moveFrom == 'H' && pH == '#') {
        return true;
    } else if (moveFrom == 'I' && pI == '#') {
        return true;
    } else if (moveFrom == 'J' && pJ == '#') {
        return true;
    } else if (moveFrom == 'K' && pK == '#') {
        return true;
    } else if (moveFrom == 'L' && pL == '#') {
        return true;
    } else if (moveFrom == 'M' && pM == '#') {
        return true;
    }
    return false;
}

bool hasValidJumpSpot() {//returns true if the spot that is being jumped has a piece in it. False otherwise
    if (pJump == 'A' && pA == '#') {
        return true;
    } else if (pJump == 'B' && pB == '#') {
        return true;
    } else if (pJump == 'C' && pC == '#') {
        return true;
    } else if (pJump == 'D' && pD == '#') {
        return true;
    } else if (pJump == 'E' && pE == '#') {
        return true;
    } else if (pJump == 'F' && pF == '#') {
        return true;
    } else if (pJump == 'G' && pG == '#') {
        return true;
    } else if (pJump == 'H' && pH == '#') {
        return true;
    } else if (pJump == 'I' && pI == '#') {
        return true;
    } else if (pJump == 'J' && pJ == '#') {
        return true;
    } else if (pJump == 'K' && pK == '#') {
        return true;
    } else if (pJump == 'L' && pL == '#') {
        return true;
    } else if (pJump == 'M' && pM == '#') {
        return true;
    }
    return false;
}

bool isDestEmpty() {//checks if the starting piece has an available destination spot to land on
    if (dest == 'A' && pA == '.') {
        return true;
    } else if (dest == 'B' && pB == '.') {
        return true;
    } else if (dest == 'C' && pC == '.') {
        return true;
    } else if (dest == 'D' && pD == '.') {
        return true;
    } else if (dest == 'E' && pE == '.') {
        return true;
    } else if (dest == 'F' && pF == '.') {
        return true;
    } else if (dest == 'G' && pG == '.') {
        return true;
    } else if (dest == 'H' && pH == '.') {
        return true;
    } else if (dest == 'I' && pI == '.') {
        return true;
    } else if (dest == 'J' && pJ == '.') {
        return true;
    } else if (dest == 'K' && pK == '.') {
        return true;
    } else if (dest == 'L' && pL == '.') {
        return true;
    } else if (dest == 'M' && pM == '.') {
        return true;
    }
    return false;
}

void increment() {//small function to keep track of pieces and empty spots
    numberOfPieces--;
    emptySpot++;
}

void makeMove() {//the function that makes the actual move.
    if (moveFrom == 'A' && pJump == 'B' && dest == 'E') {//if the user input meets these conditions
        pA = '.', pB = '.', pE = '#', increment();//setting the destination spot as a '#' and the other two to '.'
    } else if (moveFrom == 'A' && pJump == 'C' && dest == 'G') {
        pA = '.', pC = '.', pG = '#', increment();
    } else if (moveFrom == 'A' && pJump == 'D' && dest == 'I') {
        pA = '.', pD = '.', pI = '#', increment();
    } else if (moveFrom == 'B' && pJump == 'F' && dest == 'J') {
        pB = '.', pF = '.', pJ = '#', increment();
    } else if (moveFrom == 'B' && pJump == 'G' && dest == 'L') {
        pB = '.', pG = '.', pL = '#', increment();
    } else if (moveFrom == 'B' && pJump == 'C' && dest == 'D') {
        pB = '.', pC = '.', pD = '#', increment();
    } else if (moveFrom == 'B' && pJump == 'G' && dest == 'L') {
        pB = '.', pG = '.', pL = '#', increment();
    } else if (moveFrom == 'C' && pJump == 'G' && dest == 'K') {
        pC = '.', pG = '.', pK = '#', increment();
    } else if (moveFrom == 'D' && pJump == 'C' && dest == 'B') {
        pD = '.', pC = '.', pB = '#', increment();
    } else if (moveFrom == 'D' && pJump == 'G' && dest == 'J') {
        pD = '.', pG = '.', pJ = '#', increment();
    } else if (moveFrom == 'D' && pJump == 'H' && dest == 'L') {
        pD = '.', pH = '.', pL = '#', increment();
    } else if (moveFrom == 'E' && pJump == 'B' && dest == 'A') {
        pE = '.', pB = '.', pA = '#', increment();
    } else if (moveFrom == 'E' && pJump == 'F' && dest == 'G') {
        pE = '.', pF = '.', pG = '#', increment();
    } else if (moveFrom == 'E' && pJump == 'J' && dest == 'M') {
        pE = '.', pJ = '.', pM = '#', increment();
    } else if (moveFrom == 'F' && pJump == 'G' && dest == 'H') {
        pF = '.', pG = '.', pD = '#', increment();
    } else if (moveFrom == 'G' && pJump == 'C' && dest == 'A') {
        pG = '.', pC = '.', pA = '#', increment();
    } else if (moveFrom == 'G' && pJump == 'F' && dest == 'E') {
        pG = '.', pF = '.', pE = '#', increment();
    } else if (moveFrom == 'G' && pJump == 'K' && dest == 'M') {
        pG = '.', pK = '.', pM = '#', increment();
    } else if (moveFrom == 'G' && pJump == 'H' && dest == 'I') {
        pG = '.', pH = '.', pI = '#', increment();
    } else if (moveFrom == 'H' && pJump == 'G' && dest == 'F') {
        pH = '.', pG = '.', pF = '#', increment();
    } else if (moveFrom == 'I' && pJump == 'D' && dest == 'A') {
        pI = '.', pD = '.', pA = '#', increment();
    } else if (moveFrom == 'I' && pJump == 'H' && dest == 'G') {
        pI = '.', pH = '.', pG = '#', increment();
    } else if (moveFrom == 'I' && pJump == 'L' && dest == 'M') {
        pI = '.', pL = '.', pM = '#', increment();
    } else if (moveFrom == 'J' && pJump == 'F' && dest == 'B') {
        pJ = '.', pF = '.', pB = '#', increment();
    } else if (moveFrom == 'J' && pJump == 'K' && dest == 'L') {
        pJ = '.', pK = '.', pL = '#', increment();
    } else if (moveFrom == 'J' && pJump == 'G' && dest == 'D') {
        pJ = '.', pG = '.', pD = '#', increment();
    } else if (moveFrom == 'K' && pJump == 'G' && dest == 'C') {
        pK = '.', pG = '.', pC = '#', increment();
    } else if (moveFrom == 'L' && pJump == 'K' && dest == 'J') {
        pL = '.', pK = '.', pJ = '#', increment();
    } else if (moveFrom == 'L' && pJump == 'G' && dest == 'B') {
        pL = '.', pG = '.', pB = '#', increment();
    } else if (moveFrom == 'L' && pJump == 'H' && dest == 'D') {
        pL = '.', pH = '.', pD = '#', increment();
    } else if (moveFrom == 'M' && pJump == 'J' && dest == 'E') {
        pM = '.', pJ = '.', pE = '#', increment();
    } else if (moveFrom == 'M' && pJump == 'K' && dest == 'G') {
        pM = '.', pK = '.', pG = '#', increment();
    } else if (moveFrom == 'M' && pJump == 'L' && dest == 'I') {
        pM = '.', pL = '.', pI = '#', increment();
    }
}
// ----------------------------------------------------------------------
// Main section of the program, containing the game play loop
int main() {
    displayInstructions();

    // Set board values to the default starting position
    // ...

    // Game play loop
    displayBoard();//displays the board
    while (numberOfPieces>1) {//if there are 2 or more pieces on the board, the loop will keep iterating until the condition is false
        cout << moveNumber << ". "
             << "Enter positions from, jump, and to (e.g. EFG): ";
        cin >> moveFrom;                // Read just the first user input, handling inputs 'X' or 'R'
        moveFrom = toupper(moveFrom);  // Fold input into upper case to simplify later comparisons

        // If 'X' to exit was chosen, break out of game play loop
        // ...

        if (moveFrom == 'X') {//when user input is 'X'
            cout << "Exiting" << endl << endl;
            cout << "Better luck next time." << endl;
            break;//breaks out of the loop and terminates the program
        }

        // If 'R' to reset the board was chosen, reinitialize everything
        // display the board, and continue back up to re-run the while(...) loop
        // ...
        if (moveFrom == 'R') {//when user input is 'R'
            cout << endl << "   *** Restarting" << endl;
            resetBoard();
            displayBoard();
            continue;//skips the rest of the loop and starts the next iteration
        }

        // Additionally now also read the piece-to-jump and destination inputs.
        // ...
        cin >> pJump >> dest;//Once the exit and restart options are checked, read in pJump and dest
        pJump = toupper(pJump);//capitalizing to maintain consistency with input and what char the program checks
        dest = toupper(dest);

        // Ensure set of pieces (from, jump, to) are adjacent.  If they aren't, then
        // continue back up to re-run the while(...) loop.
        // ...
        if (!isAdjacent()) {//using !isAdjacent to execute the if statement when the function is false
            cout << endl << "   *** Pieces must be adjacent. Please retry" << endl << endl;
            continue;
        }

        // Ensure location we're moving FROM has a PlayerPiece in it. If it doesn't, then
        // continue back up to re-run the while(...) loop.
        if (!hasValidStartingPiece()) {//using !hasValidStartingPiece to execute the if statement when the function is false
            cout << endl << "   *** Source must have a piece. Please retry" << endl << endl;
            continue;
        }

        // Ensure piece being jumped isn't blank. If it is, then
        // continue back up to re-run the while(...) loop.
        // ...
        if (!hasValidJumpSpot()) {//using !hasValidJumpSpot to execute the if statement when the function is false
            cout << endl << "   *** Must jump a piece. Please retry" << endl << endl;
            continue;
        }

        // Ensure location we're moving TO is blank. If it is not, then
        // continue back up to re-run the while(...) loop.
        // ...
        if (!isDestEmpty()) {//using !isDestEmpty to execute the if statement when the function is false
            cout << endl << "   *** Destination must be blank. Retry" << endl << endl;
            continue;
        }

        // Make the move and display the board
        // ...
        makeMove();//Once all of the above error checks are passed, the move can be made
        displayBoard();
        moveNumber++;//increment the move number to know how many moves we have made
        if (numberOfPieces == 1 && emptySpot == 12) {//win condition; checking if there are 12 empty spots and 1 piece
            cout << endl << "Congratulations, you did it!" << endl;
            break;// if the condition is met, it will break out of the loop and you win
        }
    }//end while( numberOfPieces > 1)

    cout << "Done." << endl;
    return 0;
} //end main()