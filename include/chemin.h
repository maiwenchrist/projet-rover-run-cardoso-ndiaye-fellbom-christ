//
// Created by rafaf on 12/11/2024.
//

#ifndef UNTITLED1_CHEMIN_H
#define UNTITLED1_CHEMIN_H




typedef struct s_node
{
    int value;
    struct s_node **sons;
    int nbSons;
} t_node;

typedef struct s_tree
{
    t_node **root ;
} t_tree ;

t_node* create_node(int val, int nb_sons);
t_tree create_tree();

#endif //UNTITLED1_CHEMIN_H