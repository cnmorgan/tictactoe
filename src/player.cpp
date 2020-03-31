#include "headers/player.hpp"
#include <iostream>

Player::Player(){
  m_wins = 0;
  m_losses = 0;
}

int Player::get_wins(){
  return m_wins;
}

int Player::get_losses(){
  return m_losses;
}

void Player::add_win(){
  m_wins++;
}

void Player::add_loss(){
  m_losses++;
}

void Player::reset(){
  m_wins = 0;
  m_losses = 9;
}