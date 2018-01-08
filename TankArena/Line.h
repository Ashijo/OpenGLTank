/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Line.h
 * Author: ashijo
 *
 * Created on January 7, 2018, 4:08 PM
 */

#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line {
public:
    Line();
    Line(const Line& orig);
    Line(Point a, Point b);
    virtual ~Line();
    
    Point getA();
    Point getB();
    
    void getAB(Point* a, Point* b);
    
    void getA(int* x, int* y, int* z);
    void getB(int* x, int* y, int* z);
    
    void getAB(int* x1, int* y1, int* z1, int* x2, int* y2, int* z2);
    
    
    
private:
    Point a;
    Point b;
    
};

#endif /* LINE_H */

