
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Poly{
  int deg;
  vector <double> coefs;
  string name;

public:
  Poly() {
    deg = 0;
    coefs = {0.};
    name = "";
  }

  void set() {
    int n;
    vector <double> c;
    string s;
    cout << endl << endl << "enter polynom name : ";
    cin >> s;
    cout << endl << "enter polynom deg : ";
    cin >> n;
    cout << endl << "enter polynom coefs : " << endl;

    for (int i = 0; i < n + 1; i++) {
      double temp;
      cin >> temp;
      c.push_back(temp);
    }

    this->deg = n;
    this->coefs = c;
    this-> name = s;
  }
  
  double calc(double x) {
    double res = 0;
    for (int i = 0; i < this->deg; i++) {
      res += this->coefs[i] * pow(x, this->deg - i);
    }
    res += this->coefs[this->deg];
    return res;
  }

  Poly derivative() {
    Poly ret;
    if (this->deg == 0) {
      ret.deg = 0;
      ret.coefs[0] = 0;
    }
    if (this->deg == 1) {
      ret.deg = 0;
      ret.coefs[0] = this->coefs[0];
    }
    else {
      ret.deg = this->deg - 1;
      ret.coefs.resize(this->deg);
      for (int i = 0; i < ret.deg; i++) {
        ret.coefs[i] = this->coefs[i] * (this->deg - i);
      }
      ret.coefs[ret.deg] = this->coefs[ret.deg];
    }
    ret.name = this->name + "`";
    return ret;
  }

  friend ostream& operator << (ostream&, const Poly&);
  friend const Poly operator + (const Poly&, const Poly&);
  friend const Poly operator - (const Poly&, const Poly&);
  friend const Poly operator * (const Poly&, const Poly&);
};

ostream& operator << (ostream &out, const Poly &p) {
  if (p.deg <= 0) {
    out << endl << p.name << " : " << p.coefs[0];
  }
  else {
    out << endl << p.name << " : ";
    out << p.coefs[0] << "x^" << p.deg;
    for (int i = 1; i < p.deg; i++) {
      if (p.coefs[i] >= 0) out << " + ";
      else out << " - ";
      out << abs(p.coefs[i]) << "x^" << p.deg - i;
    }
    if (p.coefs[p.deg] >= 0) out << " + ";
      else out << " - ";
    out << abs(p.coefs[p.deg]);
  }
  return out;
}

const Poly operator + (const Poly& left, const Poly& right) {
  Poly ret;
  int max_deg;
  left.deg > right.deg ? max_deg = left.deg : max_deg = right.deg;
  ret.deg = max_deg;
  ret.coefs.resize(max_deg + 1);
  Poly a = left;
  Poly b = right;
  reverse(a.coefs.begin(), a.coefs.end());
  reverse(b.coefs.begin(), b.coefs.end());
  a.coefs.size() > b.coefs.size() ? b.coefs.resize(a.coefs.size()) : a.coefs.resize(b.coefs.size());
  for (int i = 0; i < ret.deg + 1; i++) {
    ret.coefs[i] = a.coefs[i] + b.coefs[i];
  }
  reverse(ret.coefs.begin(), ret.coefs.end());
  ret.name = left.name + " + " + right.name;
  return ret;
}

const Poly operator - (const Poly& left, const Poly& right) {
  Poly ret;
  int max_deg;
  left.deg > right.deg ? max_deg = left.deg : max_deg = right.deg;
  ret.deg = max_deg;
  ret.coefs.resize(max_deg + 1);
  Poly a = left;
  Poly b = right;
  reverse(a.coefs.begin(), a.coefs.end());
  reverse(b.coefs.begin(), b.coefs.end());
  a.coefs.size() > b.coefs.size() ? b.coefs.resize(a.coefs.size()) : a.coefs.resize(b.coefs.size());
  for (int i = 0; i < ret.deg + 1; i++) {
    ret.coefs[i] = a.coefs[i] - b.coefs[i];
  }
  reverse(ret.coefs.begin(), ret.coefs.end());
  ret.name = left.name + " - " + right.name;
  return ret;
}

const Poly operator * (const Poly& left, const Poly& right) {
  Poly ret;
  ret.deg = left.deg + right.deg;
  ret.coefs.resize(ret.deg + 1);
  Poly a = left;
  Poly b = right;
  reverse(a.coefs.begin(), a.coefs.end());
  reverse(b.coefs.begin(), b.coefs.end());
  for (int i = left.deg; i >= 0; i--)
    for (int j = right.deg; j >= 0; j--)
      ret.coefs[i + j] += left.coefs[i] * right.coefs[j];
  ret.name = left.name + " * " + right.name;
  return ret;
}


int main() {
  //a = x^4 + 7x^2 - 11x + 3
  //b = x^3 - 6x + 9
  //c = x^4 + 5x - 4
  //d = x
  //посчитаем выражаение : (a` + b * c) * d + c
  Poly a, b, c, d;
  a.set();
  cout << a;
  b.set();
  cout << b;
  c.set();
  cout << c;
  d.set();
  cout << d;
  cout << (a.derivative() + b * c) * d + c;
}