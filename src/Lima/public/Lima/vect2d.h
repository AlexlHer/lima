#ifndef _VECT2D_H
#define _VECT2D_H


#ifndef SWIG
BEGIN_NAMESPACE_LIMA
#endif

// Vecteur 2D 
class Vect2d
{
public:
  // Constructeur.
  Vect2d(double x=0, double y=0);
  
  // Lecture de la coordonnée X du vecteur.
  double        x() const;
  // Lecture de la coordonnée Y du vecteur. 
  double        y() const;
  // Lecture de la ieme composante du vecteur
#ifdef SWIG
  %rename(get_coo) coo(size_type i) const;
#endif
  double        coo(size_type i) const;

  // Mise a jour de la coordonnée X du vecteur.
  void          set_x(double d);
  // Mise a jour de la coordonnée Y du vecteur. 
  void          set_y(double d);
  // Mise a jour de la ieme composante du vecteur
#ifdef SWIG
  %rename(set_coo) coo(size_type i, double d);
#endif
  void          coo(size_type i, double d);

private:
  double        m_coo[2];
};

#ifndef SWIG
END_NAMESPACE_LIMA
#endif

#endif
