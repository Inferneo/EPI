#include <string>

using std::string;

int StringHash(const string &str, int modulus) {
    const int kMult = 997;
    int val = 0;
    for (char c : str) {
        val = (val * kMult + c) % modulus;
    }
    return val;
}