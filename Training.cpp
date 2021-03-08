// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game4


#include "Training.h"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

Training :: Training(){
}



void Training :: runningTraining(int runningArray[], string n){
    //declare variables
    double secondsPerMile; 
    int runningOption = 0;
    int runningTime = 0;
    int r = runningArray[0];
    int c = runningArray[1];
    
    //calculate how long it takes the duck to run a mile
    if (r >= 0 && r <= 10)
        secondsPerMile = 30; 
    
    else if (r > 10 && r<= 20)
        secondsPerMile = 28;
    
    else if (r > 20 && r <= 30)
        secondsPerMile = 26;
        
    else if (r > 30 && r <= 40)
        secondsPerMile = 24;
    
    else if (r > 40 && r <= 50)
        secondsPerMile = 22;
    
    else if (r > 50 && r <= 60)
        secondsPerMile = 20;
        
    else if (r > 60 && r <= 70)
        secondsPerMile = 18;
        
    else if (r > 70 && r <= 80)
        secondsPerMile = 16;
        
    else if (r > 80 && r <= 90)
        secondsPerMile = 14;
        
    else
        secondsPerMile = 10;
        
    //welcome user to running training
    cout << "Welcome to Running Training!" << endl;
    sleep(2);
        
    //let the user know the running level, and how many seconds the it takes their duck to run a mile
    cout << n << " is currently a running level " << r << ", and can run a mile in " << secondsPerMile << " seconds!" << endl;
    sleep(4);
        
    
    //while loop 
    while (1)
    {   
        int r = runningArray[0];
        int c = runningArray[1];
        
        //calculate how long it takes the duck to run a mile
        if (r >= 0 && r <= 10)
            secondsPerMile = 30; 
    
        else if (r > 10 && r<= 20)
            secondsPerMile = 28;
    
        else if (r > 20 && r <= 30)
            secondsPerMile = 26;
        
        else if (r > 30 && r <= 40)
            secondsPerMile = 24;
    
        else if (r > 40 && r <= 50)
            secondsPerMile = 22;
    
        else if (r > 50 && r <= 60)
            secondsPerMile = 20;
        
        else if (r > 60 && r <= 70)
            secondsPerMile = 18;
        
        else if (r > 70 && r <= 80)
            secondsPerMile = 16;
        
        else if (r > 80 && r <= 90)
            secondsPerMile = 14;
        
        else
            secondsPerMile = 10;
        
        //tell user their running level and how long it takes them to run a mile
        cout << n << " has reached running level " << r << ", and can run a mile in " << secondsPerMile << " seconds!" << endl;
        sleep(4);
            
        //Display running training menu
        cout << "Choose your running training from the following options: " << endl;
        sleep(3);
        cout << "1. Run a half of mile" << endl;
        cout << "2. Run a mile" << endl;
        cout << "3. Run three miles" << endl;
        cout << "4. Go back to main menu" << endl;
        cin >> runningOption;
        
        //*******************************************************************************************************************************
        
        if (runningOption == 1){
            runningTime = secondsPerMile / 2;
        
            //for loop to simulate duck running
            for (int i = runningTime; i >= 0; i--){
                cout << "Running";
                sleep(1);
                
                for (int j = i; j > 0; j--)
                    cout << ".";
                
                cout << endl;
            }
        
            //get a random number to see how many coins the user got on the run   
            srand(time(0));
            int random = (rand() % 4) + 1; //random number between 1-5
        
            //user found 1 coin on run
            if (random == 1){
                cout << n << " found 1 coin on the run!" << endl;
                sleep(3);
            
                //add 1 to coins
                c++;
                runningArray[1] = c;
            }
        
            else{
                //print the number of coins the duck found to the user
                cout << n << " found " << random << " coins on the run!" << endl;
                sleep(3);
            
                //add the number of coins the duck found to the total number of coins
                c += random;
                runningArray[1] = c;
            }
        
            
            //increase running level
            r += 2;
            
            //check to see if user has reached max running level
            if (r >= 100){
                cout << "You have reached the MAX running level of 100!" << endl;
                sleep(3);
                runningArray[0] = 100;
            }
        
            
            else{
                runningArray[0] = r;
            }
                
            
        } 
        
        //*******************************************************************************************************************************
        
        //user choose to go on mile run
        else if (runningOption == 2){
            runningTime = secondsPerMile;
            
            
            //for loop to simulate duck running
            for (int i = runningTime; i >= 0; i--){
                cout << "Running";
                sleep(1);
                
                for (int j = i; j > 0; j--)
                    cout << ".";
                
                cout << endl;
            }
            
            
            //get a random number to see how many coins the user got on the run 
            srand(time(0));
            int random = (rand() % (10 - 6) + 6); //random number between 6-10
            
            //print the number of coins the duck found to the user
            cout << n << " found " << random << " coins on the run!" << endl;
            sleep(3);
            
            //add the number of coins the duck found to the total number of coins
            c += random;
            runningArray[1] = c;
            
            //add to running level 
            r += 5;
            
            //check to see if user has reached max running level
            if (r >= 100){
                cout << "You have reached the MAX running level of 100!" << endl;
                sleep(3);
                runningArray[0] = 100;
            }
        
            
            else{
                runningArray[0] = r;   
            }
                
            
            
        }
        
        //*****************************************************************************************************************************
        
        else if (runningOption == 3){
            runningTime = secondsPerMile * 3;
            
            
            //for loop to simulate duck running
            for (int i = runningTime; i >= 0; i--){
                cout << "Running";
                sleep(1);
                
                for (int j = i; j > 0; j--)
                    cout << ".";
                
                cout << endl;
            }
            
            
            //get a random number to see how many coins the user got on the run
            srand(time(0));
            int random = (rand() % (25 - 20) ) + 20 ; //random number between 20-25
            
            //print the number of coins the duck found to the user
            cout << n << " found " << random << " coins on the run!" << endl;
            sleep(3);
            
            //add the number of coins the duck found to the total number of coins
            c += random;
            runningArray[1] = c;
            
            
            //add the running level 
            r += 17;
            
            //check to see if user has reached max running level
            if (r >= 100){
                cout << "You have reached the MAX running level of 100!" << endl;
                sleep(3);
                runningArray[0] = 100;   
            }
                
        
            
            else{
                runningArray[0] = r;
            }
            
            
            
        }
        
        //if the user wants to go back to main menu
        else if (runningOption == 4){
            runningArray[0] = r;
            break;
        }
            
        //if the user enters a invalid option
        else{
            cout << "Invalid option! Please enter a number between 1-4." << endl;
            sleep(3);
            continue;
        }
        
    }
    
}
    
    
void Training :: swimmingTraining(int swimmingArray[], string n){
    //declare variables
    int lap = 0;
    int numberOfLaps = 0;
    int randomNumber = 0;
    int swimmingOption = 1;

    
    //welcome user to swimming training
    cout << "Welcome to Swimming Training!" << endl;
    sleep(2);
    
    cout << "In swimming training " << n << " will swim 50 meter laps. Every lap " << n << " swims will level up " << n;
    cout << "'s swimming level by 1." << endl;
    
    sleep(5);
    
    //while loop to keep letting user swim laps
    while (1){
        int s = swimmingArray[0];
        int c = swimmingArray[1];
        
        //calculate how long it takes the duck swim a lap
        if (s >= 0 && s <= 20)
            lap = 6; 
    
        else if (s > 20 && s<= 40)
            lap = 5;
    
        else if (s > 40 && s <= 60)
            lap = 4;
        
        else if (s > 60 && s <= 80)
            lap = 3;
    
        else
            lap = 2;
    
        //let the user know their current swimming level, and how long it takes to swim a lap
        cout << n << " is currently a swimming level " << s << ", and can swim a 50 meter lap in " << lap << " seconds!" << endl;
        sleep(5);
    
    
        //get user input for the amount of laps they want their duck to swim
        cout << "How many laps would you like " << n << " to swim: (enter 0 to return to menu)" << endl;
        cin >> numberOfLaps;
    
        //if the user chooses 0 laps send them back to menu
        if (numberOfLaps == 0){
            swimmingArray[0] = s;
            return;
        }
    
        //if the user chooses more than 100 laps send them back
        else if (numberOfLaps > 100){
            cout << "The max swimming level is 100!  Please make sure you choose a number between 1-100!" << endl;
            sleep(3);
            continue;
        }
    
        else{
        
            //for loop to swim laps
            for (int i = 1; i <= numberOfLaps; i++){
                cout << n << " is on lap: " << i << endl;
                sleep(lap);
            }
        
            cout << "Finished!" << endl;
            sleep(1);
        
        
            //calculate how many coins duck found
            srand(time(0));
            randomNumber = (rand() % numberOfLaps) + 1; //random number between 1, and the number of laps the duck swam
        
            //print the number of coins the duck found
            cout << n << " found " << randomNumber << " coins on the swim!" << endl;
            sleep(3);    
        
            //add the number of coins the duck found to coins
            c += randomNumber;
            swimmingArray[1] = c;
            
            s += numberOfLaps; 
        
            if (s >= 100){
                cout << "You have reached the MAX swimming level of 100!" << endl;
                swimmingArray[0] = 100;
                sleep(3);
            }
        
            else{
                cout << n << " has reached swimming level " << s << endl;
                swimmingArray[0] = s;
                sleep(3);
        }
    }

    }
    
}


