#include <ijvm.h>
#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>


bool step() {
  return true;
}

byte_t* get_text() {
  return 0;
}

int text_size() {
  return 0;
}

int get_program_counter() {
  return 0;
}

byte_t get_instruction(void) {
  return (byte_t) 0;
}

// Returns the size of the file
long int fsize(const char *file_name) {
    struct stat st;

    if (stat(file_name, &st) == 0)
        return st.st_size;

    return -1;
}

// Implement loading of binary here
int init_ijvm(char *file_path)
{
  FILE *stream;
  int file_size = fsize(file_path);
  if(file_size < 0){
    return file_size;
  }
  
  stream = fopen(file_path, "rb");// Open read-only
  if(stream == NULL){
    return -1;
  }
  
  byte_t *buffer = malloc(file_size);
  if (buffer == NULL){
    return -1;
  }

  int fread_result = fread(buffer, sizeof(byte_t), file_size, stream); 
  if(fread_result < 0){
    return fread_result;
  }

  int result = fclose(stream);
  if(result < 0){
    return result;
  }
  
  // Print buffer content
  for (int i = 0; i < file_size; i++) {
    printf("%X ", buffer[i]);
  }

  free(buffer);

  return 0;
}

void destroy_ijvm()
{
  // Reset IJVM state
}

void run()
{
  // Step while you can
}


void set_input(FILE *fp)
{
  // TODO: implement me
}

void set_output(FILE *fp)
{
  // TODO: implement me
}

