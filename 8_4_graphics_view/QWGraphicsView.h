#ifndef QWGRAPHICSVIEW_H
#define QWGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QMouseEvent>

class QWGraphicsView : public QGraphicsView
{
   Q_OBJECT
public:
    QWGraphicsView(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);
};

#endif // QWGRAPHICSVIEW_H
