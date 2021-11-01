//Шаблони функцій та їх застосування.
//Шаблони класів та їх застосування. 
//Напишить шаблонний клас Раціональне число.

template <class N> //створюємо шаблон класу N, що представляє собою клас RacNumber - раціональне число
class RacNumber
{
    public:
    // конструктор,
    RacNumber(void) { }

    // метод множення чисел
    void Mult(N, N);

    // метод підведення числа до квадрату
    N MySquare(N);

    // метод, що відповідає за ділення
    N DivNumbers(N, N);
};

// шаблонний метод множення двох чисел
template <class N> void RacNumber<N>::Mult(N t1, T t2)
{
    return (N)(t1 * t2);
}

// шаблонний метод, що повертає квадрат числа
template <class N> N RacNumber<N>::MySquare(N number)
{
    return (N)(number*number);
}

// шаблон методу ділення двох чисел
template <class N> N RacNumber<N>::DivNumbers(N t1, T t2)
{
    return (N)(t1/t2);
}



int main()
{
    RacNumber <float> nf; //Об'єкт, що працює з типом float
    
    float d = 8.2f;
    float m = 20;
    
    float dm;
    dm = nf.Mult(&d, &m);
    
    float dd;
    dd = nf.MySquare(9);
    
    float t;
    t = mi.DivNumbers(5, 2);
}
