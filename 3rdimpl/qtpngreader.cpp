#include <QImage>
#include <QImageReader>
#include "3rdimpl/qtpngreader.h"
#include "3rdimpl/3rdtool.h"

QtpngReader::QtpngReader(const QString &path) : m_path(path){
    
}

void QtpngReader::initialize(int &width, int &height){
    QImageReader reader(m_path);
    m_img = reader.read();
    
    width = m_img.width();
    height = m_img.height();
}

void QtpngReader::readAllRGB(RGBA *buffer){
    int height = m_img.height();
    int width = m_img.width();
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            qrgb2rgba(m_img.pixel(x, y), (buffer + (y * width) + x));
        }
    }    
}        

void QtpngReader::finalize(){
    
}