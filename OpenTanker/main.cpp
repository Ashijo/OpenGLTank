/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: androidlinux
 *
 * Created on December 19, 2017, 10:25 AM
 */

#include <cstdlib>
#include "Game.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Game game = Game();
    
    game.Init();
    game.Start();
    game.Free();
    
    
    return 0;
}

