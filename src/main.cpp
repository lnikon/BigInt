#include <iostream>

#include "bigint.h"

int main()
{
    BigInt num1("5");
    BigInt num2("4");

    // BigInt num1("0");
    // BigInt num2("0");

    // std::cout << "Enter num1: ";
    // std::cin >> num1;

    // std::cout << "Enter num2: ";
    // std::cin >> num2;

    // auto res2 = num1 + num2;
    // std::cout
    //     << "\nAddition: "
    //     << res2 << std::endl;

    // auto res3 = num2 - num1;
    // std::cout
    //     << "\nSubtraction: "
    //     << res3 << std::endl;

    // auto res4 = num1 * num2;
    // BigInt res4("6");
    // std::cout << "res4: "
        // << res4 << std::endl;

    BigInt res5("521");
    std::cout
        << "\nFactorial: "
        << res5.factorial() << std::endl;
    return 0;
}
