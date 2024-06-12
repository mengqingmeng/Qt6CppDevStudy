#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewCordLabel = new QLabel("View坐标：");
    viewCordLabel->setMinimumWidth(150);
    sceneCordLabel = new QLabel("Scene坐标：");
    sceneCordLabel->setMinimumWidth(150);
    itemCordLabel = new QLabel("Item坐标：");
    itemCordLabel->setMinimumWidth(150);

    ui->statusbar->addWidget(viewCordLabel);
    ui->statusbar->addWidget(sceneCordLabel);
    ui->statusbar->addWidget(itemCordLabel);

    ui->graphicsView->setCursor(Qt::CrossCursor);// 十字形光标
    ui->graphicsView->setMouseTracking(true);   // 开启鼠标追踪
    ui->graphicsView->setDragMode(QWGraphicsView::RubberBandDrag); // 矩形选择框

    connect(ui->graphicsView,&QWGraphicsView::mouseMovePoint,this,[&](QPoint point){
        viewCordLabel->setText(QString::asprintf("View坐标：%d,%d",point.x(),point.y()));

        QPointF scenePoint = ui->graphicsView->mapToScene(point);
        sceneCordLabel->setText(QString::asprintf("Scene坐标：%.0f,%.0f",scenePoint.x(),scenePoint.y()));
    });

    connect(ui->graphicsView,&QWGraphicsView::mouseClicked,this,[&](QPoint point){
        // 场景坐标
        QPointF scenePoint = ui->graphicsView->mapToScene(point);
        QGraphicsItem* item = nullptr;
        item = scene->itemAt(scenePoint,ui->graphicsView->transform());
        if(item){
            QPointF itemPoint = item->mapFromScene(scenePoint);
            itemCordLabel->setText(QString::asprintf("Item坐标：%.0f,%.0f",itemPoint.x(),itemPoint.y()));
        }
    });

    initGraphicsSystem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGraphicsSystem()
{
    QRectF rect(-200,-100,400,200);
    // 场景Scene
    scene = new QGraphicsScene(rect);

    // 设置场景
    ui->graphicsView->setScene(scene);

    // 画一个矩形框，和场景一样大
    QGraphicsRectItem* item = new QGraphicsRectItem(rect);

    // 设置矩形可选中
    item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

    QPen pen(Qt::red,2);
    item->setPen(pen);

    // 将矩形添加至场景中
    scene->addItem(item);

    // 椭圆
    QGraphicsEllipseItem* item2 = new QGraphicsEllipseItem(-100,-50,200,100);
    item2->setBrush(QBrush(Qt::blue));
    item2->setPos(0,0);
    item2->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    scene->addItem(item2);

    // 圆形
    QGraphicsEllipseItem* item3 = new QGraphicsEllipseItem(-50,-50,100,100);
    item3->setPos(rect.bottomRight());
    item3->setBrush(QBrush(Qt::green));
    item3->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    scene->addItem(item3);


    // 画出文本
    QGraphicsTextItem* textItem = new QGraphicsTextItem();
    textItem->setPlainText("123");
    textItem->setPos(rect.bottomLeft());
    scene->addItem(textItem);

    scene->clearSelection();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QString str = QString::asprintf("Graphics View坐标，左上角是（0，0），宽度=%d,高度=%d",ui->graphicsView->width(),ui->graphicsView->height());
    ui->viewSizeLabel->setText(str);

    QRectF sceneRect = ui->graphicsView->sceneRect();
    QString str2 = QString::asprintf("QGraphicsView::sceneRect=(Left,Top,Width,Height)""=%.0f,%.0f,%.0f,%.0f",
                                     sceneRect.left(),sceneRect.top(),sceneRect.width(),sceneRect.height());
    ui->sceneSizeLabel->setText(str2);
}

