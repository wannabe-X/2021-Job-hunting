#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
    string name;
    bool hasTable;

public:
    Player();
    Player(const string &na, bool ht);
    void show_old();
    void reset_table(bool v)
    {
        hasTable = v;
    }
};

class NewPlayer : public Player
{
private:
    int score;

public:
    NewPlayer();
    NewPlayer(const string &na, bool ht, int sco);
    NewPlayer(const Player &pl, int sco);
    void reset_score(int sco);
    void show_new();
};

#endif