
#include <iostream>
#include <string>
#include <random>
#include<algorithm>
using namespace std;

//Function prototypes
string getplayerchoice();
string getcomputerchoice(random_device& rd);
string determinewinner(string playerchoice, string computerchoice);
void update_score(string winner, int& player_score, int& computer_score);
void declare_overralwinner(int player_score, int computer_score);

//Function for player choice
string getplayerchoice() {
  string choice;
  while (true) {
    std::cout << "Enter your choice (rock, paper, scissors, quit): ";
    std::cin >> choice;
    if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit")
      return choice;
    else
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
} 
// end of getplayerchoice function

// Function for computer choice
string getcomputerchoice(random_device& rd) {
  uniform_int_distribution<int> dist(1, 3);
     int num= dist(rd);
                                                if (num == 1)
                                                  return "rock";
                                               else if (num == 2)
                                                  return "paper";
                                               else
                                                  return "scissors";
                                               }
// end of getcomputerchoice function
// Function for determine winner of the round
string determinewinner(string playerchoice, string computerchoice) {
  if (playerchoice == computerchoice) return "tie";
  if ((playerchoice == "rock" && computerchoice == "scissors") || (playerchoice == "paper" && computerchoice == "rock") || (playerchoice == "scissors" && computerchoice == "paper")) {
    return "player";
  } else {
    return "computer";
  }
}
// end of determinewinner function
// Function for update score
void update_score(string winner, int& player_score, int& computer_score) {
  if (winner == "player") {
    player_score++;
  } else if (winner == "computer") {
    computer_score++;
  }
}
// end of update_score function
// Function for declare overall winner
void declare_overralwinner(int player_score, int computer_score) {
  if (player_score > computer_score)
    std::cout << "You win the game!" << std::endl;
  else if (player_score < computer_score)
    std::cout << "The computer wins the game!" << std::endl;
  else
    std::cout << "The game is a tie!" << std::endl;
}

// Main function
int main(){
  random_device rd;
  int player_score = 0;
  int computer_score = 0;
cout<< "Welcome to Rock, Paper, Scissors!" << endl;
  while (true){
    string playerchoice = getplayerchoice();
    if (playerchoice == "quit") break;
    
    string computerchoice = getcomputerchoice(rd);
    cout << "Computer chose: " << computerchoice << endl;
    string winner = determinewinner(playerchoice, computerchoice);
    if (winner == "tie") { cout << "It's a tie!" << endl;
                        } else if (winner == "player") {
                          cout << "You win this round!" << endl;
                          } else {
                          cout << "The computer wins this round!" << endl;
                          }       
    update_score(winner, player_score, computer_score);
    cout << "Score: Player " << player_score << " - " << computer_score << " Computer" << endl;
  }
  declare_overralwinner(player_score, computer_score);
  return 0;
}
                                             


    
    