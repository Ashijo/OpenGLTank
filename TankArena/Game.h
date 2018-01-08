/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: ashijo
 *
 * Created on January 4, 2018, 9:28 AM
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
#include <math.h>
#include "sdlglutils.h"
#include "Cylinder.h"
#include "Tank.h"
#include "Sphere.h" 


class Tank;
class Cube;
class Game {
public:
    Game();
    ~Game();
    
    void init();
    void start();
    void free();
    
    
private:
    
    // contextes
    SDL_Window* win = NULL;
    SDL_GLContext ctx;
    
    //attributs
    bool isRunning  = true;
    Cube* skybox    = NULL;
    Cube* arene     = NULL;
    Tank* test      = NULL;
    //Sphere* sphere  = NULL;
    
    
    double eyeX, eyeY, eyeZ, dirX, dirY, dirZ;
    int alphaDir = 0;
    
    const Uint8* states;
    GLuint imgSkybox[6];
    GLuint imgArn[2];
    GLuint imgTnk[3];
    
    
    //methodes de rangement 
        //initialisation
    void initSDL();
    void initTextures();
    void initModels();
    void initMatrix();
        //en jeu
    void cleaner();
    void event();
    void drawModels();
    
    
    //methodes utils
    float toRad(int deg);
    double toDeg(float rad);

};

#endif /* GAME_H */

