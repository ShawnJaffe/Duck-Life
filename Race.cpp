// CS1300 Spring 2020
// Author: Shawn Jaffe
// Recitation: 104 - Dhanendra Soni
// Project3 : Duck Life Game

#include "Race.h"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Duck.h"

int split(string stringToSplit, char seperator, string arr[], int size)
{
    //declare variables
    int count = 0;
    int slot = 0;
    string s;
    
    //check to see if the string is empty and if so return 0
    if (stringToSplit.size() == 0)
        return 0;
    
    //for loop to go through every character in the string
    for (int i = 0; i < stringToSplit.size(); i++){
        //if statement to check if the character in the string is the seperator character
        if (stringToSplit[i] == seperator){
            //check to see if the seperator is the last character and if so don't include it
            if (i + 1 == stringToSplit.size())
                continue;
            //check to make sure the size is greater than 0 and if so add it to the string   
            else if (s.size() > 0)
                arr[slot++] = s;
            //empty the string for the next string
            s = "";
        }
        
        //if the character isn't the seperator character, add it to the string
        else
            s += stringToSplit[i]; 

        }
        
        //put the last word in the array
        arr[slot++] = s;
    
    //check if theres more words in the array, then the size of the array and if so return -1
    if (slot > size)
        return -1;
        
    //return the number of words or slots back to main
    else
        return slot;
   
}



Race :: Race(){
    probability = 0;
    runningProbability = 0;
    swimmingProbability = 0;
    flyingProbability = 0;
}

