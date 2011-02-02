/*
 * @file Main.cc
 *
 * @author Orlando Alarcon <orlando.alarcon.g@gmail.com>
 */
#ifndef NULL
#define NULL ((void *) 0)
#endif

#include <iostream>
#include <gtkmm.h>
#include "includes/Programa.hh"
#include "includes/Login.hh"

using namespace std;
using namespace Gtk;
using namespace WinProg;

int main(int argc, char *argv[]){
	Main kit(argc, argv);

	/*TODO:BORRAR
	 Programa* p = new Programa(800, 600, false, "Sistema Peaje");
	p->initializeWindow();

	Window* w = p->getWindow();*/

	Login* p = new Login();
	kit.run(*p);
    delete p;

	return 0;
}
