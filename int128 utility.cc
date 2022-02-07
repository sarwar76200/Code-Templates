#include <bits/stdc++.h>

using namespace std;

namespace int128_utility {
    std::istream& operator>>(std::istream& in, __int128& n) {
        std::string s;
        in >> s;
        bool neg = !s.empty() && s.front() == '-';
        n = 0;
        for (size_t i = 0 + neg; i < s.length(); ++i) {
            n = n * 10 + (s[i] - '0');
        }
        if (neg) n *= -1;
        return in;
    }

    std::ostream& operator<<(std::ostream& out, __int128 n) {
        bool neg = n < 0;
        std::string s;
        do {
            s += to_string(abs(int(n % 10)));
            n /= 10;
        } while (neg ? n < 0 : n > 0);
        if (neg) s += '-';
        std::reverse(s.begin(), s.end());
        out << s;
        return out;
    }
}
using namespace int128_utility;;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    __int128 n = 1000000;
    cout << n << '\n';

    return 0;
}