bool Race :: beginnerRace(int r, int s, int f, int e, string n){
    //declare variables
    string start;
    
    cout << "Welcome to the beginner race!" << endl;
    sleep(2);
    
    //calculate running probability
    if (r <= 5)
        runningProbability = 0;
        
    else if (r > 5 && r <= 10)
        runningProbability = 0.2;
        
    else if (r > 10 && r <= 15)
        runningProbability = 0.5;
        
    else if (r > 15 && r <= 20)
        runningProbability = 0.8;
        
    else
        runningProbability = 1;
        
    //calculate swimming probability
    if (s <= 5)
        swimmingProbability = 0;
        
    else if (s > 5 && s <= 10)
        swimmingProbability = 0.2;
        
    else if (s > 10 && s <= 15)
        swimmingProbability = 0.5;
        
    else if (s > 15 && s <= 20)
        swimmingProbability = 0.8;
        
    else
        swimmingProbability = 1;
        
    //calculate flying probability
    if (f <= 5)
        flyingProbability = 0;
        
    else if (f > 5 && f <= 10)
        flyingProbability = 0.2;
        
    else if (f > 10 && f <= 15)
        flyingProbability = 0.5;
        
    else if (f > 15 && f <= 20)
        flyingProbability = 0.8;
        
    else
        flyingProbability = 1;
    
    //calculate the probability
    probability = (runningProbability + swimmingProbability + flyingProbability) / (3 * 1.0) * 100;
    
    //Display users probability to win the race
    cout << "The probability for you to win given "<< n << "'s currents stats is " << probability << "%"<< endl;
    sleep(3);
    
    //randomize if the user won the race, based on probabilty 
    srand(time(0));
    bool TrueFalse = (rand() % 100) < probability;
    
    //while loop to start or quit the race
    while (start != "s" && start != "S"){
        cout << "Enter s to start the race, or enter q to exit the race and return to main menu " << endl;
        cin >> start;
         
            if (start == "q" || start == "Q")
                return 0;
            }
    
    //start race
    cout << "Lane 1: " << n << endl;
    sleep(1);
    cout << "Lane 2: Ducky" << endl;
    sleep(1);
    cout << "Lane 3: Snowball" << endl;
    sleep(1);
    cout << "Lane 4: Quackers" << endl;
    sleep(1);
    
    cout << "Ready Racers!" << endl;
    sleep(2);
    cout << "On your mark" << endl;
    sleep(1);
    cout << "Get set" << endl;
    sleep(1);
    cout << "GOOO!!!" << endl;
    sleep(1);
    
    
    
    //if the probability is 70 or above
    if (probability >= 70){
        sleep (1);
        cout << n << " is off to a great start!" << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //update the player in race
        cout << n << " is currently ahead, followed by Quackers!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is leaving the other racers in the dust!" << endl;
        sleep(2);
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 2; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 20){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Quackers in 2nd, Snowball in 3rd, and Ducky in 4th" << endl; 
                sleep(3);
        
                cout << "Congrats! " << n << " has completed the beginner race!" << endl;
                sleep(2);
        
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Oh no! " << n << " tripped, and lost the race!" << endl;
            sleep(3);
            cout << "Quackers came in 1st, followed by Snowball in 2nd, Ducky in 3rd, and " << n << " in 4th!" << endl;
            sleep(4);
            
            //return false because duck lost race
            return 0;
        }
        
    }
        
    //***********************************************************************************************************************************  
    
    //if the probability is between 69 and 50
    else if (probability < 70 && probability >= 50){
        sleep (1);
        cout << n << " is off to good start!" << endl;
    
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //update the player in race
        cout << n << " is currently ahead, followed by Snowball!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is still in 1st" << endl;
        sleep(2);
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 2; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //checks if the duck won the race based on the probability
        if (TrueFalse == 1){
        
            //checks if duck had enough energy to finish race
            if (e >= 20){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(3);
                cout << "Followed by Snowball in 2nd, Quackers in 3rd, and Snowball in 4th" << endl; 
                sleep(4);
        
                cout << "Congrats! " << n << " has completed the beginner race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
            }
        
            else{
                cout << n << " fell asleep, and wasn't able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                //returns false because duck fell asleep and lost the race 
                return 0;
            }
        }
        
        //if user lost race
        else {
            //display results 
            cout << "Snowball passed " << n << " last second and won the race!" << endl;
            sleep(3);
            cout << n << " came in 2nd, followed by Snowball in 3rd, and Ducky in 4th!" << endl;
            sleep(3);
            cout << "Try again next time!" << endl;
            sleep(2);
            //return false because duck lost race
            return 0;
        
        }
    }
    
    //if the probability is between 49 and 30
    else if (probability < 50 && probability >= 30){
        sleep (1);
        cout << "The ducks are off!" << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //update the player in race
        cout << n << " is currently ahead by a hair, followed by Duckie!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << "Duckie is currently in the lead closely followed by " << n << endl;
        sleep(2);
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << "and Duckie are neck and neck!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 2; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        if (TrueFalse == 1){
        
            //checks to make sure duck had enough energy
            if (e >= 20){
        
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Duckie in 2nd, Quackers in 3rd, and Snowball in 4th" << endl; 
                sleep(4);
        
                cout << "Congrats! " << n << " has completed the beginner race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
            }
        
             else{
                cout << n << " fell asleep, and wasn't able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                //return false because duck fell asleep and last waste
                return 0;
        }
    }
    
        //if user lost race
        else {
            //display results 
            cout << "Duckie won the race!" << endl;
            sleep(2);
            cout << n << " came in 2nd, followed by Snowball in 3rd, and Quackers in 4th!" << endl;
            sleep(4);
            cout << "Try again next time!" << endl;
            sleep(2);
            //return false because duck lost race
            return 0;
        }
}

    else{
        sleep (1);
        cout << n << " is off to a poor start!" << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //update the player in race
        cout << n << " is falling behind the other racers!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is getting left in the dust by the other racers!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 2; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //check energy
        if (e >= 45){
        
                //print the results of the race
                cout << n << " came in last place." << endl;
                sleep(2);
                cout << "Level up " << n << "'s skills and try again!" << endl;
                sleep(3);
                
                //return false because user lost race
                return 0;
            }
        
             else{
                cout << n << " fell asleep, and wasn't able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                //return false because duck fell asleep and last waste
                return 0;
        }
        
        
    }

}

