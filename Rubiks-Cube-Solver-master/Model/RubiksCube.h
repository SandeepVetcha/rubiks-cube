#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

/**
 * A base class containing common various functionalities of many representations
 * of a Rubik's cube
 * Benchmarking ahs been done at a later stage to monitor the performance of each one
 */

class RubiksCube {

    public:

        // Named representaions of each face, 6 in total
        enum class Face 
        {
            UP,
            LEFT,
            FRONT,
            RIGHT,
            BACK,
            DOWN
        };

        // All the 6 colors of the faces
        enum class Color
        {
            WHITE,
            GREEN,
            RED,
            BLUE,
            ORANGE,
            YELLOW
        };

        // Defining each move
        enum class Move
        {
            L, LPRIME, L2,
            R, RPRIME, R2,
            U, UPRIME, U2,
            D, DPRIME, D2,
            F, FPRIME, F2,
            B, BPRIME, B2
        };

        /*
         * Returning the color of the cell 
         * First, the face is rotated so taht it directly faces us.
         * Now, the face is treated like a grid with 0,0 being the top left cube
         * @param Face, row and column index 
        */
        virtual Color getColor(Face face, unsigned row, unsigned col) const = 0;

        /*
         * Function returns the first letter of the color given (used to simplify notation)
         * @param Color requested
        */
        static char getColorLetter(Color color);

        /*
         * Function to check whether the Rubiks Cube is solved or not.
        */
        virtual bool isSolved() const = 0;

        /*
         * Given a move, returns it in the string format
        */
        static string getMove(Move ind);

        /*
        * Print the Rubik Cube in Planar format.
        *
        * The cube is laid out as follows.
        *
        * The sides:
        *    U
        *  L F R B
        *    D
        *
        * Color wise:
        *
        *          W W W
        *          W W W
        *          W W W
        *
        *  G G G   R R R   B B B   O O O
        *  G G G   R R R   B B B   O O O
        *  G G G   R R R   B B B   O O O
        *
        *          Y Y Y
        *          Y Y Y
        *          Y Y Y
        *
        * Row and Column Numberings:
        * rx -> row numbering
        * cx -> column numbering
        * bx -> both row and column numbering
        *
        *             b0 c1 c2
        *             r1  .  .
        *             r2  .  .
        *
        *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
        *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
        *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
        *
        *             b0 c1 c2
        *             r1  .  .
        *             r2  .  .
        *
        *
        */
        void print() const;

        /*
            * Randomly shuffles the cube with 'times' number of moves and return the moves
        */
        vector<Move> randomShuffleCube(unsigned int times);

        /*
         * Function to perform moves on a Rubik's Cube
        */
        RubiksCube& move(Move ind);

        /*
         * Inverting a move
        */
        RubiksCube& invert(Move ind);

        /*
         * Rotational Moves on the Rubik Cubes
         *
         * F, F’, F2,
         * U, U’, U2,
         * L, L’, L2,
         * D, D’, D2,
         * R, R’, R2,
         * B, B’, B2
        */

        virtual RubiksCube& f() = 0;

        virtual RubiksCube& fPrime() = 0;

        virtual RubiksCube& f2() = 0;

        virtual RubiksCube& u() = 0;

        virtual RubiksCube& uPrime() = 0;

        virtual RubiksCube& u2() = 0;

         virtual RubiksCube &l() = 0;

        virtual RubiksCube& lPrime() = 0;

        virtual RubiksCube& l2() = 0;

        virtual RubiksCube& r() = 0;

        virtual RubiksCube& d() = 0;

        virtual RubiksCube& dPrime() = 0;

        virtual RubiksCube& d2() = 0;

        virtual RubiksCube& rPrime() = 0;

        virtual RubiksCube& r2() = 0;

        virtual RubiksCube& b() = 0;

        virtual RubiksCube& bPrime() = 0;

        virtual RubiksCube& b2() = 0;

        string getCornerColorString(uint8_t ind) const;

        uint8_t getCornerIndex(uint8_t ind) const;

        uint8_t getCornerOrientation(uint8_t ind) const;

};      

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H