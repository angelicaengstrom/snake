//
// Created by angel on 2022-09-22.
//

#ifndef SNAKE_WINDOW_H
#define SNAKE_WINDOW_H

#include <QWidget>
#include <QObject>
#include <QGridLayout>
#include <QPushButton>
#include "board.h"
#include "ui_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget {
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;
//private slots:
private:
    QPushButton* design_button(QPushButton* button);
    Ui::Window *ui;
    Board* board;
};


#endif //SNAKE_WINDOW_H
