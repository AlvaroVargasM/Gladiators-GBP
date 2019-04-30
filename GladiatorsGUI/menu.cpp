#include "menu.h"
#include "ui_menu.h"
#include "display.h"

/**
 * @brief Menu default constructor. Initialize it's parent widget to null.
 * @param parent Parent QWidget.
 */
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/menu_bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

/**
 * @brief Menu default destructor.
 */
Menu::~Menu()
{
    delete ui;
}

/**
 * @brief Method called when the user clicks "Start game" option.
 *        It pops a Display instance to the user.
 */
void Menu::on_startButton_clicked()
{
    this->hide();
    Display *display = new Display();
    display->show();

}

/**
 * @brief Method called when the user clicks "Exit" option.
 *        It closes the application.
 */
void Menu::on_exitButton_clicked()
{
    this->close();
}
