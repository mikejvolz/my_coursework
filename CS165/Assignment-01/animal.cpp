/*********************************************************************
 * ** Author:  somebody who is not me  (code copied from instructure)
 * ** Date:    9/22/2016
 * ** Description:  A simple input-output program
 * *********************************************************************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
    std::string faveAnimal;
    std::cout << "Please enter your favorite animal." << std::endl;
    std::cin >> faveAnimal;
    std::cout << "Your favorite animal is the " << faveAnimal;
    std::cout << "." << std::endl;    
    
    return 0;
}
