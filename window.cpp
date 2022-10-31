//
// Created by angel on 2022-09-22.
//

#include "window.h"

Window::Window(QWidget *parent) :
        QWidget(parent), ui(new Ui::Window), board(new Board) {
    ui->setupUi(this);
    setFocusPolicy(Qt::NoFocus);

    QGridLayout* layout = new QGridLayout();
    QPalette* palette = new QPalette();
    palette->setColor(backgroundRole(), QColor("#729B79"));
    setPalette(*palette);


    QPushButton* startb = new QPushButton("&Start");
    QPushButton* cancelb = new QPushButton("&Cancel");

    layout->addWidget(design_button(startb), 2, 0, 3, 6);
    layout->addWidget(design_button(cancelb), 0, 0);

    layout->addWidget(board, 1, 0, 5, 5);
    board->setFocusPolicy(Qt::StrongFocus);

    board->hide();
    board->setStyleSheet("background-color: #BACDB0;");
    cancelb->hide();

    connect(startb, &QPushButton::released, this, [=](){
        startb->hide();

        cancelb->show();
        board->show();
        board->setFocus();
        board->start();

        setLayout(layout);
    });

    connect(cancelb, &QPushButton::released, this, [=](){
        board->stop();
        board->hide();
        cancelb->hide();

        startb->show();

        setLayout(layout);
    });

    setLayout(layout);
    setWindowTitle("Snake");

    setMinimumSize(600, 600);
    setMaximumSize(600, 600);

}

Window::~Window() {
    delete ui;
}

QPushButton *Window::design_button(QPushButton *button) {
    button->setCursor(Qt::PointingHandCursor);
    button->setStyleSheet("background-color: #BACDB0; border: none; color: #729B79; font-size: 18pt;");
    button->setFixedSize(QSize(575, 40));
    return button;
}
