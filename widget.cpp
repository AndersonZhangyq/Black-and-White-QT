#pragma execution_character_set("utf-8")

#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),vs_computer(true),wanted_depth(2),game_over(false)
{
    ui->setupUi(this);

    QMessageBox::information(NULL,tr("游戏提示"),tr("The default mode is to play with the computer!"));

    Config = new Board();

    cell = new QButtonGroup(this);
    {
        cell->addButton(ui->pushButton_11,11);
        cell->addButton(ui->pushButton_12,12);
        cell->addButton(ui->pushButton_13,13);
        cell->addButton(ui->pushButton_14,14);
        cell->addButton(ui->pushButton_15,15);
        cell->addButton(ui->pushButton_16,16);
        cell->addButton(ui->pushButton_17,17);
        cell->addButton(ui->pushButton_18,18);
        cell->addButton(ui->pushButton_21,21);
        cell->addButton(ui->pushButton_22,22);
        cell->addButton(ui->pushButton_23,23);
        cell->addButton(ui->pushButton_24,24);
        cell->addButton(ui->pushButton_25,25);
        cell->addButton(ui->pushButton_26,26);
        cell->addButton(ui->pushButton_27,27);
        cell->addButton(ui->pushButton_28,28);
        cell->addButton(ui->pushButton_31,31);
        cell->addButton(ui->pushButton_32,32);
        cell->addButton(ui->pushButton_33,33);
        cell->addButton(ui->pushButton_34,34);
        cell->addButton(ui->pushButton_35,35);
        cell->addButton(ui->pushButton_36,36);
        cell->addButton(ui->pushButton_37,37);
        cell->addButton(ui->pushButton_38,38);
        cell->addButton(ui->pushButton_41,41);
        cell->addButton(ui->pushButton_42,42);
        cell->addButton(ui->pushButton_43,43);
        cell->addButton(ui->pushButton_44,44);
        cell->addButton(ui->pushButton_45,45);
        cell->addButton(ui->pushButton_46,46);
        cell->addButton(ui->pushButton_47,47);
        cell->addButton(ui->pushButton_48,48);
        cell->addButton(ui->pushButton_51,51);
        cell->addButton(ui->pushButton_52,52);
        cell->addButton(ui->pushButton_53,53);
        cell->addButton(ui->pushButton_54,54);
        cell->addButton(ui->pushButton_55,55);
        cell->addButton(ui->pushButton_56,56);
        cell->addButton(ui->pushButton_57,57);
        cell->addButton(ui->pushButton_58,58);
        cell->addButton(ui->pushButton_61,61);
        cell->addButton(ui->pushButton_62,62);
        cell->addButton(ui->pushButton_63,63);
        cell->addButton(ui->pushButton_64,64);
        cell->addButton(ui->pushButton_65,65);
        cell->addButton(ui->pushButton_66,66);
        cell->addButton(ui->pushButton_67,67);
        cell->addButton(ui->pushButton_68,68);
        cell->addButton(ui->pushButton_71,71);
        cell->addButton(ui->pushButton_72,72);
        cell->addButton(ui->pushButton_73,73);
        cell->addButton(ui->pushButton_74,74);
        cell->addButton(ui->pushButton_75,75);
        cell->addButton(ui->pushButton_76,76);
        cell->addButton(ui->pushButton_77,77);
        cell->addButton(ui->pushButton_78,78);
        cell->addButton(ui->pushButton_81,81);
        cell->addButton(ui->pushButton_82,82);
        cell->addButton(ui->pushButton_83,83);
        cell->addButton(ui->pushButton_84,84);
        cell->addButton(ui->pushButton_85,85);
        cell->addButton(ui->pushButton_86,86);
        cell->addButton(ui->pushButton_87,87);
        cell->addButton(ui->pushButton_88,88);
    }

    {
        connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_21,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_22,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_23,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_24,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_25,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_26,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_27,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_28,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_31,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_32,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_33,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_34,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_35,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_36,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_37,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_38,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_41,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_42,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_43,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_44,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_45,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_46,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_47,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_48,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_51,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_52,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_53,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_54,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_55,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_56,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_57,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_58,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_61,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_62,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_63,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_64,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_65,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_66,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_67,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_68,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_71,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_72,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_73,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_74,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_75,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_76,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_77,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_78,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_81,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_82,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_83,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_84,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_85,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_86,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_87,SIGNAL(clicked()),this,SLOT(SetMove()));
        connect(ui->pushButton_88,SIGNAL(clicked()),this,SLOT(SetMove()));
    }

    connect(this,SIGNAL(Game_over()),this,SLOT(Show_Winner()));
    connect(this,SIGNAL(Turn_to_computer(bool)),this,SLOT(Computer_move(bool)));
    Change();
    ui->lineEditShowPlayer->setText("Player");
    ui->pushButtonVC->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

int Widget::Look_ahead(Board &game, Move &recommanded, int depth)
{
    if (game.Done() || depth <= 0)
        return game.Evaluate();
    std::stack<Move> next_step;
    bool moved = game.Legal_move(next_step);
    int value, best_value = game.Worst_case();
    while (!next_step.empty())
    {
        Move do_it, replay;
        do_it = next_step.top();
        Board new_game = game;
        new_game.Play(do_it);
        //new_game.Print();
        value = Look_ahead(new_game,replay, depth - 1);
        if (game.Better(value,best_value)) {
            best_value = value;
            recommanded = do_it;
        }
        next_step.pop();
    }
    if (!moved)
        game.Skip();
    return best_value;
}

