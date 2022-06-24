#include <stdlib.h>
#include <assert.h>


typedef struct graph *Graph;
Graph graphCreate(int n);
void graphDestroy(Graph);
void graphAddEdge(Graph,int source , int sink);
int graphVertexCount(Graph);
int graphEdgeCount(Graph);
int graphOutDegree(Graph, int source);
int graphHasEdge(Graph, int source, int sink);
void graphForeach(Graph g, int source,
     void (*f)(Graph g,int source, int sink, void *data),
     void *data);

struct graph{
  int n;   /* number of vertices */
  int m;   /* number of edges */
  struct successors{
    int d;     /* number of successors */
    int len;    /* number of slots in array */
    int isSorted;  /* true if list is already sorted */
    int list[];    /* actual list of successors starts here */
  } *alist[];
};

Graph
graphCreate(int n)
{
  Graph g;
  int i;

  g=(Graph)malloc(sizeof(struct graph) + sizeof(struct successors *) * n);
  assert(g);
  g->n=n;
  g->m=0;
  for ( i=0; i< n; i++){
    g->alist[i]=(struct successors *)malloc(sizeof(struct successors));
    assert(g->alist[i]);
    g->alist[i]->d=0;
    g->alist[i]->len=0;
    g->alist[i]->isSorted=1;
  }
  return g;
}
void
graphDestroy(Graph g)
{
  int i;
  for(i=0; i< g->n; i++)
  free(g->alist[i]);
  free(g);
}
void
graphAddEdge(Graph g, int u, int v)
{
  assert(u>=0);
  assert(u<g->n);
  assert(v>=0);
  assert(v< g->n);

  while( g->alist[u]->d >=g->alist[u]->len){
    g->alist[u]->len = g->alist[u]->len*2 +1;
    g->alist[u]= realloc(g->alist[u],sizeof(struct successors) + sizeof(int) * g->alist[u]->len);
  }

  g->alist[u]->list[g->alist[u]->d++] = v;
  g->alist[u]->isSorted =0;

  g->m++;
}

int
graphVertexCount(Graph g)
{
  return g->n;
}

int
graphEdgeCount(Graph g)
{
  return g->m;
}

int graphOutDegree(Graph g, int source)
{
  assert(source >=0 );
  assert(source < g->n);

  return g->alist[source]->d;
}

#define BSEARCH_THRESHOLD (10)

static  int
intcmp(const void *a, const void *b)
{
  return *((const int*)a) - *((const int *)b);
}

int
graphHasEdge(Graph g, int source, int sink)
{
  int i;

  assert(source >=0);
  assert(source < g->n);
  assert(sink >=0);
  assert(sink < g->n);

  if(graphOutDegree(g,source) >=BSEARCH_THRESHOLD){
    if(! g->alist[source]->isSorted){
      qsort(g->alist[source]->list, g->alist[source]->d,sizeof(int),intcmp);
    }
    return
      bsearch(&sink,
              g->alist[source]->list,
              g->alist[source]->d,
              sizeof(int),
              intcmp) !=0;
  }else {
    for(i=0; i < g->alist[source]->d; i++) {
      if(g->alist[source]->list[i] ==sink) return 1;
    }

    return 0;
  }
}

void
graphForeach(Graph g, int source ,
   void (*f)(Graph g,int source, int sink, void *data),
   void *data)
{
  int i;
  assert(source >=0);
  assert(source < g->n);

  for(i =0;i < g->alist[source]->d; i++){
    f(g, source , g->alist[source]->list[i], data);
  }
}

#define TEST_SIZE (37)
/* never call this */
static void
matchSink(Graph g, int source, int sink, void *data)
{
    assert(data && sink == *((int *) data));
}

int
main(int argc,char **argv)
{
  Graph g;
int i;
int j;

g = graphCreate(TEST_SIZE);

assert(graphVertexCount(g) == TEST_SIZE);

/* check it's empty */
for(i = 0; i < TEST_SIZE; i++) {
    for(j = 0; j < TEST_SIZE; j++) {
        assert(graphHasEdge(g, i, j) == 0);
    }
}

/* check it's empty again */
for(i = 0; i < TEST_SIZE; i++) {
    assert(graphOutDegree(g, i) == 0);
    graphForeach(g, i, matchSink, 0);
}

/* check edge count */
assert(graphEdgeCount(g) == 0);

/* fill in the diagonal */
for(i = 0; i < TEST_SIZE; i++) {
    graphAddEdge(g, i, i);
}

/* check */
assert(graphEdgeCount(g) == TEST_SIZE);

for(i = 0; i < TEST_SIZE; i++) {
    for(j = 0; j < TEST_SIZE; j++) {
        assert(graphHasEdge(g, i, j) == (i == j));
    }
}

for(i = 0; i < TEST_SIZE; i++) {
    assert(graphOutDegree(g, i) == 1);
    graphForeach(g, i, matchSink, &i);
}


/* fill in all the entries */
for(i = 0; i < TEST_SIZE; i++) {
    for(j = 0; j < TEST_SIZE; j++) {
        if(i != j) graphAddEdge(g, i, j);
    }
}

/* test they are all there */
assert(graphEdgeCount(g) == TEST_SIZE * TEST_SIZE);

for(i = 0; i < TEST_SIZE; i++) {
    assert(graphOutDegree(g, i) == TEST_SIZE);
    for(j = 0; j < TEST_SIZE; j++) {
        assert(graphHasEdge(g, i, j) == 1);
    }
}

/* free it */
graphDestroy(g);

return 0;
}
