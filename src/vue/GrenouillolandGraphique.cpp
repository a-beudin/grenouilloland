/************************************************
 * Definition de la classe GrenouillolandGraphique. *
 ************************************************/

#include "Presentateur.hh"

using namespace grenouilloland;

/************************
 * GenerationGraphique. *
 ************************/

GrenouillolandGraphique::GrenouillolandGraphique(const Glib::ustring& titre, Vue& vue):
  	Gtk::AspectFrame(titre),
  	_ptrVue(&vue) {

  	// Ajout du gestionnaire dans le contours.
  	add(_gestionnaire);

  	// Obtention du presentateur associe a la vue proprietaire.
  	const Presentateur& presentateur = vue.lirePresentateur();

  	// Obtention du modele via le presentateur.
  	const Jeu& modele = presentateur.lireModele();

  	// Obtention de dimension du modele.
  	const int& dimension = modele.lireDimension();
    
  	// Boucle de creation des cellules graphiques.
  	for (int i = 0; i < dimension*dimension; i ++) {
      	CaseGraphique* c = Gtk::manage(new CaseGraphique(*this, i%dimension, i/dimension));
      	_gestionnaire.attach(*c, i%dimension, i/dimension, 1, 1);
      	_cases.push_back(c);
    }
}

/************
 * lireVue. *
 ************/

const Vue& 
GrenouillolandGraphique::lireVue() const {
  return *_ptrVue;
}

/**********************
 * lireVueModifiable. *
 **********************/

Vue& 
GrenouillolandGraphique::lireVueModifiable() {
  return *_ptrVue;
}

/****************
 * mettreAJour. *
 ****************/

void 
GrenouillolandGraphique::mettreAJour(const Presentateur& presentateur) {
  for (CaseGraphique* ptrCase : _cases) {
    ptrCase->mettreAJour(presentateur);
  }
}
