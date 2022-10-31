//
// Created by angel on 2022-09-22.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <memory>
#include <cstddef>
#include "element.h"

class Snake: public Element {
public:
    explicit Snake(QPoint p);
    ~Snake() = default;
private:
};


#endif //SNAKE_SNAKE_H
