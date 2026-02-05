#ifndef QTPNGREADER_H
#define QTPNGREADER_H

#include <QString>
#include <QImage>
#include "3rdinclude/packer/data/data.hpp"
#include "3rdinclude/packer/core/VImage.hpp"
#include "3rdinclude/packer/impl/ImageReader.hpp"

using packer::ImageReader;
using packer::VImage;
using packer::RGBA;

class QtpngReader : public ImageReader
{
public:
    QtpngReader(const QString &path);
    
protected:
    virtual void initialize(int &width, int &height) override;
    virtual void readAllRGB(RGBA *buffer) override;            
    virtual void finalize() override;
    
private:
    QImage  m_img;
    QString m_path;
};

#endif