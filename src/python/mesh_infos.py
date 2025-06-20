import sys
from LimaScripting import *

print ("Lima version " + lima_version ( ))

print ("Affichage du contenu du maillage " + sys.argv [1])

m = Maillage ( )
m.lire (sys.argv [1])

# informations
print ("Nombre de noeuds : " + str (m.nb_noeuds ( )))
print ("Nombre de bras : " + str (m.nb_bras ( )))
print ("Nombre de polygones : " + str (m.nb_polygones ( )))
print ("Nombre de polyèdres : " + str (m.nb_polyedres ( )))
print ("Nombre de nuages : " + str (m.nb_nuages ( )))
print ("Nombre de lignes : " + str (m.nb_lignes ( )))
print ("Nombre de surfaces : " + str (m.nb_surfaces ( )))
print ("Nombre de volumes : " + str (m.nb_volumes ( )))

print ("Noeuds :")
for n in range (0, m.nb_noeuds ( )) :
	noeud	= m.noeud (n)
	print (str (noeud.id ( )) + " (" + f"{noeud.x ( ):.3e}, {noeud.y ( ):.3e}, {noeud.z ( ):.3e}" + ")")
print ("Bras :")
for b in range (0, m.nb_bras ( )) :
	bras	= m.bras (b)
	print (str (bras.id ( )) + " (" + str (bras.noeud (0).id ( )) + ", " + str (bras.noeud (1).id ( )) + ")")
print ("Polygones :")
for p in range (0, m.nb_polygones ( )) :
	pg	= m.polygone (p)
	s = str (pg.id ( )) + " ("
	for n in range (0, pg.nb_noeuds ( )):
		noeud	= pg.noeud (n)
		if 0 != n:
			s	+= ", "
		s	+= str (noeud.id ( ));
	s += ")"
	print (s)
print ("Polyedres :")
for p in range (0, m.nb_polyedres ( )) :
	pe	= m.polyedre (p)
	s = str (pe.id ( )) + " ("
	for n in range (0, pe.nb_noeuds ( )):
		noeud	= pe.noeud (n)
		if 0 != n:
			s	+= ", "
		s	+= str (noeud.id ( ));
	s += ")"
	print (s)
print ("Nuages :")
for n in range (0, m.nb_nuages ( )):
	nuage	= m.nuage_id (n)
	s	= nuage.nom ( ) + " : ";
	for n in range (0, nuage.nb_noeuds ( )):
		noeud	= nuage.noeud (n)
		if 0 != n:
			s	+= ", "
		s	+= str (noeud.id ( ));
	print (s)
print ("Lignes :")
for l in range (0, m.nb_lignes ( )):
	ligne	= m.ligne_id (l)
	s	= ligne.nom ( ) + " : ";
	for b in range (0, ligne.nb_bras ( )):
		bras	= ligne.bras (b)
		if 0 != b:
			s	+= ", "
		s	+= str (bras.id ( ));
	print (s)
print ("Surfaces :")
for sf in range (0, m.nb_surfaces ( )):
	surface	= m.surface_id (sf)
	s	= surface.nom ( ) + " : ";
	for p in range (0, surface.nb_polygones ( )):
		polygone	= surface.polygone (p)
		if 0 != p:
			s	+= ", "
		s	+= str (polygone.id ( ));
	print (s)
print ("Volumes :")
for v in range (0, m.nb_volumes ( )):
	volume	= m.volume_id (v)
	s	= volume.nom ( ) + " : ";
	for p in range (0, volume.nb_polyedres ( )):
		polyedre	= volume.polyedre (p)
		if 0 != p:
			s	+= ", "
		s	+= str (polyedre.id ( ));
	print (s)
