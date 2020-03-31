#include "headers/board.hpp"

Board::Board() : m_board {1, 2, 3, 4, 5, 6, 7, 8, 9}{
  
}

Board::~Board(){
}

int Board::check_rows(){
  if(m_board[0] == m_board[1] && m_board[1] == m_board[2]){
    return m_board[0];
  }
    
  if(m_board[3] == m_board[4] && m_board[4] == m_board[5]){
    return m_board[3];
  }
  

  if(m_board[6] == m_board[7] && m_board[7] == m_board[8]){
    return m_board[6];
  }

  return 1;
}

int Board::check_cols(){
  if(m_board[0] == m_board[3] && m_board[3] == m_board[6]){
    return m_board[0];
  }
    
  if(m_board[1] == m_board[4] && m_board[4] == m_board[7]){
    return m_board[1];
  }

  if(m_board[2] == m_board[5] && m_board[5] == m_board[8]){
    return m_board[2];
  }

  return 1;
}

int Board::check_diag(){
  if(m_board[0] == m_board[4] && m_board[4] == m_board[8]){
    return m_board[0];
  }
    
  if(m_board[2] == m_board[4] && m_board[4] == m_board[6]){
    return m_board[2];
  }

  return 1;
}

char Board::winner(){
  int winner = check_rows();
  if(winner > 0){
    winner = check_cols();
  }
  if(winner > 0){
    winner = check_diag();
  }

  char c;

  switch (winner)
  {
  case Board::X:
    c = 'X';
    break;
  
  case Board::O:
    c = 'O';
    break;

  default:
    c = ' ';
    break;
  }

  return c;
}

int Board::get(int pos){
  if(pos < 0 || pos > 8){
    throw "Index out of bounds";
  }

  return m_board[pos];
}

char Board::set(int pos, Board::Play play){
  if(pos < 0 || pos > 8){
    throw "Index out of bounds";
  }

  m_board[pos] = play;
  return winner();
}

void Board::reset(){

  for (int i = 0; i < 9; i++)
  {
    m_board[i] = i + 1;
  }
}