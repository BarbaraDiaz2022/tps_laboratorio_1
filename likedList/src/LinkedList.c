#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)		//validacion importante
    {
    	this->size = 0;		//inicializo el tamaño de la lista
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;		//el tamaño ya esta inicializado en la funcion anterior (en 0)
    }

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;	//creo el aux del puntero a nodo

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;	//apunto al primer nodo para empezar a recorrer la lista

		for(int i = 0; i < nodeIndex; i++)
		{
			pNode = pNode->pNextNode;	//recorro nodo a nodo y lo guardo en mi auxiliar
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this,int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;	//creo un auxiliar para reservar espacio de memoria para el nuevo nodo
    Node* pNodeAnterior = NULL;	//auxiliar para obtener el nodo en la posicion que sea != de la primera

    pNode = (Node*)malloc(sizeof(Node*));

    if(pNode != NULL && this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	pNode->pElement = pElement;	//guardo en mi nuevo nodo el elemento que me llega

    	if(nodeIndex == 0)	//si quisiera agregar el elemento al primero nodo se modifica la linkedlist
    	{
    		pNode->pNextNode = this->pFirstNode;	//el siguiente nodo de mi nuevo nodo va a ser el primero de la linkedlist ahora entonces se lo asigno
    		this->pFirstNode = pNode;				//marco al nodo auxiliar como primero de la linkedlist
    		pNode->pElement = pElement;				//guardo en el elemento del nodo el elemento q recibo por parametro
    		this->size++;							//incremento el tamaño de la linkedlist
    		//returnAux = 0;
    	}
    	else
    	{
    		pNodeAnterior = getNode(this, nodeIndex-1);

    		if(pNodeAnterior != NULL)
    		{
    			pNode->pNextNode = pNodeAnterior->pNextNode;	//al nextNode que voy a agregar, le asigno el nodo anterior para referenciarlo
    			pNodeAnterior->pNextNode = pNode;				//engancho la lista,lo que le sigue al anterior es el nuevo en cualquier posicion que este
    			pNode->pElement = pElement;
    			this->size++;
    			//returnAux = 0;
    		}
    	}
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento al final de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Retorna un elemento del nodo en el indice que recibe
 *
 * \param this LinkedList* Puntero a la lista
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL; //auxiliar en donde guardo el nodo que traigo

    if(this != NULL && index >= 0 && index<= ll_len(this))
    {
    	pNode = getNode(this, index);	//obtengo y guardo el nodo para acceder a su elemento

    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL; //auxiliar de tipo nodo que uso para buscar el elemento

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);	//obtengo y guardo el nodo para modificar su elemento

    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;	//agrego el elemento que recibi al campo del nodo
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;	//creo el auxiliar para guardar el nodo a borrar
    Node* pNodeAnterior = NULL; //creo otro auxiliar para guardar el previo

    if(this != NULL && index >=0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);	//obtengo el nodo que voy a borrar

    	if(pNode != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = pNode->pNextNode; //como modifico la linkedlist, el primer nodo de la linkedlist ahora va a apuntar al next node del nodo a borrar
				free(pNode);
				this->size--;
			}
			else
			{
				pNodeAnterior = getNode(this,index-1);

				if(pNodeAnterior != NULL)
				{
					pNodeAnterior->pNextNode = pNode->pNextNode;//al previo le asigno la direccion del que tenia el pNode(el nodo que estoy eliminando)
					free(pNode);							//uno el eslabon que estaba atras con el de adelante por sacar el del medio
					this->size--;
				}
			}

			returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this != NULL )
    {
    	len = ll_len(this);

    	if(len > 0)
    	{
    		for(int i = 0; i < len; i++)
			{
				ll_remove(this, 0);	//le paso 0 para no depender de la i q va variando sino que arranco a remover desde el principio en todas las iteraciones
			}

    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && ll_clear(this) == 0)	//llamo a ll_clear y si devuelve 0 es porque elimino los nodos de la lista
    {
    	free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(int i = 0; i < len; i++)
    	{	 //para retornar un elemento del nodo en el indice que recibe
    		if(ll_get(this, i) == pElement)	//comparo y en caso de ser iguales es porque el elemento existe
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))  //la diferencia entre addNode y ll_push es que addNode solo existe en esta biblioteca
    {
    	returnAux = addNode(this, index, pElement);	//agrego un elemento en el nodo en la posicion indicada
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pElementAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pElementAux = ll_get(this, index);  //primero obtengo y guardo el elemento que voy a borrar

    	if(pElementAux != NULL)
    	{
    		returnAux = pElementAux;
        	ll_remove(this, index);		//lo saco de la linkedlist
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement) != -1)//devuelve el indice del nodo del elemento que le pida
    	{
    		returnAux = 1;	//si la linkedlist contiene el elemento, retorno 1
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int lenThis2;
    void* pElementAux = NULL;

    if(this != NULL && this != NULL)
    {
		lenThis2 = ll_len(this2); //obtengo el tamaño de la lista 2 para recorrerla y evaluar si algun elemento de la lista 1 no esta contenido

		returnAux = 1; //contiene los elementos

		for(int i = 0; i < lenThis2; i++)
		{
			pElementAux = ll_get(this, i);

			if(ll_contains(this, pElementAux) == 0) //si algun elemento de la lista 2 no estan contenidos en la lista 1
			{
				returnAux = 0;  //no contiene los elementos
				break;
			}
		}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementAux = NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(int i = from; i < to; i++)
    		{
    			pElementAux = ll_get(this, i);
    			ll_add(cloneArray, pElementAux);
    		}
    	}
    }

    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL )
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int flagOrdenado; //para romper el ordenamiento si ya esta ordenado
    int len;
    void* auxElementoUno;
    void* auxElementoDos;

    if(this != NULL && (order == 0 || order == 1) && pFunc != NULL)
    {
    	len = ll_len(this);

    	do
    	{
    		flagOrdenado = 1;
    		len--;

    		for(int i = 0; i < len; i++)
    		{
    			auxElementoUno = ll_get(this, i); //obtengo los elementos de las distintas posiciones para compararlos
    			auxElementoDos = ll_get(this, i +1);

    			if((order == 1 && pFunc(auxElementoUno, auxElementoDos) > 0) || (order == 0 && pFunc(auxElementoUno,auxElementoDos) < 0))
    			{
    				ll_set(this,i,auxElementoDos);
    				ll_set(this,i+1,auxElementoUno);
    				flagOrdenado = 0;
    			}
    		}
    	}while(flagOrdenado == 0);

    	returnAux = 0;
    }

    return returnAux;
}

