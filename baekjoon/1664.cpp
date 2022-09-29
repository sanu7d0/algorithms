#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

struct ID {
    string day;
    string month;
    string year;
    string a10;
    char cd;

    bool is_valid();
};

bool ID::is_valid() {
    string str = day + month + year + a10;
    int S = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 9; ++j) {
            S += (10 - j) * (str[9 * i + j] - '0');
        }
    }
    S %= 19;

    return S <= 9 ? cd - '0' == S : cd - '0' == 19 - S;
}

int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get_days_of_month(int month, int year) {
    if (month != 2)
        return mdays[month];

    return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0 ? 29 : 28;
}

bool is_number(const string &str) {
    for (char const &c : str) {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

ll check_year(string str) {
    string year = str.substr(4, 8);

    for (int i = 0; i < 4; ++i) {
        if (year[i] == 'X') {
            string tmp;
            for (int j = 0; j <= 9; ++j) {
                tmp = year.substr(0, i) + to_string(i) + year.substr(i + 1, 5);
                if (tmp == "0000")
                    continue;
            }
        }
    }
}

ll check_month(string str) {
    //
}

ll check_day(string str) {
    //
}

int main() {
    fastio;

    string s; // DDMMYYYYAAAAAAAAAAC
    cin >> s;
    ID id = {s.substr(0, 2), s.substr(2, 4), s.substr(4, 8), s.substr(8, 18),
             s[18]};

    cout << 0;
}
