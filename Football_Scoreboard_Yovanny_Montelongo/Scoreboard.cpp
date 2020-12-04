#include <iostream>

using namespace std;

class Scoreboard{

    private:
        int homeScore;
        int awayScore;
        int currentQuarter;
        int currentDown;
        int yardsLeft;
        bool homeHasBall; // true if the home team as the ball, false if the away team has the ball

    public:

    // getters
        int getHomeScore(){
            return homeScore;
        }

        int getAwayScore(){
            return awayScore;
        }

        int getCurrentQuarter(){
            return currentQuarter;
        }

        int getCurrentDown(){
            return currentDown;
        }

        int getYardsLeft(){
            return yardsLeft;
        }

        bool getHomeHasBall(){
            return homeHasBall;
        }

        // setters
        void setHomeScore(int hScore){
            homeScore = hScore;
        }

        void setAwayScore(int aScore){
            awayScore = aScore;
        }

        void setCurrentQuarter(int quarter){
            currentQuarter = quarter;
        }

        void setCurrentDown(int down){
            currentDown = down;
        }

        void setYardsLeft(int yards){
            yardsLeft = yards;
        }

        void setHomeHasBall(bool hHasBall){
            homeHasBall = hHasBall;
        }
        
};