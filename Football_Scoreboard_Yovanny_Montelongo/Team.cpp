#include <iostream>

using namespace std;

class Team {

    private:
        string teamName;
        string coachName;
        string homeCity;
        bool isHomeTeam;
        int score;
        int timeoutCount;

    public:

        // getters
        string getTeamName(){
            return teamName;
        }

        string getCoachName(){
            return coachName;
        }

        string getHomeCity(){
            return homeCity;
        }

        bool getIsHomeTeam(){
            return isHomeTeam;
        }

        int getScore(){
            return score;
        }

        int getTimeoutCount(){
            return timeoutCount;
        }


        // setters
        void setTeamName(string tname){
            teamName = tname;
        }

        void setCoachName(string cname){
            coachName = cname;
        }

        void setHomeCity(string city){
            homeCity = city;
        }

        void setIsHomeTeam(bool isHome){
            isHomeTeam = isHome;
        }

        void setScore(int currentScore){
            score = currentScore;
        }

        void setTimeoutCount(int timeout){
            timeoutCount = timeout;
        }

};