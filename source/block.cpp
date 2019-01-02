#include "include/block.h"

Block::Block(int x, int y, bool collidable, Material m, QString texture)
    : pos_x(x), pos_y(y), _collidable(collidable), _m(m), _texture(texture)
    {
    }

Block::Block(int x, int y, QString texture)
    :pos_x(x), pos_y(y), _texture(texture)
    {
        size = 50;
        _collidable = true;
    }

QRectF Block::boundingRect() const
    {
        return QRectF(pos_x, pos_y, size, size);
    }

void Block::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(_texture.scaledToHeight(size)));
    painter->drawRect(pos_x, pos_y, size, size);
}

QPainterPath Block::shape() const
{

    QPainterPath path;
    path.addRect(pos_x, pos_y, size, size);
    return path;
}

int Block::getX()
{
    return pos_x;
}
int Block::getY()
{
    return  pos_y;
}

