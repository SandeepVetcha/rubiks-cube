#include "RubiksCube.h"


// Returning the first letter of a Color
char RubiksCube::getColorLetter (Color color)
{
    switch(color)
    {
        case Color::BLUE:
            return 'B';
        case Color::GREEN:
            return 'G';
        case Color::RED:
            return 'R';
        case Color::YELLOW:
            return 'Y';
        case Color::WHITE:
            return 'W';
        case Color::ORANGE:
            return 'O';
    }
}

// Describing a move using an index
string RubiksCube::getMove(Move ind)
{
    switch (ind) {
        case Move::L:
            return "L";
        case Move::LPRIME:
            return "L'";
        case Move::L2:
            return "L2";
        case Move::R:
            return "R";
        case Move::RPRIME:
            return "R'";
        case Move::R2:
            return "R2";
        case Move::U:
            return "U";
        case Move::UPRIME:
            return "U'";
        case Move::U2:
            return "U2";
        case Move::D:
            return "D";
        case Move::DPRIME:
            return "D'";
        case Move::D2:
            return "D2";
        case Move::F:
            return "F";
        case Move::FPRIME:
            return "F'";
        case Move::F2:
            return "F2";
        case Move::B:
            return "B";
        case Move::BPRIME:
            return "B'";
        case Move::B2:
            return "B2";
    }
}

// Perform a move operation on using a Move Index
RubiksCube& RubiksCube::move(Move ind)
{
    switch (ind) {
        case Move::L:
            return this->l();
        case Move::LPRIME:
            return this->lPrime();
        case Move::L2:
            return this->l2();
        case Move::R:
            return this->r();
        case Move::RPRIME:
            return this->rPrime();
        case Move::R2:
            return this->r2();
        case Move::U:
            return this->u();
        case Move::UPRIME:
            return this->uPrime();
        case Move::U2:
            return this->u2();
        case Move::D:
            return this->d();
        case Move::DPRIME:
            return this->dPrime();
        case Move::D2:
            return this->d2();
        case Move::F:
            return this->f();
        case Move::FPRIME:
            return this->fPrime();
        case Move::F2:
            return this->f2();
        case Move::B:
            return this->b();
        case Move::BPRIME:
            return this->bPrime();
        case Move::B2:
            return this->b2();
    }
}

// Inverting a move, making use of the fact that invert(A) = A'
// and vice-versa, invert(A2) = A2
RubiksCube& RubiksCube::invert(Move ind)
{
    switch (ind) {
        case Move::L:
            return this->lPrime();
        case Move::LPRIME:
            return this->l();
        case Move::L2:
            return this->l2();
        case Move::R:
            return this->rPrime();
        case Move::RPRIME:
            return this->r();
        case Move::R2:
            return this->r2();
        case Move::U:
            return this->uPrime();
        case Move::UPRIME:
            return this->u();
        case Move::U2:
            return this->u2();
        case Move::D:
            return this->dPrime();
        case Move::DPRIME:
            return this->d();
        case Move::D2:
            return this->d2();
        case Move::F:
            return this->fPrime();
        case Move::FPRIME:
            return this->f();
        case Move::F2:
            return this->f2();
        case Move::B:
            return this->bPrime();
        case Move::BPRIME:
            return this->b();
        case Move::B2:
            return this->b2();
    }
}

// Printing the cube
void RubiksCube::print() const
{
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(Face::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(Face::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(Face::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(Face::RIGHT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(Face::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(Face::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Giving random moves of a Cube
vector<RubiksCube::Move> RubiksCube::randomShuffleCube(unsigned int times)
{
    // Cannot pick arbitray ovlors of a face as it may lead to same color on two sides of a face
    vector<Move> moves_performed;
    
    srand(time(0));

    for (unsigned int i = 0; i < times; i++) {

        // Trying to pick one of the 18 possible moves 
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<Move>(selectMove));
        this->move(static_cast<Move>(selectMove));
    }
    return moves_performed;
}

//Helper function returns string of corner
string RubiksCube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(Face::UP, 2, 2));
            str += getColorLetter(getColor(Face::FRONT, 0, 2));
            str += getColorLetter(getColor(Face::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(Face::UP, 2, 0));
            str += getColorLetter(getColor(Face::FRONT, 0, 0));
            str += getColorLetter(getColor(Face::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(Face::UP, 0, 0));
            str += getColorLetter(getColor(Face::BACK, 0, 2));
            str += getColorLetter(getColor(Face::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(Face::UP, 0, 2));
            str += getColorLetter(getColor(Face::BACK, 0, 0));
            str += getColorLetter(getColor(Face::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(Face::DOWN, 0, 2));
            str += getColorLetter(getColor(Face::FRONT, 2, 2));
            str += getColorLetter(getColor(Face::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(Face::DOWN, 0, 0));
            str += getColorLetter(getColor(Face::FRONT, 2, 0));
            str += getColorLetter(getColor(Face::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(Face::DOWN, 2, 2));
            str += getColorLetter(getColor(Face::BACK, 2, 0));
            str += getColorLetter(getColor(Face::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(Face::DOWN, 2, 0));
            str += getColorLetter(getColor(Face::BACK, 2, 2));
            str += getColorLetter(getColor(Face::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}

