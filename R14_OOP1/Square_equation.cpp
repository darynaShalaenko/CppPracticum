#include <cassert>
#include <vector>

using namespace std;

class Square_equation
{
    private:
        double _a, _b, _c;

    public:
        Square_equation(double a, double b, double c) {
            setA(a);
            setB(b);
            setC(c);
        }

        void setA(double a) {
            assert(a != 0);
            _a = a;
        }

        double getA() {
            return _a;
        }

        void setB(double b) {
            _b = b;
        }

        double getB() {
            return _b;
        }

        void setC(double c) {
            _c = c;
        }

        double getC() {
            return _c;
        }

        friend ostream& operator<<(ostream& out, Square_equation& se) {
            out << se._a << " * x ^ 2 + (" << se._b << ") * x + (" << se._c << ") = 0";
            return out;
        }

        vector<double> getRoots() {
            vector<double> roots;
            double D = (_b * _b - 4 * _a * _c);
            if (D >= 0){
                roots.push_back(( -1 * _b + sqrt(D)) / (2 * _a));
                roots.push_back(( -1 * _b - sqrt(D)) / (2 * _a));
            }
            return roots;
        }

        double getExtremum() {
            return - _b / (2 * _c);
        }

        void getInreasing() {
            if (_a > 0) {
                cout << "["<< this->getExtremum() << "; +oo)";
            } else {
                cout << "(-oo; " << this->getExtremum() << ")";
            }
        }

        void getDecreasing() {
            if (_a < 0) {
                cout << "["<< this->getExtremum() << "; +oo)";
            } else {
                cout << "(-oo; " << this->getExtremum() << "]";
            }
        }
};

int main() {
    vector<double> allRoots;
    Square_equation se1 = Square_equation(1, 2, 1);
    Square_equation se2 = Square_equation(1, -2, 1);
    Square_equation se3 = Square_equation(1, 6, -2);
    Square_equation se4 = Square_equation(1, 0, -4);
    Square_equation arr[4] = {se1, se2, se3, se4};
    for (Square_equation se : arr) {
        vector<double> roots = se.getRoots();
        allRoots.insert(allRoots.end(), roots.begin(), roots.end());
    }
    double min = 100500, max = -100500;
    for (double r : allRoots) {
        if (max < r) {
            max = r;
        }
        if (min > r) {
            min = r;
        }
    }
    cout << min << " " << max << endl;
    return 0;
}
