// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game

#include <iostream>
#ifndef Duck_H
#define Duck_H
using namespace std;



class Duck{
    private:
        string name;
        int running;
        int swimming;
        int flying;
        int energy;
        int coins;

    
    
    public:
        Duck(); //constructor
        Duck(string, int, int, int, int, int); //constructor
        int getRunning(); //getter
        int getSwimming(); //getter
        int getFlying(); //getter
        int getEnergy(); //getter
        int getCoins(); //getter
        string getName(); //getter
        void setRunning(int); //setter
        void setSwimming(int); //setter
        void setFlying(int); //setter
        void setEnergy(int); //setter
        void setCoins(int); //setter
        void setName(string); //setter
        void showStats();
        string chooseColor();
        int shop(int);  
      
};

#endif