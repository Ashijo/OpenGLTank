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

    c = new Cube(5,5,5);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) WIN_WIDTH / WIN_HEIGHT, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 1);

    isRunning = true;


}

void Game::Start() {
    const Uint8* states;
    SDL_Event event;
    int start, end;

    while (isRunning) {
        start = SDL_GetTicks();

        SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        if (event.type == SDL_QUIT)
            isRunning = false;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(10, 10, 25, 0, 0, 0, 0, 0, 1);



        c->render();


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
