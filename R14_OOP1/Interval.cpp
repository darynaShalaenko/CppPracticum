include <iostream>
#include <cfloat>

using namespace std;


class Interval {
    public:
        int edgeT, edgeB; // including edge - 0, without edge - 1; edgeT - Top edge, edgeB - Bot edge
        double bot, top;

        int intCrossing(const Interval &i2) {
            if (top-DBL_EPSILON*edgeT - i2.bot+DBL_EPSILON*i2.edgeB >= DBL_EPSILON) return 1;
            if (bot+DBL_EPSILON*edgeB - i2.top-DBL_EPSILON*i2.edgeT >= DBL_EPSILON) return 1;
            return 0;
        }

        Interval operator/(const Interval &other) {
            if (!intCrossing(other)) return Interval(0, 0, 1, 1);
            Interval res;
            if (bot > other.bot) {
                res.bot = bot;
                res.edgeB = edgeB;
            } else {
                res.bot = other.bot;
                res.edgeB = other.edgeB;
            }
            if (top > other.top) {
                res.top = other.top;
                res.edgeT = other.edgeT;
            } else {
                res.top = top;
                res.edgeT = edgeT;
            }
            return res;
        }

        Interval operator+(const Interval &other) {
            if (!intCrossing(other)) return Interval(0, 0, 1, 1);
            Interval res;
            if (top > other.top) {
                res.top = top;
                res.edgeT = edgeT;
            } else {
                res.top = other.top;
                res.edgeT = other.edgeT;
            }
            if (bot > other.bot) {
                res.bot = other.bot;
                res.edgeB = other.edgeB;
            } else {
                res.bot = bot;
                res.edgeB = edgeB;
            }
            return res;
        }

        double length() {
            return top - bot;
        }

        int operator>(Interval i) {
            if (length() > i.length()) return 1;
            return 0;
        }

        friend ostream& operator<<(ostream &out, const Interval &i) {
            if (!i.edgeB) cout << "[";
            else cout << "(";
            cout << i.bot << "; " << i.top;
            if (!i.edgeT) cout << "]";
            else cout << ")";
        }

        friend istream& operator>>(istream &in, Interval &res) {
            cout << endl << "bot: ";
            cin >> res.bot;
            cout << "including edge?(0 - Yes, 1 - No)";
            int item;
            cin >> item;
            if (item == 0) res.edgeB = 0;
            else res.edgeB = 1;
            cout << "top: ";
            cin >> res.top;
            cout << "including edge?(0 - Yes, 1 - No)";
            cin >> item;
            if (item == 0) res.edgeT = 0;
            else res.edgeT = 1;
        }

        Interval(){bot=0;top=0;edgeB=1;edgeT=1;};
        Interval(double b, double t, int e1, int e2): bot(b), top(t), edgeB(e1), edgeT(e2){};
};


int main() {
    Interval i1(-1, 5, 0, 1), i2(4, 7, 1, 1), i3, i4;
    i3 = i1+i2;
    cout << i1 << " + " << i2 << " = " << i3;
    i4 = i1/i2;
    cout << endl << i1 << " / " << i2 << " = " << i4;

    int n;
    cout << "\nHow many intervals do you want? ";
    cin >> n;
    Interval* ints = (Interval*)malloc(sizeof(Interval)*n);
    for (int i=0; i<n; i++) {
        cin >> ints[i];
    }
    cout << endl;
    Interval max_int;
    for (int i=0; i<n; i++) {
        cout << ints[i] << " ";
        if (ints[i] > max_int) max_int = ints[i];
    }
    cout << "\nMax interval: " << max_int;

    free(ints);
}
