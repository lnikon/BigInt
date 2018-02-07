#include <iostream>

#include "bigint.h"

int main()
{
    BigInt num1("1000");
    BigInt num2("123");

    auto res2 = num1 + num2;
    std::cout 
    << "\nAddition: "
    << res2.getNumber() << std::endl;

    auto res3 = num1 - num2;
    std::cout 
    << "\nSubtraction: "
    << res3.getNumber() << std::endl;


    return 0;
}
