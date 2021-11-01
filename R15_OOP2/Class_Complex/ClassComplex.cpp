#include <string>
#include <sstream>

enum class ENumberType
{
    Unknown,
    Simple,
    Complex
};

class INumber
{
public:
    explicit INumber(ENumberType type)
        : m_type(type)
    {
    }

    // Virtual dtor to achive proper deletion of object with pointer on Base class.
    virtual ~INumber() = default;

    // Pure virtual function.
    virtual std::string GetInfo() const = 0;

    void SetType(ENumberType type) { m_type = type; }
    ENumberType GetType() const { return m_type; }

    // Overload output operator.
    friend std::ostream& operator<< (std::ostream& out, INumber const& n)
    {
        out << n.GetInfo();
        return out;
    }

protected:
    ENumberType m_type = ENumberType::Unknown;
};

// ENumberType::Simple just for demostrate posibilities of using abstartct INumber class.

class Complex : public INumber
{
public:
    // All ctors
    Complex()
        : INumber(ENumberType::Complex)
        , m_x(0.0)
        , m_i(0.0)
    {
    }

    Complex(double x)
        : INumber(ENumberType::Complex)
        , m_x(x)
        , m_i(0.0)
    {
    }

    Complex(double x, double i)
        : INumber(ENumberType::Complex)
        , m_x(x)
        , m_i(i)
    {
    }

    Complex(Complex const& other)
        : INumber(other.m_type)
        , m_x(other.m_x)
        , m_i(other.m_i)
    {
    }

    // Override virtual method
    std::string GetInfo() const override
    {
        std::stringstream ss;
        ss << "Complex number: x=" << m_x << " i=" << m_i;
        return ss.str();
    }

    // Overload operators
    Complex& operator= (Complex const& other)
    {
        if (this != &other)
        {
            m_x = other.m_x;
            m_i = other.m_i;
        }

        return *this;
    }

    Complex& operator+= (Complex const& other)
    {
        m_x += other.m_x;
        m_i += other.m_i;
        return *this;
    }

    Complex operator+ (Complex const& other)
    {
        return Complex(m_x + other.m_x, m_i + other.m_i);
    }

    Complex operator- (Complex const& other)
    {
        return Complex(m_x - other.m_x, m_i - other.m_i);
    }

    Complex operator* (Complex const& other)
    {
        return Complex(m_x * other.m_x, m_i * other.m_i);
    }

    Complex operator/ (Complex const& other)
    {
        Complex temp;

        double x = other.m_x * other.m_x + other.m_i * other.m_i;
        temp.m_x = (m_x * other.m_x + m_i * other.m_i) / x;
        temp.m_i = (m_i * other.m_x - m_x * other.m_i) / x;

        return temp;
    }

    // Overload input operator.
    friend std::istream& operator>> (std::istream& in, Complex& c)
    {
        in >> c.m_x >> c.m_i;
        return in;
    }

private:
    double m_x;
    double m_i;
};