/**
 * Contains physics equations as functions.
 * 
 * Each function represents some sort of physics equation or something close.
 * 
 * @note These functions are mainly for 1-d calculations, most do not take CoordStructs or other structs as arguments and do not return them. They will typically return float values.
 * 
 * @file PhysicsEquations.h
 */

#ifndef PHYSICSEQUATIONS_H
#define PHYSICSEQUATIONS_H

#pragma once

#include "Types.h"

#include <math.h>

//holds the basic equations needed for physic calculations as functions.
//The function name is the variable it is finding and the parameters are what it is finding it with.

/// @brief Finds force using f = ma.
/// @param objectMass A variable of type float for the objects mass.
/// @param objectAcceleration A variable of type float for objects acceleration.
/// @return Force as type float.
float findForce(float objectMass, float objectAcceleration);    

//-------------- kinematics --------------

/// @brief Finds velocity with v = v + at.
/// @param deltaTime The delta time.
/// @param objectVelocity The objects velocity.
/// @param objectAcceleration The objects acceleration.
/// @return A new velocity as type float.
float findVelocity(float deltaTime, float objectVelocity,float objectAcceleration);

/// @brief Finds displacement using x = v*t + (.5)*(a)*(square(t)).
/// @param deltaTime The delta time.
/// @param objectVelocity The objects velocity.
/// @param objectAcceleration The objects acceleration.
/// @return Displacement as type float.
float findDisplacement(float deltaTime, float objectVelocity, float objectAcceleration);    

/// @brief Overloaded function for find displacement without acceleration.
/// @param deltaTime The delta time. 
/// @param objectVelocity The objects Velocity.
/// @return Displacement as type float.
float findDisplacement(float deltaTime, float objectVelocity);                               


#endif