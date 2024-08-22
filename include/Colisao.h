#pragma once

//namespace Entidades
//{
  class Entidade;
//}

//using namespace Entidades;

class Colisao
{
private:
  int x;
  int y;
  int width;
  int height;
public:
  Colisao(int x = 0, int y = 0, int w = 0, int h = 0);
  ~Colisao();
  void setWidth(const int n);
  const int getWidth() const;
  void setHeight(const int n);
  const int getHeight() const;
  void setX(const int n);
  const int getX() const;
  void setY(const int n);
  const int getY() const;
};


bool colidindo(Entidade *e1, Entidade *e2);
int direcaoColisao(Entidade *e1, Entidade *e2);

#define NAOCOLIDIU 0
#define TOTAL 2
#define HOR -1
#define VER 1