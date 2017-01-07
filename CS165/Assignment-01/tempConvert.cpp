/*********************************************************************
 * ** Author:  Michael Volz
 * ** Date:    9/22/2016
 * ** Description:  A simple program that converts 
 * **                 Celsius temperatures to Fahrenheit temperatures
 * *********************************************************************/

#include <iostream>
#include <string>

int main()
{
  float temperatureCelsius;          // declare Celsius variable
  float temperatureFahrenheit;       // declare Fahrenheit variable

  // promp user for input
  std::cout << "Please enter a Celsius temperature." << std::endl;
  std::cin >> temperatureCelsius;    // user input to temperatureCelsius

  // now we have the user input, and can calculate the Fahrenheit value
  // apparently floating point literals must have .0 at the end
  temperatureFahrenheit = temperatureCelsius * (9.0/5.0) + 32.0;

  // display the resulting value
  std::cout << "The equivalent Fahrenheit temperature is:\n" << temperatureFahrenheit << std::endl; 
    
  return 0;
}
