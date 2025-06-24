#ifndef _MAILLAGE_H
#define _MAILLAGE_H

#include "config.h"
#include "handle.h"
#include "size.h"
#include "enum.h"
#include "composition.h"
#include "callback.h"
#include "lima.h"

#ifndef SWIG
BEGIN_NAMESPACE_LIMA
#endif

class Noeud;
class Bras;
class Polygone;
class Polyedre;

class Nuage;
class Ligne;
class Surface;
class Volume;

class _MaillageInterne;
class Liste_attribut;  


#ifndef SWIG
typedef _Handle<_MaillageInterne> Handle_MaillageInterne;
#endif

class Maillage : public Handle_MaillageInterne
{
public:
    
  /// Constructeur
#ifndef SWIG
  Maillage(const IN_STD string& str="");
#else
  Maillage(const char* str="");
#endif
  /// Destructeur
  ~Maillage();
#ifndef SWIG
  Maillage(const Maillage& mai); 
  Maillage (_MaillageInterne*);
  const Maillage& operator = (const Maillage& mai);
#endif

  /*! La composition du maillage. */
  Composition composition_noeuds ( ) const;
  Composition composition_bras ( ) const;
  Composition composition_polygones ( ) const;
  Composition composition_polyedres ( ) const;

  /// Libere toutes les ressources allouées par le maillage. */
  void          vider();

  /**  Lire la structure d'un maillage.
   *  @exception renvoie un code d'erreur non null em cas de problème 
   */
#ifndef SWIG
  void          lire_structure(const IN_STD string& nom_fichier, format_t format=SUFFIXE, size_type num=1);
#else
  void          lire_structure(const char* nom_fichier, format_t format=SUFFIXE, size_type num=1);
#endif
  /**  Lire un maillage.
   *  @exception renvoie un code d'erreur non null em cas de problème */
#ifndef SWIG
  void          lire(const IN_STD string& nom_fichier, format_t format=SUFFIXE, size_type num=1);
#else
  void          lire(const char* nom_fichier, format_t format=SUFFIXE, size_type num=1);
#endif
  /**  Ecrire un maillage.
   * @param		Chemin d'accès complet du fichier dans lequel est écrit le
   *			maillage.
   * @param		Format d'écriture, où SUFFIXE pour un choix automatique fonction
   *			de l'extension du fichier.
   * @param		Numéro du maillage dans le fichier, pour les formats supportant
   *			plusieurs maillages dans un même fichier.
   * @param		true si la numérotation des mailles doit être préalablement
   *			compactée, false dans le cas contraire.
   *  @exception renvoie un code d'erreur non null em cas de problème */
#ifndef SWIG
  void          ecrire(
	const IN_STD string& nom_fichier, format_t format=SUFFIXE, size_type num=1,
	bool compacter=true);
#else
  void          ecrire(
	const char* nom_fichier, format_t format=SUFFIXE, size_type num=1,
	bool compacter=true);
#endif
  /** Effectue les traitements de verification et de
   *  calcul selon le niveau de preparation demande.
   *  @exception renvoie un code d'erreur non null en cas de problème */
  void          preparer(preparation_t preparation);
  void          preparation_parametrable(TypeMasque preparation) ;

  /**
   * @param		précision utilisée lors du calcul de distance entre deux
   *            noeuds. Cette valeur est notamment utilisée par la préparation
   *			élémentaire LM_SUPPRIMER_DOUBLONS_NOEUDS.
   *			Cette valeur n'est prise en compte que si elle est strictement
   *			positive.
   * @exception	une exception est levée si la valeur n'est pas prise en compte.
   */
  static void precision_distance_noeuds (double precision);

  /** Vérifie que le maillage est conforme au code dont l'identifiant est
   *  tranmis en argument.
   *  @exception Lève une exception de type Lima::erreur contenant les non
   *             conformités rencontrées.
   */    
  void          verification_code (TypeVerificationCode type) const;

  /** Vérifie que le maillage est conforme aux spécifications demandées
   *  dans le masque transmis en argument.
   *  @exception Lève une exception de type Lima::erreur contenant les non
   *             conformités rencontrées.
   */
  void          verification_parametrable (TypeMasqueVerification masque) const;

  /// Dimension du maillage, 1D, 2D ou 3D.
  dim_t         dimension() const;
  /** Coefficient multiplicatif à appliquer sur les coordonnées
   *  pour obtenir des métres */
  double        unite_longueur() const;
  /** Coefficient multiplicatif à appliquer sur les angles
   *  pour obtenir des radians */
  double        unite_angle() const;
  /// Retourne le type de coordonnées.
  coordonnee_t  type_coordonnee() const;
  ///Retourne le type de géométrie.
  geometrie_t   type_geometrie() const;
  /// Retourne le titre du maillage.
  const IN_STD string& titre() const;
  /// Retourne la date de création du maillage.
  const IN_STD string& date() const;

