#ifndef CLIENTE_H
#define CLIENTE_H

#include "lista.h"
#include <string>

class Cliente{

	private:

		int descuento;

	public:

		//Descripcion: Metodo constructor de objetos de clase Cliente. 
		//Precondiciones: Le llega como parametro del metodo un entero "descuento" que se encuentra
		//dentro del dominio del atributo "descuento" de objetos de clase Cliente.
		//Postcondiciones: Los atributos de un objeto de clase Cliente son inicializados correctamente.
		Cliente(int descuento);

		//Descripcion: Este metodo se encarga de retornar el porcentaje de descuento correspondiente al tipo 
		//de cliente que corresponda.
		//Precondiciones: -. 
		//Postcondiciones: El porcentaje de descuento al precio fijo es devuelto correctamente.
		virtual int obtener_descuento();

		//Descripcion: Metodo virtual que se encarga de listar los nombres de los clientes en las clases hijas.
		//Precondiciones: -.
		//Postcondiciones: En la clase cliente, este metodo es abstracto, por lo que no realiza ninguna accion.
		virtual void listar_cliente() = 0;

		//Descripcion: Es un metodo virtual que se encarga de devolver el tipo de cliente con el cual se esta trabajando.
		//Precondiciones: -.
		//Postcondiciones: En la clase Cliente no realiza ninguna tarea, solo se necesita en las clases hijas Individuo y Familia.
		virtual string obtener_tipo_de_cliente() = 0;

		//Descripcion: Es un metodo virtual que se encarga de obtener el numero de telefono de un cliente determinado.
		//Precondiciones: -. 
		//Postcondiciones: En la clase Cliente no realiza ninguna tarea, es un metodo abstracto, sin embargo, en las clases
		//hijas Individuo y Familia, devuelve el correspondiente numero de telefono de un cliente. 
		virtual int obtener_numero_de_telefono() = 0;
	
};




#endif