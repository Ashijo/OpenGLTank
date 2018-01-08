/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cylinder.h
 * Author: ashijo
 *
 * Created on January 6, 2018, 3:13 PM
 */

#ifndef CYLINDER_H
#define CYLINDER_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Rendable.h"
#include <iostream>

class Cylinder : public Rendable {
public:
    Cylinder();
    Cylinder(GLuint idTexture,Point pos, Point size);
    Cylinder(const Cylinder& orig);
    virtual ~Cylinder();
    
    void render(double anglX,double anglY,double anglZ);
private:
    GLUquadric* params;
    GLuint idGPU;
};

#endif /* CYLINDER_H */

