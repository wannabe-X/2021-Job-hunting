#include "player.h"
#include <iostream>
#include <string>
using namespace std;

// 实现基类函数
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
    cout << "Name:" << name << endl;
    cout << "hasTable:" << hasTable << endl;
}

// 实现派生类函数 非静态const成员数据和引用数据必须用这种语法初始化
// 成员初始化列表的语法仅仅用于构造函数
NewPlayer::NewPlayer() : Player(), score(0)
{
}

// 非静态const成员数据和引用数据必须用这种语法初始化
NewPlayer::NewPlayer(const string &na, bool ht, int sco) : Player(na, ht), score(sco)
{
}

// 调用复制构造函数
// const Player &pl 新建一个对象并且将其初始化为同类现有对象
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
    cout << "score:" << score << endl;
}
