#ifndef _GrenouillolandGraphique_hh
#define _GrenouillolandGraphique_hh

#include "CaseGraphique.hh"
#include <gtkmm/aspectframe.h>
#include <gtkmm/grid.h>
#include <vector>

namespace grenouilloland {

/**
 * Declarations incompletes necessaires.
 */
class Vue;

/**
 * @class GrenouillolandGraphique GrenouillolandGraphique.hh
 * @brief Representation graphique du Jeu grenouilloland.
 * @author Yann Dauxais
 * @author Alexandre Beudin
 * @date 6.1.2013
 *
 * Declaration de la classe GrenouillolandGraphique representant le
 * plateau du Jeu Grenouilloland.
 *
 * @note Une instance de cette classe ne peut être dupliquée.
 */
class GrenouillolandGraphique: public Gtk::AspectFrame {
public:

  /**
   * Declaration d'amitié.
   */
  friend class Vue;

  /**
   * Declaration d'amitié.
   */
  friend class CaseGraphique;

public:

  /**
   * Constructeur logique.
   *
   * @param[in] titre - le titre du contour.
   * @param[in,out] vue - la valeur de @ref _ptrVue.
   */
  GrenouillolandGraphique(const Glib::ustring& titre, Vue& vue);

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrVue.
   */
  const Vue& lireVue() const;

protected:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrVue.
   */
  Vue& lireVueModifiable();

protected:

  /**
   * Met a jour l'ensemble des cases graphiques de ce jeu graphique.
   *
   * @param[in] presentateur - le presentateur a invoquer.
   *
   * @note La vue doit etre verrouillee pour pouvoir invoquer cette methode.
   */
  void mettreAJour(const Presentateur& presentateur);

protected:

  /**
   * Unique vue proprietaire de cette generation.
   */
  Vue* const _ptrVue;

  /**
   * Gestionnaire de mise en forme de ce plateau.
   */
  Gtk::Grid _gestionnaire;

  /**
   * Cases graphiques de cette representation graphique du jeu grenouilloland.
   */
  std::vector< CaseGraphique* > _cases;

};
}

#endif
