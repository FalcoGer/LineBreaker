#pragma once
#include "RenderItem.h"
#include "Snake.h"
#include <vector>
#include <iostream>

using namespace std;

class Snake;

class GameBoard :
    public RenderItem
{
public:
    const unsigned int OFFSET_TOP = 48;
    const unsigned int OFFSET_LEFT = 16;
    const unsigned int CELL_WIDTH = 8;
    const unsigned int CELL_HEIGHT = 8;

    GameBoard(unsigned int width, unsigned int height);
    ~GameBoard();

    // Geerbt über RenderItem
    void draw(sf::RenderWindow & window);
    void update(sf::Int64 deltaTime);

    inline unsigned int getWidth() { return width; }
    inline unsigned int getHeight() { return height; }

    inline void setOccupied(unsigned int x, unsigned int y, bool occupied) { boardOccupations[x]->at(y) = occupied; }
private:
    vector<Snake*> snakes;
    vector<vector<bool>*> boardOccupations;

    sf::VertexArray gameBoardCornerSeperator;

    unsigned int width;
    unsigned int height;
};

