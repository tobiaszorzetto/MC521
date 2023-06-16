#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

bool can(const vector<char> &event, const vector<unsigned> & km, const vector<unsigned> & val, double f) {
    double init = f;
    unsigned i, cons, ckm, leak;

    cons = ckm = leak = 0;

    for (i = 0; i < event.size(); i++) {
        f -= leak * (km[i] - ckm) + cons * (km[i] - ckm)/100.0;

        if (f < 0) {
            return false;
        }
        else {
            if (event[i] == 'F') {
                cons = val[i];
            } else if (event[i] == 'L') {
                leak++;
            } else if (event[i] == 'G') {
                f = init;
            } else if (event[i] == 'M') {
                leak = 0;
            }
            ckm = km[i];
        }
    }
    return true;
}

int main() {
    string line, s, t;
    istringstream ss;
    unsigned n, c;
    vector<char> event;
    vector<unsigned> km, val;
    double lo, hi, mid, ans;

    cout << fixed << setprecision(3);

    while(getline(cin, line)) {
        if (line == "0 Fuel consumption 0") {
            break;
        }

        ss = istringstream(line);

        ss >> n >> s;

        if (s == "Fuel" || s == "Gas") {
            ss >> t;
        }

        ss >> c;
        km.push_back(n);
        event.push_back(s[0]);

        if (s == "Fuel") {
            val.push_back(c);
        }
        else {
            val.push_back(0);
        }

        if (s == "Goal") {
            lo = 0;
            hi = 10000;

            while (hi - lo > 1e-4) {
                mid = (lo + hi) / 2;

                if (can(event, km, val, mid)) {
                    hi = mid;
                    ans = mid;
                }
                else {
                    lo = mid;
                }
            }
            cout << ans << endl;
            event.clear();
            km.clear();
            val.clear();
            ans= 0;
        }
    }
    return 0;
}