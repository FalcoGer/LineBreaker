#include "GameBoard.h"



GameBoard::GameBoard(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;

    const sf::Color color = sf::Color(0x30, 0x00, 0x00, 0xFF);
    gameBoardCornerSeperator.setPrimitiveType(sf::PrimitiveType::Lines);

    for (unsigned int x = 0; x < width; x++)
    {
        for (unsigned int y = 0; y < height; y++)
        {
            gameBoardCornerSeperator.append(sf::Vertex(
                sf::Vector2f(
                    static_cast<float>((CELL_WIDTH * x - 2) + OFFSET_LEFT),
                    static_cast<float>(CELL_HEIGHT * y + OFFSET_TOP)
                ),
                color));
            gameBoardCornerSeperator.append(sf::Vertex(
                sf::Vector2f(
                    static_cast<float>((CELL_WIDTH * x + 2) + OFFSET_LEFT),
                    static_cast<float>(CELL_HEIGHT * y + OFFSET_TOP)
                ),
                color));
            gameBoardCornerSeperator.append(sf::Vertex(
                sf::Vector2f(
                    static_cast<float>((CELL_WIDTH * x) + OFFSET_LEFT),
                    static_cast<float>((CELL_HEIGHT * y - 2) + OFFSET_TOP)
                ),
                color));
            gameBoardCornerSeperator.append(sf::Vertex(
                sf::Vector2f(
                    static_cast<float>((CELL_WIDTH * x) + OFFSET_LEFT),
                    static_cast<float>((CELL_HEIGHT * y + 2) + OFFSET_TOP)
                ),
                color));
        }
    }

    for (unsigned int x = 0; x < width; x++)
    {
        boardOccupations.push_back(new vector<bool>);
        for (unsigned int y = 0; y < height; y++)
        {
            boardOccupations[x]->push_back(false);
        }
    }
}


GameBoard::~GameBoard()
{
#if _DEBUG
    printf("GameBoard @ %p destroy\n", this);
#endif
    for (unsigned int x = 0; x < width; x++)
    {
        delete(boardOccupations[x]);
    }
    boardOccupations.clear();
}

void GameBoard::draw(sf::RenderWindow & window)
{
    window.draw(gameBoardCornerSeperator);
    for (auto& snake : snakes)
    {
        snake->draw(window);
    }
}

void GameBoard::update(sf::Int64 deltaTime)
{
    for (auto& snake : snakes)
    {
        snake->update(deltaTime);
    }
}
