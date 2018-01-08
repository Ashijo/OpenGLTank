/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: ashijo
 *
 * Created on January 4, 2018, 9:31 AM
 */

#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point();
    Point(int x, int y, int z);
    
    //getters
    int getX();
    int getY();
    int getZ();
    
    void getXY(int* x, int* y);
    void getXYZ(int* x, int* y, int* z);
    
    
    //setter
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    
    void setXY(int x, int y);
    void setXYZ(int x, int y, int z);
    void setXYZ(Point point);
    
private:
    int x,y,z;
    
};

#endif /* POINT_H */