  // Dimension du maillage.
#ifdef SWIG
  %rename(set_dimension) dimension(dim_t dim);
#endif
  void          dimension(dim_t dim);
  // Unité de longueur du maillage.
#ifdef SWIG
  %rename(set_unite_longueur) unite_longueur(double unilo);
#endif
  void          unite_longueur(double unilo);
  // Unité d'angle du maillage.
#ifdef SWIG
  %rename(set_unite_angle) unite_angle(double unia);
#endif
  void          unite_angle(double unia);
  // Type de géométrie du maillage.
#ifdef SWIG
  %rename(set_type_geometrie) type_geometrie(geometrie_t geom);
#endif
  void          type_geometrie(geometrie_t geom);
  // Type de coordonnée du maillage.
#ifdef SWIG
  %rename(set_type_coordonnee) type_coordonnee(coordonnee_t tycoo);
#endif
  void          type_coordonnee(coordonnee_t tycoo);
  /// Titre du maillage.
#ifdef SWIG
  %rename(set_titre) titre(const char* titre);
  void titre (const char* titre);
#else
  void          titre(const IN_STD string& titre);
#endif
  /// Date du maillage.
#ifdef SWIG
  %rename(set_date) date(const char* date);
  void date(const char* date);
#else
  void          date(const IN_STD string& date);
#endif
  //  Liste des attributs du maillage.
  Liste_attribut&         att_maillage();

  /// Nombre de noeuds.
  size_type               nb_noeuds() const;
  // Noeud numéro n.
  Noeud                   noeud(size_type n) const;
  // Noeud d'ID n.
  Noeud                   noeud_id(size_type id) const;    
#ifdef SWIG
  %rename(contenir_noeud) contenir(const Noeud& nd) const;
#endif
  bool                    contenir(const Noeud& nd) const;
#ifdef SWIG
  %rename(ajouter_noeud) ajouter(const Noeud& nd);
#endif
  void                    ajouter(const Noeud& nd);
#ifdef SWIG
  %rename(retirer_noeud) retirer(const Noeud& nd);
#endif
  void                    retirer(const Noeud& nd);
#ifdef SWIG
  %rename(deplacer_noeud) deplacer(size_type id, double x, double y, double z);
#endif
  void                    deplacer(size_type id, double x, double y, double z);
  //  Liste des attributs des noeuds.
  Liste_attribut&         att_noeuds();

  /// Nombre de bras.
  size_type               nb_bras() const;
  // Bras numéro n.
  Bras                    bras(size_type n) const;
  // Bras d'ID n.
  Bras                    bras_id(size_type id) const;
#ifdef SWIG
  %rename(contenir_bras) contenir(const Bras& br) const;
#endif
  bool                    contenir(const Bras& br) const;
#ifdef SWIG
  %rename(ajouter_bras) ajouter(const Bras& br);
#endif
  void                    ajouter(const Bras& br);
#ifdef SWIG
  %rename(retirer_bras) retirer(const Bras& br);
#endif
  void                    retirer(const Bras& br);
  //  Liste des attributs des bras.
  Liste_attribut&         att_bras();

  /// Nombre de polygones.
  size_type               nb_polygones() const;
  // Polygone numéro n.
  Polygone                polygone(size_type n) const;
  // Polygone d'ID n.
  Polygone                polygone_id(size_type id) const;
#ifdef SWIG
  %rename(contenir_polygone)contenir(const Polygone& pg) const;
#endif
  bool                    contenir(const Polygone& pg) const;
#ifdef SWIG
  %rename(ajouter_polygone) ajouter(const Polygone& pg);
#endif 
  void                    ajouter(const Polygone& pg);
#ifdef SWIG
  %rename(retirer_polygone) retirer(const Polygone& pg);
#endif
  void                    retirer(const Polygone& pg);
  //  Liste des attributs des polygones.
  Liste_attribut&         att_polygones();

  /// Nombre de polyedres.
  size_type               nb_polyedres() const;
  // Polyedre numéro n.
  Polyedre                polyedre(size_type n) const;
  // Polyedre d'ID n.
  Polyedre                polyedre_id(size_type id) const;
#ifdef SWIG
  %rename(contenir_polyedre) contenir(const Polyedre& pd) const;
#endif
  bool                    contenir(const Polyedre& pd) const;
#ifdef SWIG
  %rename(ajouter_polyedre) ajouter(const Polyedre& pd);
#endif
  void                    ajouter(const Polyedre& pd);
#ifdef SWIG
  %rename(retirer_polyedre) retirer(const Polyedre& pd);
#endif
  void                    retirer(const Polyedre& pd);
  //  Liste des attributs des polyèdres.
  Liste_attribut&         att_polyedres();
    
