#ifndef _POLYEDRE_H
#define _POLYEDRE_H

#include "config.h"
#include "handle.h"
#include "size.h"

#ifndef SWIG
BEGIN_NAMESPACE_LIMA
#endif

class Noeud;
class Bras;
class Polygone;
class _PolyedreInterne;

#ifndef SWIG
typedef _Handle<_PolyedreInterne> Handle_PolyedreInterne;
#endif

// Polyedre du maillage.
class Polyedre : public Handle_PolyedreInterne
{
public:
#ifndef SWIG
  typedef enum {
    TETRAEDRE = 0, 
    PYRAMIDE,
    PRISME,
    HEXAEDRE,
    HEPTAEDRE,
    OCTOEDRE,
    maxPolyedreType
  } PolyedreType;

  // Voir polyedre.C pour la definition du nombre de noeuds suivant le 
  // type de polyedre.
  static int PolyedreNbNode[maxPolyedreType];
#endif

  Polyedre();
#ifdef SWIG
  %rename(Tetraedre) Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3);
#endif
  Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3);
#ifdef SWIG
  %rename(Pyramide) Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2, const Noeud& n3,  const Noeud& n4);
#endif
  Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2, const Noeud& n3,  const Noeud& n4);
#ifdef SWIG
  %rename(Prisme) Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5);
#endif
  Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5);
#ifdef SWIG
  %rename(Hexaedre) Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7);
#endif
  Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7);
#ifdef SWIG
  %rename(Heptaedre) Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9);
#endif
  Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9);
#ifdef SWIG
  %rename(Octoedre) Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9, const Noeud& n10,  const Noeud& n11);
#endif
  Polyedre(const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9, const Noeud& n10,  const Noeud& n11);
#ifdef SWIG
  %rename(Tetraedre_id) Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3);
#endif
  Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3);
#ifdef SWIG
  %rename(Prisme_id) Polyedre(size_type n, const Noeud& n0, const Noeud& n1, const Noeud& n2, const Noeud& n3,  const Noeud& n4);
#endif
  Polyedre(size_type n, const Noeud& n0, const Noeud& n1, const Noeud& n2, const Noeud& n3,  const Noeud& n4);
#ifdef SWIG
  %rename(Pyramide_id) Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5);
#endif
  Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5);
#ifdef SWIG
  %rename(Hexaedre_id) Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7);
#endif
  Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7);
#ifdef SWIG
  %rename(Heptaedre_id) Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9);
#endif
  Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9);
#ifdef SWIG
  %rename(Octoedre_id) Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9, const Noeud& n10,  const Noeud& n11);
#endif
  Polyedre(size_type n, const Noeud& n0,  const Noeud& n1, const Noeud& n2,  const Noeud& n3, const Noeud& n4,  const Noeud& n5, const Noeud& n6,  const Noeud& n7, const Noeud& n8,  const Noeud& n9, const Noeud& n10,  const Noeud& n11);

  //! Remplace le noeud n1 par le noeud n2 pour chaque occurence existante de n1.
  void remplacer_noeud (const Noeud& n1, const Noeud& n2);

#ifndef SWIG
  Polyedre(_PolyedreInterne* ptr);
  Polyedre(const Polyedre& pd);
#endif
  ~Polyedre();
  
  // Numero d'identification
  size_type       id() const;
  
  // Type de polyedre
  Polyedre::PolyedreType  type() const;

  // Nombre de noeuds.
  size_type       nb_noeuds() const;
  // Noeud numéro n.
  Noeud           noeud(size_type n) const;
  // Nombre de bras.
  size_type       nb_bras() const;
  // Bras numéro n.
  Bras            bras(size_type n) const;
  // Nombre de polygones.
  size_type       nb_polygones() const;
  // Polygone numéro n.
  Polygone        polygone(size_type n) const;
  
  double          volume() const;

#ifndef SWIG
  const Polyedre& operator = (const Polyedre& pd);
  bool operator == (const Polyedre& pd);
#endif
};

#ifndef SWIG
END_NAMESPACE_LIMA
#endif

#endif
