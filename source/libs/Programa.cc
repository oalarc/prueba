/*
 * @file Programa.cc
 *
 * @author Orlando Alarcon <orlando.alarcon.g@gmail.com>
 */
#include <stdexcept>
#include "../includes/Programa.hh"


using namespace WinProg;

Programa::Programa(){
	W_WIDTH = 800;
	W_HEIGHT = 600;
	W_IS_RESIZSABLE = true;
	W_TITULO = "Programa";
	this->w = new Window();
}

Programa::Programa(const Glib::ustring titulo){
	W_WIDTH = 800;
	W_HEIGHT = 600;
	W_IS_RESIZSABLE = true;
	W_TITULO = titulo;
	this->w = new Window();
}

Programa::Programa(int width,
		int height,
		bool resizable,
		const Glib::ustring titulo){
	W_WIDTH = width;
	W_HEIGHT = height;
	W_IS_RESIZSABLE = resizable;
	W_TITULO = titulo;
	this->w = new Window();
}

Programa::~Programa(){
	delete w;
};

Window* Programa::getWindow(){
	return w;
}

void Programa::button1_onClick_Other(){
	MessageDialog* dialogo = new MessageDialog("mensaje",
			false,
			Gtk::MESSAGE_INFO,
			Gtk::BUTTONS_OK,
			true);

	if(dialogo->run() == Gtk::RESPONSE_OK){
	}

	delete dialogo;
}

void Programa::button1_onClick(){

}

