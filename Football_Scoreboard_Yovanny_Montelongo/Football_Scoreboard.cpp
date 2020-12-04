#include <iostream>
#include "Team.cpp"
#include "Scoreboard.cpp"
#include "Input_Validation_Extended.h" //courtesy of Dr_T :)

using namespace std;

void changeHomeTeamScore(Team &homeTeam){
    int score = 0;
    int currentScore = homeTeam.getScore();

    cout << "\n\nEnter amount you want to add to " << homeTeam.getTeamName() << " score: ";
    score = validateInt(score);
    homeTeam.setScore((currentScore + score));

    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    
}

void changeAwayTeamScore(Team &awayTeam){
    int score = 0;
    int currentScore = awayTeam.getScore();

    cout << "\n\nEnter amount you want to add to " << awayTeam.getTeamName() << " score: ";
    score = validateInt(score);
    awayTeam.setScore((currentScore + score));

    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    
}

void displayScoreboard(Team &t1, Team &t2, Scoreboard &sb){

    // show basic team info
    cout << "\n----- " << t1.getTeamName() << " vs " << t2.getTeamName() << " -----" << endl;
    cout << "Coaches: \n\t" << t1.getTeamName() << ": " << t1.getCoachName() << "\n\t" << t2.getTeamName() << ": " << t2.getCoachName() << endl;
    cout << "Cities: \n\t" << t1.getTeamName() << ": " << t1.getHomeCity() << "\n\t" << t2.getTeamName() << ": " << t2.getHomeCity() << endl << endl;

    cout << "--------------------------------------------------\n\n";

    // show current game info
    cout << "Scores: \n\t" << t1.getTeamName() << ": " << t1.getScore() << "\n\t" << t2.getTeamName() << ": " << t2.getScore() << endl << endl;
    cout << "Timeouts: \n\t" << t1.getTeamName() << ": " << t1.getTimeoutCount() << "\n\t" << t2.getTeamName() << ": " << t2.getTimeoutCount() << endl << endl;
    
    cout << "Quarter: " << sb.getCurrentQuarter() << endl;
    cout << "Down: " << sb.getCurrentDown() << endl;
    cout << "Yards to go: " << sb.getYardsLeft() << endl;
    
    if(t1.getIsHomeTeam() == t2.getIsHomeTeam()){
        cout << "\n\nBoth teams can't be home team!\n\n";
    } else {
        if (sb.getHomeHasBall()){
            cout << t1.getTeamName() << " has the ball.\n\n";
        } else {
            cout << t2.getTeamName() << " has the ball.\n\n";
        }
    }

}

void changeYardsLeft(Scoreboard &sb){
    int currentYards = sb.getYardsLeft();

    do {

        cout << "\nEnter amount of yards left (should be less than 120): ";
        currentYards = validateInt(currentYards);

    } while(!(currentYards < 120));

    sb.setYardsLeft(currentYards);

    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    
}

void changePossession(Scoreboard &sb){

    if(sb.getHomeHasBall()){
        sb.setHomeHasBall(false);
    } else {
        sb.setHomeHasBall(true);
    }

    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)

}

void changeCurrentDown(Scoreboard &sb){

    int currentDown = sb.getCurrentDown();
    
    if (currentDown == 4){
        sb.setCurrentDown(1);
        sb.setYardsLeft(10);
        changePossession(sb);
        cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    } else {
        sb.setCurrentDown((++currentDown));
        cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    }

}

void changeQuarter(Team &t1, Team &t2, Scoreboard &sb){

    int currentQuarter = sb.getCurrentQuarter();

    if (currentQuarter == 4){
        sb.setCurrentQuarter(1);
        sb.setCurrentDown(1);
        sb.setYardsLeft(10);
        t1.setTimeoutCount(3);
        t2.setTimeoutCount(3);
        changePossession(sb);
    } else if(currentQuarter == 2){
        sb.setCurrentQuarter(++currentQuarter);
        sb.setCurrentDown(1);
        sb.setYardsLeft(10);
        t1.setTimeoutCount(3);
        t2.setTimeoutCount(3);
        changePossession(sb);
    } else {
        sb.setCurrentQuarter(++currentQuarter);
    }

    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)

}

void changeTimeout(Team &team){

    int timeout = team.getTimeoutCount();
    if (timeout == 0){
        cout << "\nCan't decrement any further!\n";
    } else {
        team.setTimeoutCount(--timeout);
    }

    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    
}

