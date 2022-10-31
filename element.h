//
// Created by angel on 2022-09-23.
//

#ifndef SNAKE_ELEMENT_H
#define SNAKE_ELEMENT_H

#include <QPoint>

class Element {
public:
    Element() = delete;
    explicit Element(QPoint p);
    QPoint getPos(){ return pos; };
    void setPos(QPoint p){ pos = p; };
    virtual ~Element() = default;
private:
    QPoint pos;
};


#endif //SNAKE_ELEMENT_H
