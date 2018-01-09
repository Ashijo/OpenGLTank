/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Line.cpp
 * Author: ashijo
 * 
 * Created on January 7, 2018, 4:08 PM
 */

#include "Line.h"

Line::Line() {
}

Line::Line(const Line& orig) {
}

Line::~Line() {
}

Line::Line(Point a, Point b){

    this->a = a;
    this->b = b;

    
};

Point Line::getA(){
    return a;
}
Point Line::getB(){
    return b;
}
