#include <string>
#include <sstream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::map;
using std::pair;
using monom = pair<size_t, int>;

vector<string> tokenize(string str, string delim) {
    vector<string> result{};
    size_t previous = 0;
    size_t current = str.find_first_of(delim);
    while (previous != string::npos) {
        if (previous != current)
            result.push_back(str.substr(previous, current - previous));
        previous = current;
        current = str.find_first_of(delim, ++current);
    }
    return result;
}

monom get_monom(string token, string delim, char variable) {
    size_t var_pos = token.find(variable);
    size_t power{ 0 }; int coeff{ 0 };
    if (var_pos != string::npos) {
        stringstream ss1(token.substr(0, var_pos) + "1");
        ss1 >> coeff;
        stringstream ss2(token.substr(++var_pos) + "^1");
        ss2.get();
        ss2 >> power;
    }
    return { power, coeff };
}

string derive_monom(monom m, bool first = false) {
    stringstream ss{};
    if ((m.second *= m.first--) != 0) {
        ss << (first || m.second < 0 ? "" : "+");
        if (std::abs(m.second) != 1 || m.first == 0)
            ss << m.second;
        if (std::abs(m.second) != 1 && m.first > 0)
            ss << "*x";
        if (m.first > 1)
            ss << "^" << m.first;
    }
    return ss.str();
}

class polynom : public map<size_t, int> {
public:
    polynom(const string& polynomial, const string& delim, char var) {
        auto tokens = tokenize(polynomial, delim);
        for (auto token : tokens)
            add(get_monom(token, delim, var));
    }

    void add(monom value) {
        auto it = this->find(value.first);
        if (it == this->end()) {
            this->insert(value);
            return;
        }
        it->second += value.second;
    }

    string derivative() const {
        stringstream ss{};
        for (auto rev = this->rbegin(), first = rev; rev != this->rend(); ++rev)
            ss << derive_monom(*rev, rev == first);
        return ss.str();
    }
};

std::string derivative(std::string polynomial) {
    polynom poly(polynomial, "+-", 'x');
    return poly.derivative();
}
