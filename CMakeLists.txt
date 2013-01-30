# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin du répertoire contenant les binaires.
SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Modules nécessaires.
FIND_PACKAGE( PkgConfig REQUIRED )
FIND_PACKAGE( Doxygen REQUIRED )
PKG_CHECK_MODULES( GTKMM gtkmm-3.0 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/modele/include 
		     src/presentateur/include
		     src/vue/include
		     ${GTKMM_INCLUDE_DIRS}
)

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++0x")

# Options de l'éditeur de lien pour supporter cmath.
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm" )

# Librairies nécessaires à l'édition de liens.
LINK_DIRECTORIES( ${GTKMM_LIBRARY_DIRS} )

# Création des exécutables.
ADD_EXECUTABLE( grenouilloland
		src/client/grenouilloland.cpp
		src/modele/Jeu.cpp
		src/modele/Case.cpp
		src/modele/Eau.cpp
		src/modele/Element.cpp
		src/modele/ElementMortel.cpp
		src/modele/Etat.cpp
		src/modele/Grenouille.cpp
		src/modele/Nenuphar.cpp
		src/modele/NenupharDopant.cpp
		src/modele/NenupharImmortel.cpp
		src/modele/NenupharMortel.cpp
		src/modele/NenupharNutritif.cpp
		src/modele/NenupharVeneneux.cpp
		src/modele/StrategieAbstraite.cpp
		src/modele/StrategieDopante.cpp
		src/modele/StrategieMort.cpp
		src/modele/StrategieNutritive.cpp
		src/modele/StrategieVeneneuse.cpp
		src/modele/StrategieNeutre.cpp
		src/presentateur/Presentateur.cpp
		src/vue/Vue.cpp
		src/vue/GrenouillolandGraphique.cpp
		src/vue/CaseGraphique.cpp
		src/vue/Chronometre.cpp
		src/vue/Dimension.cpp
		src/vue/PointsDeVie.cpp
)

TARGET_LINK_LIBRARIES( grenouilloland ${GTKMM_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

