#include "menu.h"
#include <stdlib.h>

Menu::Menu(){
	arbol = Abb();
	precio_fijo = 0;
}

void Menu::guardar_dato(string linea){
	Lista* lista = new Lista();
	size_t pos_ini = 0;
	string nombre;

	size_t pos = linea.find(',');
 	string clave_aux = linea.substr(pos_ini,pos);
 	
 	while(pos != string::npos){
 		pos_ini = pos;
 		pos = linea.find(',',pos+1);
 		nombre = linea.substr(pos_ini+1,pos-(pos_ini+1));
 		if(pos != string::npos) lista->agregar(nombre,lista->tamanio()+1);
 				
 	}

 	int clave = atoi(clave_aux.c_str());

 	Cliente* cliente;
 	if(lista->tamanio() > 0){
 		Familia* familia = new Familia(clave,lista);
 		cliente = familia;
 	}
 	else {
 		delete lista;
 		Individuo* individuo = new Individuo(clave,nombre);
 		cliente = individuo;
 	}

 	
 	arbol.agregar_nodo(clave,cliente);
}

void Menu::leer_archivo(char const* archivo){
	string linea;
	ifstream archivo_clientes(archivo);
    while(getline(archivo_clientes,linea)){
    	guardar_dato(linea);
    }
    archivo_clientes.close();
}


void Menu::dar_de_baja(){
	int clave;

	cout << "ingrese el numero de telefono a dar de baja:" << endl;
	cin >> clave;


	bool se_dio_de_baja = arbol.eliminar_nodo(clave);
	if(se_dio_de_baja){
		cout << "el cliente se dio de baja correctamente" << endl;
	}
	else {
		cout << "el  numero de telefono no se encuentra vinculado a un cliente" << endl;
	}

}

void Menu::mostrar(Nodo_abb* nodo){
	Cliente* cliente = nodo->obtener_dato();
	cout << cliente->obtener_numero_de_telefono() <<" ";
	cliente->listar_cliente();
}

void Menu::in_orden(Nodo_abb* nodo){
	if(!nodo){
		return;
	}
	in_orden(nodo->obtener_izquierda());
	mostrar(nodo);
	cout<<"Y el monto que debe abonar por el producto es $";
	cout<<calcular_precio_final(nodo)<<endl<<endl;
	in_orden(nodo->obtener_derecha());
}

void Menu::listar_clientes(){
	in_orden(arbol.obtener_raiz());
}

void Menu::buscar_cliente(){
	int clave;
	cout << "ingrese el numero de telefono del cliente a buscar:" << endl;
	cin >> clave;

	Nodo_abb* nodo = arbol.buscar_nodo(clave);
	if(!nodo) cout << "el numero telefonico ingresado no se encuentra vinculado a un cliente" << endl;
	else {
		cout << "el cliente asociado al numero de telefono ingresado es:" << endl;
		mostrar(nodo);
		cout<<"Y el monto que debe abonar por el producto es $";
		cout<<calcular_precio_final(nodo)<<endl;
	}
}

int Menu::generar_clave(){
	int uno = 00000001;
	int clave = 00100030;
	bool no_encontrado = true;
	while(no_encontrado){
		if(arbol.buscar_nodo(clave)){
			clave += uno;
		}
		else no_encontrado = false;	
	}
	return clave;
	
}

void Menu::agregar_familia(int clave){
	Lista* lista = new Lista();
	char continuar;
	string nombre;
	do{
		cout << "ingrese el nombre del nuevo cliente:" << endl;
		cin >> nombre;

		cout << "va incorporar mas nombres,SI(s) o NO(n)" << endl;
		cin >> continuar;
		lista->agregar(nombre,lista->tamanio()+1);
	}while(continuar == 's');

	Familia* familia = new Familia(clave,lista);
	Cliente* cliente = familia;
	arbol.agregar_nodo(clave,cliente);
}

void Menu::agregar_nuevo_cliente(){
	int clave = generar_clave();
	int tipo;
	string nombre;
	cout << "que tipo de cliente va ingresar?:"<< endl;
	cout << "INDIVIDUO.....................[1]"<< endl;
	cout << "FAMILIA.......................[2]"<< endl;
	cin >> tipo;
	if(tipo == 2) agregar_familia(clave);
	else{
		cout << "ingrese el nombre del cliente:" <<endl;
		cin >> nombre;
		Individuo* individuo = new Individuo(clave,nombre);
		Cliente* cliente = individuo;
		arbol.agregar_nodo(clave,cliente);
	}
}

float Menu::calcular_precio_final(Nodo_abb* nodo){
	int cantidad_de_integrantes = 1;
	string tipo_de_cliente;
	Cliente* cliente = nodo->obtener_dato();
	if(cliente->obtener_tipo_de_cliente()=="familia"){
		Familia* cliente_familia = reinterpret_cast<Familia*>(cliente);
	 	cantidad_de_integrantes = cliente_familia->cantidad_de_integrantes();
	}
	float precio_final = cantidad_de_integrantes*(precio_fijo - ((precio_fijo*cliente->obtener_descuento())/100));

	return precio_final;
}

void Menu::indicar_precio_fijo(){
	cout<<endl<<"Por favor indique el precio fijo que tendrán los productos de todos los clientes: "<<endl;
	cin>>precio_fijo;
}

void  Menu::ejecutar_opcion( int opcion) {

	switch(opcion){
			case 1:
				agregar_nuevo_cliente();
			break;

			case 2:
				dar_de_baja();
			break;

			case 3:
				listar_clientes();
			break;

			case 4:
				buscar_cliente();
			break;

			case 5:
				indicar_precio_fijo();
			break;

			default:
				cout << "saliendo..." << endl;
		}
}



void Menu::iniciar_interfaz(char const* archivo){
	leer_archivo(archivo);
	int opcion;
	do{
		
		cout <<"*"<<" **********************************" <<"*"<< endl;
		cout <<"*"<<"           MENU DE OPCIONES        " <<"*"<< endl;
		cout <<"*"<<" Agregar un Nuevo Cliente       [1]" <<"*"<< endl;
		cout <<"*"<<" Dar de Baja un Cliente         [2]" <<"*"<< endl;
		cout <<"*"<<" Listar Clientes                [3]" <<"*"<< endl;
		cout <<"*"<<" Buscar un cliente              [4]" <<"*"<< endl;
		cout <<"*"<<" Indicar el precio fijo         [5]" <<"*"<< endl;
		cout <<"*"<<" Salir                          [6]" <<"*"<< endl;
		cout <<"*"<<"                                   " <<"*"<< endl;
		cout <<"*"<<"  Elija una de las Opciones:       " <<"*"<< endl;
		cout <<"*"<<" **********************************" <<"*"<< endl;

		cin >> opcion;

		ejecutar_opcion(opcion);

	}while(opcion != 6);	
}

Menu::~Menu(){
	
}