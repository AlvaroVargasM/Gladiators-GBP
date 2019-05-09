#ifndef STATISTICS_H
#define STATISTICS_H

#include <QMainWindow>
#include <QtCharts/QLineSeries>
#include <QGridLayout>
#include "genericlinkedlist.h"
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Statistics;
}

/**
 * @brief Window that shows the game session statistics.
 *
 */
class Statistics : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Class default constructor.
     *
     * @param parent
     */
    explicit Statistics(QWidget *parent = nullptr);

    /**
     * @brief Sets the window's parent window.
     *
     * @param display Parent window.
     */
    void setParent(QMainWindow *display);

    /**
     * @brief Generate all the window charts.
     *
     */
    void generateCharts();

    /**
     * @brief Creates and returns a QLineSeries from the given info.
     *
     * @param list List containing the numerical data.
     * @param name Series name.
     * @param color Series line color.
     * @return QLineSeries A customized QLineSeries instance.
     */
    QLineSeries* getSeries(GenericLinkedList<int> *list,QString name,QColor color);

    /**
     * @brief Creates a chart from the given info.
     *
     * @param name Chart title.
     * @param generations Number of generations to be graphed.
     * @param data1 Set of data to be graphed.
     * @param data2  Set of data to be graphed.
     * @return QChart A customized graph.
     */
    QChart *createChart(QString name,int generations,QLineSeries *data1, QLineSeries *data2);

    /**
     * @brief Creates a chart from the given info.
     *
     * @param name Chart title.
     * @param generations Number of generations to be graphed.
     * @param data1 Set of data to be graphed.
     * @param data2 Set of data to be graphed.
     * @param data3 Set of data to be graphed.
     * @param data4 Set of data to be graphed.
     * @return QChart A customized graph.
     */
    QChart *createChart(QString name,int generations,QLineSeries *data1, QLineSeries *data2,QLineSeries *data3, QLineSeries *data4);

    /**
     * @brief Class destructor.
     */
    ~Statistics();

private:
    Ui::Statistics *ui; /**< Qt form of Display class. Used to arrange the visual objects.  */
    QMainWindow *display; /**< Qt parent window */
    QGridLayout *layout; /**< Qt window layout */

    public slots:
        /**
         * @brief Hides the current window and shows its parent.
         */
        void newGame();

        /**
         * @brief Closes the window.
         *
         */
        void exit();
};

#endif // STATISTICS_H
