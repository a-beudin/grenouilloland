#ifndef _PointsDeVie_hh
#define _PointsDeVie_hh

#include <gtkmm/frame.h>

namespace grenouilloland {

/**
 * Declarations incompletes necessaires.
 */
class Vue;

/**
 * @class PointsDeVie PointsDeVie.hh
 * @brief Afficheur des points de vie de la Grenouille.
 * @author Yann Dauxais
 * @author Alexandre Beudin
 * @date 6.1.2013
 *
 * Declaration de la classe PointsDeVie representant l'affichage
 * des PointsDeVie et de la santé de la Grenouille. Les Widget
 * utilisés sont un label et une image.
 *
 * @note une instance de cette classe ne peut etre dupliquee.
 * 
 * @note chaque instance de cette classe est son propre listener.
 */
class PointsDeVie: public Gtk::Frame {

	/**
   	* Declaration d'amitié.
   	*/
  	friend class Vue;

	public:
	
		/**
   		* Constructeur logique.
   		*
   		* @param[in] titre - le titre du contour.
   		*/
		PointsDeVie(const Glib::ustring& titre);	
	
	protected:
		/**
   		* Met à jour l'image et le label selon l'état de la Grenouille
		* et son nombre de points de vie.
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
  		PointsDeVie(const PointsDeVie& autre) = delete;

  		/**
   		* Operateur d'affectation.
   		*
   		* @param[in] autre - l'instance à recopier.
   		* @return cette instance apres recopie.
   		*/
  		PointsDeVie& operator=(const PointsDeVie& autre) = delete;

	protected:

		/**
   		* Image.
   		*/
		Gtk::Image _imageCoeur;

		/**
   		* Label.
   		*/
		Gtk::Label _labelPv;

};
}

#endif
