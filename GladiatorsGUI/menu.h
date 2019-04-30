#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class Menu;
}

/**
 * @brief First menu window displayed to the user.
 *        Contains 2 options: start game and exit.
 *
 */
class Menu : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Menu default constructor. Initialize it's parent widget to null.
     * @param parent Parent QWidget.
     */
    explicit Menu(QWidget *parent = nullptr);

    /**
     * @brief Menu default destructor.
     */
    ~Menu();

private slots:
    /**
     * @brief Method called when the user clicks "Start game" option.
     *        It pops a Display instance to the user.
     */
    void on_startButton_clicked();

    /**
     * @brief Method called when the user clicks "Exit" option.
     *        It closes the application.
     */
    void on_exitButton_clicked();

private:
    Ui::Menu *ui; /**< Qt form of Menu class. Used to arrange the visual objects. */
};

#endif // MENU_H
