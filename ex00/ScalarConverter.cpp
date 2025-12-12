/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:13:44 by ndogan            #+#    #+#             */
/*   Updated: 2025/07/25 16:26:22 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cmath>
#include <limits>


ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(std::string const _str){
    std::cout << "ScalarConverter constructor called!" << std::endl;
    str = _str;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other): str(other.str){
    std::cout << "ScalarConverter copy constructor called!" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    if (this != &other)
        this->str = other.str;
    std::cout << "ScalarConverter copy assignment operator called!" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor called!" << std::endl;
}

char ScalarConverter::isChar(std::string str){
    if ((str[0] != 0 && str[1] == 0))
    {
        if(isdigit(str[0]))
            return isInt(str);
        else 
            return 'c';
    } 
    else
        return isInt(str); 

}

char ScalarConverter::isInt(std::string str){
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
        return isFloat(str);
    
    while (str[i])
    {
        if (str[i] == '.' || str[i] == 'e' || str[i] == 'E')
            return isDouble(str);
        else if (!isdigit(str[i]))
            return 'n';
        if (i > 10)
            return isDouble(str);
        i++;
    }
    std::stringstream ss(str);
    long l;
    ss >> l;

    if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        return isDouble(str);
    
    return 'i';
}

char ScalarConverter::isFloat(std::string str){
    size_t i = 0;
    bool point = false;
    int pointPos = -1;
    bool eFound = false;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    if (str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F')
        return isDouble(str);

    while (i < str.length() - 1)
    {
        if (!point && str[i] == '.')
        {
            point = true;
            pointPos = i;
            i++;
        }
        else if ((str[i] == 'e' || str[i] == 'E') && !eFound)
        {
            eFound = true;
            i++;
            if (str[i] == '+' || str[i] == '-')
                i++;
            if (!isdigit(str[i]))
                return 'n';
            while (isdigit(str[i]))
                i++;
        }
        else if(isdigit(str[i]))
            i++;
        else
            return 'n';
    }

    if (point)
    {
         if (pointPos == 0 || pointPos == (int)str.length() - 1)
            return 'n'; 
        if (!isdigit(str[pointPos - 1]) || !isdigit(str[pointPos + 1]))
            return 'n';
    }
    return 'f';
    
}

char ScalarConverter::isDouble(std::string str){
    int i = 0;
    bool point = false;
    int pointPos = 0;
    bool eFound = false; 
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    while (str[i])
    {
        if (!point && str[i] == '.')
        {
            point = true;
            pointPos = i;
            i++;
        }
        else if ((str[i] == 'e' || str[i] == 'E') && !eFound)
        {
            eFound = true;
            i++;
            if (str[i] == '+' || str[i] == '-')
                i++;
            if (!isdigit(str[i]))
                return 'n';
            while (isdigit(str[i]))
                i++;
        }
        else if (isdigit(str[i]))
            i++;
        else
            return 'n';
    }
    if (point)
    {
        if (pointPos == 0 || pointPos == (int)str.length() - 1)
            return 'n'; 
        if (!isdigit(str[pointPos - 1]) || !isdigit(str[pointPos + 1]))
            return 'n';
    }
    return 'd';
}

void ScalarConverter::fromChar(std::string str)
{
    unsigned char c = static_cast<unsigned char>(str[0]);

    if (c < 32 || c >= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt(std::string str)
{
    std::stringstream ss(str);
    long i;
    ss >> i;
        
    unsigned char c = static_cast<unsigned char>(i);

    if (i < 0 || i > std::numeric_limits<int>::max())
        std::cout << "char: impossible" << std::endl; 
    else if (c < 32 || c >= 127)
        std::cout << "char: Non displayable" << std::endl; 
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::fromFloat(std::string str)
{
    std::stringstream ss(str);
    float f;
    ss >> f;
    
    unsigned char c = static_cast<unsigned char>(f);

    if (f < 0 || f > std::numeric_limits<int>::max())
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c >= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(std::string str)
{
    std::cout << "geldii" << std::endl;
    std::stringstream ss(str);
    double d;
    ss >> d;
    unsigned char c = static_cast<unsigned char>(d);

    std::cout << d << std::endl;


    if (d < 0 || d > std::numeric_limits<int>::max())
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c >= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::impossible()
{
    std::cout << "char: impossible \nint: impossible \nfloat: impossible \ndouble: impossible"<< std::endl;
}

void ScalarConverter::spacialLiteral(std::string str){

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf" || str == "+nan" || str == "+nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    else if (str == "-inf" || str == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return (
        str == "-inff" || str == "+inff" || str == "nanf" ||
        str == "-inf"  || str == "+inf"  || str == "nan" ||
        str == "inf" || str == "inff" || str == "+nan" || str == "+nanf"
    );
}

void ScalarConverter::convert(std::string literal){
    if (literal.length() == 0)
        return impossible();

    if (isPseudoLiteral(literal))
        return spacialLiteral(literal);
    
    const char result = isChar(literal);
    
    switch (result)
    {
        case 'c':
            fromChar(literal);
            break;
        case 'i':
            fromInt(literal);
            break;
        case 'f':
            fromFloat(literal);
            break;
        case 'd':
            fromDouble(literal);
            break;
        case 'n':
            impossible();
            break;
        default:
            break;
    }
}