/*
 * @file Login.cc
 *
 * @author Orlando Alarcon <orlando.alarcon.g@gmail.com>
 */
#include "../includes/Login.hh"

using namespace WinProg;

Login::Login(){
	/*
	 * Cajas base
	 */
	VBox* cajaPrincipal = new VBox(2);
	VBox* subCajaSuperior = new VBox(2);
	VBox* subCajaInferior = new VBox(2);


	/*
	 * Widgets parte superior
	 */
	Glib::RefPtr<Gdk::Pixbuf> mapLogo =
			Gdk::Pixbuf::create_from_inline(
					sizeof(logo_final) / sizeof(guint8), logo_final, false);
	/*
	 * Icono de la ventana
	 */
	Glib::RefPtr<Gdk::Pixbuf> icono =
				Gdk::Pixbuf::create_from_inline(
						sizeof(icon64) / sizeof(guint8), icon64, false);

	Image* logo = new Image(mapLogo);

	VButtonBox* auxButLabel = new VButtonBox();
	Pango::FontDescription* descripcion = new Pango::FontDescription();
	Label* titulo = new Label("Sistema Peaje");

	/*
	 * Widgets parte inferior
	 */
	VButtonBox* cajaButArriba = new VButtonBox();
	HButtonBox* cajaButAbajo = new HButtonBox();
	Table* tabla = new Table(2, 2, false);

	/*
	 * Widget cajaArriba
	 */
	Label* labelUsuario = new Label("Usuario:");
	Label* labelClave = new Label("Clave:");
	Entry* entryUsuario = new Entry();
	Entry* entryClave = new Entry();

	/*
	 * Widget cajaAbajo
	 */
	Button* botonEntrar = new Button("Entrar");


	/*
	 * empaquetado parte1
	 */
	descripcion->set_family("OpenSymbol");
	descripcion->set_size(20 * Pango::SCALE);
	descripcion->set_style(Pango::STYLE_ITALIC);
	descripcion->set_weight(Pango::WEIGHT_BOLD);

	titulo->modify_font(*descripcion);
	titulo->modify_fg(STATE_NORMAL, Gdk::Color("orange"));

	auxButLabel->add(*titulo);

	/*
	 * empaquetado parte 2
	 */
	entryClave->set_visibility(false);
	tabla->attach(*labelUsuario, 0, 1, 0, 1);
	tabla->attach(*labelClave, 0, 1, 1, 2);
	tabla->attach(*entryUsuario, 1, 2, 0, 1);
	tabla->attach(*entryClave, 1, 2, 1, 2);

	cajaButArriba->set_homogeneous();
	cajaButArriba->add(*tabla);

	botonEntrar->signal_clicked().connect( sigc::bind(
			sigc::mem_fun(*this, &Login::doLogin),
			entryUsuario,
			entryClave));
	cajaButAbajo->set_homogeneous(false);
	cajaButAbajo->add(*botonEntrar);

	/*
	 * empaquetado parte 3
	 */

	subCajaSuperior->set_homogeneous(false);
	subCajaSuperior->pack_start(*logo, true, true, 0);
	subCajaSuperior->pack_end(*auxButLabel, false, false, 5);


	subCajaInferior->set_homogeneous(false);
	subCajaInferior->pack_start(*cajaButArriba, false, true, 18);
	subCajaInferior->pack_end(*cajaButAbajo, false, true, 18);

	cajaPrincipal->set_homogeneous(false);
	cajaPrincipal->pack_start(*subCajaSuperior, true, true, 0);
	cajaPrincipal->pack_start(*subCajaInferior, false, false, 0);

	add(*cajaPrincipal);

	set_resizable(false);
	set_position(WIN_POS_CENTER_ALWAYS);
	set_size_request(300, 400);
	set_icon(icono);
	set_title("Login Sistema Peaje");
	show_all();
}

Login::~Login(){
}

void Login::doLogin(Gtk::Entry* usuario, Gtk::Entry* clave){

	//TODO: borrar printf
	std::cout << usuario->get_text() << std::endl;
	std::cout << clave->get_text() << std::endl;


	if(usuario->get_text().compare("admin") == 0){



		Programa* pa = new Programa(800, 600, false, "Sistema Peaje");
		pa->initializeWindow();
		pa->getWindow()->show_all();
		delete this;
	}
	else{
		Gtk::MessageDialog* d = new MessageDialog("No se pudo acceder",
				false, MESSAGE_WARNING, BUTTONS_CLOSE, true);
		d->set_title("Problemas al acceder");
		d->set_secondary_text("El usuario o la clave son incorrectos, "
				"intente nuevamente");
		int opcion = d->run();

		switch(opcion)
		{
			case(Gtk::RESPONSE_CLOSE):
			{
				delete d;

			}

		}
	}
}
