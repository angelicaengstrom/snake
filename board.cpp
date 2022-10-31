//
// Created by angel on 2022-09-22.
//

#include <QPainter>
#include <QPainterPath>
#include "board.h"

Board::Board(QWidget *parent): snake(getRandomPoint()), food(getRandomPoint()){
    setFrameShape(QFrame::NoFrame);
    setFocusPolicy(Qt::StrongFocus);
}

void Board::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);
    if(!isGameOver) {
        for (auto e: elements) {
            painter.setPen(QColor("#BACDB0"));
            QRect pixel = QRect(e->getPos().x() * getPixelWidth(), e->getPos().y() * getPixelHeight(), getPixelWidth(),
                                getPixelHeight());
            auto s = dynamic_cast<Snake *>(e);
            if (s != nullptr) {
                painter.fillRect(pixel, QColor("#729B79"));
            } else {
                painter.fillRect(pixel, Qt::red);
            }
            painter.drawRect(pixel);
        }
    }else{
        painter.setPen(QColor("#729B79"));
        painter.setFont(QFont("Arial", 30));
        painter.drawText(rect(), Qt::AlignCenter, "GAME OVER");
    }
}

void Board::keyPressEvent(QKeyEvent *event) {
    if(isStarted) {
        switch (event->key()) {
            case Qt::Key_W:
                if(direction != Down) {
                    direction = Up;
                }
                break;
            case Qt::Key_A:
                if(direction != Right) {
                    direction = Left;
                }
                break;
            case Qt::Key_S:
                if(direction != Up) {
                    direction = Down;
                }
                break;
            case Qt::Key_D:
                if(direction != Left) {
                    direction = Right;
                }
                break;
            case Qt::Key_Up:
                break;
            case Qt::Key_Down:
                break;
            case Qt::Key_Left:
                break;
            case Qt::Key_Right:
                break;
        }
    }else{
        QWidget::keyPressEvent(event);
    }

}

QPoint Board::getRandomPoint() {
    QPoint point(rand() % Width, rand() % Height);
    return point;
}

void Board::stop() {
    isStarted = false;
    elements.clear();
    killTimer(timer);
}

void Board::start() {
    isGameOver = false;
    isStarted = true;
    snake.setPos(getRandomPoint());
    food.setPos(getRandomPoint());
    elements.push_back(&food);
    elements.push_back(&snake);

    interval = 300;
    timer = startTimer(interval);
    points = 0;
    direction = getRandomDirection();
}

void Board::timerEvent(QTimerEvent *event) {
    updateSnake();

    switch(direction){
        case Up:
            if(snake.getPos().y() != 0){
                snake.setPos(QPoint(snake.getPos().x(), snake.getPos().y() - 1));
            }else{
                gameOver();
            }
            update();
            break;
        case Down:
            if(snake.getPos().y() != Height) {
                snake.setPos(QPoint(snake.getPos().x(), snake.getPos().y() + 1));
            }else{
                gameOver();
            }
            update();
            break;
        case Right:
            if(snake.getPos().x() != Width) {
                snake.setPos(QPoint(snake.getPos().x() + 1, snake.getPos().y()));
            }else{
                gameOver();
            }
            update();
            break;
        case Left:
            if(snake.getPos().x() != 0) {
                snake.setPos(QPoint(snake.getPos().x() - 1, snake.getPos().y()));
            }else{
                gameOver();
            }
            update();
            break;
    }

    if(hasCollided()){
        gameOver();
    }

    if(hasAteFood()){
        killTimer(timer);
        interval = interval / 1.1;
        timer = startTimer(interval);
        food.setPos(getRandomPoint());
        growSnake();
    }
    QObject::timerEvent(event);
}

Board::Direction Board::getRandomDirection() {
    return (Direction)(rand() % 4);
}

bool Board::hasAteFood(){
    return food.getPos() == snake.getPos();
}

void Board::growSnake() {
    auto last_s = dynamic_cast<Snake*>(elements.back());
    if(last_s != nullptr) {
        Snake *new_s = new Snake(last_s->getPos());
        elements.push_back(new_s);
    }
}

void Board::updateSnake() {
    for(int i = elements.size() - 1; i > 1; i--){
        auto s = dynamic_cast<Snake*>(elements[i]);
        if(s != nullptr) {
            elements[i]->setPos(elements[i - 1]->getPos());
        }
    }
}

bool Board::hasCollided() {
    for(int i = elements.size() - 1; i > 1; i--){
        return elements[i]->getPos() == snake.getPos();
    }
    return false;
}

void Board::gameOver() {
    isGameOver = true;
}