void showCommandsList(){
    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    cout << "\n\n*************** COMMANDS ***************\n";
    cout << "h/H: add to home team's score\n";
    cout << "a/A: add to away team's score\n";
    cout << "q/Q: change current quarter (resets to 1 after 4 and resets d and y after 2 and 4)\n";
    cout << "d/D: change current down (resets to 1 after 4 and also resets y)\n";
    cout << "t/T: take one away from timeout for a team (resets to three after quarter 2 and 4)\n";
    cout << "y/y: change yards left\n";
    cout << "p/p: change possession of the ball\n";
    cout << "*************** COMMANDS ***************\n";
}

int main(){

    char input = '0';
    string sInput = "";
    int iInput = 0;

    Team t1 = Team();
    Team t2 = Team();
    Scoreboard sb = Scoreboard();

    // setting info for team 1
    cout << "\n!!! Initial Setup !!!\n";

    cout << "Enter TEAM 1's name: ";
    sInput = validateString(sInput);
    t1.setTeamName(sInput);

    cout << "\nEnter TEAM 1's coach name: ";
    sInput = validateString(sInput);
    t1.setCoachName(sInput);

    cout << "\nEnter TEAM 1's hometown name: ";
    sInput = validateString(sInput);
    t1.setHomeCity(sInput);

    do {
        cout << "\nEnter TEAM 1's home status (0 for away, 1 for home): ";
        iInput = validateInt(iInput);
        t1.setIsHomeTeam(iInput);
    } while((iInput > 2 || iInput < 0));
    
    t1.setScore(0);
    t1.setTimeoutCount(3);  

    // setting info for team 2
    cout << "\n!!! Initial Setup !!!\n";

    cout << "Enter TEAM 2's name: ";
    sInput = validateString(sInput);
    t2.setTeamName(sInput);

    cout << "\nEnter TEAM 2's coach name: ";
    sInput = validateString(sInput);
    t2.setCoachName(sInput);

    cout << "\nEnter TEAM 2's hometown name: ";
    sInput = validateString(sInput);
    t2.setHomeCity(sInput);

    if (t1.getIsHomeTeam()){
        t2.setIsHomeTeam(false);
    } else {
        t2.setIsHomeTeam(true);
    }

    t2.setScore(0);
    t2.setTimeoutCount(3);  

    // setting default scoreboard info
    sb.setHomeScore(t1.getScore());
    sb.setAwayScore(t2.getScore());
    sb.setCurrentDown(1);
    sb.setHomeHasBall(true);
    sb.setYardsLeft(10);
    sb.setCurrentQuarter(1);

    do {

        displayScoreboard(t1, t2, sb);
        cout << "Enter a single letter command (enter \'z\' for a list of commands or \'x\' to exit): ";
        input = validateChar(input);
        cout << "\n\n\n";

        if(input == 'a' || input == 'A'){
            
            if (t2.getIsHomeTeam()){
                changeAwayTeamScore(t1);
            } else {
                changeAwayTeamScore(t2);
            }

        } else if(input == 'd' || input == 'D'){
            changeCurrentDown(sb);
        } else if(input == 'h' || input == 'H'){
            
            if (t1.getIsHomeTeam()){
                changeHomeTeamScore(t1);
            } else {
                changeHomeTeamScore(t2);
            }

        } else if(input == 'p' || input == 'P'){
            changePossession(sb);
        } else if(input == 'q' || input == 'Q'){
            changeQuarter(t1, t2, sb);
        } else if(input == 't' || input == 'T'){
            
            cout << "Enter 1 for " << t1.getTeamName() << " or 2 for " << t2.getTeamName() << ": ";
            iInput = validateInt(iInput);

            if (iInput == 1){
                changeTimeout(t1);
            } else if (iInput == 2){
                changeTimeout(t2);
            } else {
                cout << "\nNot a valid input! Try again.\n";
            }
            

        } else if(input == 'y' || input == 'Y'){
            changeYardsLeft(sb);
        } else if(input == 'z' || input == 'Z'){
            showCommandsList();
        }


    } while(input != 'x' && input != 'X');

    displayScoreboard(t1, t2, sb);
    cout << "\033[2J\033[1;1H"; // clear's screen (should work w/ windows AND unix/macos. tested on macos)
    
    return 0;

}
