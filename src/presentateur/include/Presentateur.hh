#ifndef _Presentateur_hh
#define _Presentateur_hh

#include "Jeu.hh"
#include "Vue.hh"

namespace grenouilloland {

/**
 * @class Presentateur Presentateur.hh
 * @brief Presentateur de l'application.
 * @author Yann Dauxais
 * @author Alexandre Beudin
 * @date 6.1.2013
 *
 * Declaration de la classe Presentateur representant le presentateur dans le
 * modele d'archiecture graphique MVP.
 *
 * @note une instance de cette classe ne peut etre dupliquee.
 */
class Presentateur {

public:

  /**
   * Constructeur logique.
   *
   * @param[in] dimensionMinimum - la valeur de @ref _dimensionMinimum.
   * @param[in] dimensionMaximum - la valeur de @ref _dimensionMaximum.
   * @param[in] dimension - la resolution initiale.
   */
  Presentateur(const int& dimensionMinimum, 
	       const int& dimensionMaximum,
	       const int& resolution);

public:

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _dimensionMinimum.
   */
  const int& lireDimensionMinimum() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _dimensionMaximum.
   */
  const int& lireDimensionMaximum() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrModele.
   */
  const Jeu& lireModele() const;

  /**
   * Accesseur.
   *
   * @return la valeur de @ref _ptrVue.
   */
  const Vue& lireVue() const;

  /**
   * Retourne la dimension du modele associe a ce presentateur.
   *
   * @return la dimension du modele associe a ce presentateur.
   */
  const int& dimension() const;

public:
  /**
   * Demarre ce presentateur.
   */
  void demarrer();

protected:
  
  /**
   * Lance une nouvelle partie du Jeu.
   */
  void lancerPartie();

  /**
   * Change le modele associe a ce presentateur.
   *
   * @param[in] dimension - la dimension souhaitee.
   */
  void nouveauModele(const int& dimension);

  /**
   * Déplace la grenouille dans le Jeu.
   *
   * @param[in] ligne - la ligne souhaitee.
   * @param[in] colonne - la colonne souhaitee.
   */
  bool deplacerGrenouille(const int& ligne, const int& colonne);

  /**
   * Lance le vieillissement des éléments du Jeu.
   */
  bool vieillissement();

private:
  /**
   * Constructeur par recopie.
   *
   * @param[in] autre - l'instance a recopier.
   */
  Presentateur(const Presentateur& autre) = delete;

  /**
   * Operateur d'affectation.
   *
   * @param[in] autre - l'instance à recopier.
   * @return cette instance apres recopie.
   */
  Presentateur& operator=(const Presentateur& autre) = delete;

protected:

  /**
   * Dimension minimum du modele.
   */
  const int _dimensionMinimum;

  /**
   * Dimension maximum du modele.
   */
  const int _dimensionMaximum;

  /**
   * Modele associe a ce presentateur.
   */
  std::unique_ptr< Jeu > _ptrModele;

  /**
   * Vue associee a ce presentateur.
   */
  std::unique_ptr< Vue > _ptrVue;
  
  /**
   * Connecteur de slot à un évènement.
   */
  sigc::connection _conn;
  
  /**
   * Slot qui sera attaché à la méthode vieillissement.
   */
  const sigc::slot<bool> _vieillissement;
  
public:
	
	/**
	 * @class MandataireVue
	 * @brief MandataireVue du Presentateur du Jeu Grenouilloland.
	 *
	 * Declaration de la classe MandataireVue de la classe Presentateur
	 * communiquant avec la classe Vue amie.
	 */
	class MandataireVue
	{
		
		public :

			friend class Vue;		

		private :

			static void lancerPartie(Presentateur& presentateur)
			{
				presentateur.lancerPartie();
			}

			static void nouveauModele(Presentateur& presentateur, const int& dimension)
			{
				presentateur.nouveauModele(dimension);
			}
	};

	/**
	 * @class MandataireCaseGraphique
	 * @brief MandataireCaseGraphique du Presentateur du Jeu Grenouilloland.
	 *
	 * Declaration de la classe MandataireCaseGraphique de la classe Presentateur
	 * communiquant avec la classe CaseGraphique amie.
	 */
	class MandataireCaseGraphique
	{
		
		public :

			friend class CaseGraphique;		

		private :

			static bool deplacerGrenouille(Presentateur& presentateur, const int& ligne, const int& colonne)
			{
				return presentateur.deplacerGrenouille(ligne, colonne);
			}
	};

};
}

#endif
