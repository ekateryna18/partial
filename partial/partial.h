#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_partial.h"

class partial : public QMainWindow
{
    Q_OBJECT

public:
    partial(QWidget *parent = Q_NULLPTR);

private:
    Ui::partialClass ui;
};
