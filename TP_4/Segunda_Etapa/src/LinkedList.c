/*
 * LinkedList.c
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */
#include "LinkedList.h"
#define FALSE -1
#define TRUE 0

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

Node* getNode(LinkedList *this, int nodeIndex)
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

int addNode(LinkedList *this, int nodeIndex, void *pElement)
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
