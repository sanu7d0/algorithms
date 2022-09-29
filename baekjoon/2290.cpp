#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

// seven-segment display
bool sA[10] = {true, false, true, true, false, true, true, true, true, true};
bool sB[10] = {true, true, true, true, true, false, false, true, true, true};
bool sC[10] = {true, true, false, true, true, true, true, true, true, true};
bool sD[10] = {true, false, true, true, false, true, true, false, true, true};
bool sE[10] = {true, false, true, false, false, false, true, false, true, false};
bool sF[10] = {true, false, false, false, true, true, true, false, true, true};
bool sG[10] = {false, false, true, true, true, true, true, false, true, true};

int main() {
    fastio;

    int s;
    string n;
    cin >> s >> n;

    string buffer = "";
    for (int i = 0; i < 2 * s + 3; ++i) {
        for (int j = 0; j < n.length(); ++j) {
            int num = n.at(j) - '0';
            if (i == 0)
                buffer += " " + string(s, sA[num] ? '-' : ' ') + " ";
            else if (0 < i && i < s + 1)
                buffer += (sF[num] ? '|' : ' ') + string(s, ' ') + (sB[num] ? '|' : ' ');
            else if (i == s + 1)
                buffer += " " + string(s, sG[num] ? '-' : ' ') + " ";
            else if (s + 1 < i && i < 2 * s + 2)
                buffer += (sE[num] ? '|' : ' ') + string(s, ' ') + (sC[num] ? '|' : ' ');
            else
                buffer += " " + string(s, sD[num] ? '-' : ' ') + " ";

            buffer += " ";
        }
        buffer += "\n";
    }
    cout << buffer;
}
