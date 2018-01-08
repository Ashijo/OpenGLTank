/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rendable.h
 * Author: ashijo
 *
 * Created on January 4, 2018, 9:50 AM
 */

#ifndef RENDABLE_H
#define RENDABLE_H

#include "Point.h"

class Rendable {
public:
    Rendable();
    Rendable(Point position);
    Rendable(Point position, int sizeX, int sizeY, int sizeZ);
    Rendable(Point position, Point size);
    
    Point getPos();
    void getPos(Point* pos);
    void getPos(Point* pos, int* sizeX, int* sizeY, int* sizeZ);
    void getPos(Point* pos, Point* size);
    
    void setPos(Point newPos);
    void setPos(int x, int y);
    void setPos(int x, int y, int z);
   
    virtual void render();
    
protected:
    Point position, size;
    
};

#endif /* RENDABLE_H */

