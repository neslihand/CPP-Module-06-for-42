/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:48:03 by ndogan            #+#    #+#             */
/*   Updated: 2025/08/03 19:09:38 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ABC.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() {
    int random = std::rand() % 3;
    
    try
    {
        switch (random) {
            case 0: return new A();
            case 1: return new B();
            case 2: return new C();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return NULL; 
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
    
    std::cout << "Unknown type" << std::endl;
}


int main() {
    std::srand(std::time(0));
    
    for (int i = 0; i < 10; i++) {
        Base* obj = generate();
        
        std::cout << "Test " << i + 1 << ":" << std::endl;
        std::cout << "Pointer identification: ";
        identify(obj);
        
        std::cout << "Reference identification: ";
        identify(*obj);
        
        std::cout << std::endl;
        delete obj;
    }
    
    return 0;
}