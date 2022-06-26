#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define min(a,b) (((a) > ( b)) ?  (b):(a))

   FILE *fp;
typedef struct
{
  uint8_t *base;
  uint8_t *read_pos;
  uint8_t *write_pos;
  uint16_t len;
  uint32_t bytes_consumed;
}buffer_t;

size_t buf_data_total(buffer_t *buf)
{
  if(buf==NULL) return -1;

  return buf->write_pos-buf->read_pos;
}


void FifoRead(char *buff, int len)
{
 int ret=   fread(buff,1,len,fp);
 printf("+ret= %d \n",ret);
}
buffer_t *buf_create(size_t len)
{
  buffer_t* buf=(buffer_t *)malloc(sizeof(*buf));
  buf->len=len;
  buf->base = malloc(len*sizeof(uint8_t));

  if(buf->base ==NULL) printf("malloc error \n");

  buf->read_pos=buf->base;
  buf->write_pos=buf->base;
  buf->bytes_consumed =0;
}
int buf_destroy(buffer_t *buf)
{
  if(buf ==NULL) return -1;
  if(buf->base !=NULL)
   free(buf->base);
   free(buf);
}

size_t buf_data_unread(buffer_t *buf)
{
  if(buf ==NULL) return -1;

  return buf->write_pos - buf->read_pos;
}

int buf_drain(buffer_t *buf, int bytes)
{
  if(buf == NULL) return -1;

  if(bytes > buf_data_unread(buf))
    return -1;
  buf->read_pos +=bytes;
  buf->bytes_consumed +=bytes;
}


int buf_free_capacity(buffer_t *buf)
{
  if(buf ==NULL) return -1;

  return ( buf->base + buf->len)-buf->write_pos;   // len is int, base and write is pointer.
}

size_t buf_move_remaining_bytes_to_front(buffer_t *buf)
{
   size_t unread_data =buf_data_unread(buf);
   memmove(buf->base, buf->read_pos, unread_data);
   buf->read_pos= buf->base;
   buf->write_pos = buf->base + unread_data;

   return buf_free_capacity(buf);
}
int buf_fill(buffer_t *buf,int bytes)
{
  if(buf ==NULL) return -1;

  if(bytes > buf_free_capacity(buf)) return -1;

  buf->write_pos +=bytes;

  return bytes;
}
size_t buf_data_stale(buffer_t *buf)
{
  if(buf==NULL) return -1;
  return buf->read_pos -buf->base;
}
size_t buf_free_capacity_after_purge(buffer_t *buf)
{
  if(buf ==NULL) return -1;

  return buf_free_capacity(buf)+buf_data_stale(buf);
}
size_t buf_write(buffer_t *buf,const void *from, size_t len)
{
   size_t bytes_to_write = min(buf_free_capacity(buf),len);

   if(bytes_to_write ==0 && buf_free_capacity_after_purge(buf) >0 ){
     bytes_to_write = min(buf_move_remaining_bytes_to_front(buf),len);
   }

   if( bytes_to_write >0 ){
     memcpy(buf->write_pos, from, bytes_to_write);
     buf->write_pos +=bytes_to_write;
   }

   return bytes_to_write;
}
size_t fill_read_buffer(buffer_t *buf)
{
  buf_move_remaining_bytes_to_front(buf);
  size_t bytes_to_read = buf_free_capacity_after_purge(buf);
  if(bytes_to_read >0) {
    FifoRead((char *)buf->write_pos,bytes_to_read);
    buf->write_pos +=bytes_to_read;
  }
  return bytes_to_read;
}

int buf_seek_rel(buffer_t *buf, uint32_t offset)
{
  if(buf ==NULL) return -1;

  //advance through buffer, loading new data as necessary
  while(1){
    size_t data_avail = buf_data_unread(buf);

    //if offset exceed buffer capacity, load more data
    if(offset > data_avail){
      buf->read_pos +=data_avail;
      offset -=data_avail;
      buf->bytes_consumed +=data_avail;
      fill_read_buffer(buf);
    }
    else{
      buf->read_pos +=offset;
      buf->bytes_consumed +=offset;
      break;
    }
  }
  return 0;
}

int buf_seek_abs(buffer_t *buf, uint32_t pos)
{
   if(buf ==NULL) return -1;

   if(pos >(uint32_t) buf->write_pos){
     printf("pos=%u larger than fill pos %u\n",pos,(uint32_t)buf->write_pos);
     return -1;
   }
   size_t delta = pos-(uint32_t)buf->read_pos;
   buf->bytes_consumed +=delta;
   buf->read_pos = (uint8_t*)pos;
}

size_t buf_read(void *ptr, size_t size, size_t count, buffer_t *buf)
{
  if(size==0 || count ==0) return 0;

  size_t bytes_to_copy = size*count;
  if(bytes_to_copy > buf->len) {
     printf( "buf_read failed, bytes_to_copy = %d larger than buffer size %d\n", bytes_to_copy, buf->len);
  }

  while(bytes_to_copy > buf_data_unread(buf)){
    fill_read_buffer(buf);
  }
  if(bytes_to_copy > buf_data_unread(buf)){
     printf( "buf_read failed bytes_to_copy %d, buf_data_unread %d\n", bytes_to_copy, buf_data_unread(buf));
     return -1;
  }
  memcpy(ptr,buf->read_pos, bytes_to_copy);
  buf->read_pos += bytes_to_copy;
  buf->bytes_consumed +=bytes_to_copy;

  return bytes_to_copy;
}

#define SIZE 1024
int main(int argc, char *argv[])
{

   buffer_t *stream;
   uint8_t buff[64];

   stream=buf_create(SIZE);
   fp=fopen("short.wma","rb");
   size_t ret= buf_read(buff,1,16,stream);
   for(int i=0;i <16; i++ ) printf("%02x ",buff[i]);
   printf("\n");
   buf_seek_rel(stream, 16);

   buf_read(buff,1,16,stream);
   for(int i=0;i <16; i++ ) printf("%02x ",buff[i]);
   printf("\n");

   fill_read_buffer(stream);
   for(int i=0;i <16; i++ ) printf("%02x ",buff[i]);
   printf("\n");


   buf_destroy(stream);
   return 0;
}
