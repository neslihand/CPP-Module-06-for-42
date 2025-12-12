/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:34:10 by ndogan            #+#    #+#             */
/*   Updated: 2025/07/30 22:47:00 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data original(42, "Test Data");
    
    // Print original address and values
    std::cout << "Original address: " << &original << std::endl;
    std::cout << "Original values: " << original.value << ", " << original.name << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize back to pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    
    // Verify the deserialized pointer
    if (deserialized == &original) {
        std::cout << "Success! Pointers match." << std::endl;
        std::cout << "Deserialized values: " << deserialized->value << ", " << deserialized->name << std::endl;
    } else {
        std::cout << "Error! Pointers don't match." << std::endl;
    }

    std::cout << "----- Test Over -----" << std::endl;
    
    return 0;
}
