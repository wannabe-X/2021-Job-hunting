#include "player.h"
#include <iostream>
#include <string>
using namespace std;

//实现基类
Player::Player()
{
    name = "NULL";
    hasTable = false;
}

Player::Player(const string &na, bool ht) : name(na), hasTable(ht)
{
}

void Player::show_old()
{
    cout << "Info\n";
    cout << "name: " << name << endl;
    cout << boolalpha;
    cout << "hastable: " << hasTable << endl;
}

//实现派生类
NewPlayer::NewPlayer() : Player(), score(0)
{
}

NewPlayer::NewPlayer(const string &na, bool ht, int sco) : Player(na, ht), score(sco)
{
}

NewPlayer::NewPlayer(const Player &pl, int sco) : Player(pl), score(sco)
{
}

void NewPlayer::reset_score(int sco)
{
    score = sco;
}

void NewPlayer::show_new()
{
    show_old();
    cout << "score: " << score << endl
         << endl;
}