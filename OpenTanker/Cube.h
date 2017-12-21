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


class Cube {
public:    
    Cube();
    virtual ~Cube();
    void render();
    Cube(GLubyte r,GLubyte g,GLubyte b);
    Cube(GLuint idTexture);
    Cube(GLuint idTexture[6]);
    
private:
    GLuint idGPU;

};

#endif /* CUBE_H */

