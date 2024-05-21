#include "Widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    this->resize(600,400);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 反锯齿设置

    // 原始视口 宽、高
    int sourceViewPortWidth = width();
    int sourceViewPortHeight = height();

    int side = qMin(sourceViewPortHeight,sourceViewPortWidth);

    // 中间正方形区域
    QRect rect((sourceViewPortWidth - side) / 2, (sourceViewPortHeight - side) / 2,side,side); // 使用物理坐标，原点在左上角
    painter.drawRect(rect);
    painter.setViewport(rect); // 设置视口
    painter.setWindow(-100,-100,200,200); // 设置窗口，逻辑宽高是200，使用的是逻辑坐标，原点在中心。

    // 设置画笔样式
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap); // 端点样式
    pen.setJoinStyle(Qt::BevelJoin); // 连接样式
    painter.setPen(pen);

    for(int i=0;i<36;++i){
        painter.drawEllipse(QPoint(50,0),50,50);
        painter.rotate(10); // 旋转窗口
    }

    event->accept();
}

