/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sphere.h
 * Author: ashijo
 *
 * Created on January 7, 2018, 5:10 PM
 */

#ifndef SPHERE_H
#define SPHERE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Point.h"


class Sphere {
public:
    Sphere();
    Sphere(const Sphere& orig);
    virtual ~Sphere();
    Sphere(GLuint idTexture, Point center, int r);

    void render();
private:
    Point center;
    int r;
    GLuint idList;
    GLuint idTexture;
    GLUquadric* quadric;
    
    
};

#endif /* SPHERE_H */