  /// Nombre de nuages.
  size_type               nb_nuages() const;
  // Nuage numéro n.
#ifdef SWIG
  %rename(nuage_id) nuage(size_type n) const;
#endif
  Nuage                   nuage(size_type n) const;
  // Nuage de nom str.
#ifndef SWIG
  Nuage                   nuage(const IN_STD string& str) const;    
#else
  Nuage                   nuage(const char* str) const;    
#endif
#ifdef SWIG
  %rename(contenir_nuage) contenir(const Nuage& nu) const;
#endif
  bool                    contenir(const Nuage& nu) const;
#ifdef SWIG
  %rename(ajouter_nuage) ajouter(const Nuage& nu);
#endif
  void                    ajouter(const Nuage& nu);
#ifdef SWIG
  %rename(retirer_nuage) retirer(const Nuage& nu);
#endif
  void                    retirer(const Nuage& nu);
  //  Liste des attributs des nuages.
  Liste_attribut&         att_nuages();
  
  /// Nombre de lignes.
  size_type               nb_lignes() const;
  // Ligne numéro n.
#ifdef SWIG
  %rename(ligne_id) ligne(size_type n) const;
#endif
  Ligne                   ligne(size_type n) const;
  // Ligne de nom str.
#ifndef SWIG
  Ligne                   ligne(const IN_STD string& str) const;    
#else
  Ligne                   ligne(const char* str) const;    
#endif
#ifdef SWIG
  %rename(contenir_ligne) contenir(const Ligne& li) const;
#endif
  bool                    contenir(const Ligne& li) const;
#ifdef SWIG
  %rename(ajouter_ligne) ajouter(const Ligne& li);
#endif
  void                    ajouter(const Ligne& li);
#ifdef SWIG
  %rename(retirer_ligne) retirer(const Ligne& li);
#endif
  void                    retirer(const Ligne& li);
  //  Liste des attributs des lignes.
  Liste_attribut&         att_lignes();

  /// Nombre de surfaces.
  size_type               nb_surfaces() const;
  // Surface numéro n.
#ifdef SWIG
  %rename(surface_id) surface(size_type n) const;
#endif
  Surface                 surface(size_type n) const;
  // Surface de nom str.
#ifndef SWIG
  Surface                 surface(const IN_STD string& str) const;    
#else
  Surface                 surface(const char* str) const;    
#endif
#ifdef SWIG
  %rename(contenir_surface) contenir(const Surface& su) const;
#endif
  bool                    contenir(const Surface& su) const;
#ifdef SWIG
  %rename(ajouter_surface)  ajouter(const Surface& su);
#endif
  void                    ajouter(const Surface& su);
#ifdef SWIG
  %rename(retirer_surface) retirer(const Surface& su);
#endif
  void                    retirer(const Surface& su);
  //  Liste des attributs des surfaces.
  Liste_attribut&         att_surfaces();

  /// Nombre de volumes.
  size_type               nb_volumes() const;
  // Volume numéro n.
#ifdef SWIG
  %rename(volume_id) volume(size_type n) const;
#endif
  Volume                  volume(size_type n) const;
  // Volume de nom str.
#ifndef SWIG
  Volume                  volume(const IN_STD string& str) const;    
#else
  Volume                  volume(const char* str) const;    
#endif
#ifdef SWIG
  %rename(contenir_volume) contenir(const Volume& vo) const;
#endif
  bool                    contenir(const Volume& vo) const;
#ifdef SWIG
  %rename(ajouter_volume) ajouter(const Volume& vo);
#endif
  void                    ajouter(const Volume& vo);
#ifdef SWIG
  %rename(retirer_volume) retirer(const Volume& vo);
#endif
  void                    retirer(const Volume& vo);
  //  Liste des attributs des volumes.
  Liste_attribut&         att_volumes();

  // Initialisation des listes d'attributs du maillage.
  void                    init_att();

  // Ajoute un callback sur le chargement du maillage.
  void ajouter_reader_callback (ReaderCallback* rc);

  // Enlève un callback sur le chargement du maillage.
  void enlever_reader_callback (ReaderCallback* rc);
};

Maillage maillage_C_vers_CPP (int_type ref);


#ifndef SWIG
END_NAMESPACE_LIMA
#endif

#endif
