#include <iostream>

int main()
{
    int fib1 = 1;
    int fib2 = 2;
    int fib3 = 0;
    int sum = fib2;
    while (fib3 < 4000000)
    {
        fib3 = fib1 + fib2;

        if (fib3 % 2 == 0)
        {
            //sum of the even-valued fibonacci terms
            sum += fib3;
            std::cout << sum << '\n';
        }


        fib1 = fib2;
        fib2 = fib3;

    }

    std::cout << '\n';

    return 0;

}