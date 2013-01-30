/****************************
 * Definition de la classe. *
 ****************************/

#include "Presentateur.hh"
#include "PointsDeVie.hh"

using namespace grenouilloland;

/**************
 * PointsDeVie. *
 **************/

PointsDeVie::PointsDeVie(const Glib::ustring& titre):
	Gtk::Frame(titre),
	_imageCoeur(Vue::_cheminImages + "coeur-96x96.png") 
{
	// Affichage des points de vie en "large"
	_labelPv.set_markup("<span font-size=\"large\">1</span>");

	Gtk::HBox* gestionnaire = Gtk::manage(new Gtk::HBox());

	gestionnaire->pack_start(_imageCoeur);
	gestionnaire->pack_start(_labelPv);

	add(*gestionnaire);
}

/****************
 * mettreAJour. *
 ****************/

void
PointsDeVie::mettreAJour(const Presentateur& presentateur) {

	// Récupération du nombre de points de vie de la grenouille.
	const unsigned int pv = presentateur.lireModele().lirePvGrenouille();

	// Conversion en string
	std::ostringstream convert;
	convert << pv;

	// Mise à jour du label
	_labelPv.set_markup("<span font-size=\"large\">" + convert.str() + "</span>");

	// Mise à jour de l'image du coeur.
	if(presentateur.lireModele().grenouilleMalade())
		_imageCoeur.set(Vue::_cheminImages + "coeur_malade-96x96.png");
	else
		_imageCoeur.set(Vue::_cheminImages + "coeur-96x96.png");
}
