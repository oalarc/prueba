/*
 * @file Programa.hh
 *
 * @author Orlando Alarcon <orlando.alarcon.g@gmail.com>
 */
#ifndef __W_PROGRAMA_
#define __W_PROGRAMA_ 1

#include <iostream>
#include <gtkmm.h>
#include "../includes/resources.hh"
#include "../includes/screens/Welcome.hh"

using namespace std;
using namespace Gtk;

namespace WinProg{

/**
 * Estructura _fullMaps permite un manejo sencillo de mapas para Gdk::Pixbuf
 */
struct _fullMaps {
	/**
	 * @brief tamaño del mapa
	 */
	int size;

	/**
	 * @brief puntero al arreglo del mapa
	 */
	const guint8* maps;
} typedef fullMaps;

/**
 * @brief Ventana principal de administración
 */
class Programa : public Glib::Object{
private:
	int W_WIDTH;
	int W_HEIGHT;
	bool W_IS_RESIZSABLE;
	Glib::ustring W_TITULO;
	Window* w;

public:
	/**
	 * @brief Constructor
	 *
	 * Inicializa la ventana
	 */
	Programa();

	/**
	 * @brief Constructor 2
	 */
	Programa(const Glib::ustring titulo);

	/**
	 * @brief Constructor 3
	 */
	Programa(int width,
			int height,
			bool resizable,
			const Glib::ustring titulo);

	/**
	 * @brief Destructor
	 */
	virtual ~Programa();

	/**
	 * @brief Devuelve la instancia del Gtk::Window interno
	 *
	 * Retorna una instancia de Gtk::Window esto es útil para poder "arrancar"
	 * la aplicacion Gtk con Main::run
	 */
	Window* getWindow();

	/**
	 * TODO: @brief Borrar o cambiar
	 */
	void button1_onClick_Other();

	/**
	 * @brief Manejador de signed_clicked para el button1
	 */
	void button1_onClick();

	/**
	 * @brief LLena e inicializa el ToolItem Usuarios
	 */
	ToolItemGroup* fillButtonsUsers();

	/**
	 * @brief LLena e inicializa el ToolItem Clientes
	 */
	ToolItemGroup* fillButtonsClients();

	/**
	 * @brief LLena e inicializa el ToolItem Reportes
	 */
	ToolItemGroup* fillButtonsReports();

	/**
	 * @brief LLena e inicializa el ToolItem Codigos
	 */
	ToolItemGroup* fillButtonsCodes();

	/**
	 * @brief LLena e inicializa el ToolItem Respaldo
	 */
	ToolItemGroup* fillButtonsBackup();

	/**
	 * @brief Construye la paleta de herramientas
	 *
	 * Esta es una descripción de como es la fuente a ocupar y ese generada
	 * previamente en addElementsAtWindow
	 *
	 * @see addElementsAtWindow
	 *
	 * @param font el estilo de fuente para los botones de la paleta
	 *
	 * @return la paleta de herramientas lista
	 */
	ToolPalette* buildPalette(Pango::FontDescription* font);

	/**
	 * @brief Agrega los respectivos elementos a la ventana
	 *
	 * Inicializa e incorpora los elementos graficos necesarios para desplegar
	 * la ventana
	 */
	void addElementsAtWindow();

	/**
	 * @brief Inicializa y ajusta los componentes de la ventana
	 */
	void initializeWindow();

};

}

#endif /*  __W_PROGRAMA_   */
