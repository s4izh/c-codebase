#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  void *next;
  /* struct Node *prev; */
} Node;

Node *head = NULL;

// add a node to the list

Node* add_node(int value)
{
  Node *new = malloc(sizeof(Node));

  if (new == NULL) return NULL;

  new->value = value;

  if (head == NULL) new->next = NULL;
  else new->next = head;

  head = new;
  return new;
}

Node *add_node_position(int value, int position)
{
  Node *new = malloc(sizeof(Node));

  if (new == NULL) return NULL;

  new->value = value;

  Node *current = head;
  Node *prev = head;

  while (position > 0 && current != NULL)
  {
    prev = current;
    current = prev->next;
    --position;
  }

  if (position != 0) return NULL;

  if (current == NULL)
    new->next = NULL;
  else new->next = current;

  if (current == head)
    head = new;
  else prev->next = new;

  return new;
}

// remove a node from the list

void remove_head()
{
  Node *removed = head;
  head = removed->next;
  free(removed);
}


// options

void print_list()
{
  Node* current = head;

  while(current != NULL) {
    printf("%d->", current->value);
    current = current->next;
  }
  printf("\n");
  return;
}

void print_options()
{
  printf("Options:\n");
  printf("\t1) add an element to the list head\n");
  printf("\t2) add an element in a given position\n");
  printf("\t3) remove an element from the list head\n");
  printf("\t4) remove an element from a given position\n");
  printf("\t5) print the list\n");
  printf("\t6) exit\n");
}

int main (int argc, char *argv[])
{
  print_options();

  int option = 0;

  while (option != 6)
  {
    scanf("%d", &option);
    int value, position;
    Node *new;

    switch (option) {
      case 1:
        scanf("%d", &value);
        new = add_node(value);
        print_list();
        break;
      case 2:
        scanf("%d", &value);
        scanf("%d", &position);
        new = add_node_position(value, position);
        print_list();
        break;
      case 3:
        remove_head();
        print_list();
        break;
      case 4:
        printf("remove an element from a given position\n");
        break;
      case 5:
        printf("printing the list\n");
        print_list();
        break;
      case 6:
        printf("exit\n");
        break;
      default:
        printf("invalid option\n");
        break;
    }
  }

  return 0;
}
