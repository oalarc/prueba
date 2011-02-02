/*
 * @file Welcome.cc
 *
 * @author Orlando Alarcon <orlando.alarcon.g@gmail.com>
 */

#include "../includes/screens/Welcome.hh";

using namespace WinProg;

Welcome::Welcome(){
	set_label("Bienvenido");
	add( *( new Button("mi boton")) );
}

Welcome::~Welcome(){

}
