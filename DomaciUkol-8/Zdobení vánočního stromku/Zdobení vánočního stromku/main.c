#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAX_BRANCHES             3
#define DECORATION_NONE          0
#define DECORATION_CANDLE        1
#define DECORATION_SPARKLER      2


typedef struct TNode
{
  struct TNode   * m_Parent;
  struct TNode   * m_Branches[MAX_BRANCHES];
  int              m_Decoration;
} TNODE;
#endif /* __PROGTEST__ */

int                easyToCatchFire    ( TNODE           * root )
{
    if (root->m_Branches[0] == NULL &&
        root->m_Branches[1] == NULL &&
        root->m_Branches[2] == NULL) {
        return 1;
    }
    if (root->m_Branches[0] != NULL && (root->m_Branches[0]->m_Decoration + root->m_Decoration == 3)) {
        return 0;
    }
    if (root->m_Branches[1] != NULL && (root->m_Branches[1]->m_Decoration + root->m_Decoration == 3)) {
        return 0;
    }
    if (root->m_Branches[2] != NULL && (root->m_Branches[2]->m_Decoration + root->m_Decoration == 3)) {
        return 0;
    }
    if (root->m_Branches[0] != NULL && root->m_Branches[1] != NULL && (root->m_Branches[0]->m_Decoration + root->m_Branches[1]->m_Decoration == 3)) {
        return 0;
    }
    if (root->m_Branches[1] != NULL && root->m_Branches[2] != NULL && (root->m_Branches[1]->m_Decoration + root->m_Branches[2]->m_Decoration == 3)) {
        return 0;
    }
    
        int res1 = 1, res2 = 1, res3 = 1;
        if (root->m_Branches[0] != NULL) {
            res1 = easyToCatchFire(root->m_Branches[0]);
        }
        if (root->m_Branches[1] != NULL) {
            res2 = easyToCatchFire(root->m_Branches[1]);
        }
        if (root->m_Branches[2] != NULL) {
            res3 = easyToCatchFire(root->m_Branches[2]);
        }
        if (res1 == 0 || res2 == 0 || res3 == 0) {
            return 0;
        
    }
    return 1;
}

int                cutBranch          ( TNODE          ** root,
                                        const char      * path )
{
    return 1;

}

int res (TNODE ** root, char * path, int decor) {
    int ind = (int)path[0] - 48;
    char newpath[strlen(path)-1];
    newpath[0] = '3';
    for (int i = 0; i<strlen(path)-1; i++) {
        newpath[i] = path[i+1];
    }
    if ((*root)->m_Branches[ind] == NULL) {
        (*root)->m_Branches[ind] = (TNODE*)malloc(sizeof(TNODE));
        (*root)->m_Branches[ind]->m_Parent = *root;
        (*root)->m_Branches[ind]->m_Branches[0] = NULL;
        (*root)->m_Branches[ind]->m_Branches[1] = NULL;
        (*root)->m_Branches[ind]->m_Branches[2] = NULL;
        (*root)->m_Branches[ind]->m_Decoration = 0;
    }
    if (newpath[0] == '3') {
        (*root)->m_Branches[ind]->m_Decoration = decor;
        return 1;
    }
    
    res(&(*root)->m_Branches[ind], newpath, decor);
    return 1;
}

