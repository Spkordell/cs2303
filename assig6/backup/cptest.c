#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/time.h>
#include <dirent.h>
#include <string.h>
#include <libgen.h>

// function prototype
int copyfile1(char* infilename, char* outfilename);
int copyfile2(char* infilename, char* outfilename);
int copyfile3(char* infilename, char* outfilename, int bufferSize);
struct timeval* timeDifference(struct timeval* startTime, struct timeval* finishTime);

/** cptest.cpp
 * A file copying program.
 * Derived partially from caesar.cpp by Horstmann and Budd from big C++
 */

/**
   Prints usage instructions.
   @param program_name the name of this program
*/
void usage(char* program_name) {  
  printf("Usage: %s infile outfile [copymethod] [buffersize]\n", program_name);
}

/**
   Prints file opening error message
   @param filename the name of the file that could not be opened
*/
void open_file_error(char* filename) {  
  printf("Error opening file %s\n", filename);
}

/** Main program: copies a file.
    @param argc Number of command-line arguments (including program name).
    @param argv Array of pointers to character arays holding arguments.
    @return 0 if successful, 1 if fail.
*/
int main(int argc, char* argv[]) {  
  char* infilename; // Names of files.
  char* outfilename;
  int returnstatus;
  struct timeval tcpstart;
  struct timeval tcpfinish;


  if (argc < 3 || argc > 5) {
    usage(argv[0]); // Must have between 3 and 5 arguments, inclusive
    return 1;
  }

  infilename = argv[1];
  outfilename = argv[2];

  gettimeofday(&tcpstart,NULL);
  if (argc == 4 || argc == 5) {
    switch(atoi(argv[3])) {
    case 1:
      returnstatus = copyfile1(infilename, outfilename);
      break;
    case 2:
      returnstatus = copyfile2(infilename, outfilename);
      break;
    case 3:
      returnstatus = copyfile3(infilename, outfilename, argc == 5 ? atoi(argv[4]) : 1024);
      break; 
    default:
      usage(argv[0]);
      printf("Invalid copymethod argument. Options are 1, 2, or 3. You enterered \"%s\". No files have been copied.\n",argv[3]);
      break;
    }      
  } else {
    returnstatus = copyfile3(infilename, outfilename,1024);
  }
  gettimeofday(&tcpfinish,NULL);

  struct timeval* tcpDifference =  timeDifference(&tcpstart, &tcpfinish);

  
  printf("\nCopy started: %d seconds and %d microseconds from UTC start.\n",tcpstart.tv_sec,tcpstart.tv_usec);
  printf("Copy finished: %d seconds and %d microseconds from UTC start.\n",tcpfinish.tv_sec,tcpfinish.tv_usec);
  printf("Time for Copy: %d seconds and %d microseconds.\n",tcpDifference->tv_sec,tcpDifference->tv_usec);

  free(tcpDifference);
  return returnstatus;
}

/** Copies one file to another using formatted I/O, one character at a time.
 @param infilename Name of input file
 @param outfilename Name of output file
 @return 0 if successful, 1 if error.
*/
int copyfile1(char* infilename, char* outfilename) {
  FILE* infile; //File handles for source and destination.
  FILE* outfile;
  DIR* dir;
 
  infile = fopen(infilename, "r"); // Open the input and output files.
  if (infile == NULL) {
    open_file_error(infilename);
    return 1;
  }

  dir = opendir(outfilename); //try to open the directory
  if (dir == NULL) {
    //the directoy doesn't exist, copy the file to a new name in the current directory
    outfile = fopen(outfilename, "w");
  } else {
    //the directory does exist, copy the file with the same name to the directory
    char* tempStr = (char*) malloc(sizeof(char)*(strlen(outfilename)+3+strlen(basename(infilename))));
    strcat(tempStr,"./"); 
    strcat(tempStr,outfilename);
    strcat(tempStr,"/");
    strcat(tempStr,basename(infilename));
    outfile = fopen(tempStr, "w");
    free(tempStr);
  }
  if (outfile == NULL) {
    open_file_error(outfilename);
    return 1;
  }

  int intch;  // Character read from input file. must be an int to catch EOF.
  unsigned char ch; // Character stripped down to a byte.

  // Read each character from the file, checking for EOF.
  while ((intch = fgetc(infile)) != EOF) {
    ch = (unsigned char) intch; // Convert to one-byte char.
    fputc(ch, outfile); // Write out.
  }

  // All done--close the files and return success code.
  fclose(infile);
  fclose(outfile);
  closedir(dir);

  return 0; // Success!
}

