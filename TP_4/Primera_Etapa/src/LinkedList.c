#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#define FALSE -1
#define TRUE 0

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList *this;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this)
{
	int returnAux;

	returnAux = FALSE;
	if (this != NULL)
	{
		returnAux = this->size;
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
static Node* getNode(LinkedList *this, int nodeIndex)
{
	Node *getNode;
	int i;

	getNode = NULL;
	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		getNode = this->pFirstNode;
		for (i = 0; i < nodeIndex; i++)
		{
			getNode = getNode->pNextNode;
		}
	}

	return getNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex)
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
static int addNode(LinkedList *this, int nodeIndex, void *pElement)
{
	int returnAux;
	Node *prevNode;
	Node *newNode;

	prevNode = NULL;
	newNode = (Node*) malloc(sizeof(Node));
	returnAux = FALSE;
	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && newNode != NULL)
	{
		newNode->pElement = pElement;
		newNode->pNextNode = NULL;

		if (nodeIndex == 0)
		{
			newNode->pNextNode = this->pFirstNode;
			this->pFirstNode = newNode;
		}
		else
		{
			prevNode = getNode(this, nodeIndex - 1);
			newNode->pNextNode = prevNode->pNextNode;
			prevNode->pNextNode = newNode;
		}
		this->size++;
		returnAux = TRUE;
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
int test_addNode(LinkedList *this, int nodeIndex, void *pElement)
{
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement)
{
	int returnAux;

	returnAux = FALSE;
	if (this != NULL)
	{
		if (addNode(this, ll_len(this), pElement) == TRUE)
		{
			returnAux = TRUE;
		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index)
{
	void *returnAux;
	Node *auxNode;

	returnAux = NULL;
	auxNode = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);
		if (auxNode != NULL)
		{
			returnAux = auxNode->pElement;
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
int ll_set(LinkedList *this, int index, void *pElement)
{
	int returnAux;
	Node *auxNode;

	auxNode = NULL;
	returnAux = FALSE;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);
		if (auxNode != NULL)
		{
			auxNode->pElement = pElement;
			returnAux = TRUE;
		}
	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index)
{
	int returnAux;
	Node *removeNode;
	Node *pPreviousNode;

	removeNode = NULL;
	pPreviousNode = NULL;
	returnAux = FALSE;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		removeNode = getNode(this, index);

		if (index == 0)
		{
			this->pFirstNode = removeNode->pNextNode;
		}
		else
		{
			pPreviousNode = getNode(this, index - 1);
			pPreviousNode->pNextNode = removeNode->pNextNode;
		}
		free(removeNode);
		this->size--;
		returnAux = TRUE;

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
int ll_clear(LinkedList *this)
{
	int returnAux;
	int lenLinkedList;

	returnAux = FALSE;
	if (this != NULL)
	{
		lenLinkedList = ll_len(this);
		while (lenLinkedList > 0)
		{
			ll_remove(this, 0);
			lenLinkedList--;
		}
		returnAux = TRUE;
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
int ll_deleteLinkedList(LinkedList *this)
{
	int returnAux;

	returnAux = FALSE;
	if (this != NULL)
	{
		if (ll_clear(this) == TRUE)
		{
			free(this);
			returnAux = TRUE;
		}
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
int ll_indexOf(LinkedList *this, void *pElement)
{
	int returnAux;
	int i;
	int sizeLinkedList;
	void *auxElement;

	auxElement = NULL;
	returnAux = FALSE;
	if (this != NULL)
	{
		sizeLinkedList = ll_len(this);
		for (i = 0; i < sizeLinkedList; i++)
		{
			auxElement = ll_get(this, i);
			if (auxElement == pElement)
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
int ll_isEmpty(LinkedList *this)
{
	int returnAux;

	returnAux = -1;
	if (this != NULL)
	{
		returnAux = 0;
		if (ll_len(this) == 0)
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
int ll_push(LinkedList *this, int index, void *pElement)
{
	int returnAux;

	returnAux = FALSE;
	if (this != NULL && index >= 0 && index <= ll_len(this))
	{
		if (addNode(this, index, pElement) == TRUE)
		{
			returnAux = TRUE;
		}
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
void* ll_pop(LinkedList *this, int index)
{
	void *returnAux;

	returnAux = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		returnAux = ll_get(this, index);
		ll_remove(this, index);
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
int ll_contains(LinkedList *this, void *pElement)
{
	int returnAux;

	returnAux = -1;
	if (this != NULL)
	{
		returnAux = 1;
		if (ll_indexOf(this, pElement) == FALSE)
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
int ll_containsAll(LinkedList *this, LinkedList *this2)
{
	int returnAux;
	int i;
	int sizeList2;
	void *pElement;

	pElement = NULL;
	returnAux = -1;
	if (this != NULL && this2 != NULL)
	{
		sizeList2 = ll_len(this2);
		returnAux = 0;
		for (i = 0; i < sizeList2; i++)
		{
			returnAux = 1;
			pElement = ll_get(this2, i);
			if (ll_contains(this, pElement) == 0)
			{
				returnAux = 0;
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
LinkedList* ll_subList(LinkedList *this, int from, int to)
{
	LinkedList *cloneArray;
	void *auxElement;
	int sizeList;
	int i;

	auxElement = NULL;
	cloneArray = NULL;
	if ((this != NULL))
	{
		sizeList = ll_len(this);
		if (from >= 0 && from <= sizeList && to > from && to <= sizeList)
		{
			cloneArray = ll_newLinkedList();
			for (i = from; i < to; i++)
			{
				auxElement = ll_get(this, i);
				ll_add(cloneArray, auxElement);
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
LinkedList* ll_clone(LinkedList *this)
{
	LinkedList *cloneArray;
	int sizeList;

	cloneArray = NULL;
	if (this != NULL)
	{
		sizeList = ll_len(this);
		cloneArray = ll_subList(this, 0, sizeList);
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
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order)
{
	int returnAux;
	int i;
	int j;
	int returnFunction;
	int sizeList;
	void *prevElement;
	void *nextElement;
	void *auxElment;

	prevElement = NULL;
	nextElement = NULL;
	auxElment = NULL;
	returnAux = FALSE;
	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		sizeList = ll_len(this);

		for (i = 0; i < sizeList - 1; i++)
		{
			for (j = i + 1; j < sizeList; j++)
			{
				prevElement = ll_get(this, i);
				nextElement = ll_get(this, j);
				returnFunction = pFunc(prevElement, nextElement);

				if ((returnFunction == 1 && order == 1) || (returnFunction == -1 && order == 0))
				{
					auxElment = nextElement;
					ll_set(this, j, prevElement);
					ll_set(this, i, auxElment);
					returnAux = TRUE;
				}
			}
		}
	}

	return returnAux;
}

