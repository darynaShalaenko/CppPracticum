include <iostream>

using namespace std;


class PolynomialError: public logic_error {

public:
    PolynomialError(string message): logic_error(message) {}
};


class NegDegError: public PolynomialError {

public:
    NegDegError(): PolynomialError("Deg < 0!") {}
};

class NotIntengerError: public PolynomialError {

public:
    NotIntengerError(): PolynomialError("Deg is not an intenger") {}
};

class QCoefError: public PolynomialError {

public:
    QCoefError(): PolynomialError("Coef is not Q") {}
};



class Polynomial
{
private:
   int coef[100];  

   int deg;       


public:
    Polynomial() 
    {
        for ( int i = 0; i < 100; i++ )
        {
            coef[i] = 0;
        }
    }

    void set ( double a , double b ) 
    {
      if (b<0.0) throw NegDegError();
      if ((double)((int)b)!=b) throw NotIntengerError();
      if (a!=(double)a) throw QCoefError();
      coef[(int)b] = (double)a;
      deg = degree();
    }

    void input(istream& inp = cin) {
        double a, b;
        inp >> a;
        inp.ignore(256, '/');
        inp >> b;
        set(a, b);
    }



   int degree()
   {
      int d = 0;
      for ( int i = 0; i < 100; i++ )
         if ( coef[i] != 0 ) d = i;
      return d;
   }

   void print()
   {
      for ( int i = 99; i >= 0; i-- ) {
          if ( coef[i] != 0 ) {
              if (coef[i]>0) cout<<"+";
              cout << coef[i] << "x^" << i;
          }
      }
      cout<<"=0";
   }


   int evaluate ( int x )
   {
      int p = 0;
      for ( int i = deg; i >= 0; i-- )
         p = coef[i] + ( x * p );
      return p;
   }


   Polynomial differentiate()
   {
      if ( deg == 0 )  {
         Polynomial t;
         t.set ( 0, 0 );
         return t;
      }
      Polynomial deriv;// = new Polynomial ( 0, deg - 1 );
      deriv.deg = deg - 1;
      for ( int i = 0; i < deg; i++ )
         deriv.coef[i] = ( i + 1 ) * coef[i + 1];
      return deriv;
   }

   Polynomial plus ( Polynomial b )
   {
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;

      for ( int i = 0; i <= a.deg; i++ ) c.coef[i] += a.coef[i];
      for ( int i = 0; i <= b.deg; i++ ) c.coef[i] += b.coef[i];
      c.deg = c.degree();

      return c;
   }

   Polynomial minus ( Polynomial b )
   {
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;

      for ( int i = 0; i <= a.deg; i++ ) c.coef[i] += a.coef[i];
      for ( int i = 0; i <= b.deg; i++ ) c.coef[i] -= b.coef[i];
      c.deg = c.degree();

      return c;
   }

   Polynomial times ( Polynomial b )
   {
      Polynomial a = *this; 
      Polynomial c;

      for ( int i = 0; i <= a.deg; i++ )
         for ( int j = 0; j <= b.deg; j++ )
            c.coef[i+j] += ( a.coef[i] * b.coef[j] );
      c.deg = c.degree();
      return c;
   }
};

int main()
{
   int i=0, n=1;
   while (i<n){
   try {
       Polynomial a, b, c, d;
       double deg,coef;
       cin>>deg>>coef;
       a.set(coef,deg); 
       cin>>deg>>coef;
       a.set (coef,deg); 
       cin>>deg>>coef;
       b.set (coef,deg); 
       cin>>deg>>coef;
       b.set (coef,deg); 

        c = a.minus ( b ); 
        cout << "minus:";
        c.print();
        cout << "\n";

        c = a.times ( b ); 
        c.print();
        cout << "\n";

        cout << "differentiate:";
        d = c.differentiate();
        d.print();
        cout << "\n";

        cout << c.evaluate ( 2 ); //substitue x with 2

        }
        catch (PolynomialError & e) {
            cout << e.what() << endl;
            cout << "Try again" << endl;
            continue;
        }
        catch (exception& e) {
            cout << e.what() << endl;
            break;
        }
        catch (...) {
            cout << "Unknown exception was caught" << endl;
            break;
        }
        i++;
   }

} 
