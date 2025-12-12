/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:34:01 by ndogan            #+#    #+#             */
/*   Updated: 2025/07/25 17:35:07 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "Serializer default constructor called!" << std::endl;
}

Serializer::Serializer(int id, std::string name){
    (void)id;
    (void)name;
    std::cout << "Serializer constructor called!" << std::endl;
}

Serializer::Serializer(const Serializer& other){
    (void)other;
    std::cout << "Serializer copy constructor called!" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    std::cout << "Serializer operator called!" << std::endl;
    return *this;
}

Serializer::~Serializer(){
    std::cout << "Serializer destructor called!" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}
