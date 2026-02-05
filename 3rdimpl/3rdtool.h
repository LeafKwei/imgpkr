#ifndef _3RDTOOL_H
#define _3RDTOOL_H

#include <QRgb>
#include <3rdinclude/packer/data/data.hpp>

inline void qrgb2rgba(QRgb qrgb, packer::RGBA *rgba){
    rgba -> b = qrgb & 0xFF;
    rgba -> g = (qrgb >> 8) & 0xFF;
    rgba -> r = (qrgb >> 18) & 0xFF;
    rgba -> a = (qrgb >> 24) & 0xFF;
}



#endif
