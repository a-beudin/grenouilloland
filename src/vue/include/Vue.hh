#ifndef _Vue_hh
#define _Vue_hh

#include "GrenouillolandGraphique.hh"
#include "Chronometre.hh"
#include "Dimension.hh"
#include "PointsDeVie.hh"
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/stock.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/cellrendererpixbuf.h>
#include <map>
#include <mutex>

namespace grenouilloland {

/**
 * Declarations incompletes necessaires.
 */
class Presentateur;

/**
 * @class Vue Vue.hh
 * @brief Vue de l'application.
 * @author Yann Dauxais
 * @author Alexandre Beudin
 * @date 6.1.2013
 *
 * Declaration de la classe Vue representant la vue de l'application, c'est a
 * dire son interface graphique.
 *
 * @note Une instance de cette classe ne peut etre dupliquee.
 */
class Vue: public Gtk::Window {
public:

  /**
   * Declaration d'amitié.
   */
  friend class CaseGraphique;

  /**
   * Declaration d'amitié.
   */
  friend class Dimension;

  /**
   * Declaration d'amitié.
   */
  friend class PointsDeVie;

public:

  /**
   * Initialise cette classe.
   *
   * @note cette methode doit etre appelee avant toute autre.
   */
  static void initialiser();

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _titreVue.
   */
  static const Glib::ustring lireTitreVue();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _titreGrenouilloland.
   */
  static const Glib::ustring lireTitreGrenouilloland();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _titrePointsDeVie.
   */
  static const Glib::ustring lireTitrePointsDeVie();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _titreChronometre.
   */
  static const Glib::ustring lireTitreChronometre();

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _titreDimension.
   */
  static const Glib::ustring lireTitreDimension();

protected:

  /**
   * Retourne l'image dont le nom est fourni en argument.
   *
   * @param[in] nom - le nom de l'image.
   * @return l'image correspondante.
   */
  static const Glib::RefPtr< Gdk::Pixbuf>& lireImage(const Glib::ustring& nom);

public:

  /**
   * Constructeur logique.
   *
   * @param[in] presentateur - la valeur de @ref _ptrPresentateur.
   */
  Vue(Presentateur& presentateur);

protected:

  /**
   * Met à jour l'affichage des PointsDeVie, l'ensemble des CaseGraphique
   * du GrenouillolandGraphique ainsi que le Chronometre.
   *
   */
  void mettreAJour();

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrPresentateur.
   */
  const Presentateur& lirePresentateur() const;

protected:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrPresentateur.
   */
  Presentateur& lirePresentateurModifiable();

protected:

  /**
   * Verrouille cette vue.
   */
  void verrouiller();

  /**
   * Deverrouille cette vue.
   */
  void deverrouiller();

protected:

  /**
   * Construit les barre de menus et d'outils.
   * 
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associe a
   *   la fenetre principale.
   */
  void construireBarreMenusEtOutils(Gtk::VBox& gestionnaire);

  /**
   * Construit la partie centrale de la fenetre principale contenant le 
   * GrenouillolandGraphique et le panneau d'affichage des PointsDeVie.
   * 
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associe a
   *   la fenetre principale.
   */
  void construirePartieCentrale(Gtk::VBox& gestionnaire);

  /**
   * Construit la partie inferieure de la fenetre principale contenant le
   * controleur de la dimension du jeu.
   * 
   * @param[in,out] gestionnaire - le gestionnaire de mise en forme associe a
   *   la fenetre principale.
   */
  void construirePartieInferieure(Gtk::VBox& gestionnaire);

protected:

  /**
   * Callback permettant de preparer le jeu pour une nouvelle partie. Cette 
   * methode est invoquee suite a un click sur l'entree "Nouveau" du menu 
   * "Commandes" ou bien sur le bouton correspondant dans la barre d'outils.
   *
   * @note Cette methode verrouille cette vue pendant toute son execution.
   */
  void cbNouveau();

  /**
   * Callback permettant de preparer une nouvelle partie avec une autre 
   * dimension. Cette methode est invoquee par le controleur de la resolution
   * du jeu.
   *
   * @note Cette methode verrouille cette vue pendant toute son execution.
   */
  void cbChangerModele();

  /**
   * Callback permettant de presenter l'application et ses auteurs. Cette
   * methode est invoquee suite a un click sur l'entree "A propos ..." du menu
   * "Commandes" ou bien sur le bouton correspondant dans la barre d'outils.
   */
  void cbAPropos();

  /**
   * Callback permettant de quitter proprement l'application. Cette methode
   * est invoquee suite a un click sur l'entree "Quitter" du menu "Commandes"
   * ou bien sur le bouton correspondant dans la barre d'outils.
   *
   * @note Cette methode verrouille cette vue pendant toute son execution.
   */
  void cbQuitter();

private:

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance a recopier.
   */
  Vue(const Vue& autre) = delete;

  /**
   * Operateur d'affectation.
   *
   * @param[in] autre - l'instance a recopier.
   * @return cette instance apres recopie.
   */
  Vue& operator=(const Vue& autre) = delete;

protected:

  /**
   * Titre de cette vue.
   */
  static const Glib::ustring _titreVue;

  /**
   * Titre de la representation graphique du jeu grenouilloland.
   */
  static const Glib::ustring _titreGrenouilloland;

  /**
   * Titre du panneau de points de vie.
   */
  static const Glib::ustring _titrePointsDeVie;

  /**
   * Titre du controleur du chronomètre du jeu.
   */
  static const Glib::ustring _titreChronometre;

  /**
   * Titre du controleur de la dimension du jeu.
   */
  static const Glib::ustring _titreDimension;


  /**
   * Chemins d'acces au répertoire contenant les images.
   */
  static const Glib::ustring _cheminImages;

  /**
   * Map permettant de stocker les images manipulees par cette vue.
   */
  static std::map< Glib::ustring, Glib::RefPtr< Gdk::Pixbuf> > _images;

protected:

  /**
   * Presentateur unique associe a cette vue.
   */
  Presentateur* const _ptrPresentateur;

  /**
   * Representation graphique du modele.
   */
  std::unique_ptr< GrenouillolandGraphique > _ptrGrenouillolandGraphique;

  /**
   * Affichage des points de vie de la grenouille.
   */
  PointsDeVie _pointsDeVie;

  /**
   * Controleur de la dimension du jeu.
   */
  Dimension _dimension;

  /**
   * Affichage du chronomètre du jeu.
   */
  Chronometre _chronometre;

  /**
   * Gestionnaire de la partie centrale de la fenetre principale
   * contenant GrenouillolandGraphique et PointsDeVie.
   */
  Gtk::HBox _gestionnaireCentre;

  /**
   * Gestionnaire de la partie inférieure de la fenetre principale
   * contenant Dimension et Chronometre.
   */
  Gtk::HBox _gestionnaireBas;

  /**
   * Verrou associe à cette vue.
   */
  std::mutex _verrou;

  /**
   * Sous-classe Mandataire amie avec le Presentateur, permettant à ce dernier
   * de mettre à jour la Vue sans lui donner accés à d'autre méthodes protégées de
   * la Vue.
   */
public :
	class Mandataire
	{
		public :
			friend class Presentateur;			

		private :

			static void mettreAJour(Vue& vue)
			{
				vue.mettreAJour();
			}
	};

};
}

#endif
