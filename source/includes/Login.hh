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
	Login();
	virtual ~Login();
	void doLogin(Gtk::Entry* usuario, Gtk::Entry* clave );
};

}
#endif /*   __W_LOGIN_   */
