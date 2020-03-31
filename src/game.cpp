#include <iostream>
#include "headers/game.hpp"

/**
 * @brief A quick and dirty way to clear the terminal for output
 * 
 */
void ClearScreen()
{
  std::cout << std::string( 200, '\n' );
}

Game::Game(){
  m_board = new Board();
  m_player_x = new Player();
  m_player_o = new Player();
}

Game::~Game(){
  delete m_board;
  delete m_player_x;
  delete m_player_o;
}

void Game::play(){
  bool playing = true;
  
  while (playing)
  {
    Player *current_player = m_player_x;
    Board::Play player_num = Board::X;
    bool game_over = false;
    while (!game_over)
    {
      //Clear the screen before we begin the output
      ClearScreen();

      display_header();
      display_board();

      std::cout << "choose where to go: ";

      int input;

      std::cin >> input;

      char winner = m_board->set(input - 1, player_num);

      if(winner == 'X'){
        m_player_x->add_win();
        m_player_o->add_loss();
        game_over = true;
        std::cout << "X wins!" << std::endl;
      }
      else if(winner == 'O'){
        m_player_o->add_win();
        m_player_x->add_loss();
        game_over = true;
        std::cout << "O wins!" << std::endl;
      }

      if(game_over){
        m_board->reset();
        std::string res;
        std::cout << "Play again? y/n ";
        std::cin >> res;
        if(res.compare("y") != 0){
          playing = false;
        }
      }
      else{
        if(player_num == Board::X){
          current_player = m_player_o;
          player_num = Board::O;
        }
        else{
          current_player = m_player_x;
          player_num = Board::X;
        }
      }

    }
    
  }
  
}

void Game::display_board(){

  std::string* board_strings = new std::string[9];

  for (int i = 0; i < 9; i++)
  {
    int val = m_board->get(i);
    if(val == Board::X){
      board_strings[i] = "X";
    }
    else if(val == Board::O){
      board_strings[i] = "O";
    }
    else{
      board_strings[i] = std::to_string(val);
    }
  }

  std::cout << "  " << " " << "  |  " << " " << "  |  " << " " << "  " << std::endl;
  std::cout << "  " << board_strings[0] << "  |  " << board_strings[1] << "  |  " << board_strings[2] << "  " << std::endl;
  std::cout << "  " << " " << "  |  " << " " << "  |  " << " " << "  " << std::endl;
  std::cout << "-----+-----+-----" << std::endl;
  std::cout << "  " << " " << "  |  " << " " << "  |  " << " " << "  " << std::endl;
  std::cout << "  " << board_strings[3] << "  |  " << board_strings[4] << "  |  " << board_strings[5] << "  " << std::endl;
  std::cout << "  " << " " << "  |  " << " " << "  |  " << " " << "  " << std::endl;
  std::cout << "-----+-----+-----" << std::endl;
  std::cout << "  " << " " << "  |  " << " " << "  |  " << " " << "  " << std::endl;
  std::cout << "  " << board_strings[6] << "  |  " << board_strings[7] << "  |  " << board_strings[8] << "  " << std::endl;
  std::cout << "  " << " " << "  |  " << " " << "  |  " << " " << "  " << std::endl;
  
}

void Game::display_header(){
  std::cout << "-----------------" << std::endl;
  std::cout << "pX " << m_player_x->get_wins() << "/" << m_player_x->get_losses() << " pO " << m_player_o->get_wins() << "/" << m_player_o->get_losses() << std::endl;
  std::cout << "-----------------" << std::endl;
}
