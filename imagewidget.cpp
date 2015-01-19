#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
    processor = new ImageProcessor();
}

ImageWidget::~ImageWidget()
{

}

void ImageWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush("#1e1e1e"));

    if(m_originalImage.isNull())
    {
        return;
    }

    m_pixmap = QPixmap::fromImage(m_processedImage);

    painter.setRenderHint(QPainter::Antialiasing, true);
    QSize pixSize = m_pixmap.size();

    QPoint topleft;
    topleft.setX((this->width() - pixSize.width()) / 2);
    topleft.setY((this->height() - pixSize.height()) / 2);

    painter.drawPixmap(topleft, m_pixmap.scaled(pixSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ImageWidget::load(QString &path)
{
    m_originalImage = QImage(path);
    m_processedImage = m_originalImage;
}

void ImageWidget::greyScale()
{
    QImage* image = processor->greyScale(&m_originalImage);
    m_processedImage = *image;
    this->update();
}

void ImageWidget::revokeOrigin()
{
    m_processedImage = m_originalImage;
    this->update();
}

void ImageWidget::brightness()
{
    int delta = 10;
    QImage* image = processor->brightness(delta, &m_processedImage);
    m_processedImage = *image;
    this->update();
}
