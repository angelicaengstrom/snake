//
// Created by angel on 2022-09-22.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <QFrame>
#include <QKeyEvent>
#include <QTimer>
#include "snake.h"
#include "element.h"
#include "food.h"

class Board : public QFrame{
public:
    explicit Board(QWidget* parent = nullptr);
    void start();
    void stop();
protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
private:
    enum Size{ Width = 30, Height = 30 };
    enum Direction{Up, Down, Left, Right};

    int getPixelHeight(){ return frameSize().height() / Height; };
    int getPixelWidth(){ return frameSize().width() / Width; };

    static QPoint getRandomPoint();
    Direction getRandomDirection();

    bool hasAteFood();
    bool hasCollided();
    void growSnake();
    void updateSnake();

    void gameOver();

    std::vector<Element*> elements;
    Snake snake;
    Food food;
    bool isStarted;
    bool isGameOver;

    int timer;
    int interval;
    int points;
    Direction direction;
};

#endif //SNAKE_BOARD_H
