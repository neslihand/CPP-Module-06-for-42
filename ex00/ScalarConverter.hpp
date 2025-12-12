/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:13:54 by ndogan            #+#    #+#             */
/*   Updated: 2025/07/23 16:17:03 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ScalarConverter{
    private:
        std::string str;

        ScalarConverter();
        ScalarConverter(const std::string str);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static char isChar(std::string str);
        static char isFloat(std::string str);
        static char isInt(std::string str);
        static char isDouble(std::string str);

        static void fromChar(std::string str);
        static void fromInt(std::string str);
        static void fromFloat(std::string str);
        static void fromDouble(std::string str);
        
        static void spacialLiteral(std::string str);
        static void impossible();
        static bool isPseudoLiteral(const std::string& str);
    public:
        static void convert(std::string literal);

};
