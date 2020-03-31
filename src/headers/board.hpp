#pragma once

#include <string>

class Board{


  public:
    enum Play{
      X = -1,
      O = 0
    };

    Board();

    ~Board();
    /**
     * @brief Checks if the board has a winner
     * 
     * @return char 'x' if x wins or 'o' of o wins. Otherwise returns a space ' ' 
     */
    char winner();

    /**
     * @brief Gets the value of the board at a position
     * 
     * @param pos the position to get
     * @return int the value at pos
     */
    int get(int pos);

    /**
     * @brief Sets the value of the board at a given position
     * 
     * @param pos position to set
     * @param play the value to set
     */
    char set(int pos, Board::Play play);

    void reset();
    
  private:
    int m_board[9];
    int check_rows();
    int check_cols();
    int check_diag();


};