/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cube.h
 * Author: androidlinux
 *
 * Created on December 19, 2017, 10:27 AM
 */

#ifndef CUBE_H
#define CUBE_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Rendable.h"

class Rendable;
class Cube : public Rendable {
public:    
    Cube();
    virtual ~Cube();
    void render();
    Cube(GLubyte r,GLubyte g,GLubyte b, Point pos, Point size);
    Cube(GLuint idTexture, Point pos, Point size);
    Cube(GLuint idTexture[],int nbText ,Point pos, Point size);
    
private:
    GLuint idGPU;

};

#endif /* CUBE_H */