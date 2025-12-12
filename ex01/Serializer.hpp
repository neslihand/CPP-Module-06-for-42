/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:34:05 by ndogan            #+#    #+#             */
/*   Updated: 2025/07/25 17:30:37 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer{
    private:

    Serializer();
    Serializer(int id, std::string name);
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

    public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};