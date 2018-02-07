#include <iostream>
#include "bigint.h"

// ===================================
// Big five is here
// ===================================

BigInt::BigInt(
    const std::string &number)
{
    setNumber(number);
}

BigInt::BigInt(
    const std::string &number,
    const bool &sign)
{
    setNumber(number);
    setSign(sign);
}

BigInt::BigInt(const BigInt &ob)
{
    setNumber(ob.getNumber());
    setSign(ob.getSign());
}

BigInt BigInt::operator=(const BigInt &ob)
{
    BigInt res(ob);
    return res;
}

BigInt::BigInt(BigInt &&)
{

}

BigInt BigInt::operator=(BigInt &&)
{

}

// ===================================
// Getters and Setters
// ===================================

const std::string& BigInt::getNumber() const
{
    return m_number;
}

void BigInt::setNumber(const std::string &number)
{
    if (number[0] == '+')
    {
        m_number = number.substr(1, number.length() - 1);
        setSign(false);
    }
    else if (number[0] == '-')
    {
        m_number = number.substr(1, number.length() - 1);
        setSign(true);
    }
    else
    {
        m_number = number;
        setSign(false);
    }
}

const bool &BigInt::getSign() const
{
    return m_sign;
}

void BigInt::setSign(const bool &sign)
{
    m_sign = sign;
}

// ===================================
// Basic operations. + - * /
// ===================================

std::string BigInt::add(std::string left,
                        std::string right)
{
    std::string temp;
    auto diff = std::abs((int)left.length() - (int)right.length());

    if (left.length() > right.length())
    {
        right.insert(0, diff, '0');
    }
    else if (left.length() < right.length())
    {
        left.insert(0, diff, '0');
    }

    temp = left;

    char rem = '0';
    for (int i = temp.length() - 1; i >= 0; --i)
    {
        temp[i] = ((rem - '0') + (left[i] - '0') + (right[i] - '0')) + '0';

        if (i != 0)
        {
            if (temp[i] > '9')
            {
                temp[i] -= 10;
                rem = '1';
            }
            else
            {
                rem = '0';
            }
        }

        if (temp[0] > '9')
        {
            temp[0] -= 10;
            size_t one = 1;
            temp.insert(0, one, '1');
        }
    }
    return temp;
}

std::string BigInt::add(std::string right)
{
    return add(m_number, right);
}

std::string BigInt::sub(std::string left,
                        std::string right)
{
    std::string temp;
    auto diff = std::abs((int)left.length() - (int)right.length());

    if (left.length() > right.length())
    {
        right.insert(0, diff, '0');
    }
    else if (left.length() < right.length())
    {
        left.insert(0, diff, '0');
    }

    temp = left;

    for(int i = left.length() - 1; i >= 0; --i)
    {
        if(left[i] < right[i])
        {
            left[i] += 10;
            left[i - 1] -= 1;
        }
        temp[i] = ((left[i] - '0') - (right[i] - '0')) + '0';
    }

    while(temp[0] == '0' && temp.length() != 1)
    {
        temp.erase(0, 1);
    }

    return temp;
}

std::string BigInt::sub(const std::string &right)
{
    return sub(getNumber(), right);
}

std::string BigInt::mul(std::string left,
                        std::string right)
{
}

std::string BigInt::mul(const std::string &right)
{
    mul(getNumber(), right);
}

std::string BigInt::div(std::string left,
                        std::string right)
{
}

std::string BigInt::div(const std::string &right)
{
    div(getNumber(), right);
}

// ===================================
// Operators overloading
// ===================================

BigInt BigInt::operator+(BigInt ob)
{
    BigInt temp("0");

    if(getSign() == ob.getSign())
    {
        temp.setNumber(add(getNumber(), ob.getNumber()));
        temp.setSign(ob.getSign());
    }
    else
    {
        if(abs() > ob.abs())
        {
            temp.setNumber(sub(getNumber(), ob.getNumber()));
            temp.setSign(getSign());
        }
        else
        {
            temp.setNumber(sub(ob.getNumber(), getNumber()));
            temp.setSign(ob.getSign());
        }
    }

    if(temp.getNumber()  == "0")
    {
        temp.setSign(false);
    }

    return temp;
}

BigInt BigInt::operator-(BigInt ob)
{
    ob.setSign(!ob.getSign());
    return *this + ob;
}

BigInt BigInt::operator*(BigInt ob)
{

}

BigInt BigInt::operator/(BigInt ob)
{

}

bool BigInt::operator>(const BigInt & ob)
{
    return greater(*this, ob);
}

bool BigInt::operator<(const BigInt & ob)
{
    return less(*this, ob);
}

bool BigInt::operator==(const BigInt & ob)
{
    return equal(*this, ob);
}

bool BigInt::operator>=(const BigInt & ob)
{
    return greaterOrEqual(*this, ob);
}

bool BigInt::operator<=(const BigInt & ob)
{
    return lesserOrEqual(*this, ob);
}

bool BigInt::operator!=(const BigInt & ob)
{
    return notEqual(*this, ob);
}

// ===================================
// Utility functions
// ===================================

bool BigInt::BigInt::greater(const BigInt &left,
                             const BigInt &right)
{
    return !less(left, right) &&
           !equal(left, right);
}

bool BigInt::less(const BigInt &left,
                  const BigInt &right)
{
    // -left/+right
    if((left.getSign() == true) && (right.getSign() == false))
    {
        // left < right
        return true;
    }
    // +left/-right
    else if((left.getSign() == false) && (right.getSign() == true))
    {
        // left > right
        return false;
    }
    // +left/+right
    else if((left.getSign() == false) && (right.getSign() == false))
    {
        if(left.getNumber().length() > right.getNumber().length())
        {
            return false;
        }
        else if(left.getNumber().length() < right.getNumber().length())
        {
            return true;
        }
        else 
        {
            return left.getNumber() < right.getNumber();
        }
    }
    // -left/-right
    else
    {
        if (left.getNumber().length() < right.getNumber().length())
        {
            return false;
        }
        else if (left.getNumber().length() > right.getNumber().length())
        {
            return true;
        }
        else
        {
            return left.getNumber() > right.getNumber();
        }
    }
}

bool BigInt::greaterOrEqual(const BigInt &left,
                            const BigInt &right)
{
    return greater(left, right) ||
           equal(left, right);
}

bool BigInt::lesserOrEqual(const BigInt &left,
                           const BigInt &right)
{
    return less(left, right) ||
           equal(left, right);
}

bool BigInt::equal(const BigInt &left,
                   const BigInt &right)
{
    return (left.getNumber() == right.getNumber()) &&
           (left.getSign() == right.getSign());
}

bool BigInt::notEqual(const BigInt &left,
                      const BigInt &right)
{
    return (left.getNumber() != right.getNumber()) ||
           (left.getSign() != right.getSign());
}

BigInt BigInt::abs()
{
    return BigInt(getNumber(), false);
}
