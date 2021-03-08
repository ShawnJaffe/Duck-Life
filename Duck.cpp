// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game
#include "Duck.h"
#include <unistd.h>

Duck :: Duck(){
    name = "";
    running = 0;
    swimming = 0;
    flying = 0;
    energy = 0;
    coins = 0;
   
    
}

int Duck :: getRunning(){
    return running;
}

int Duck :: getSwimming(){
    return swimming;
}

int Duck :: getFlying(){
    return flying;
}

int Duck :: getEnergy(){
    return energy;
}

int Duck :: getCoins(){
    return coins;
}

string Duck :: getName(){
    return name;
}

void Duck :: setRunning(int r){
    running = r;
}

void Duck :: setSwimming(int s){
    swimming = s;
}

void Duck :: setFlying(int f){
    flying = f;
}


void Duck :: setEnergy(int e){
    energy = e;
}

void Duck :: setCoins(int co){
    coins = co;
}

void Duck :: setName(string n){
    name = n;
}


void Duck :: showStats(){
    cout << "Here are " << getName() << "'s stats:" << endl;
    sleep(2);
    cout << "Running: " << getRunning() << endl;
    sleep(1);
    cout << "Swimming: " << getSwimming() << endl;
    sleep(1);
    cout << "Flying: " << getFlying() << endl;
    sleep(1);
    cout << "Energy: " << getEnergy() << endl;
    sleep(1);
    cout << "Coins: " << getCoins() << endl;
    sleep(1);
}

string Duck :: chooseColor(){
    
    //declare variables
    int choice;
    Duck temp;
    
    
    
    //display menu
    sleep(1);
    cout << "1. Red (increases starting running level)" << endl;
    sleep(1);
    cout << "2. Blue (increases starting swimming level) " << endl;
    sleep(1);
    cout << "3. Yellow (increases starting flying level) " << endl;
    
    //store users choice
    cin >> choice;
    
    //if the user chose the red duck, increase running to level 3
    if (choice == 1){
        setRunning(3);
        return "red";
    }
    
    //if the user chose the blue duck, increase swimming to level 3
    else if (choice == 2){
        setSwimming(3);
        return "blue";
    }
    
    //if the user chose the yellow duck, increase flying to level 3
    else if (choice == 3){
        setFlying(3);
        return "yellow";
    }
    
    
    //user didn't choose a number between 1-3
    else{
        cout << "Invalid option." << endl;
        chooseColor();
    }
}


