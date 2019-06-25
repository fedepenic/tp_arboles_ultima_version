#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "cliente.h"
const int DESCUENTO_IND = 10;

class Individuo: public Cliente{

	public:

			int numero_de_telefono;

			string tipo_de_cliente;

			string nombre;
	
	public:
	
		//Descripcion: Metodo constructor de objetos de clase Individuo.
		//Precondiciones: Le llegan como parametros del metodos un numero que se encuentra dentro del dominio
		//del atributo numero_de_telefono de un objeto de clase Individuo junto con un nombre valido.
		//Postcondiciones: Se inicializan correctamente los atributos de un objeto de clase Individuo.
		Individuo(int numero, string nombre);

		//Descripcion: Se encarga de devolver el tipo de cliente del cual se esta trabajando.
		//Precondiciones: -. 
		//Postcondiciones: Se retrona una cadena de caracteres indicando el tipo de cliente con el cual se trabaja.
		string obtener_tipo_de_cliente();

		//Descripcion: Metodo virtual de la clase padre Cliente que se encarga de imprimir por pantalla el nombre del individuo.
		//Precondiciones: -.
		//Postcondiciones: El usuario visualiza por pantalla el nombre del individuo con el cual se esta trabajando.
		void listar_cliente();

		//Descripcion: Este metodo se encarga de devolver el atributo numero_de_telefono de un objeto de clase Individuo.
		//Precondiciones: -.
		//Postcondiciones: Se retorna correctamente el numero de telefono de un cliente.
		int obtener_numero_de_telefono();

	
};

#endif