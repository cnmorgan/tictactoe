#pragma once

#include "board.hpp"
#include "player.hpp"

class Game{
  public:
    Game();
    ~Game();
    void play();
    
  private:
    Board *m_board;
    Player *m_player_x;
    Player *m_player_o;
    void display_board();
    void display_header();
};

