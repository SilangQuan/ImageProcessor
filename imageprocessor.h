#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <QColor>
#include <QImage>

class ImageProcessor
{
public:
    ImageProcessor();
    ~ImageProcessor();

    QImage* greyScale(QImage* origin);
    QImage* brightness(int delta, QImage* origin);
};

#endif // IMAGEPROCESSOR_H
