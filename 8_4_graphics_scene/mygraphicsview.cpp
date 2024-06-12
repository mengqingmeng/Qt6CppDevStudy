#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget* parent) : QGraphicsView(parent) {
    // 设置视图信息
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 禁用水平滚动
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 禁用垂直滚动

    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding); // 拉伸内容

    setMinimumHeight(100);
    setMinimumWidth(100);

    // 新建场景
    m_scene = new QGraphicsScene();
    this->setScene(m_scene);

    m_group1 = new QGraphicsItemGroup();
    m_group2 = new QGraphicsItemGroup();

    m_scene->addItem(m_group1);
    m_scene->addItem(m_group2);

    // 计时器
    m_timer = new QTimer();
    m_timer->setSingleShot(true);

    connect(m_timer,&QTimer::timeout,this,&MyGraphicsView::slotAlarmTimer);

    m_timer->start(50);
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    m_timer->start(50);
    QGraphicsView::resizeEvent(event);
}

void MyGraphicsView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    foreach( QGraphicsItem *item, m_scene->items(group->boundingRect())) {
        if(item->group() == group ) {
            delete item;
        }
    }
}

void MyGraphicsView::slotAlarmTimer(){

    // 清除后，重绘
    this->deleteItemsFromGroup(m_group1);
    this->deleteItemsFromGroup(m_group2);

    int width = this->width();
    int height = this->height();

    m_scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);

    // 画一个黑色矩形
    auto item1 = m_scene->addLine(20,20,width-20,20,penBlack);
    auto item2 = m_scene->addLine(width-20,20,width-20,height-20,penBlack);
    auto item3 = m_scene->addLine(width - 20,height - 20,20,height - 20,penBlack);
    auto item4 = m_scene->addLine(20,height-20,20,20,penBlack);

    m_group1->addToGroup(item1);
    m_group2->addToGroup(item2);
    m_group2->addToGroup(item3);
    m_group2->addToGroup(item4);

    // 画一个红色矩形
    int sideOfSquare = qMin(width,height) - 60;
    int centerOfWidgetX = width / 2;
    int centerOfWidgetY = height / 2;

    auto item5 = m_scene->addLine(centerOfWidgetX - sideOfSquare / 2,centerOfWidgetY - sideOfSquare/ 2,centerOfWidgetX + sideOfSquare/ 2,centerOfWidgetY - sideOfSquare/ 2,penRed);
    auto item6 = m_scene->addLine(centerOfWidgetX + sideOfSquare/ 2,centerOfWidgetY - sideOfSquare/ 2,centerOfWidgetX + sideOfSquare/ 2,centerOfWidgetY + sideOfSquare/ 2,penRed);
    auto item7 = m_scene->addLine(centerOfWidgetX + sideOfSquare/ 2,centerOfWidgetY + sideOfSquare/ 2,centerOfWidgetX - sideOfSquare/ 2,centerOfWidgetY + sideOfSquare/ 2,penRed);
    auto item8 = m_scene->addLine(centerOfWidgetX - sideOfSquare/ 2,centerOfWidgetY + sideOfSquare/ 2,centerOfWidgetX - sideOfSquare/ 2,centerOfWidgetY - sideOfSquare/ 2,penRed);
    m_group2->addToGroup(item5);
    m_group2->addToGroup(item6);
    m_group2->addToGroup(item7);
    m_group2->addToGroup(item8);

}
