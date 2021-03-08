// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game

#include <iostream>
#ifndef Training_H
#define Training_H
#include "Duck.h"
using namespace std;

class Training{
    public:
        Training();
        void runningTraining(int[], string); //training to increase running level
        void swimmingTraining(int[], string); // training to increase swimming level
        void flyingTraining(int[], string); //training to increase flying level
        
};

#endif