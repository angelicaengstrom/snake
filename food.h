//
// Created by angel on 2022-09-23.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include "element.h"

class Food : public Element {
public:
    explicit Food(QPoint p);
    ~Food() = default;
};


#endif //SNAKE_FOOD_H