/*
 * brief recibe una lista y llama a la funcion criterio para determinar si un elemento sera agregado a la nueva lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return retorna la linkedlist con los items correspondientes
 * LinkedList* ll_filter(LinkedList* this, int(*pFun)(void* element))
{
	int len;
	void* auxElemento;
	LinkedList* newLinkedList = NULL; //la nueva lista que va a ser retornada

	newLinkedList = ll_newLinkedList(); //la creo de forma dinamica

	if(this != NULL && pFun != NULL)
	{
		len = ll_len(this);

		for(int i = 0; i < len; i++)
		{
			auxElemento = ll_get(this, i);

			if(pFun(auxElemento) == 0)
			{
				ll_add(newLinkedList, auxElemento);
			}
		}
	}

	return newLinkedList;
}

 * brief recibe una lista y llama a la funcion criterio para determinar si un elemento sera agregado a la nueva lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return retorna la linkedlist con los campos promedios correspondientes agregados a la nueva lista
LinkedList* ll_map(LinkedList* this, void*(*pFun)(void* element))
{
	int len;
	LinkedList* newLinkedList = ll_newLinkedList();
	Jugador* auxElement;

	if(this != NULL && pFun != NULL)
	{
		len = ll_len(this);

		for(int i = 0; i < len; i++)
		{
			auxElement = ll_get(this, i);

			pFun(auxElement); //le paso el elemento y calcula el campo promedio

			ll_add(newLinkedList, auxElement);
		}
	}

	return newLinkedList;
}*/

/*case dondeusellsort:
	if(ll_isEmpty(lista)==0)
	{
		listaPrimeraClase = ll_filter(lista, primeraClase);
		if(controller_saveAsPassengersFirstClass("PPrimeraClase.csv", listaPrimeraClase)==0)
		{
			printf("\nSe han cargado correctamente los pasajeros de primera clase\n");
		}
	}
	else
	{
		printf("\nNo hay pasajeros cargados\n");
	}
	break;
case dondeusellmap:
	if(ll_isEmpty(lista)==0)
	{
		listaConMillas = ll_map(lista, calcular);
		controller_ListPassengerWithMillas(listaConMillas);
	}
	else
	{
		printf("\nNo hay pasajeros cargados para filtrar\n");
	}
	break;

int primeraClase(void* element)
{
	int retorno = -1;
	int auxTipoDePasajero;

	if(element != NULL)
	{
		Passenger_getTipoPasajero((Passenger*)element, &auxTipoDePasajero);
		if(auxTipoDePasajero == 1) //si el getter me traia 1 era porque el pasajero era de primera clase entonces retorno que si pertenece
		{
			retorno = 0;
		}

	}

	return retorno;
}



void calcular(void* element)
{
//	Passenger* auxPassenger;
	float auxPrecio;
	int auxTipoDePasajero;
	float millas;

	if(element != NULL)
	{
		Passenger_getPrecio((Passenger*)element, &auxPrecio);
		Passenger_getTipoPasajero((Passenger*)element, &auxTipoDePasajero);

		millas = auxPrecio / 100;

		if(auxTipoDePasajero == 1)
		{
			millas = millas * 2;
		}
		else if(auxTipoDePasajero == 2)
		{
			millas = millas * 3;
		}

		Passenger_setMillas((Passenger*)element, millas);
	}
}

 *
 * */
