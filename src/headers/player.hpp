#pragma once

class Player{
  public:
    Player();

    /**
     * @brief Get the number of wins for this player
     * 
     * @return int 
     */
    int get_wins();

    /**
     * @brief Get the number of losses for this player
     * 
     * @return int 
     */
    int get_losses();

    /**
     * @brief Add a win for this player
     * 
     */
    void add_win();

    /**
     * @brief Add a loss for this player
     * 
     */
    void add_loss();

    /**
     * @brief Reset this players wins and losses to 0
     * 
     */
    void reset();
  private:
    int m_wins;
    int m_losses;
};