/*********************************************
 * Definition de la classe CaseGraphique. *
 *********************************************/

#include "Presentateur.hh"
#include "Etat.hh"

using namespace grenouilloland;

/*********************
 * CaseGraphique. *
 *********************/

CaseGraphique::CaseGraphique(GrenouillolandGraphique& grenouillolandGraphique,
				   const int& colonne,
				   const int& ligne):
  _ptrGrenouillolandGraphique(&grenouillolandGraphique),
  _ligne(ligne),
  _colonne(colonne) {

  // Obtention de la vue.
  const Vue& vue = _ptrGrenouillolandGraphique->lireVue();

  // Obtention du presentateur.
  const Presentateur& presentateur = vue.lirePresentateur();

  // Creation des pixmaps representants les etats d'une case.
  {
      
    // Renommage de type local.
    typedef std::unique_ptr< Gtk::Image > Pointer;

	// Grandes	

    // L'élément de la case est Eau.
    _etats[0] = Pointer(new Gtk::Image(vue.lireImage("eau")));

	// L'élément de la case est Nenuphar.
    _etats[1] = Pointer(new Gtk::Image(vue.lireImage("nen")));

	// L'élément de la case est NenupharDopant.
    _etats[2] = Pointer(new Gtk::Image(vue.lireImage("nen_dopant")));

	// L'élément de la case est NenupharImmortel.
    _etats[3] = Pointer(new Gtk::Image(vue.lireImage("nen")));

	// L'élément de la case est NenupharMortel.
    _etats[4] = Pointer(new Gtk::Image(vue.lireImage("nen_dopant")));

	// L'élément de la case est NenupharNutritif.
    _etats[5] = Pointer(new Gtk::Image(vue.lireImage("nen_nutritif")));

	// L'élément de la case est NenupharVeneneux.
    _etats[6] = Pointer(new Gtk::Image(vue.lireImage("nen_veneneux")));
 
	// Moyennes	

    // L'élément de la case est Eau.
    _etats[7] = Pointer(new Gtk::Image(vue.lireImage("eau")));

	// L'élément de la case est Nenuphar.
    _etats[8] = Pointer(new Gtk::Image(vue.lireImage("nen_moyen")));

	// L'élément de la case est NenupharDopant.
    _etats[9] = Pointer(new Gtk::Image(vue.lireImage("nen_dopant_moyen")));

	// L'élément de la case est NenupharImmortel.
    _etats[10] = Pointer(new Gtk::Image(vue.lireImage("nen")));

	// L'élément de la case est NenupharMortel.
    _etats[11] = Pointer(new Gtk::Image(vue.lireImage("nen_dopant_moyen")));

	// L'élément de la case est NenupharNutritif.
    _etats[12] = Pointer(new Gtk::Image(vue.lireImage("nen_nutritif_moyen")));

	// L'élément de la case est NenupharVeneneux.
    _etats[13] = Pointer(new Gtk::Image(vue.lireImage("nen_veneneux_moyen")));

	// Petites	

    // L'élément de la case est Eau.
    _etats[14] = Pointer(new Gtk::Image(vue.lireImage("eau")));

	// L'élément de la case est Nenuphar.
    _etats[15] = Pointer(new Gtk::Image(vue.lireImage("nen_petit")));

	// L'élément de la case est NenupharDopant.
    _etats[16] = Pointer(new Gtk::Image(vue.lireImage("nen_dopant_petit")));

	// L'élément de la case est NenupharImmortel.
    _etats[17] = Pointer(new Gtk::Image(vue.lireImage("nen")));

	// L'élément de la case est NenupharMortel.
    _etats[18] = Pointer(new Gtk::Image(vue.lireImage("nen_dopant_petit")));

	// L'élément de la case est NenupharNutritif.
    _etats[19] = Pointer(new Gtk::Image(vue.lireImage("nen_nutritif_petit")));

	// L'élément de la case est NenupharVeneneux.
    _etats[20] = Pointer(new Gtk::Image(vue.lireImage("nen_veneneux_petit")));

// Avec Grenouille
    // L'élément de la case est Eau.
    _etats[21] = Pointer(new Gtk::Image(vue.lireImage("gren_eau")));

	// L'élément de la case est Nenuphar.
    _etats[22] = Pointer(new Gtk::Image(vue.lireImage("gren_nen")));

	// L'élément de la case est NenupharDopant.
    _etats[23] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_dopant")));

	// L'élément de la case est NenupharImmortel.
    _etats[24] = Pointer(new Gtk::Image(vue.lireImage("gren_nen")));

	// L'élément de la case est NenupharMortel.
    _etats[25] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_dopant")));

	// L'élément de la case est NenupharNutritif.
    _etats[26] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_nutritif")));

	// L'élément de la case est NenupharVeneneux.
    _etats[27] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_veneneux")));
 
	// Moyennes	

    // L'élément de la case est Eau.
    _etats[28] = Pointer(new Gtk::Image(vue.lireImage("gren_eau")));

	// L'élément de la case est Nenuphar.
    _etats[29] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_moyen")));

	// L'élément de la case est NenupharDopant.
    _etats[30] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_dopant_moyen")));

	// L'élément de la case est NenupharImmortel.
    _etats[31] = Pointer(new Gtk::Image(vue.lireImage("gren_nen")));

	// L'élément de la case est NenupharMortel.
    _etats[32] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_dopant_moyen")));

	// L'élément de la case est NenupharNutritif.
    _etats[33] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_nutritif_moyen")));

	// L'élément de la case est NenupharVeneneux.
    _etats[34] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_veneneux_moyen")));

	// Petites	

    // L'élément de la case est Eau.
    _etats[35] = Pointer(new Gtk::Image(vue.lireImage("gren_eau")));

	// L'élément de la case est Nenuphar.
    _etats[36] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_petit")));

	// L'élément de la case est NenupharDopant.
    _etats[37] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_dopant_petit")));

	// L'élément de la case est NenupharImmortel.
    _etats[38] = Pointer(new Gtk::Image(vue.lireImage("gren_nen")));

	// L'élément de la case est NenupharMortel.
    _etats[39] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_dopant_petit")));

	// L'élément de la case est NenupharNutritif.
    _etats[40] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_nutritif_petit")));

	// L'élément de la case est NenupharVeneneux.
    _etats[41] = Pointer(new Gtk::Image(vue.lireImage("gren_nen_veneneux_petit")));
  }

  // Connection du callback associe au click de souris.
  {
    auto crochet = sigc::mem_fun(*this, &CaseGraphique::cbClickSouris);
    signal_button_press_event().connect(crochet);
  }

  // Mise a jour de cette cellule graphique.
  mettreAJour(presentateur);

}

