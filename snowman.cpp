#include "snowman.hpp"

#include <array>
#include <iostream>
#include <string>

namespace constant {
// all ingredients constants
const array<string, 4> HAT{" _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const array<string, 4> NOSE{",", ".", "_", " "};
const array<string, 4> EYE{".", "o", "O", "-"};
const array<string, 4> LEFT_ARM{"<", "\\", "/", " "};
const array<string, 4> RIGHT_ARM{">", "/", "\\", " "};
const array<string, 4> TORSO{"( : )", "(] [)", "(> <)", "(   )"};
const array<string, 4> BASE{"( : )", "(\" \")", "(___)", "(   )"};

const string SPACE = " ";
const string NEW_LINE = "\n";
const int SM_BUILDER_LENGTH = 8;
const int BASE_COUNT = 10;
const int UPWARDS_ARM = 2;

// HNLRXYTB
const int H = 0;
const int N = 1;
const int L = 2;
const int R = 3;
const int X = 4;
const int Y = 5;
const int T = 6;
const int B = 7;
}  // namespace constant

using namespace std;

string getHat(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::HAT.at(num - 1);
}

string getNose(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::NOSE.at(num - 1);
}

string getEye(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::EYE.at(num - 1);
}

string getLeftArm(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::LEFT_ARM.at(num - 1);
}

string getRightArm(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::RIGHT_ARM.at(num - 1);
}

string getTorso(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::TORSO.at(num - 1);
}

string getBase(int num) {
    // check if num is valid input
    if (num < 1 || num > 4) {
        throw out_of_range{"invalid input"};
    }
    return constant::BASE.at(num - 1);
}

namespace ariel {
string snowman(int snowmanBuilder) {
    int size = to_string(snowmanBuilder).length();
    if (size != constant::SM_BUILDER_LENGTH || snowmanBuilder < 0) {
        // check that the input have 8 digits
        throw out_of_range{"invalid input"};
    }
    array<int, constant::SM_BUILDER_LENGTH> arr{};
    for (int i = constant::SM_BUILDER_LENGTH - 1; i >= 0; --i) {
        arr.at(i) = snowmanBuilder % constant::BASE_COUNT;
        snowmanBuilder /= constant::BASE_COUNT;
    }
    // get all the ingredients of the snowman
    string hat = getHat(arr.at(constant::H));
    string nose = getNose(arr.at(constant::N));
    string leftEye = "(" + getEye(arr.at(constant::L));
    string rightEye = getEye(arr.at(constant::R)) + ")";
    string leftArm = getLeftArm(arr.at(constant::X));
    string rightArm = getRightArm(arr.at(constant::Y));
    string torso = getTorso(arr.at(constant::T));
    string base = getBase(arr.at(constant::B));

    string sm = hat + constant::NEW_LINE;
    if (arr.at(constant::X) == int(constant::UPWARDS_ARM) && arr.at(constant::Y) == int(constant::UPWARDS_ARM)) {
        // if both arms are upward put them near the face
        sm += leftArm + leftEye + nose + rightEye + rightArm + constant::NEW_LINE +
              constant::SPACE + torso;
    } else if (arr.at(constant::X) == int(constant::UPWARDS_ARM)) {
        // if just one arm are upward put the arm near the face and the anther arm near the torso
        sm += leftArm + leftEye + nose + rightEye + constant::NEW_LINE +
              constant::SPACE + torso + rightArm;
    } else if (arr.at(constant::Y) == int(constant::UPWARDS_ARM)) {
        sm += constant::SPACE + leftEye + nose + rightEye + rightArm + constant::NEW_LINE +
              leftArm + torso;
    } else {
        // if none of the arms are upward put both near the torso
        sm += constant::SPACE + leftEye + nose + rightEye + constant::NEW_LINE +
              leftArm + torso + rightArm;
    }
    return constant::NEW_LINE + sm + constant::NEW_LINE + constant::SPACE + base + constant::NEW_LINE;
}
}  // namespace ariel
