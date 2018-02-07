#pragma once
#include <string>

class BigInt
{
  public:
    // TODO: Where I should use 'explicit' keyword?
    BigInt(const std::string &);
    BigInt(const std::string &, const bool &);

    BigInt(const BigInt &);
    BigInt operator=(const BigInt &);
    BigInt(BigInt &&);
    BigInt operator=(BigInt &&);

    // Getters and Setters
    const std::string &getNumber() const;
    void setNumber(const std::string &);

    const bool &getSign() const;
    void setSign(const bool &);

    // Basic operation
    // TODO: Change to return the const reference
    std::string add(std::string);

    std::string sub(const std::string &);

    std::string mul(const std::string &);

    std::string div(const std::string &);

    // operators
    BigInt operator+(BigInt);
    // BigInt operator+(const BigInt &);
    BigInt operator-(BigInt);
    BigInt operator*(BigInt);
    BigInt operator/(BigInt);

    bool operator>(const BigInt &);
    bool operator<(const BigInt &);
    bool operator==(const BigInt &);
    bool operator>=(const BigInt &);
    bool operator<=(const BigInt &);
    bool operator!=(const BigInt &);

    // Utility functions
    bool greater        (const BigInt &, const BigInt &);
    bool less           (const BigInt &, const BigInt &);
    bool greaterOrEqual (const BigInt &, const BigInt &);
    bool lesserOrEqual  (const BigInt &, const BigInt &);
    bool equal          (const BigInt &, const BigInt &);
    bool notEqual       (const BigInt &, const BigInt &);

    BigInt abs();

  private:
    std::string add(std::string left,
                    std::string right);
    std::string sub(std::string left,
                    std::string right);
    std::string mul(std::string left,
                    std::string right);
    std::string div(std::string left,
                    std::string right);

  private:
    std::string m_number;
    bool m_sign;
};