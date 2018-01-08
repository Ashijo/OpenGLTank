/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ashijo
 *
 * Created on January 4, 2018, 9:27 AM
 */

#include "Game.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Game* game = new Game();
    
    game->init();
    game->start();
    game->free();
    
    

    
    return 0;
}

