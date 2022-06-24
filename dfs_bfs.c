#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef int Vertex;

#define VERTEX_NULL (-1)

struct node{
  Vertex *neighbors;   //outgoing edge
  Vertex parent;     //for search
};

struct graph{
  size_t n;    // number of vertices
  struct node *v;    //list of verties
};

void
graphDestroy(struct graph *g)
{
  Vertex v;

  for(v=0; v< g->n; v++){
    free(g->v[v].neighbors);
  }
  free(g);
}

struct graph *
makeSampleGraph(size_t n)
{
  struct graph *g;
  Vertex v;
  const int allocNeighbors =4;
  int i;

  g=(struct graph *)malloc(sizeof(*g));
  assert(g);
  g->n=n;
  g->v=(struct node*)malloc(sizeof(struct node) *n);
  assert(g->v);

  for(v=0; v< n; v++) {
    g->v[v].parent = VERTEX_NULL;
    g->v[v].neighbors =(Vertex*)malloc(sizeof(Vertex)* allocNeighbors);
    i=0;
    if( v%2 ==0) {g->v[v].neighbors[i++]=v/2;}
    if(3*v < n) {g->v[v].neighbors[i++] = 3*v;}
    if(v+1 < n) { g->v[v].neighbors[i++]=v+1;}
    g->v[v].neighbors[i++]=VERTEX_NULL;
  }

  return g;
}

void
printGraph(const struct graph *g)
{
  Vertex u;
  size_t i;
  puts("digraph G{");

  for(u=0; u< g->n; u++){
     for(i=0; g->v[u].neighbors[i] !=VERTEX_NULL ; i++){
       printf("%d -> %d;\n",u,g->v[u].neighbors[i]);
     }
  }
  puts("}");
}

void
printPath(const struct graph *g, Vertex u)
{
  do{
    printf(" %d",u);
    u=g->v[u].parent;
  }while(g->v[u].parent !=u);
}

void
printTree(const struct graph *g)
{
  Vertex u;
  puts("digraph G{");

  for(u=0; u<g->n;u++) {
     if( g->v[u].parent !=VERTEX_NULL){
       printf("%d ->%d; \n",u,g->v[u].parent);
     }
  }
  puts("}");
}

static void
dfsHelper(struct graph *g, Vertex parent, Vertex child)
{
  int i;
  Vertex neighbor;
  if(g->v[child].parent == VERTEX_NULL) {
    g->v[child].parent =parent;
    for(i=0; (neighbor = g->v[child].neighbors[i]) !=VERTEX_NULL; i++){
      dfsHelper(g,child,neighbor);
    }
  }
}

void
dfs(struct graph *g, Vertex root)
{
  dfsHelper(g,root,root);
}

void
bfs(struct graph *g,Vertex root)
{
  Vertex *q;
  int head;
  int tail;
  Vertex current;
  Vertex nbr;
  int i;

  q=(Vertex*)malloc(sizeof(Vertex)* g->n);
  assert(q);

  head= tail=0;
  g->v[root].parent=root;
  q[tail++]=root;

  while(head < tail){
    current= q[head++];

    for(i=0; (nbr = g->v[current].neighbors[i])!= VERTEX_NULL; i++) {
      if(g->v[nbr].parent ==VERTEX_NULL) {
        g->v[nbr].parent = current;
        q[tail++]=nbr;
      }
    }
  }
  free(q);
}

int
main(int argc, char **argv)
{
  int n;

  struct graph *g;
  if(argc != 3) {
    fprintf(stderr, "Usage: %s action n\nwhere action =\n g - print graph\n d - print \
    dfs tree\n b - print bfs tree\n", argv[0]);
    return 1;
  }
  n = atoi(argv[2]);
  g = makeSampleGraph(n);
  switch(argv[1][0]) {
    case 'g':
      printGraph(g);
      break;
    case 'd':
      dfs(g, 0);
      printTree(g);
      break;
    case 'b':
      bfs(g, 0);
      printTree(g);
      break;
    default:
      fprintf(stderr, "%s: unknown action '%c'\n", argv[0], argv[1][0]);
      return 1;
  }
 graphDestroy(g);
 return 0;
}
