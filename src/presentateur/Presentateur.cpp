/*****************************************
 * Definition de la classe Presentateur. *
 *****************************************/

#include "Presentateur.hh"
#include "Case.hh"

using namespace grenouilloland;

/*****************
 * Presentateur. *
 *****************/

Presentateur::Presentateur(const int& dimensionMinimum, 
	const int& dimensionMaximum,
	const int& dimension):
	_dimensionMinimum(dimensionMinimum),
	_dimensionMaximum(dimensionMaximum),
	_ptrModele(new Jeu(dimension)),
	_ptrVue(new Vue(*this)),
	_vieillissement(sigc::mem_fun(*this, &Presentateur::vieillissement))
{
}

/*************************
 * lireDimensionMinimum. *
 *************************/

const int& 
Presentateur::lireDimensionMinimum() const {
  return _dimensionMinimum;
}

/*************************
 * lireDimensionMaximum. *
 *************************/

const int& 
Presentateur::lireDimensionMaximum() const {
  return _dimensionMaximum;
}

/***************
 * lireModele. *
 ***************/

const Jeu& 
Presentateur::lireModele() const {
  return *_ptrModele;
}

/************
 * lireVue. *
 ************/

const Vue& 
Presentateur::lireVue() const {
  return *_ptrVue;
}

/**************
 * dimension. *
 **************/

const int& 
Presentateur::dimension() const {
  return _ptrModele->lireDimension();
}

/*************
 * demarrer. *
 *************/

void
Presentateur::demarrer() {
  Gtk::Main::run(*_ptrVue);
}

/*******************
 * vieillissement. *
 *******************/

bool
Presentateur::vieillissement() {

	// Lance le vieillissement du Jeu.
	bool ret = Jeu::Mandataire::vieillissement(*_ptrModele);

	// Met la Vue à jour.
	Vue::Mandataire::mettreAJour(*_ptrVue);
	return ret;
}

/*******************
 * lancerPartie. *
 *******************/

void
Presentateur::lancerPartie() {

	// Déconnecte le connecteur pour stopper une éventuelle partie.
	_conn.disconnect();

	// Réinitialise le Jeu.
	Jeu::Mandataire::reinitialiser(*_ptrModele);

	if (_ptrModele->end()) {

		// Démarre le Jeu.
		Jeu::Mandataire::lancerPartie(*_ptrModele);

		// Lance la création du premier chemin de nénuphars.
		Jeu::Mandataire::creerChemin(*_ptrModele);

		// Met la Vue à jour.
		Vue::Mandataire::mettreAJour(*_ptrVue);
		
		// Connecte le connecteur au slot _vieillissement avec un timer d'une seconde.
		// La méthode vieillissement sera ainsi lancé toutes les secondes. 
		_conn = Glib::signal_timeout().connect(_vieillissement, 1000);
	}
}

/***********************
 * deplacerGrenouille. *
 ***********************/

bool
Presentateur::deplacerGrenouille(const int& ligne, const int& colonne) {
	if (Jeu::Mandataire::deplacerGrenouille(*_ptrModele, colonne, ligne)) {

		// Met la Vue à jour.
		Vue::Mandataire::mettreAJour(*_ptrVue);
		return true;
	}
	return false;
}

/******************
 * nouveauModele. *
 ******************/

void 
Presentateur::nouveauModele(const int& dimension) {
	_ptrModele.reset(new Jeu(dimension));
}