void Widget::SetMove()
{
    if (game_over) return;
    if (Config->Done())
    {
        emit Game_over();
        return;
    }
    int clicked = cell->id(dynamic_cast<QPushButton*>(sender()));
    Move player(clicked / 10, clicked % 10);
    if (Config->IsValid(player) != legal)
    {
        QMessageBox::warning(this,tr("Illegal"),tr("The step is invalid! Please try again."));
        return;
    }
    Config->Play(player);
    Change();
    if (vs_computer)
        ui->lineEditShowPlayer->setText("Computer");
    else if (ui->lineEditShowPlayer->text() == "Player 1")
        ui->lineEditShowPlayer->setText("Player 2");
    else
        ui->lineEditShowPlayer->setText("Player 1");
}

void Widget::Show_Winner()
{
    if (game_over) return;
    if (vs_computer)
    {
        if (Config->Winner() == 1) QMessageBox::information(this,tr("游戏提示"),tr("Game over with computer win"));
        else if (Config->Winner() == 2)  QMessageBox::information(this,tr("游戏提示"),tr("Game over with you win"));
        else  QMessageBox::information(this,tr("游戏提示"),tr("Game over with a draw"));
    }
    else
    {
        if (Config->Winner() == 1) QMessageBox::information(this,tr("游戏提示"),tr("Game over with Player 2 win"));
        else if (Config->Winner() == 2)  QMessageBox::information(this,tr("游戏提示"),tr("Game over with Player 1 win"));
        else  QMessageBox::information(this,tr("游戏提示"),tr("Game over with a draw"));
    }
    game_over = true;
}

void Widget::Computer_move(bool skip)
{
    if (Config->Done())
    {
        emit Game_over();
        return;
    }
    Move recommended;
    Look_ahead(*Config, recommended, wanted_depth);
    Config->Play(recommended);
    Change();
    if (!skip)
        ui->lineEditShowPlayer->setText("Player");
    else
        on_lineEditShowPlayer_textChanged("Player");
}

void Widget::Change()
{
    int get[10][10];
    Config->GetBoard(get);
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (get[i][j] == 1)
                cell->button(10*i+j)->setStyleSheet("background-color: rgb(255, 255, 255);");
            if (get[i][j] == 2)
                cell->button(10*i+j)->setStyleSheet("background-color: rgb(0, 0, 0);");
            if (get[i][j] == 0)
                cell->button(10*i+j)->setStyleSheet("background-color: rgb(255, 252, 207);");
        }
    }
    if (Config->Done())
    {
        emit Game_over();
        return;
    }
}

void Widget::ShowHint(std::stack<Move> can)
{
    while(!can.empty())
    {
        Move* temp = new Move(can.top());
        cell->button(10*temp->x+temp->y)->setStyleSheet("");
        can.pop();
        delete temp;
    }
}

void Widget::on_pushButtonRestart_clicked()
{
    QMessageBox::StandardButton restart = QMessageBox::information(this,tr("游戏提示"),tr("Are you sure to RESTART the game?"),
                                                                   QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if (restart == QMessageBox::Yes)
    {
        delete Config;
        Config = new Board();
        Change();
    }
    if (vs_computer)
    {
        if (ui->lineEditShowPlayer->text() == "Player")
            on_lineEditShowPlayer_textChanged("Player");
        else
            ui->lineEditShowPlayer->setText("Player");
    }
    else
    {
        if (ui->lineEditShowPlayer->text() == "Player 1")
            on_lineEditShowPlayer_textChanged("Player 1");
        else
            ui->lineEditShowPlayer->setText("Player 1");
    }
    game_over = false;
}

void Widget::on_pushButtonVP_clicked()
{
    if (vs_computer == true)
    {
        delete Config;
        Config = new Board();
        Change();
        vs_computer = false;
        ui->labelPlayer->setText("Player 1");
        ui->labelComputer->setText("Player 2");
        ui->lineEditShowPlayer->setText("Player 1");
        ui->pushButtonVP->setEnabled(false);
        ui->pushButtonVC->setEnabled(true);
        ui->comboBox->setEnabled(false);
        game_over = false;
    }
}

void Widget::on_pushButtonVC_clicked()
{
    if (vs_computer == false)
    {
        vs_computer = true;
        delete Config;
        Config = new Board();
        Change();
        ui->labelPlayer->setText("Player");
        ui->labelComputer->setText("Computer");
        ui->lineEditShowPlayer->setText("Player");
        ui->pushButtonVP->setEnabled(true);
        ui->pushButtonVC->setEnabled(false);
        ui->comboBox->setEnabled(true);
        game_over = false;
    }
}

void Widget::on_lineEditShowPlayer_textChanged(const QString &arg1)
{
    if (game_over)  return;
    if (arg1 == "Computer")
        Computer_move(false);
    else
    {
        std::stack<Move> can;
        Config->Legal_move(can);
        if (can.size() == 0)
        {
            QMessageBox::information(this,tr("游戏提示"),
                                     tr("Unfortunatly, you have no place to go. Your turn is skipped!"));
            Config->Skip();
            if (vs_computer)
                emit Turn_to_computer(true);
            return;
        }
        ShowHint(can);
    }
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    wanted_depth = (index == 0? 2: index + 3);
    on_pushButtonRestart_clicked();
}

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this,tr("About"),tr("Name: Black & White\nVersion: v1.1\nContact:zhangyiqing818@sina.com"));
}
