#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    int points;
    int amountOfHits;

public:
    Player(int points = 0, int amountOfHits = 0){
        this->points = points;
        this->amountOfHits = amountOfHits;
    };

    void setPoints(int newPoints);
    void setAmountOfHits(int newAmountOfHits);
    void addPoints(int newPoints);
    void addHit(int newHit);

    int getPoints();
    int getAmountOfHits();

};

#endif // PLAYER_H
