#include <string>
#include <array>

using namespace std;

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

namespace ariel {
    string snowman(int snowmanBuilder);
}