#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct{
  char *bytes;
  size_t size;
  size_t read;
  size_t remaining;
}ringbuf_t;

void
ringbuf_init(ringbuf_t *p, char *buffer, size_t size)
{
  memset(p, 0, sizeof(ringbuf_t));
  p->bytes=buffer;
  p->read=0;
  p->size=size;
  p->remaining= 0;     //current saveed data array.
}

void
ringbuf_flush(ringbuf_t *p)
{
  p->read =0;
  p->remaining =0;
}
int
ringbuf_write(ringbuf_t *p, char *bytes, size_t size)
{
  printf("p->read= %d ,p->remaining=%d \n",p->read,p->remaining);
  if(p->size - p->remaining < size)  return -1;   // writable size is less than input sze
  size_t cursor = p->read + p->remaining;     //read pointer
  printf("cursor=%d \n",cursor);

  cursor %=p->size;            // read pointer reachd end

  if(p->size - cursor >=size) {
    memcpy(p->bytes + cursor, bytes,size);
    p->remaining +=size;
  }
  else {
    size_t n=p->size-cursor;
    if(n> 0) {
      memcpy(p->bytes + cursor, bytes,n);
      p->remaining +=n;
      size -=n;
      bytes +=n;
    }
    memcpy(p->bytes, bytes,size);
    p->remaining +=size;
  }
   return 0;
}

size_t
ringbuf_read_int(ringbuf_t *p, char *bytes,size_t size, int keep)
{
  if(p->remaining < size) size = p->remaining ;

  size_t rb=size;
  printf("#p->read= %d ,p->remaining=%d \n",p->read,p->remaining);
  if(p->size -p->read >= size ){
    memcpy(bytes,p->bytes + p->read, size);
    if(!keep) {
      p->read += size;
      p->remaining -=size;
    }
  }
  else{
    size_t n= p->size-p->read;
    if(n>0){
      memcpy(bytes, p->bytes+p->read,n);
      if(!keep){
        p->read +=n;
        p->remaining -=n;
      }
      bytes +=n;
      size -=n;
    }
    memcpy(bytes, p->bytes, size);
    if(!keep){
      p->read = size;
      p->remaining -=size;
    }
  }
  return rb;
}

size_t
ringbuf_read(ringbuf_t *p, char *bytes,size_t size)
{
  return ringbuf_read_int(p,bytes, size, 0);
}
size_t
ringbuf_read_keep(ringbuf_t *p, char *bytes, size_t size)
{
  return ringbuf_read_int(p, bytes, size, 1);
}

#define SIZE 24
int main(int argc, char *argv[])
{
  ringbuf_t *Rb;
  char buf[SIZE];
  int size = SIZE;
  char Rx;
  char w=20;
  char test[10];
memset(test,0,sizeof(test));

  Rb=(ringbuf_t *)malloc(sizeof(*Rb));
//  for(int i=0; i<SIZE;i++) buf[i]=i;

  ringbuf_init(Rb,buf,size);

  ringbuf_write(Rb,test,10);
  for(int i=0;i<10; i++) printf("%d ",buf[i]);

    ringbuf_write(Rb,&test[0],1); //printf("%d ",buf[10]);
    ringbuf_write(Rb,&test[1],1); //printf("%d ",buf[11]);

  ringbuf_read_int(Rb,&Rx,1,0); //printf("%d ",Rx);
 ringbuf_read_int(Rb,&Rx,1,0); //printf("%d ",Rx);
//ringbuf_read_int(Rb,&Rx,1,0); //printf("%d ",Rx);
//ringbuf_read_int(Rb,&Rx,1,0); //printf("%d ",Rx);

   ringbuf_write(Rb,&w,1); //printf("%d ",w);

  return 0;
}