int Duck :: shop(int coins)
{
    //declare variables
    int option = 0;
    int quantity = 0;
    int money = 0;
    int cost = 0;
    int eLevel = 0;
   
    
    //welcomes user to the shop 
    cout << "Welcome to the shop!" << endl;
    
    sleep(2);
    
    cout << "You have a total of: " << coins << " coins!" << endl;
    
    
    //while loop until user wants to exit the store
    while (option != 3)
    {
        //display store menu and store option
        cout << "Product:" << "                                                 " << "   Coins:" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        
        sleep(1);
        
        cout << "1. Seed (increases energy level)" << "                                  " << "1" << endl;
        
        sleep(1);
        
        cout << "2. Super seed (increases energy level and trains all skills)" << "      " << "10" << endl;
        
        sleep(1);
    
        cout << "3. Quit" << "                                                           " << "0" << endl;
        
        sleep(1);
        
        cout << "What would you like to buy (enter a number 1-2, enter 3 to quit): ";
        cin >> option;
        
        //***********************************************************************************************************************
        
        //if user chose to buy seeds
        if (option == 1){
            
            //get the amount of coins the user has
            money = getCoins();
            
            //ask the user how many seeds they want
            cout << "How many seeds do you want to buy (enter 0 to go back to shop): ";
            cin >> quantity;
            
            //calculate the cost 
            cost = 1 * quantity;
            
            //checks if the user inputted 0 for quantity, and if so takes user back to menu
            if (quantity == 0)
                continue;
            
            //checks if the user doesn't have enough money for items
            else if (cost > money){
                cout << "You have insufficent funds!" << endl;
                cout << quantity << " seed(s) costs " << cost << " coin(s)!" << endl;
                cout << "You have " << money << " coin(s)!" << endl;
        }
            
            else{
                //declare variables
                string feed;
                
                
                //get the energy level
                eLevel = getEnergy();
                
                //subtract the cost from the money
                money -= cost;
                
                //while loop to force user to feed duck
                while (feed != "f" && feed != "F"
                
                )
                {
                    cout << "Enter f to feed your duck: " << endl;
                    cin >> feed;
                }
                
                //for loop to eat seeds 
                for (int i = quantity; i >= 0; i--){
                    cout << "( o)> ";
                    sleep(1);
                    
                    for(int j = i; j > 0; j--){
                        cout << ".";
                    }
                    
                    cout << endl;
                }
                
                sleep (1);
                
                
                //check to make sure user hasn't reached max energy level
                if (eLevel + quantity >= 100){
                    setEnergy(100);
                    
                    cout << getName() << " has reached the MAX energy level of 100!" << endl;
                    
                    sleep(3);
                }
                
                
                
                else{
                    //display energy level to user
                    cout << getName() << "'s energy level increased from level " << eLevel; 
                
                    //update the energy level 
                    eLevel += quantity;
                
                    cout << " to level " << eLevel << endl;
                
                    //update energy
                    setEnergy(eLevel);
                
                    sleep(3);
                }
                
                //display the remaining funds
                cout << "You spent " << cost << " coins on " << quantity << " seeds." << endl;
                
                sleep(3);
                
                cout << "Your remaining balance is: " << money << " coins" << endl;
                
                sleep(3);
                
                //update set coins
                setCoins(money);
            }
        
        
    }
    
    //********************************************************************************************************************************
    
        //if the user chose to purchase super seeds
        else if (option == 2)
    {
            //get the amount of coins the user has
            money = getCoins();
        
            //ask the user how many seeds they want
            cout << "How many super seeds do you want to buy (enter 0 to go back to shop): ";
            cin >> quantity;
        
            //calculate the cost 
            cost = 10 * quantity;
        
            //checks if the user inputted 0 for quantity, and if so takes user back to menu
            if (quantity == 0)
                continue;
                
            //checks if the user doesn't have enough money for items
            else if (cost > money){
                cout << "You have insufficent funds!" << endl;
                cout << quantity << " super seed(s) costs " << cost << " coins!" << endl;
                cout << "You have " << money << " coins!" << endl;
        
            }
            
            else{
                string feedDuck;
                
                //get the energy level
                eLevel = getEnergy();
                
                //subtract the cost from the money
                money -= cost;
                
                //while loop to force user to feed duck
                while (feedDuck != "f" && feedDuck != "F")
                {
                    cout << "Enter f to feed your duck: " << endl;
                    cin >> feedDuck;
                }
                
                //for loop to eat seeds 
                for (int i = quantity; i >= 0; i--){
                    cout << "( o)> ";
                    sleep(1);
                    
                    for(int j = i; j > 0; j--){
                        cout << ".";
                    }
                    
                    cout << endl;
                }
                
                //check to make sure user hasn't reached max energy level
                if (eLevel + quantity >= 100){
                    setEnergy(100);
                    
                    cout << getName() << " has reached the MAX energy level of 100!" << endl;
                    
                    sleep(3);
                }
                
                else{
                    cout << getName() << "'s energy level increased from level " << getEnergy();
                    setEnergy(eLevel + quantity);
                    cout << " to level " << getEnergy() << endl;
                    sleep(3);
                }
                
                //check to make sure user hasn't reached max running level
                if (getRunning() + quantity >= 100){
                    setRunning(100);
                    
                    cout << getName() << " has reached MAX running level of 100!" << endl;
                    sleep(1);
                }
                
                else{
                    cout << getName() << "'s running level increased from level " << getRunning();
                    setRunning(getRunning() + quantity);
                    cout << " to level " << getRunning() << endl;
                    sleep(3);
                }
                
                //check to make sure user hasn't reached max swimming level
                if (getSwimming() + quantity >= 100){
                    setSwimming(100);
                    
                    cout << getName() << " has reached MAX swimming level of 100!" << endl;
                    sleep(1);
                }
                
                else{
                    cout << getName() << "'s swimming level increased from level " << getSwimming();
                    setSwimming(getSwimming() + quantity);
                    cout << " to level " << getSwimming() << endl;
                    sleep(3);
                }
                
                //check to make sure user hasn't reached flying energy level
                if (getFlying() + quantity >= 100){
                    setFlying(100);
                    
                    cout << getName() << " has reached MAX flying level of 100!" << endl;
                    sleep(1);
                }
                
                else{
                    cout << getName() << "'s flying level increased from level " << getFlying();
                    setFlying(getFlying() + quantity);
                    cout << " to level " << getFlying() << endl;
                    sleep(3);
                }
                
                
                //display the remaining funds
                cout << "You spent " << cost << " coins on " << quantity << " super seed(s)." << endl;
                cout << "Your remaining balance is: " << money << " coins" << endl;
                
                //update set coins
                setCoins(money);
            }
  
    }
    
    //**************************************************************************************************************************
        //if user chooses to quit
        else if (option == 3)
            break;
    
    //***************************************************************************************************************************
        else{
            cout << "Invalid option! Please enter a number between 1-3!" << endl;
            sleep(3);
        }
    
    
    }
    

}