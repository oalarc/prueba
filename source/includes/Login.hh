/**
 * @file Login.hh
 *
 * @author Orlando Alarcon <orlando.alarcon.g@gmail.com>
 */
#ifndef __W_LOGIN_
#define __W_LOGIN_ 1
#include <gtkmm.h>
#include <iostream>
#include "../includes/Programa.hh"
#include "../includes/resources.hh"


using namespace Gtk;

namespace WinProg{

class Login : public Gtk::Window{
public:
	/**
	 * @brief Constructor
	 */
	Login();

	/**
	 * @brief Destructor
	 */
	virtual ~Login();

	/**
	 * @brief ejecuta el autentificado del login
	 *
	 * @param usuario es el campo de texto del cual se extraerá el valor
	 * @param clave es el campo de texto del cual se extraerá el valor
	 */
	void doLogin(Gtk::Entry* usuario, Gtk::Entry* clave );
};

}
#endif /*   __W_LOGIN_   */