ToolItemGroup* Programa::fillButtonsUsers(){
	const int CANT = 2;
	int j = 0;
	ToolItemGroup* i = new ToolItemGroup();
	string but_label[2][CANT] = {
			{"Agregar", "Buscar"},
			{"Agrega un nuevo Usuario", "Busca un Usuario existente"}
	};

	/*
	 * Se agregan los Botones a los ToolItems que perteneceran al grupo
	 */
	for (j = 0; j < CANT; j++) {
		/*
		 * Por cada ciclo se generan nuevas instancias para el respectivo item
		 */
		ToolItem* auxItem = new ToolItem();
		Button* auxBut = new Button();
		HBox* auxBox = new HBox();
		Image* auxImg = new Image();
		Label* auxLabel = new Label(but_label[0][j]);

		switch(j){
		case 0:
			auxImg->set(Gtk::StockID(Gtk::Stock::ADD),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		case 1:
			auxImg->set(Gtk::StockID(Gtk::Stock::FIND),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		}

		auxBox->set_homogeneous(false);
		auxBox->pack_start(*auxImg, false, false, 0);
		auxBox->pack_end(*auxLabel, true, false, 0);

		auxBut->set_tooltip_text(but_label[1][j]);
		auxBut->add(*auxBox);
		auxBut->set_relief(RELIEF_NONE);

		auxItem->set_size_request(250, 35);
		auxItem->add(*auxBut);

		i->add(*auxItem);
	}

    return i;
}

ToolItemGroup* Programa::fillButtonsClients(){
	const int CANT = 2;
	int j = 0;
	ToolItemGroup* i = new ToolItemGroup();
	string but_label[2][CANT] = {
			{"Agregar", "Buscar"},
			{"Agrega un nuevo Cliente", "Busca un Cliente existente"}
	};

	/*
	 * Se agregan los Botones a los ToolItems que perteneceran al grupo
	 */
	for (j = 0; j < CANT; j++) {
		/*
		 * Por cada ciclo se generan nuevas instancias para el respectivo item
		 */
		ToolItem* auxItem = new ToolItem();
		Button* auxBut = new Button();
		HBox* auxBox = new HBox();
		Image* auxImg = new Image();
		Label* auxLabel = new Label(but_label[0][j]);

		switch(j){
		case 0:
			auxImg->set(Gtk::StockID(Gtk::Stock::ADD),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		case 1:
			auxImg->set(Gtk::StockID(Gtk::Stock::FIND),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		}

		auxBox->set_homogeneous(false);
		auxBox->pack_start(*auxImg, false, false, 0);
		auxBox->pack_end(*auxLabel, true, false, 0);

		auxBut->set_tooltip_text(but_label[1][j]);
		auxBut->add(*auxBox);
		auxBut->set_relief(RELIEF_NONE);

		auxItem->set_size_request(250, 35);
		auxItem->add(*auxBut);

		i->add(*auxItem);
	}

    return i;
}

ToolItemGroup* Programa::fillButtonsReports(){
	const int CANT = 3;
	int j = 0;
	ToolItemGroup* i = new ToolItemGroup();
	string but_label[2][CANT] = {
			{"Ventas", "Compras", "Boletas"},
			{"Lista las ventas por rango",
			"Lista las compras realizadas en un peridos de tiempo",
			"Lista las boletas diarias"}
	};

	/*
	 * Se agregan los Botones a los ToolItems que perteneceran al grupo
	 */
	for (j = 0; j < CANT; j++) {
		/*
		 * Por cada ciclo se generan nuevas instancias para el respectivo item
		 */
		ToolItem* auxItem = new ToolItem();
		Button* auxBut = new Button();
		HBox* auxBox = new HBox();
		Image* auxImg = new Image();
		Label* auxLabel = new Label(but_label[0][j]);

		switch(j){
		case 0:
			auxImg->set(Gtk::StockID(Gtk::Stock::FILE),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		case 1:
			auxImg->set(Gtk::StockID(Gtk::Stock::DND_MULTIPLE),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		case 2:
			auxImg->set(Gtk::StockID(Gtk::Stock::DND_MULTIPLE),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		}

		auxBox->set_homogeneous(false);
		auxBox->pack_start(*auxImg, false, false, 0);
		auxBox->pack_end(*auxLabel, true, false, 0);

		auxBut->set_tooltip_text(but_label[1][j]);
		auxBut->add(*auxBox);
		auxBut->set_relief(RELIEF_NONE);

		auxItem->set_size_request(250, 35);
		auxItem->add(*auxBut);

		i->add(*auxItem);
	}

    return i;
}

ToolItemGroup* Programa::fillButtonsCodes(){
	const int CANT = 2;
	int j = 0;
	ToolItemGroup* i = new ToolItemGroup();
	string but_label[2][CANT] = {
			{"Generar", "Buscar"},
			{"Agrega  codigos", "Busca codigos generados"}
	};

	/*
	 * Se agregan los Botones a los ToolItems que perteneceran al grupo
	 */
	for (j = 0; j < CANT; j++) {
		/*
		 * Por cada ciclo se generan nuevas instancias para el respectivo item
		 */
		ToolItem* auxItem = new ToolItem();
		Button* auxBut = new Button();
		HBox* auxBox = new HBox();
		Image* auxImg = new Image();
		Label* auxLabel = new Label(but_label[0][j]);

		switch(j){
		case 0:
			auxImg->set(Gtk::StockID(Gtk::Stock::NEW),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		case 1:
			auxImg->set(Gtk::StockID(Gtk::Stock::FIND),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		}

		auxBox->set_homogeneous(false);
		auxBox->pack_start(*auxImg, false, false, 0);
		auxBox->pack_end(*auxLabel, true, false, 0);

		auxBut->set_tooltip_text(but_label[1][j]);
		auxBut->add(*auxBox);
		auxBut->set_relief(RELIEF_NONE);

		auxItem->set_size_request(250, 35);
		auxItem->add(*auxBut);

		i->add(*auxItem);
	}

    return i;
}

ToolItemGroup* Programa::fillButtonsBackup(){
	const int CANT = 2;
	int j = 0;
	ToolItemGroup* i = new ToolItemGroup();
	string but_label[2][CANT] = {
			{"Importar", "Exportar"},
			{"Carga datos a la BD", "Realiza un respaldo de la BD"}
	};

	/*
	 * Se agregan los Botones a los ToolItems que perteneceran al grupo
	 */
	for (j = 0; j < CANT; j++) {
		/*
		 * Por cada ciclo se generan nuevas instancias para el respectivo item
		 */
		ToolItem* auxItem = new ToolItem();
		Button* auxBut = new Button();
		HBox* auxBox = new HBox();
		Image* auxImg = new Image();
		Label* auxLabel = new Label(but_label[0][j]);

		switch(j){
		case 0:
			auxImg->set(Gtk::StockID(Gtk::Stock::GO_BACK),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		case 1:
			auxImg->set(Gtk::StockID(Gtk::Stock::GO_FORWARD),
					*(new IconSize(ICON_SIZE_BUTTON)) );
			break;
		}

		auxBox->set_homogeneous(false);
		auxBox->pack_start(*auxImg, false, false, 0);
		auxBox->pack_end(*auxLabel, true, false, 0);

		auxBut->set_tooltip_text(but_label[1][j]);
		auxBut->add(*auxBox);
		auxBut->set_relief(RELIEF_NONE);

		auxItem->set_size_request(250, 35);
		auxItem->add(*auxBut);

		i->add(*auxItem);
	}

    return i;
}

ToolPalette* Programa::buildPalette(Pango::FontDescription* font){
	/*
	 * declaracion de variables
	 */
	const int CANTIDAD = 5;
	int count = 0;

	/*
	 * Paleta principal donde se insertaran los elementos
	 */
	ToolPalette* paleta = new ToolPalette();

	enum Buttons{
		B_USUARIOS,
		B_CLIENTES,
		B_INFORMES,
		B_CODIGOS,
		B_RESPALDO
	};
	/*
	 * Listado de nombres de los botones con sus correspondientes imagenes
	 */
	Glib::ustring names[CANTIDAD] =
			{"Usuarios", "Clientes", "Informes", "Códigos", "Respaldo"};

	/*
	 * carga de los mapas de bits correspondientes a las imagenes
	 */
	fullMaps maps[] = {
			{sizeof(contactsMap)/sizeof(guint8), contactsMap},
			{sizeof(contactsMap)/sizeof(guint8), contactsMap},
			{sizeof(calculatorMap)/sizeof(guint8), calculatorMap},
			{sizeof(settingsMap)/sizeof(guint8), settingsMap},
			{sizeof(itunesMap)/sizeof(guint8), itunesMap }
	};


	/*
	 * Ajuste de la paleta principal
	 *
	 * los ToolItems son agrupados e insertados al programa
	 */
	for(count = 0; count < CANTIDAD; count++){
		HBox* cajaBoton = new HBox(2);
		Label* la = new Label(names[count]);
		Image* im = new Image();

		/*
		 * creacion del los Pixbuf, de aqui se generara la imagen en memoria
		 * segun el mapa cargado previamente
		 */
		Glib::RefPtr<Gdk::Pixbuf> aux =
				Gdk::Pixbuf::create_from_inline(
						maps[count].size,
						maps[count].maps, false);

		/*
		 * Escalar el pixbuf original a 40px
		 */
		im->set(aux->scale_simple(40, 40, Gdk::INTERP_BILINEAR));

		la->modify_font(*font);

		/*
		 * Ajustar el contenedor (Widget) que se ocupara como label_widget
		 */
		cajaBoton->set_homogeneous(false);
		cajaBoton->pack_start(*im,PACK_SHRINK, 0);
		cajaBoton->pack_end(*la, true, true, 5);

		/*
		 * Importante: pare ver los resultado se debe indicar explicitamente
		 * al widget que ira dentro del ToolItemGroup, que se muestren tanto
		 * el contenedor mismo como sus hijos, de otra forma no se  observaran
		 * los cambios (en apariencia solo ocurre con los ToolItems)
		 */
		cajaBoton->show_all();

		/*
		 * Se crea y lego se ajusta la apariencia del ToolItemGroup con
		 * set_label_widget
		 */
		ToolItemGroup* i = NULL;

		switch(count)
		{

		case B_USUARIOS:
			i = fillButtonsUsers();
			break;
		case B_CLIENTES:
			i = fillButtonsClients();
			break;
		case B_INFORMES:
			i = fillButtonsReports();
			break;
		case B_CODIGOS:
			i = fillButtonsCodes();
			break;
		case B_RESPALDO:
			i = fillButtonsBackup();
			break;
		}

		/*
		 * Ajustes de estetica del ToolItemGroup
		 */
		i->set_collapsed(true);
		i->set_label_widget(*cajaBoton);

		/*
		 * Se agregan el grupo respectivo a la paleta
		 */
		paleta->add(*i);
	}

	return paleta;
}

void Programa::addElementsAtWindow(){
	/*
	 * Ajuste del tipo de fuente para los botones principales
	 */
	Pango::FontDescription* font = new Pango::FontDescription();
	font->set_family("OpenSymbol");
	font->set_weight(Pango::WEIGHT_BOLD);
	font->set_size(10 * Pango::SCALE);

	Frame* marco = new Frame();

	Label* nombreUsuario = new Label("Bienvenido: Nombre Usuario");

	/*
	 * Primer panel a insertar
	 */
	HButtonBox* part1 = new HButtonBox();

	/*
	 * Caja principal de 3 ranuras, toda la aplicacion se creara aqui
	 */
	VBox* mainBox = new VBox(3);

	HButtonBox* part3 = new HButtonBox();

	/*
	 * Paleta principal donde se insertaran los elementos
	 */
	ToolPalette* paleta = buildPalette(font);
	ScrolledWindow* scrollw = new ScrolledWindow();
	//TODO: borrar scrollw->set_hadjustment(Adjustment);
	scrollw->add(*paleta);

	/*
	 * Contenedores para organizar la ventanta
	 */
	HPaned* pan = new HPaned();


	/*
	 * Ajuste del font de nombre de usuario
	 */
	nombreUsuario->modify_font( *font );

	/*
	 * Empaquetado de los elementos en el primer panel
	 */
	part1->set_border_width(5);
	part1->set_homogeneous(false);
	part1->pack_start( *nombreUsuario, true, true, 0 );
	part1->pack_end( *( new Button("Salir")), false, false, 0 );

	Label* clock_label = new Label("00:00:00");

	clock_label->modify_font( *font);
	part3->set_layout(BUTTONBOX_END);
	part3->set_border_width(5);
	part3->pack_end( *clock_label, false, false, 0);

	pan->set_position(200);
    pan->pack1(*scrollw, Gtk::SHRINK);
	pan->pack2(*(new Welcome()), Gtk::EXPAND);

	marco->add( *pan );
	marco->set_shadow_type(SHADOW_IN);

	/*
	 * Ajuste del comportamiento del espaciado
	 *
	 * Es necesario especificar que los elementos no son homogeneos,
	 * luego las opciones de espaciado y relleno son concideradas de lo
	 * contrario las partes insertadas tendran el mismo tamaño (de ahi homogeneo)
	 */
	mainBox->set_homogeneous(false);
	mainBox->pack_start( *part1, false, false, 0 );
	mainBox->pack_start( *marco, true, true, 0);
	mainBox->pack_start( *part3, false, false, 0);

	w->add( *mainBox );

	w->show_all_children();
}

void Programa::initializeWindow(){
	Glib::RefPtr<Gdk::Pixbuf> icono =
				Gdk::Pixbuf::create_from_inline(
						sizeof(icon64) / sizeof(guint8), icon64, false);
	Settings::get_default()->property_gtk_button_images() = true;
	w->set_size_request(this->W_WIDTH, this->W_HEIGHT);
	w->set_position(WIN_POS_CENTER_ALWAYS);
	w->set_resizable(W_IS_RESIZSABLE);
	w->set_title(W_TITULO);
	w->set_icon(icono);

	addElementsAtWindow();
}
