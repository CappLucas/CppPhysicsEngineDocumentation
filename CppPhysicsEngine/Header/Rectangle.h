/**
 * File for class for rectangle specific methods and members.
 * 
 * @note If confused about certain data types, see Types.h
 * @see Types.h
 * 
 * @note most setters and getters are not fully documented as there are very self explanetory.
 * 
 * @file Rectangle.h
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once

#include "Types.h"

/**
 * Class that holds rectangle specific methods and members.
 * 
 * @class Rectangle
 */
class Rectangle{
public:
    /// @brief Overloaded constructor for 2 corner initializing.
    /// @param newPlane a variable of type Plane that represents the bottom left corner and the top right corner of the rectangle.
    Rectangle(Plane newPlane) : plane(newPlane){};
    
    /// @brief Overloaded constructor for bottom left corner and length and width value initializing. 
    /// @param newBottomLeftCorner a variable of type Cooridinate for the bottom left corner.
    /// @param length a variable of type float for length of rectangle.
    /// @param height a variable fo type float for height of rectangle.
    Rectangle(Cooridinate newBottomLeftCorner, float length, float height){
        plane.bottomLeft = newBottomLeftCorner;
        plane.topRight = {newBottomLeftCorner.x + length, newBottomLeftCorner.y + height};
    }

    //------------------------- getters ---------------------------
    Cooridinate getBottomLeftCorner(){return plane.bottomLeft;}
    Cooridinate getTopRightCorner(){return plane.topRight;}

    float getLeftX(){return plane.bottomLeft.x;}
    float getRightX(){return plane.topRight.x;}
    float getBottomY(){return plane.bottomLeft.y;}
    float getTopY(){return plane.topRight.y;}

    float getLength(){return plane.topRight.x - plane.bottomLeft.x;}
    float getHeight(){return plane.topRight.y - plane.bottomLeft.y;}

    float getXCenter(){return (plane.bottomLeft.x + plane.topRight.x)/2;}
    float getYCenter(){return (plane.bottomLeft.y + plane.topRight.y)/2;}

    Cooridinate getCenter(){return {getXCenter(),getYCenter()};}

    //------------------------- setters ----------------------------
    void setBottomLeft(Cooridinate newCorner){plane.bottomLeft = newCorner;}
    void setTopRight(Cooridinate newCorner){plane.topRight = newCorner;}

    void setLeftX(float leftX){if(leftX < getRightX()){plane.bottomLeft.x = leftX;}};
    void setRightX(float rightX){if(rightX > getLeftX()){plane.topRight.x = rightX;}};
    void setBottomY(float bottomY){if(bottomY < getTopY()){plane.bottomLeft.x = bottomY;}};
    void setTopY(float topY){if(topY > getBottomY()){plane.topRight.x = topY;}};
    
    //------------------------- methods ----------------------------
    /**
     * Moves the rectangles cooridinates to a cooridinate.
     * 
     * Moves the rectangle to an absolute location.
     * 
     * @param newPosition A cooridinate for the bottom left corner of the new position.
     */
    void moveTo(Cooridinate newPosition){
        //finds how much the rectangle has to move
        Cooridinate displacement = {newPosition.x - plane.bottomLeft.x,newPosition.y - plane.bottomLeft.y};

        plane.bottomLeft = newPosition;
        plane.topRight = {plane.topRight.x + displacement.x, plane.topRight.y + displacement.y};
    };
    /**
     * Moves the rectangle relative to current position.
     * 
     * Given a displacement, it will move rectangle.
     * 
     * @param displacement A variable of type Cooridinate to represent displacement.
     */
    void move(Cooridinate displacement){
        plane.bottomLeft.x += displacement.x;
        plane.topRight.x += displacement.x;
        plane.bottomLeft.y += displacement.y;
        plane.topRight.y += displacement.y;
    };
private:
    // holds the bottom left corner and the top right corner of the rectangle.
    // first cooridinate: ----bottom left corner----- other one: -------top right corner
    Plane plane;
};

#endif