/** Copies one file to another using raw unformatted I/O, one byte at a time.
 * @param infilename Name of input file
 * @param outfilename Name of output file
 * @return 0 if successful, 1 if error.
 * @author Steven Kordell
*/
int copyfile2(char* infilename, char* outfilename) {
  int infile;
  int outfile;
  DIR* dir;


  //open file for reading
  infile = open(infilename,O_RDONLY);
  if (infile == -1) {
    open_file_error(outfilename);
    return 1;
  }


  // Open or create file for writing
  dir = opendir(outfilename); //try to open the directory
  if (dir == NULL) {
    //the directoy doesn't exist, copy the file to a new name in the current directory
    outfile = open(outfilename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
  } else {
    //the directory does exist, copy the file with the same name to the directory
    char* tempStr = (char*) malloc(sizeof(char)*(strlen(outfilename)+3+strlen(basename(infilename))));
    strcat(tempStr,"./"); 
    strcat(tempStr,outfilename);
    strcat(tempStr,"/");
    strcat(tempStr,basename(infilename));
    outfile = open(tempStr, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    free(tempStr);
  }
  if (outfile == -1) {
    open_file_error(outfilename);
    return 1;
  }

  unsigned char ch[1]; //the character read from infile to be written to outfile

  while(read(infile,ch,1)) { //read each character, checking for EOF
    write(outfile,ch,1); //Write the character to the output file
  }

  //close the files
  close(infile);
  close(outfile);
  closedir(dir);
  return 0;
}


/** Copies one file to another using raw unformatted I/O, one byte at a time.
 * @param infilename Name of input file
 * @param outfilename Name of output file
 * @return 0 if successful, 1 if error.
 * @author Steven Kordell
*/
int copyfile3(char* infilename, char* outfilename, int bufferSize) {
  int infile;
  int outfile;
  int sizeRead;
  DIR* dir;

  //make a buffer to hold the copied data
  unsigned char* buffer = (unsigned char*) malloc(sizeof(unsigned char)*bufferSize);
  if(buffer == NULL) {
    printf("Error: Buffer exceeds available memory.\n");
    return -1;
  }

  //open file for reading
  infile = open(infilename,O_RDONLY);
  if (infile == -1) {
    open_file_error(outfilename);
    return 1;
  }

  // Open or create file for writing
  dir = opendir(outfilename); //try to open the directory
  if (dir == NULL) {
    //the directoy doesn't exist, copy the file to a new name in the current directory
    outfile = open(outfilename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
  } else {
    //the directory does exist, copy the file with the same name to the directory
    char* tempStr = (char*) malloc(sizeof(char)*(strlen(outfilename)+3+strlen(basename(infilename))));
    strcat(tempStr,"./"); 
    strcat(tempStr,outfilename);
    strcat(tempStr,"/");
    strcat(tempStr,basename(infilename));
    outfile = open(tempStr, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    free(tempStr);
  }

  if (outfile == -1) {
    open_file_error(outfilename);
    return 1;
  }

  while((sizeRead = read(infile,buffer,bufferSize)) > 0) { //read each character, checking for EOF
    write(outfile,buffer,sizeRead); //Write the character to the output file
  }

  //close the files
  close(infile);
  close(outfile);
  closedir(dir);
  //free the buffer
  free(buffer);

  return 0;
}

/** Calculates the difference between two timestamps and returns a new timestamp with the result. startTime must be less than finishTime
 * @param startTime The ealier time
 * @param finishTime The later time
 * @return A pointer to a newly allocated timeval struct containing the difference between the two timestamps
 * @author Steven Kordell
 */
struct timeval* timeDifference(struct timeval* startTime, struct timeval* finishTime) {
  struct timeval* result = (struct timeval*) malloc(sizeof(struct timeval));
  // resutl->tv_usec = (finisTime->tv_sec*1000000+finishTime->tv_usec) - (startTime->tv_sec*1000000+startTime->tv_usec) 

  result->tv_sec = finishTime->tv_sec - startTime->tv_sec;
  if (finishTime->tv_usec - startTime->tv_usec < 0) {
    result->tv_sec--;
    result->tv_usec = 1000000+(finishTime->tv_usec - startTime->tv_usec);
  } else {
    result->tv_usec = finishTime->tv_usec - startTime->tv_usec;
  }

  return result;
}