/****************************
 * lireGrenouillolandGraphique. *
 ****************************/

const GrenouillolandGraphique& 
CaseGraphique::lireGrenouillolandGraphique() const {
  return *_ptrGrenouillolandGraphique;
}

/**************
 * lireLigne. *
 **************/

const int& 
CaseGraphique::lireLigne() const {
  return _ligne;
}

/****************
 * lireColonne. *
 ****************/

const int& 
CaseGraphique::lireColonne() const {
  return _colonne;
}

/****************
 * mettreAJour. *
 ****************/

void 
CaseGraphique::mettreAJour(const Presentateur& presentateur) {
  
  // Obtention du nouvel etat de la case du modele correspondante via le 
  // presentateur.
  const int id = presentateur.lireModele().lireCase(_ligne,_colonne).lireElement().lireId();
  Etat etat = presentateur.lireModele().lireCase(_ligne,_colonne).lireElement().lireEtat();
  int n = 0;
  if(etat == Etat::Moyen)
	n = 1;
  else if(etat == Etat::Petit)
	n = 2;

  if (presentateur.lireModele().presenceGrenouille(_ligne,_colonne)) n+=3;

  // Obtention du pixmap correspondant.
  Gtk::Image& image = *_etats[id+n*(_etats.size()/6)];
  
  // Si l'etat de cette cellule n'a pas change, il n'y a rien a faire.
  if (&image == get_child()) {
    return;
  }

  // Sinon, suppression de l'ancien pixmap et affichage du nouveau.
  remove();
  add(image);
  image.show();
}

/******************
 * cbClickSouris. *
 ******************/

bool 
CaseGraphique::cbClickSouris(GdkEventButton* evt) {

  // Obtention de la vue modifiable.
  Vue& vue = _ptrGrenouillolandGraphique->lireVueModifiable();

  // Obtention du presentateur modifiable associe a la vue.
  Presentateur& presentateur = vue.lirePresentateurModifiable();

  // Verrouillage de la vue.
  vue.verrouiller();

  Presentateur::MandataireCaseGraphique::deplacerGrenouille(presentateur, _ligne,_colonne);

  // Mise a jour de cette case graphique.
  _ptrGrenouillolandGraphique->mettreAJour(presentateur);

  // Deverrouillage de la vue.
  vue.deverrouiller();

  return true;
}
