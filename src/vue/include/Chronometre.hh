#ifndef _Chronometre_hh
#define _Chronometre_hh

#include <gtkmm/frame.h>
#include <gtkmm/progressbar.h>

namespace grenouilloland {

/**
 * Declarations incompletes necessaires.
 */
class Vue;

/**
 * @class Chronometre Chronometre.hh
 * @brief Afficheur du temps de Jeu.
 * @author Yann Dauxais
 * @author Alexandre Beudin
 * @date 6.1.2013
 *
 * Declaration de la classe Chronometre representant l'affichage
 * du chronomètre du Jeu. Le Widget utilisé est une barre de progression.
 *
 * @note une instance de cette classe ne peut etre dupliquee.
 * 
 * @note chaque instance de cette classe est son propre listener.
 */
class Chronometre: public Gtk::Frame {

	/**
   	* Declaration d'amitie.
   	*/
  	friend class Vue;

public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   */
  Chronometre(const Glib::ustring& titre);

protected:

  /**
   * Met à jour la barre de progression selon le chronomètre du Jeu.
   *
   * @param[in] presentateur - le Presentateur à invoquer.
   */
  void mettreAJour(const Presentateur& presentateur);

private:

  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance à recopier.
   */
  Chronometre(const Chronometre& autre) = delete;

  /**
   * Operateur d'affectation.
   *
   * @param[in] autre - l'instance à recopier.
   * @return cette instance apres recopie.
   */
  Chronometre& operator=(const Chronometre& autre) = delete;

protected:

  /**
   * Barre de progression.
   */
  Gtk::ProgressBar _barreDeProgression;

};
}

#endif
