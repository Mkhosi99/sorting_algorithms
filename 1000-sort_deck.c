#include "deck.h"

int strngCmpre(const char *st1, const char *st2);
char fetchValue(deck_node_t *m_card);
void insertSort_deckKind(deck_node_t **m_deck);
void insertSort_deckVal(deck_node_t **m_deck);
void sort_deck(deck_node_t **deck);

/**
 * strngCmpre - Function compares two strings.
 * @st1: The first string that will be compared.
 * @st2: The second string that will be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int strngCmpre(const char *st1, const char *st2)
{
	while (*st1 && *st2 && *st1 == *st2)
	{
		st1++;
		st2++;
	}

	if (*st1 != *st2)
		return (*st1 - *st2);
	return (0);
}

/**
 * fetchValue - Function gets the numerical value of a card.
 * @m_card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char fetchValue(deck_node_t *m_card)
{
	if (strngCmpre(m_card->card->value, "Ace") == 0)
		return (0);
	if (strngCmpre(m_card->card->value, "1") == 0)
		return (1);
	if (strngCmpre(m_card->card->value, "2") == 0)
		return (2);
	if (strngCmpre(m_card->card->value, "3") == 0)
		return (3);
	if (strngCmpre(m_card->card->value, "4") == 0)
		return (4);
	if (strngCmpre(m_card->card->value, "5") == 0)
		return (5);
	if (strngCmpre(m_card->card->value, "6") == 0)
		return (6);
	if (strngCmpre(m_card->card->value, "7") == 0)
		return (7);
	if (strngCmpre(m_card->card->value, "8") == 0)
		return (8);
	if (strngCmpre(m_card->card->value, "9") == 0)
		return (9);
	if (strngCmpre(m_card->card->value, "10") == 0)
		return (10);
	if (strngCmpre(m_card->card->value, "Jack") == 0)
		return (11);
	if (strngCmpre(m_card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertSort_deckKind - Will sort a deck of cards from spades to diamonds.
 * @m_deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertSort_deckKind(deck_node_t **m_deck)
{
	deck_node_t *iterate, *place, *tempo;

	for (iterate = (*m_deck)->next; iterate != NULL; iterate = tempo)
	{
		tempo = iterate->next;
		place = iterate->prev;
		while (place != NULL && place->card->kind > iterate->card->kind)
		{
			place->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = place;
			iterate->prev = place->prev;
			iterate->next = place;
			if (place->prev != NULL)
				place->prev->next = iterate;
			else
				*m_deck = iterate;
			place->prev = iterate;
			place = iterate->prev;
		}
	}
}

/**
 * insertSort_deckVal - Will sort a deck of cards sorted from
 *                      spades to diamonds from ace to king.
 * @m_deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertSort_deckVal(deck_node_t **m_deck)
{
	deck_node_t *iterate, *place, *tempo;

	for (iterate = (*m_deck)->next; iterate != NULL; iterate = tempo)
	{
		tempo = iterate->next;
		place = iterate->prev;
		while (place != NULL &&
		       place->card->kind == iterate->card->kind &&
		       fetchValue(place) > fetchValue(iterate))
		{
			place->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = place;
			iterate->prev = place->prev;
			iterate->next = place;
			if (place->prev != NULL)
				place->prev->next = iterate;
			else
				*m_deck = iterate;
			place->prev = iterate;
			place = iterate->prev;
		}
	}
}

/**
 * sort_deck - Function will sort a deck of cards
 *             from ace to king and spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertSort_deckKind(deck);
	insertSort_deckVal(deck);
}
