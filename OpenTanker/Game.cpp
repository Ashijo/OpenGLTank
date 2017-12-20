/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: androidlinux
 * 
 * Created on December 19, 2017, 10:49 AM
 */

#include "Game.h"

void Game::Init() {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    IMG_Init(IMG_INIT_JPG);


    win = SDL_CreateWindow("Christmass", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    ctx = SDL_GL_CreateContext(win);

    dirX = 10;
    dirY = 10;
    dirZ = 25;
    
    eyeX = 40;
    eyeY = 40;
    eyeZ = 10;
    
    
    c = new Cube(60,55,255);
    cone = new Cone();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) WIN_WIDTH / WIN_HEIGHT, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 1);

    isRunning = true;


}

void Game::Start() {
    int start, end;

    while (isRunning) {
        start = SDL_GetTicks();

        event();
                
                
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        
        
        gluLookAt(eyeX, eyeY, eyeZ, dirX, dirY, dirZ, 0, 0, 1);
        //gluLookAt(10, 10, 25, x, y, 0, 0, 0, 1);

        glScaled(100,100,1);
        c->render();
        
        glLoadIdentity();
        glColor3ub(255,0,255);
        cone->render();

        //mettre a jour l ecran
        SDL_GL_SwapWindow(win);
                
                end = SDL_GetTicks();
                
                if (end-start < 1000/FPS){
                    SDL_Delay((1000/FPS)-(end-start));
                }

    }



}

void Game::Free() {

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    IMG_Quit();

    SDL_Quit();

}


void Game::event(){
    
    SDL_Event event;
    SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT || states[SDL_SCANCODE_ESCAPE])
            isRunning = false;
        if(states[SDL_SCANCODE_W])
            eyeX--;
        if(states[SDL_SCANCODE_S])
            eyeX++;
        if(states[SDL_SCANCODE_A])
            eyeY--;
        if(states[SDL_SCANCODE_D])
            eyeY++;
        
        
    int x = 0;
    int y = 0;
    Uint32 result;
    
    result = SDL_GetMouseState(&x,&y);
    
    x -= WIN_WIDTH/2;
    y -= WIN_HEIGHT/2;
    
    if (y < -3){
        dirZ++;
    }
    if (y > 3){
        dirZ--;
    }
    
    if (x < -3){
        alphaDir++;
    }
    if (x > 3){
        alphaDir--;
    }
    
    dirX = toDeg(sin(toRad(alphaDir))) * 30;
    dirY = toDeg(cos(toRad(alphaDir))) * 30;
            
//    if (toDeg(sin(toRad(alphaDir))) > 0){
//        dirX ++;
//    }
//    if (toDeg(sin(toRad(alphaDir))) < 0){
//        dirX --;
//    }
//    if (toDeg(cos(toRad(x)))>0){
//        dirY ++;
//    }
//    if (toDeg(cos(toRad(x)))<0){
//        dirY --;
//    }
    
    //dirX = toDeg(cos(toRad(alphaDir)))*30;
    //dirY = toDeg(sin(toRad(alphaDir)))*30;
    
    SDL_WarpMouseInWindow(win, WIN_WIDTH/2 , WIN_HEIGHT/2);
    
    std::cout << "alpha dir : " << alphaDir << std::endl;
    std::cout << "toRad(alphaDir) : " << toRad(alphaDir) << std::endl;
    std::cout << "cos(toRad(alphaDir)) : " << cos(toRad(alphaDir)) << std::endl;
    std::cout << "dirX : " << dirX << ".  dirY :" << dirY << std::endl;
    //std::cout << "  Result : " << result << "     " << std::endl;


}




float Game::toRad(int deg){
    
    float r = (float)deg/180/3.14159265358979323846;
    return  r;
}

 double Game::toDeg(float rad){
 
    return rad*180/3.14159265358979323846;
 };
