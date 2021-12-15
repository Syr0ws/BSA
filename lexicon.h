#ifndef _LEXICON_
#define _LEXICON_

typedef struct L_Node {

    char* word;
    struct L_Node* next;

} L_Node;

typedef struct Lexicon {

    L_Node* head;

} Lexicon;

Lexicon* create_lexicon();

int insert_begining_lexicon(Lexicon* lexicon, char* word);

void destruct_lexicon(Lexicon* lexicon);

void display_lexicon(Lexicon* lexicon);

float jaccard_index(Lexicon* lexicon1, Lexicon* lexicon2);

#endif