bool Race :: amateurRace(int r, int s, int f, int e, string n){
    //declare variables
    string start;
    
    cout << "Welcome to the amateur race!" << endl;
 
    
    //calculate running probability
    if (r <= 30)
        runningProbability = 0;
        
    else if (r > 30 && r <= 40)
        runningProbability = 0.2;
        
    else if (r > 40 && r <= 60)
        runningProbability = 0.5;
        
    else if (r > 60 && r <= 80)
        runningProbability = 0.8;
        
    else
        runningProbability = 1;
        
    //calculate swimming probability
    if (s <= 30)
        swimmingProbability = 0;
        
    else if (s > 30 && s <= 40)
        swimmingProbability = 0.2;
        
    else if (s > 40 && s <= 60)
        swimmingProbability = 0.5;
        
    else if (s > 60 && s <= 80)
        swimmingProbability = 0.8;
        
    else
        swimmingProbability = 1;
        
    //calculate flying probability
    if (f <= 30)
        flyingProbability = 0;
        
    else if (f > 30 && f <= 40)
        flyingProbability = 0.2;
        
    else if (f > 40 && f <= 60)
        flyingProbability = 0.5;
        
    else if (f > 60 && f <= 80)
        flyingProbability = 0.8;
        
    else
        flyingProbability = 1;
        
    //randomize if the user won the race, based on probabilty 
    srand(time(0));
    bool TrueFalse = (rand() % 100) < probability;
    
    //calculate the probability
    probability = (runningProbability + swimmingProbability + flyingProbability) / (3 * 1.0) * 100;
    
    //Display users probability to win the race
    cout << "The probability for you to win given "<< n << "'s currents stats is " << probability << "%"<< endl;
    sleep(3);
    
    //while loop to start or quit the race
    while (start != "s" && start != "S"){
        cout << "Enter s to start the race, or enter q to exit the race and return to main menu " << endl;
        cin >> start;
         
            if (start == "q" || start == "Q")
                return 0;
            }
            
    //start race
    cout << "Lane 1: Daffy" << endl;
    sleep(1);
    cout << "Lane 2: " << n << endl;
    sleep(1);
    cout << "Lane 3: Donald" << endl;
    sleep(1);
    cout << "Lane 4: Daisy" << endl;
    sleep(1);
    
    cout << "Ready Racers!" << endl;
    sleep(2);
    cout << "On your mark" << endl;
    sleep(1);
    cout << "Get set" << endl;
    sleep(1);
    cout << "GOOO!!!" << endl;
    sleep(1);
    
    //**********************************************************************************************************************************
    //if the probability is 70 or above
    if (probability >= 70){
        sleep (1);
        cout << n << " is off to a great start!" << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 5; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 5; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        cout << n << " is leaving the other racers in the dust!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 45){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(3);
                cout << "Followed by Daisy in 2nd, Donald in 3rd, and Daffy in 4th" << endl; 
                sleep(3);
                cout << "Congrats! " << n << " has completed the amateur race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Oh no! " << n << " got lost, and came in last place!" << endl;
            sleep(2);
            cout << "Daisy came in 1st, followed by Donald in 2nd, Daffy in 3rd, and " << n << " in 4th!" << endl;
            sleep(3);
            
            //return false because duck lost race
            return 0;
        }
        
    }
    
    //***********************************************************************************************************************************
    
    //if the probability is between 69 and 50
    else if (probability < 70 && probability >= 50){
        sleep (1);
        cout << n << " is off to a good start!" << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 5; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 5; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        cout << n << " is in leading the pack, only slighty ahead of Donald" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 45){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Donald in 2nd, Daisy in 3rd, and Daffy in 4th" << endl; 
                sleep(3);
                cout << "Congrats! " << n << " has completed the amateur race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Donald passed "<< n << " last minute and came in first!" << endl;
            sleep(3);
            cout << "Followed by " << n << " in 2nd, followed by Daffy in 3rd, and Daffy in 4th!" << endl;
            sleep(3);
            
            //return false because duck lost race
            return 0;
        }
        
    }
    
    //**********************************************************************************************************************************
    
    //if the probability is between 49 and 30
    else if (probability < 50 && probability >= 30){
        sleep (1);
        cout << "The ducks are off! " << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 5; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << "Daffy is in the lead followed by " << n << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 5; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << "Daffy and " << n << " are neck and neck!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 45){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Daffy in 2nd, Daisy in 3rd, and Donald in 4th" << endl; 
                sleep(3);
                cout << "Congrats! " << n << " has completed the amateur race!" << endl;
                sleep(3);
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Daffy came in 1st place!" << endl;
            sleep(2);
            cout << n << " in 2nd, followed by Daisy in 3rd, and Donald in 4th!" << endl;
            sleep(3);
            
            //return false because duck lost race
            return 0;
        }
        
    }
    
    else{
        sleep (1);
        cout << n << " is off to a poor start!" << endl;
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 5; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 5; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        cout << n << " is falling behind the other racers!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is being left in the dust by the other racers!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 3; i >= 0; i--){
            cout << "Running";
            sleep(1);
            
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        //check energy
        if (e >= 45){
        
            //print the results of the race
            cout << n << " came in last place." << endl;
            sleep(2);
            cout << "Level up " << n << "'s skills and try again!" << endl;
            sleep(3);
                
            //return false because user lost race
            return 0;
            }
        
        else{
            cout << n << " fell asleep, and wasn't able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
            sleep(4);
            //return false because duck fell asleep and last waste
            return 0;
        }
        
    }

}

