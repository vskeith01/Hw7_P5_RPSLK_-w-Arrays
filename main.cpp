/******************************************************************************
Description: Rock, Paper, Scissors, Lizard, Spock Game
This game is unfinished. Complete the game.
Last Modified by: Veronica Keith
*******************************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//////////////////// Prototype Functions /////////////////////////////////////
void TranslatePick(int flag_who, char selection);
char ComputerSelectRPSLK();
char WinLoose(char user, char comp);
void RandMessage(char Result);
//////////////////// MAIN ////////////////////////////////////////////////////

int main()
{
// declare vars
  char userPick; // user's selection for game
  bool valid_pick = false; // flag controlled while loop for obtaining
  char result;
  
// user input
  char computerPick; // randomly selected computer selection for
  
// game
  
// Display rules of the game.
  cout << "It's time to play Rock, Paper, Scissors, Lizard, Spock!" << endl;
  cout << "Use R (for Rock), P (for Paper), S (for Scissors), ";
  cout << "L (for Lizard), and K (for Spock)." << endl;
  
// Obtain userPick. Prompt until a valid selection is made.
while (valid_pick == false)
  {
    cout << "You pick: ";
    cin >> userPick;
    if ( (userPick == 'R') || (userPick == 'P') || (userPick == 'S' ) ||
    (userPick == 'L') || (userPick == 'K') )
      {
        valid_pick = true;
      }
    else
    cout << "Invalid Selection. Try again. " << endl;
  }
// Repeat selection back to user.
  TranslatePick(0, userPick);

  
// Obtain computer selection.
  computerPick = ComputerSelectRPSLK();
  TranslatePick(1, computerPick); // Inform user of computer selection


//WinLoose(userPick, computerPick);

  result = WinLoose(userPick, computerPick);
  RandMessage(result);
  

  
return 0;
}


/////////////// User-Created Functions ////////////////////////////////////////
/* Descprition: This function is used to translate the character selection to a
statement which is displayed to the user.
Parameters: flag_who is an integer which is used to indicate if the computer
or the user made the choice.
selection is one of the 5 valid character selections */
  void TranslatePick(int flag_who, char selection)  // void style does not return a vlaue 
  {
    // declare local function variables
    string who_text;
    // identify which statements to insert into the output below
    if (flag_who == 0)
      who_text = "You";
    else
      who_text = "The Computer";
    // display output where the char selection is translated into words
    if (selection == 'R')
      cout << who_text <<" selected Rock." << endl;
    else if (selection == 'P')
      cout << who_text <<" selected Paper." << endl;
    else if (selection == 'S')
      cout << who_text <<" selected Scissors." << endl;
    else if (selection == 'L')
      cout << who_text <<" selected Lizard." << endl;
    else if (selection == 'K')
      cout << who_text <<" selected Spock." << endl;
    else // something is wrong
      cout << "Check code for errors. Message from TranslatePick fcn." << endl;
    return;
  }

  


/* Descprition: This function is used to make a random character selection in the
game Rock, Paper, Scissors, Lizard, Spock
Parameters: there are no inputs */
  char ComputerSelectRPSLK()
{
// declare local function variables
  char randPickChar;
  int randPick;
// pick a random number from 0 to 4
  srand (time(NULL)); // initialize random seed.
  randPick = rand() % 5; // gives us 0 to 4
//cout << randPick; // uncomment to debug
// assign random number to letter
  switch (randPick)
  {
    case 0:
      randPickChar = 'R';
      break;
    case 1:
      randPickChar = 'P';
      break;
    case 2:
      randPickChar = 'S';
      break;
    case 3:
      randPickChar = 'L';
      break;
    case 4:
      randPickChar = 'K';
      break;
    default:
      cout << "Error in the function ComputerSelectRPSLK. " << endl;
  }
  return randPickChar;
}

/////// Creat Function to choose a winner ////////

char WinLoose(char user, char comp)  // might need to return bool win
{
  char result;
  result = 'L';
  
  
  if (user  == 'R')
    switch (comp)
      {
        case 'R':
          cout << "It's a Tie";
          break; 
        case 'L':
        case 'S':
          cout << "You Win! ";
          result = 'W';
        break;
        case 'P':
        case 'K':
          cout << "You loose";
          break;
      }
  else if (user  == 'P')
      switch (comp)
      {
        case 'P':
          cout << "It's a Tie";
          break; 
        case 'L':
          case 'S':
          cout << "You loose";
        break;
        case 'R':
        case 'K':
          cout << "You Win! ";
          result = 'W';
          break;
      }
  else if (user  == 'S')
      switch (comp)
      {
        case 'S':
          cout << "It's a Tie ";
          break; 
        case 'R':
        case 'K':
          cout << "You loose";
          break;
        case 'P':
        case 'L':
          cout << "You Win! ";
          result = 'W';
          break;
      }
  else if (user  == 'L')
      switch (comp)
      {
        case 'L':
          cout << "It's a Tie";
          break; 
        case 'R':
        case 'S':
          cout << "You loose";
          break;
        case 'P':
        case 'K':
          cout << "You Win! ";
          result = 'W';
          break;
      }
  else if (user  == 'K')
      switch (comp)
      {
        case 'K':
          cout << "It's a Tie";
          break; 
        case 'P':
        case 'L':
          cout << "You loose";
          break;
        case 'R':
        case 'S':
          cout << "You Win! ";
          result = 'W';
          break;
      }  
  return result;
}


// Selects a random number and outputs a congrats message
void RandMessage(char Result)
{
  int randPick;

  srand (time(NULL));
  randPick = rand() % 5;
  if (Result == 'W')
    switch (randPick)
      {
        case 0:
        cout << "Great Job" << endl;
        break;
        case 1:
        cout << "Wahooo!!!!";
        break;
        case 2: 
        cout << "You're The Best!";
        break;
        case 3:
        cout << "Amazing!" << endl;
        break;
        case 4:
        cout << "Congrats!!!" << endl;
        break;
        
      }
      
      
      
}