#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include <QBrush>
#include <QPaintEvent>

#include "imageprocessor.h"

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);
    ~ImageWidget();
    void load(QString &path);

signals:

public slots:
    void greyScale();
    void revokeOrigin();
    void brightness();

private:
    QImage m_originalImage;
    QImage m_processedImage;
    QPixmap m_pixmap;
    ImageProcessor *processor;

protected:
    void paintEvent(QPaintEvent* event);
};

#endif // IMAGEWIDGET_H
