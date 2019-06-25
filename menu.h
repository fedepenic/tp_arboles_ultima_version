#ifndef MENU_H
#define MENU_H

#include "abb.h"
#include "cliente.h"
#include "lista.h"
#include "individuo.h"
#include "familia.h"
#include <fstream>

class Menu{

	private:

		Abb arbol;
		int precio_fijo;

	public:

		Menu();
		void iniciar_interfaz(char const* archivo);
		~Menu();

	private:

		/* Descripcion: Ejecuta la opcion a los valores del valor del parametro recibido
		 * Pre: Opción tiene un valor dentro del rango 1 al 5
		 * Publicación:
		*/
		void  ejecutar_opcion ( int opcion);
		
		void leer_archivo(char const* archivo);
		void listar_clientes();
		void dar_de_baja();

		//Se toma como precondición que si el usuario no ingreso ningun precio fijo para los productos, este es igual a cero.
		void indicar_precio_fijo();
		void buscar_cliente();
		float calcular_precio_final(Nodo_abb* nodo);
		void guardar_dato(string linea);
		int generar_clave();
		void agregar_nuevo_cliente();
		void agregar_familia(int clave);
		void mostrar(Nodo_abb* nodo);
		void pre_orden(Nodo_abb* nodo);
		void agregar_cliente();
	
};
#endif