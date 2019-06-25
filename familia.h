#ifndef FAMILIA_H
#define FAMILIA_H

#include "cliente.h"

const int DESCUENTO_FAM = 35;

class Familia:public Cliente{

	private:

		int numero_de_telefono;

		string tipo_de_cliente;

		Lista* miembros;


	public:


		//Descripcion: Metodo constructor de objetos de clase Familia.
		//Precondiciones: Le llegan como parametros del metodo un numero que se encuentra dentro del dominio
		//de los atributos numero_de_telefono de los objetos de clase Familia, junto con una lista de cadena 
		//de caracteres, la cual contiene los nombres de todos los miembros de la familia.
		//Postcondiciones: Se inicializan correctamente todos los atributos de un objeto de clase Familia.
		Familia(int numero,Lista* miembros);

		//Descripcion: Se encarga de devolver el tipo de cliente del cual se esta trabajando.
		//Precondiciones: -. 
		//Postcondiciones: Se retrona una cadena de caracteres indicando el tipo de cliente con el cual se trabaja.
		string obtener_tipo_de_cliente();

		//Descripcion: Metodo virtual de la clase padre Cliente que se encarga de imprimir por pantalla el nombre de todos 
		//los miembros de la familia.
		//Precondiciones: -.
		//Postcondiciones: El usuario visualiza por pantalla los nombres de todos los integrantes de la familia con la cual se esta trabajando.
		void listar_cliente();

		//Descripcion: Este metodo se encarga de devolver el numero de integrantes que posee la familia con la cual se esta trabajando.
		//Precondiciones: -.
		//Postcondiciones: El numero de integrantes que posee la familia es retornado correctamente.
		int cantidad_de_integrantes();

		//Descripcion: Este metodo se encarga de devolver el atributo numero_de_telefono de un objeto de clase Familia.
		//Precondiciones: -.
		//Postcondiciones: Se retorna correctamente el numero de telefono de un cliente.
		int obtener_numero_de_telefono();

		//Descripcion: Metodo destructor de objetos de clase Familia.
		//Precondiciones: -.
		//Postcondiciones: Se libera correctamente toda la memoria requerida para crear la lista de miembros de la familia. 
		~Familia();


	
};

#endif