// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game

#include <iostream>
using namespace std;
#ifndef Race_H
#define Race_H

class Race{
    private:
        double runningProbability;
        double swimmingProbability;
        double flyingProbability;
        double probability;
        
    
    public:
        Race();
        bool beginnerRace(int, int, int, int, string); //Beginner race
        bool amateurRace(int, int, int, int, string); //amateur race
        bool expertRace(int, int, int, int,  string); //expert race
        bool worldChampionship(int, int, int, int, string); //world championship
    
    
};

#endif