bool Race :: expertRace(int r, int s, int f, int e, string n){
    //declare variables
    string start;
    
    cout << "Welcome to the expert race!" << endl;
 
    //calculate running probability
    if (r <= 60)
        runningProbability = 0;
        
    else if (r > 60 && r <= 70)
        runningProbability = 0.2;
        
    else if (r > 70 && r <= 80)
        runningProbability = 0.5;
        
    else if (r > 80 && r <= 90)
        runningProbability = 0.8;
        
    else
        runningProbability = 1;
        
    //calculate swimming probability
    if (s <= 60)
        swimmingProbability = 0;
        
    else if (s > 60 && s <= 70)
        swimmingProbability = 0.2;
        
    else if (s > 70 && s <= 80)
        swimmingProbability = 0.5;
        
    else if (s > 80 && s <= 90)
        swimmingProbability = 0.8;
        
    else
        swimmingProbability = 1;
        
    //calculate flying probability
    if (f <= 60)
        flyingProbability = 0;
        
    else if (f > 60 && f <= 70)
        flyingProbability = 0.2;
        
    else if (f > 70 && f <= 80)
        flyingProbability = 0.5;
        
    else if (f > 80 && f <= 90)
        flyingProbability = 0.8;
        
    else
        flyingProbability = 1;
        
    //randomize if the user won the race, based on probabilty 
    srand(time(0));
    bool TrueFalse = (rand() % 100) < probability;
    
    //calculate the probability
    probability = (runningProbability + swimmingProbability + flyingProbability) / (3 * 1.0) * 100;
    
    //Display users probability to win the race
    cout << "The probability for you to win given "<< n << "'s currents stats is " << probability << "%"<< endl;
    sleep(3);
    
    //while loop to start or quit the race
    while (start != "s" && start != "S"){
        cout << "Enter s to start the race, or enter q to exit the race and return to main menu " << endl;
        cin >> start;
         
            if (start == "q" || start == "Q")
                return 0;
            }
            
    //start race
    cout << "Lane 1: Peep" << endl;
    sleep(1);
    cout << "Lane 2: Feathers" << endl;
    sleep(1);
    cout << "Lane 3: " << n << endl;
    sleep(1);
    cout << "Lane 4: Smokey" << endl;
    sleep(1);
    
    cout << "Ready Racers!" << endl;
    sleep(1);
    cout << "On your mark" << endl;
    sleep(1);
    cout << "Get set" << endl;
    sleep(1);
    cout << "GOOO!!!" << endl;
    sleep(1);
    
    //if the probability is 70 or above
    if (probability >= 70){
        sleep (1);
        cout << n << " is off to a great start!" << endl;
        
        //for loop to simulate duck flying
        for (int i = 7; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is leading the pack!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is leaving the other racers in the dust!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 10; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 70){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Smokey in 2nd, Peep in 3rd, and Feathers in 4th" << endl; 
                sleep(3);
        
                cout << "Congrats! " << n << " has completed the expert race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Oh no! " << n << " went the wrong way, and lost the race!" << endl;
            sleep(3);
            cout << "Smokey came in 1st, followed by Peep in 2nd, Feathers in 3rd, and " << n << " in 4th!" << endl;
            sleep(3);
            cout << "Better luck next time!" << endl;
            sleep(2);
            //return false because duck lost race
            return 0;
        }
        
    }
    
    //if the probability is between 69 and 50
    else if (probability < 70 && probability >= 50){
        sleep (1);
        cout << n << " is off to a good start!" << endl;
        
        //for loop to simulate duck flying
        for (int i = 7; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is slighty ahead of the others!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is still in the lead!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 10; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 70){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Peep in 2nd, Smokey in 3rd, and Feathers in 4th" << endl; 
                sleep(3);
        
                cout << "Congrats! " << n << " has completed the expert race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Peep passed " << n << " last minute and won the race!" << endl;
            sleep(3);
            cout << "Peep came in 1st, followed by  " << n << " in 2nd, Smokey in 3rd, and Feathers in 4th!" << endl;
            sleep(3);
            cout << "Better luck next time!" << endl;
            sleep(3);
            
            //return false because duck lost race
            return 0;
        }
        
    }
    
    //if the probability is between 49 and 30
    else if (probability < 50 && probability >= 30){
        sleep (1);
        cout << "The ducks are off!" << endl;
        
        //for loop to simulate duck flying
        for (int i = 7; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is neck and neck with Feathers!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << "Feathers has taken a slight lead over " << n << "!" << endl;
        sleep(2);
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is neck and neck with Feathers!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 10; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        //checks if the duck won the race based on the probibility
        if (TrueFalse == 1){
            
            //checks if the duck has enough energy to finish the race
            if (e >= 70){
                //print the results of the race
                cout << n << " came in 1st place!" << endl;
                sleep(2);
                cout << "Followed by Feathers in 2nd, Smokey in 3rd, and Peep in 4th" << endl; 
                sleep(3);
        
                cout << "Congrats! " << n << " has completed the expert race!" << endl;
                sleep(3);
        
                //return true because user won race
                return 1;
        }
            
            //checks if the duck ran out of energy
            else{
                cout << n << " fell asleep, and wasnt able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
                sleep(4);
                return 0;
            }
        }
    
        else {
            
            //display results 
            cout << "Fethers won the race by a hair!" << endl;
            sleep(2);
            cout << "Fethers came in 1st, followed by " << n << " in 2nd, Smokey in 3rd, and Peep in 4th!" << endl;
            sleep(3);
            cout << "Level up " << n << "'s skills and try again next time!" << endl;
            sleep(3);
            
            //return false because duck lost race
            return 0;
        }
        
    }
    
    else{
        sleep (1);
        cout << n << " is off to a poor start!" << endl;
        
        //for loop to simulate duck flying
        for (int i = 7; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is falling behind!" << endl;
        sleep(2);
        
        //for loop to simulate duck running
        for (int i = 5; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck swimming
        for (int i = 2; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck flying
        for (int i = 2; i >= 0; i--){
            cout << "Flying";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        cout << n << " is being left in the dust!" << endl;
        sleep(2);
        
        //for loop to simulate duck swimming
        for (int i = 3; i >= 0; i--){
            cout << "Swimming";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        //for loop to simulate duck running
        for (int i = 10; i >= 0; i--){
            cout << "Running";
            sleep(1);
                
            for (int j = i; j > 0; j--)
                cout << ".";
                
            cout << endl;
        }
        
        
        //check energy
        if (e >= 70){
        
            //print the results of the race
            cout << n << " came in last place." << endl;
            sleep(2);
            cout << "Level up " << n << "'s skills and try again!" << endl;
            sleep(3);
                
            //return false because user lost race
            return 0;
        }
        
        else{
            cout << n << " fell asleep, and wasn't able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
            sleep(4);
            //return false because duck fell asleep and last waste
            return 0;
        }
    
    }
    
}

bool Race :: worldChampionship (int r1, int s1, int f1, int e, string n){
    cout << "Welcome to the World Championship!" << endl;
    sleep(2);
    
    //declare variables
    int count = 0;
    string line;
    string statsArray[6];
    int size = 6;
    ifstream inFile;
    
    //declare array of duck objects for racers
    Duck racers[10];
                        
    //open the file
    inFile.open("opponent.txt");

    //read file and store information from file in racers array                        
    while (getline(inFile, line)){
                            
    //call split function to split the line
    split(line, ',', statsArray, size);
    
    //store stats in racers array                        
    racers[count].setName(statsArray[0]);
    racers[count].setRunning(stoi(statsArray[1]));
    racers[count].setSwimming(stoi(statsArray[2]));
    racers[count].setFlying(stoi(statsArray[3]));
                            
    //add one to the count
    count++;
                            
    }
    
    //randomize who makes it to the world cup, out of the opponents file
    //randomize if the user won the race, based on probabilty 
    srand(time(0));
    int racerNumber = (rand() % 10); //generates a random number between 0-9
    
    //aassign variable to opponents name
    string opponentsName = racers[racerNumber].getName();
    
    //put the opponents stats in variables
    int r2 = racers[racerNumber].getRunning();
    int s2 = racers[racerNumber].getSwimming();
    int f2 = racers[racerNumber].getFlying();
    
    //calculate the average of each of their stats
    double racerOneStats = (r1 + s1 + f1) / 3 * 1.0;
    
    double racerTwoStats = (r2 + s2 + f2) / 3 * 1.0;
    
    //announce the racers for the world championship race
    cout << "The World Champion racers are: " << n << " in lane 1, and " << opponentsName <<  " in lane 2." << endl;
    sleep(3);
    
    cout << "Lets take a look at the racers stats!" << endl;
    sleep(3);
    
    //check who has the higher running stats
    if (r1 > r2){
        cout << n << " has the advantage in the running category!" << endl;
        sleep(3);
    }
    
    else if (r1 == r2){
        cout << "The racers have about even running skills!" << endl;
        sleep(3);
    }
        
    else{
        cout << opponentsName << " has the advantage in the running category!" << endl;
        sleep(3);
    }
    
    //check who has the higher swimming level
    if (s1 > s2){
        cout << n << " has the advantage in the swimming category!" << endl;
        sleep(3);
    }
    
    else if (s1 == s2){
        cout << "The racers have about the same swimming skills!" << endl;
        sleep(3);
    }
    
    else{
        cout << opponentsName << " has the advantage in the swimming category!" << endl;
        sleep(3);
    }
    
    //check who has the higher flying level
    if (f1 > f2){
        cout << n << " has the advantage in the flying category!" << endl;
        sleep(3);
    }
    
    else if (f1 == f2){
        cout << "The racers have about the same flying skills!" << endl;
        sleep(3);
    }
    
    else{
        cout << opponentsName << " has the advantage in the flying category!" << endl;
    }
    
    cout << "The racers are starting up on the starting line!" << endl;
    sleep(3);
    
    cout << "Ready Racers!" << endl;
    sleep(2);
    cout << "On your mark" << endl;
    sleep(1);
    cout << "Get set" << endl;
    sleep(1);
    cout << "GOOO!!!" << endl;
    sleep(1);
    
    cout << "The racers are off!" << endl;
    sleep(2);
        
    //for loop to simulate duck running
    for (int i = 8; i >= 0; i--){
        cout << "Running";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
    
    //for loop to simulate duck flying
    for (int i = 7; i >= 0; i--){
        cout << "Flying";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
        
    //for loop to simulate duck swimming
    for (int i = 8; i >= 0; i--){
        cout << "Swimming";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
    
    cout << "The racers are neck and neck!" << endl;
    sleep(2);
        
    //for loop to simulate duck flying
    for (int i = 3; i >= 0; i--){
        cout << "Flying";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
        
    //for loop to simulate duck swimming
    for (int i = 2; i >= 0; i--){
        cout << "Swimming";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
    
        
    //for loop to simulate duck running
    for (int i = 5; i >= 0; i--){
        cout << "Running";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
    
    cout << opponentsName << " is ahead of " << n << " by a hair!" << endl;
    sleep(2);
        
    //for loop to simulate duck flying
    for (int i = 5; i >= 0; i--){
        cout << "Flying";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
        
    //for loop to simulate duck running
    for (int i = 2; i >= 0; i--){
        cout << "Running";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
        
    //for loop to simulate duck swimming
    for (int i = 5; i >= 0; i--){
        cout << "Swimming";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
    
    cout << n << " caught up to " << opponentsName << " and is now side by side with " << opponentsName << "!" << endl;
    sleep(2);
        
    //for loop to simulate duck running
    for (int i = 3; i >= 0; i--){
        cout << "Running";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
        
    //for loop to simulate duck flying
    for (int i = 2; i >= 0; i--){
        cout << "Flying";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
        
    //for loop to simulate duck running
    for (int i = 5; i >= 0; i--){
        cout << "Running";
        sleep(1);
                
        for (int j = i; j > 0; j--)
            cout << ".";
                
        cout << endl;
    }
    
    //check to make sure user had enough energy
    if (e < 90){
        cout << n << " fell asleep, and wasn't able to finish the race. Make sure to buy seeds in the store to level up energy!" << endl;
        //return false because duck fell asleep and lost race
        return 0;
    }
    
    //if the user has a higher or equal stat average than the opponent than the user wins the race
    if (racerOneStats >= racerTwoStats){
    
        cout << n << " won the Championship!!!" << endl;
        sleep(2);
        
        //return 1 because user won race
        return 1;
    }
        
    
    else{
        cout << opponentsName << " won the Championship." << endl;
        sleep(2);
        cout << n << " came in 2nd. Better luck next time!" << endl;
        sleep(2);
    }

    return 0;
        
}
