#ifndef TYPES_H
#define TYPES_H

#include "Object.h"

#include <utility>
#include <vector>

/**
 * A structure with 2 float values, x and y.
 * 
 * @struct CoordStruct
 */
struct CoordStruct{
    float x;
    float y;
};

/** 
 * A sructure with 2 CoordStruct structures, bottomLeft and topRight.
 * 
 * This structure represents the coords of a 
 * bottom left corner and a top right corner.
 * 
 * @struct CornerStruct
*/
struct CornerStruct{
    CoordStruct bottomLeft;
    CoordStruct topRight;
};

/**
 * Used to represent a 2d point.
 * 
 * Cooridinate is of type CoordStruct
 * 
 * @typedef Cooridinate
 */
using Cooridinate = CoordStruct;

/**
 * Used to hold a 2d point.
 * 
 * Velocity is of type CoordStruct and is used to 
 * hold the seperate x and y velocities.
 * 
 * @typedef Velocity
 */
using Velocity = CoordStruct;

/**
 * Used to hold a 2d point.
 * 
 * Acceleration is of type CoordStruct and is used to 
 * hold the seperate x and y accelerations.
 * 
 * @typedef Acceleration
 */
using Acceleration = CoordStruct;

/**
 * Used to hold 2 corners, making a plane.
 * 
 * Commonly used in the Rectangle class.
 * 
 * @see Rectangle.h
 * @see Rectangle.cpp
 * 
 * @typedef Plane
 */
using Plane = CornerStruct;

/**
 * Used to hold pointers to game objects
 * 
 * Commonly used in ObjectManager and CollisionDetectionManager
 * 
 * @see ObjectManager.h
 * @see ObjectManager.cpp
 * @see CollisionDetectionManager.h
 * @see CollisionDetectionManager.cpp
 * 
 * @typedef ObjectVector
 * 
 * @warning ObjectVector contains POINTERS to game OBJECTS. Be carefull when allocating to the std::vector.
 */
using ObjectVector = std::vector<Object*>;

/**
 * Used to hold ObjectVectors.
 * 
 * Commonly used to represent objects in collision.
 * 
 * @see CollisionDetectionManager.h
 * @see CollisionDetectionManager.cpp
 * 
 * @typedef CollisionObjectVector
 */
using CollisionObjectVector = std::vector<ObjectVector>;

#endif