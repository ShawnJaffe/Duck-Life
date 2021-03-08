// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <fstream>
#include "Duck.h"
#include "Training.h"
#include "Race.h"
using namespace std;

int main()
{
    //declare variables
    string duckName;
    Duck player;
    Training train;
    Race r1;
    int coins = 0;
    int choice = 0;
    int rl = 0;
    int sl = 0;
    int fl = 0;
    int en = 0;
    int raceOption = 0;
    bool beginnerRace = 0;
    bool amateurRace = 0;
    bool expertRace = 0;
    bool worldChampionship = 0;
    ofstream outFile;
    
    //open file
    outFile.open("opponent.txt");
    
    //write to file
    outFile << "Lightning, 95, 93, 97" << endl;
    outFile << "Bullet, 97, 98, 90" << endl; 
    outFile << "Dash, 100, 93, 92" << endl;
    outFile << "Flash, 100, 100, 100" << endl;
    outFile << "Fireball, 90, 90, 90" << endl;
    outFile << "Speedo, 95, 95, 100" << endl;
    outFile << "Arrow, 94, 91, 96" << endl;
    outFile << "Thunder, 97, 98, 99" << endl;
    outFile << "Tornado, 99, 98, 91" << endl;
    outFile << "Rocket, 100, 92, 100" << endl;
    
    //close file
    outFile.close();
    
    
    //welcome user to the game
    cout << "Welcome to Duck Life!" << endl;
    
    sleep(2);
    
    //ask user for name
    cout << "Please enter a name for your duck: " << endl;
    cin >> duckName;
    
    //set the ducks name
    player.setName(duckName);
    
    //set the name to variable n
    string n = player.getName();
    
    //explain how the game works
    cout << "The goal of the game is to train " << n << " to be the Champion Racer!" << endl;
    sleep(5);
    cout << "You do this by leveling up " << n << "'s running, swimming, and flying levels (max levels are 100!)" << endl;
    sleep(5);
    cout << "Make sure to also visit the shop to level up energy (max level also 100!), as well as your skills!" << endl;
    sleep(5);
    cout << "Once you level up your skills and energy enough, enter races to ultimately unlock the World Championship!" << endl;
    sleep(5);
    cout << "Now you know what to do to make " << n << " a Champion Racer!" << endl;
    sleep(5);
    
    
    //ask user what duck color they want
    cout << "Please select what color you want " << n << " to be from the following options:" << endl;
    
    sleep(3);
    
    //get user input for the color of the duck
    string color = player.chooseColor();
    
    //display the name and color the user chose for their duck
    cout << "Awesome! " << n << " is a " << color << " duck." << endl;
    
    sleep(3);
    
    //show player stats
    player.showStats();
    
    
    //while loop for menu options
    while (choice != 7)
    {
        sleep(1);
        cout << "=== Please select from the following options! ===" << endl;
        sleep(3);
        cout << "1. Enter Race" << endl;
        cout << "2. Go to shop" << endl;
        cout << "3. Train Running" << endl;
        cout << "4. Train Swimming" << endl;
        cout << "5. Train Flying" << endl;
        cout << "6. View Stats" << endl;
        cout << "7. Quit" << endl;
        
        cin >> choice;
        
        //race option
        if (choice == 1){
            //declare variables
            rl = player.getRunning();
            sl = player.getSwimming();
            fl = player.getFlying();
            en = player.getEnergy();
           
            
            //while loop to show racing menu
            while (1){
                
                //check if user completed worldChampionship
                if (worldChampionship == 1){
                    cout << "Congrats! You have completed the game! " << n << " is the World Champion racer!" << endl;
                    sleep(3);
                    cout << "Thanks for playing Duck Life! " <<  endl;
                    return 0;
                }
                
                //display racing menu
                cout << "Welcome to Racing! You can only win each race once. Please select from the following options:" << endl;
                cout << "1. Enter the Beginner Race (recommended levels over 10)" << endl;
                cout << "2. Enter the Amateur Race (recommeded levels over 40)" << endl;
                cout << "3. Enter the Expert Race (recommended levels over 80)" << endl;
                cout << "4. Enter the World Champion (recommended levels over 90, must win every other race to unlock this race)" << endl; 
                cout << "5. Go back to main menu" << endl;
                
                cin >> raceOption;
                
                //beginner race
                if (raceOption == 1)
                    //checks to see if user already completed race
                    if (beginnerRace == 1)
                        cout << "You already won this race please choose a different option!" << endl;
                    
                    else
                        beginnerRace = r1.beginnerRace(rl, sl, fl, en, n);
                
                //amateur race 
                else if (raceOption == 2)
                    //check to see if user already completed race
                    if (amateurRace == 1)
                        cout << "You already won this race please choose a different option!" << endl;
                    else
                        amateurRace = r1.amateurRace(rl, sl, fl, en, n);
                    
                //expert race
                else if (raceOption == 3){
                    //check to see if user already completed race
                    if (expertRace == 1)
                        cout << "You already won this race please choose a different option!" << endl;
                    else
                        expertRace = r1.expertRace(rl, sl, fl, en, n);
                }
                //world championship race
                else if (raceOption == 4){
                    //check to see if user already completed the world championship
                    if (worldChampionship == 1)
                        cout << "You already won the World Chamionship, you have completed the game!" << endl;
                    
                    //make sure user has won all races before entering the world championship
                    else if (beginnerRace == 1 && amateurRace == 1 && expertRace == 1)
                        worldChampionship = r1.worldChampionship(rl, sl, fl, en, n);
                        
                    else
                        cout << "You must win all races before entering the World Championship!" << endl;
                    
                    
                }
            
                else if (raceOption == 5)
                    break;
                
                //invalid option
                else
                    cout << "Invalid option. Please enter a number between 1-5." << endl;
                
            }
        }
         
        //shop   
        else if (choice == 2){
            coins = player.getCoins();
            coins = player.shop(coins);
        }
        
        //running training
        else if (choice == 3){
            //declare array
            int runningArr[2];
            
            //set elements in array
            runningArr[0] = player.getRunning();
            runningArr[1] = player.getCoins();
            
            //go to running training 
            train.runningTraining(runningArr, n);
            
            //update running and coins
            player.setRunning(runningArr[0]);
            player.setCoins(runningArr[1]);
        }
        
        //swimming training
        else if (choice == 4){
            //declare array
            int swimmingArr[2];
            
            //set elements in array
            swimmingArr[0] = player.getSwimming();
            swimmingArr[1] = player.getCoins();
            
            //go to swimming training
            train.swimmingTraining(swimmingArr, n);
            
            //update swimming and coins
            player.setSwimming(swimmingArr[0]);
            player.setCoins(swimmingArr[1]);
        }
        
        //flying training    
        else if (choice == 5){
            //declare array
            int flyingArr[2];
            
            //set elements in array
            flyingArr[0] = player.getFlying();
            flyingArr[1] = player.getCoins();
            
            //go to flying training
            train.flyingTraining(flyingArr, n);
            
            //update flying and coins
            player.setFlying(flyingArr[0]);
            player.setCoins(flyingArr[1]);
        }
        
        //show stats    
        else if (choice == 6)
            player.showStats();
        
        //quit    
        else if (choice == 7)
            cout << "Good Bye!" << endl;
         
        //invalid option    
        else{
            cout << "Invalid option." << endl;
            sleep(2);
        }
    }
    
    
    return 0;
}