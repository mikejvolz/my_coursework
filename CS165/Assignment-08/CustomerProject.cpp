/****************************************************************
 ** Author:  Michael Volz
 ** Date:   11/14/2016
 ** Description: Implementation of CustomerProject class
 **             member variables include: hours, materials, and transportation
 **             (each doubles), as well as set and get methods for each
 **             also pure virtual method billAmount
 ***************************************************************/

#include "CustomerProject.hpp"
#include <iostream>

using namespace std;

/************************************************
 * CustomerProject constructor with arguments
 ************************************************/
CustomerProject::CustomerProject(double newHours, double newMaterials, double newTransportation)
{
    setHours(newHours);
    setMaterials(newMaterials);
    setTransportation(newTransportation);
}

/************************************************
 * CustomerProject setHours method applies input value to 
 * hours data member
 ************************************************/
void CustomerProject::setHours(double newHours)
{
    this->hours = newHours;
}

/************************************************
 * CustomerProject getHours method returns value of
 * hours data member
 ************************************************/
double CustomerProject::getHours()
{
  return this->hours;
}

/************************************************
 * CustomerProject setMaterials method applies input value to 
 * materials data member
 ************************************************/
void CustomerProject::setMaterials(double newMaterials)
{
    this->materials = newMaterials;
}

/************************************************
 * CustomerProject getMaterials method returns value of
 * materials data member
 ************************************************/
double CustomerProject::getMaterials()
{
  return this->materials;
}

/************************************************
 * CustomerProject setTransportation method applies input value to 
 * Transportation data member
 ************************************************/
void CustomerProject::setTransportation(double newTransportation)
{
    this->transportation = newTransportation;
}

/************************************************
 * CustomerProject getTransportation method returns value of
 * transportation data member
 ************************************************/
double CustomerProject::getTransportation()
{
  return this->transportation;
}

/************************************************
 * CustomerProject billAmount method 
 * 
 ************************************************/
double CustomerProject::billAmount()
{
  // empty method - pure virtual method
}

