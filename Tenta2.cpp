// Tenta2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum 
{
    Goalie,
    Defence,
    Forward
}POSITION;

class Person
{
private:
    int age;
    string firstname;
    int birthmonth;
    string lastname;
public:
        
    void SetAge(int age)
    {
        if (age < 0)
        {
            return;
        }
        this->age = age;
    }
    int GetAge()
    {
        return age;
    }

};

class Player
{
private:
    int jerseynumber;
    string namn;
    int age;
    POSITION position;
public:
    Player(string namn, int jerseyNumber, int age, POSITION pos)
    {
        this->namn = namn;
        this->age = age;
        this->jerseynumber = jerseyNumber;
        this->position = pos;
    }

    void SetJerseyNumber(int n)
    {
        this->jerseynumber = n;
    }

    string GetName()
    {
        return this->namn;
    }

    int GetAge()
    {
        return this->age;
    }

    int GetJersey()
    {
        return this->jerseynumber;
    }

    string GetPosition()
    {
        //return this->position;
        string PositionText;
        if (this->position == 0)
        {
            string PositionText;
            PositionText = "Goalie";
            return PositionText;
        }
        if (this->position == 1)
        {
            string PositionText;
            PositionText = "Defence";
            return PositionText;
        }
        if (this->position == 2)
        {
            string PositionText;
            PositionText = "Forward";
            return PositionText;
        }
    }
};
    
class Team
{
private:
	string namn;
	vector<Player> players;
public:
    Team(string namn)
    {
        this->namn = namn;
    }

    int NumberOfPlayers()
    {
        return players.size();
    }

    Player GetPlayerByIndex(int index)
    {
        return players[index];
    }
    void AddPlayer(Player p)
    {
        if (players.size() > 5)
            throw std::exception("Too many players");
        players.push_back(p);
    }
    
};


int main()
{
    Person str;  
    str.SetAge(12);
    cout << str.GetAge() << endl;

    Team t("Oldboysclub");
    Player p("NeilSawbridge",7,50,Forward);
    Player p2("BobbySmith", 8, 65,Goalie);
    Player p3("AlanNorth", 12, 32,Defence);
    
    t.AddPlayer(p);
    t.AddPlayer(p2);
    t.AddPlayer(p3);

    for (int i = 0; i < t.NumberOfPlayers(); i++)
    {
        Player printplayer = t.GetPlayerByIndex(i);
        cout << "Name: " << printplayer.GetName() << " Age: " << printplayer.GetAge() << " Jersey No. " 
        << printplayer.GetJersey() << " Position: " << printplayer.GetPosition() << endl;
    }
    

    return 0;
}
