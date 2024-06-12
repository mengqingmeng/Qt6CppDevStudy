#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

class MyGraphicsView : public QGraphicsView
{
public:
    explicit MyGraphicsView(QWidget* parent = nullptr);

private:
    QGraphicsScene* m_scene;
    QGraphicsItemGroup* m_group1;
    QGraphicsItemGroup* m_group2;

    QTimer* m_timer;

    void resizeEvent(QResizeEvent* event);

    void deleteItemsFromGroup(QGraphicsItemGroup* group);

private slots:
    void slotAlarmTimer();
};

#endif // MYGRAPHICSVIEW_H
