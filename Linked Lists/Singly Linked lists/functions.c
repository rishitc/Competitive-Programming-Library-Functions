#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *ptr;
} node;

node * add_element(node *ll, int n)
{
	node *lll = ll;

	if (ll == NULL)	
	{
		ll = malloc(sizeof(node));
		ll->num = n;
		ll->ptr = NULL;
		return ll;
	} else {
	while (ll->ptr != NULL)
	{
		ll = ll->ptr;
	}
	ll->ptr = malloc(sizeof(node));
	ll = ll->ptr;
	ll->num = n;
	ll->ptr = NULL;
	return lll;
}
}

node * priority_insert(node *lll, int n)
{
	if (lll == NULL)									
	{													
		lll = malloc(sizeof(node));
		lll->num = n;
		lll->ptr = NULL; 
		return lll;
	}
	node *ll = lll;
	node *temp1 = NULL;
	while ((n >= (ll->num)) && ((ll->ptr) != NULL))		
	{
		temp1 = ll;
		ll = ll->ptr;
	}
	if (n < ll->num){									
		if (ll == lll)										
		{
			node *temp = ll;								
			ll = malloc(sizeof(node));						
			ll->num = n;
			ll->ptr = temp;
			return ll;										
		}													
		temp1->ptr = malloc(sizeof(node));					
		(temp1->ptr)->num = n;								
		(temp1->ptr)->ptr = ll;
		
		return lll;											
	} else if (ll->ptr == NULL)								
		{													
			ll->ptr = malloc(sizeof(node));
			ll = ll->ptr;
			ll->num = n;
			ll->ptr = NULL;
			return lll;
		}
}

void display_list(node *ll)
{
	if (ll == NULL)
	{
		printf("Nothing here!\n");
	} else {

	while (ll->ptr != NULL)
	{
		printf("%d ", ll->num);
		ll = ll->ptr;
	}printf("%d\n", ll->num);
}
}

void last_element(node *ll)
{
	while (ll->ptr != NULL)
	{
		ll = ll->ptr;
	}
	printf("Last element: %d\n", ll->num);
}

void free_list(node *ll)
{
	node *l1; node *l2;
	l1 = ll;
	l2 = l1;
	while (l2 != NULL)
	{
		l2 = l1->ptr;
		free(l1);
		l1 = l2;
	}
}

int sum_of_all_nodes(node *ll)
{
	int sum = 0;
	while (ll->ptr != NULL)
	{
		sum+= ll->num;
		ll = ll->ptr;
	}
	sum+=ll->num;
	return sum;

}

int no_of_elements(node *ll)
{
	int n = 0;
	while (ll->ptr != NULL)
	{
		n+=1;
		ll = ll->ptr;
	}
	n+=1;
	return n;
}
int middle_element(node *ll)
{
	int n = no_of_elements(ll);
	n = n / 2;
	for (int i = 0; i < n; i++)
	{
		ll = ll->ptr;
		// printf("%d ", ll->num);
	}
	return ll->num;

}

node * copy_list(node *ll2)
{
	node *ll1 = NULL;
	while (ll2->ptr != NULL)
	{
		ll1 = add_element(ll1, ll2->num);
		ll2 = ll2->ptr;
	}
	ll1 = add_element(ll1, ll2->num);
	return ll1;
	
}

node * reverse_list(node *ll)
{	
	node *p, *q, *r;
	p = ll;
	q = p->ptr;
	r = p->ptr->ptr;
	p->ptr = NULL;
	while (r->ptr != NULL)
	{
		q->ptr = p;
		p = q;
		q = r;
		r = r -> ptr;
	}
	q->ptr = p;
	r->ptr = q;
	return r;
}

void delete_all(node *ll, int n)
{
	node *temp = ll;
	while (ll->ptr != NULL)
	{
		ll = ll->ptr;
		if (ll->num == n)
		{
			ll = ll->ptr;
			// free(temp->ptr);
			printf("%d\n", ll->ptr->num);
			temp->ptr = ll;
		} else {
			temp = temp->ptr;
		}

	}

}

