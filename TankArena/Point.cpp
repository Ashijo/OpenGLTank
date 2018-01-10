/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.cpp
 * Author: ashijo
 * 
 * Created on January 4, 2018, 9:31 AM
 */

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}


int Point::getX(){
    return x;
};
int Point::getY(){
    return y;
};
int Point::getZ(){
    return z;
};
    
void Point::getXY(int* x, int* y){
    *x = this->x;
    *y = this->y;
};

void Point::getXYZ(int* x, int* y, int* z){
    *x = this->x;
    *y = this->y;
    *z = this->z;
};

void Point::getXYZ(double* x, double* y, double* z){
    *x = this->x;
    *y = this->y;
    *z = this->z;
};


void Point::setX(int x){
    this->x = x;
};
void Point::setY(int y){
    this->y = y;
};
void Point::setZ(int z){
    this->z = z;
};
    
void Point::setXY(int x, int y){
    this->x = x;
    this->y = y;
};
void Point::setXYZ(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
};

void Point::setXYZ(Point point){
    setXYZ(point.x, point.y, point.z);
}