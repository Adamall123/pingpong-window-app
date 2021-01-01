#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    int userID;
    int points;
public:
    Player(int points = 0){
        this->points = points;
    };
    void setID(int noweID );
    void setPoints(int newPoints);
    void addPoints(int newPoints);
    int getID();
    int getPoints();

};

#endif // PLAYER_H