int                setDecoration      ( TNODE          ** root,
                                        char      * path,
                                        int               decor )
{
    if (!*root) {
        *root = (TNODE*)malloc(sizeof(TNODE));
        (*root)->m_Decoration = 0;
        (*root)->m_Branches[0] = NULL;
        (*root)->m_Branches[1] = NULL;
        (*root)->m_Branches[2] = NULL;
        (*root)->m_Parent = NULL;
    }
    
    if (strcmp(path, "") == 0) {
        (*root)->m_Decoration = decor;
        return 1;
    }
    
    int ind = (int)path[0] - 48;
    char newpath[strlen(path)-1];
    newpath[0] = '3';
    for (int i = 0; i<strlen(path)-1; i++) {
        newpath[i] = path[i+1];
    }
    if ((*root)->m_Branches[ind] == NULL) {
        (*root)->m_Branches[ind] = (TNODE*)malloc(sizeof(TNODE));
        (*root)->m_Branches[ind]->m_Branches[0] = NULL;
        (*root)->m_Branches[ind]->m_Parent = *root;
        (*root)->m_Branches[ind]->m_Branches[1] = NULL;
        (*root)->m_Branches[ind]->m_Branches[2] = NULL;
        (*root)->m_Branches[ind]->m_Decoration = 0;
    }
    if (newpath[0] == '3') {
        (*root)->m_Branches[ind]->m_Decoration = decor;
        return 1;
    }
    
    res(&(*root)->m_Branches[ind], newpath, decor);
    return 1;
}

void               destroyTree        ( TNODE           * root )
{
    return;
}

#ifndef __PROGTEST__
int                main               ( void )
{
  TNODE * r;

  r = NULL;
  assert ( setDecoration ( &r, "000", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "001", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "002", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "1", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] != NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL
           && r -> m_Branches[1] -> m_Parent == r
           && r -> m_Branches[1] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "01", DECORATION_NONE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] != NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[1] -> m_Parent == r
           && r -> m_Branches[1] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] != NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[1] -> m_Parent == r
           && r -> m_Branches[1] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( easyToCatchFire ( r ) == 0 );
  destroyTree ( r );

  r = NULL;
  assert ( setDecoration ( &r, "000", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "002", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "2", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL
           && r -> m_Branches[2] -> m_Parent == r
           && r -> m_Branches[2] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( easyToCatchFire ( r ) == 0 );
  destroyTree ( r );

  r = NULL;
  assert ( setDecoration ( &r, "0001", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "000", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( easyToCatchFire ( r ) == 1 );
  destroyTree ( r );

  r = NULL;
  assert ( setDecoration ( &r, "012001", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[1]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "012002", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[1]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] -> m_Branches[0] -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( easyToCatchFire ( r ) == 1 );
  assert ( cutBranch ( &r, "0120" ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[1]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( easyToCatchFire ( r ) == 0 );
  destroyTree ( r );

  r = NULL;
  assert ( setDecoration ( &r, "0123", DECORATION_SPARKLER ) == 0 );
  assert ( r == NULL );
  assert ( cutBranch ( &r, "012" ) == 0 );
  assert ( r == NULL );
  assert ( easyToCatchFire ( r ) == 0 );
  destroyTree ( r );

  r = NULL;
  assert ( setDecoration ( &r, "012", DECORATION_SPARKLER ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[1]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( setDecoration ( &r, "011", DECORATION_CANDLE ) == 1 );
  assert ( r != NULL
           && r -> m_Parent == NULL
           && r -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] != NULL
           && r -> m_Branches[1] == NULL
           && r -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Parent == r
           && r -> m_Branches[0] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Parent == r -> m_Branches[0]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Decoration == DECORATION_NONE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] != NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] -> m_Parent == r -> m_Branches[0] -> m_Branches[1]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] -> m_Decoration == DECORATION_CANDLE
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[1] -> m_Branches[2] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Parent == r -> m_Branches[0] -> m_Branches[1]
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Decoration == DECORATION_SPARKLER
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[0] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[1] == NULL
           && r -> m_Branches[0] -> m_Branches[1] -> m_Branches[2] -> m_Branches[2] == NULL );
  assert ( easyToCatchFire ( r ) == 1 );
  assert ( cutBranch ( &r, "" ) == 1 );
  assert ( r == NULL );
  assert ( easyToCatchFire ( r ) == 0 );
  assert ( cutBranch ( &r, "" ) == 0 );
  assert ( r == NULL );
  destroyTree ( r );

  return 0;
}
#endif /* __PROGTEST__ */
