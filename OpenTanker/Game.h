/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: androidlinux
 *
 * Created on December 19, 2017, 10:49 AM
 */

#ifndef GAME_H
#define GAME_H


#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Constantes.h"
#include "Cube.h"
#include "Cone.h"
#include <math.h>

class Game {
public:
    void Init();
    void Start();
    void Free();
    
private:
    SDL_Window* win;
    SDL_GLContext ctx;
    bool isRunning;
    Cube* c = NULL;
    Cone* cone = NULL;
    
    double eyeX, eyeY, eyeZ, dirX, dirY, dirZ;
    int alphaDir = 0;
    
    void event();
    const Uint8* states;
    
    float toRad(int deg);
    double toDeg(float rad);

};

#endif /* GAME_H */