void Training :: flyingTraining(int flyingArray[], string n){
    //declare variables
    int distance = 0;
    
    
    //welcome user to flying training
    cout << "Welcome to Flying Training!" << endl;
    
    sleep(2);
    
    //explain how flying training works
    cout << "Flying training works by increasing the distance your duck is able to fly." << endl;
    cout << "The more practice you duck gets, the further it will be able to fly, which will increase " << n << "'s flying level!" << endl;
    sleep(5);
    
    
    while (1){
        //declare variables
        int randomNum = 0;
        string train = " ";
        int f = flyingArray[0];
        int c = flyingArray[1];
        
        //calculate the distance the duck is able to fly
        if (f >= 0 && f <= 2)
            distance = 300;
            
        else
            distance = f * 100;
    
    
        //while loop to start or quit training 
        while (train != "s" && train != "S"){
            cout << "Enter s to start flying training, or enter q to exit flying training: " << endl;
            cin >> train;
         
            if (train == "q" || train == "Q"){
                flyingArray[0] = f;
                return;
                
            }
        }
        
        
        for (int i = 0; i <= distance; i += 100){
        
            if (i == distance - 100){
                cout << "Slowing down" << endl;
                sleep(1);
                cout << "Falling" << endl;
                sleep(1);
                cout << "Falling" << endl;
                sleep(1);
            }
        
        
            else if (i == distance){
                cout << n << " hit the ground at " << distance << " meters!" << endl;
                sleep(1);
            }
        
            else{
                cout << "Flying : " << i << " meters" << endl;
                sleep(1);
            }
        
        }
    
    
        //calculate the increase in the flying level, and the number of coins found
        if (f >= 0 && f <= 20){
            f += (distance / 100);
            srand(time(0));
            randomNum = (rand() % 4) + 1;
           
        }
    
        else if (f > 20 && f <= 40){
            f += (distance / 200); 
            srand(time(0));
            randomNum = (rand() % (10 - 5)) + 5;
        }
    
        else if (f > 40 && f <= 60){
            f += (distance / 300);
            srand(time(0));
            randomNum = (rand() % (15 - 10)) + 10;
        }
    
        else{
            f += (distance / 400);
            srand(time(0));
            randomNum = (rand() % (20 - 15)) + 15;
        }
        
        //print the number of coins the duck found
        cout << n << " found " << randomNum << " coins while flying!" << endl;
        sleep(3);
        
        //update the coins
        c += randomNum;
        flyingArray[1] = c;
        
        
        //check to see if plaer got maxed level
        if (f >= 100){
            cout << "You have reached the MAX flying level of 100!" << endl;
            sleep(3);
            flyingArray[0] = 100;
        }
        
        //
        else{
            cout << n << "'s flying level increased to " << f << "!" << endl;
            sleep(3);
            flyingArray[0] = f;
    }
}

}
    
    
    
    
    
    
    
    
    
