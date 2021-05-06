#include "player.h"

int main(void)
{
    Player player("Tom", true);
    player.show_old();

    NewPlayer newplayer("Jack", true, 95);
    newplayer.show_new();

    // 调用复制构造函数
    NewPlayer newplayer1(player, 96);
    newplayer1.show_new();

    newplayer1.reset_score(68);
    newplayer1.reset_table(false);
    newplayer1.show_new();

    return 0;
}
