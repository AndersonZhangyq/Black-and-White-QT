#ifndef WIDGET_H
#define WIDGET_H

#include <Board.h>

#include <stack>
#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void Play_the_Game();
    int Look_ahead(Board & game, Move & recommanded, int depth = 2);

signals:
    void Game_over();
    void Turn_to_computer(bool skip);

public slots:
    void Show_Winner();
    void Computer_move(bool skip);

private slots:
    void SetMove();

    void on_pushButtonVC_clicked();

    void on_pushButtonVP_clicked();

    void on_pushButtonRestart_clicked();

    void on_lineEditShowPlayer_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    Board* Config;

    void Change();
    void ShowHint(std::stack<Move> can);
    QButtonGroup* cell;
    int wanted_depth;
    bool vs_computer;
    bool game_over;
};

#endif // WIDGET_H
