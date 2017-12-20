/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cone.h
 * Author: androidlinux
 *
 * Created on December 20, 2017, 11:41 AM
 */

#ifndef CONE_H
#define CONE_H
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Cone {
public:
    Cone();
    Cone(const Cone& orig);
    virtual ~Cone();
    void render();
private:
    GLUquadric* params;

};

#endif /* CONE_H */

