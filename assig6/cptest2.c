#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/time.h>
#include <dirent.h>
#include <string.h>
#include <libgen.h>

// function prototypes
int copyfile1(char** infilenames, char* outfilename, int fileCount);
int copyfile2(char** infilenames, char* outfilename, int fileCount);
int copyfile3(char** infilenames, char* outfilename, int fileCount, int bufferSize);
struct timeval* timeDifference(struct timeval* startTime, struct timeval* finishTime);
char* convertToUpper(char *str);
int searchArrayForString(char* arr[], int count, char* key);
int findFirstFile(char* argv[], int argc);
int countInputFiles(char* argv[], int argc);

/** cptest.cpp
 * A file copying program.
 * Derived partially from caesar.cpp by Horstmann and Budd from big C++
 */

/**
   Prints usage instructions.
   @param program_name the name of this program
*/
void usage(char* program_name) {  
  printf("Usage: %s infile outfile [-c copymethod] [-b buffersize]\n", program_name);
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
  char** infilenames; // Names of files.
  char* outfilename;
  int fileCount;
  int returnstatus;
  int paramIndex;
  char method;
  int bufferSize;
  int i; //An iterator
  struct timeval tcpstart;
  struct timeval tcpfinish;

  if (argc < 3) {
    usage(argv[0]); // Must have at least 3 arguments
    return 1;
  }

  //search for copy type
  if ((paramIndex = searchArrayForString(argv,argc,"-c")) != -1) {
    if (paramIndex+1 == argc) {
      printf("Missing parameter. Program terminated.\n");
      return 1;
    }
    method = atoi(argv[paramIndex+1]);
    if (method != 1 && method != 2 && method != 3) {
      printf("Invalid copymethod argument. Valid options are 1, 2, or 3. You entered \"%s\". Program Terminated.\n",argv[paramIndex+1]);
      return 1;
    }
  } else {
    method = 3; //set default method
  }

  //Set buffer size
  if (method == 3) {
    if ((paramIndex = searchArrayForString(argv,argc,"-b")) != -1) {
      if (paramIndex+1 == argc) {
	printf("Missing parameter. Program terminated.\n");
	return 1;
      }
      bufferSize = atoi(argv[paramIndex+1]);
      if (bufferSize <= 0) {
	printf("Invalid buffer Size. Program terminatred\n");
	return 1;
      }
    } else {
      bufferSize = 1024; //set default buffer size
    }
  }

  //find file names
  if ((paramIndex = findFirstFile(argv,argc)) == -1) {
    printf("No file names entered. Program Terminated.\n");
    return 1;
  }
  if ((fileCount = countInputFiles(argv,argc)) < 1) {
    printf("At least two file names or locations must be specified. Program terminated\n");
    return 1;
  }
  infilenames = (char**) malloc(sizeof(char*)*fileCount); //Make space for a list of the files to copy
  //Fill an array of files to copy
  for (i = 0; i < fileCount; i++) {
    infilenames[i] = argv[paramIndex + i];
  }
  outfilename = argv[paramIndex + fileCount];
 
  //Copy the files based on the current method
  gettimeofday(&tcpstart,NULL);
  switch(method) {
  case 1:
    returnstatus = copyfile1(infilenames, outfilename, fileCount);
    break;
  case 2:
    returnstatus = copyfile2(infilenames, outfilename, fileCount);
    break;
  case 3:
    returnstatus = copyfile3(infilenames, outfilename, fileCount, bufferSize);
    break; 
  }
  gettimeofday(&tcpfinish,NULL);

  struct timeval* tcpDifference =  timeDifference(&tcpstart, &tcpfinish);

  if (!returnstatus) {
    printf("\nCopy started: %d seconds and %d microseconds from UTC start.\n",tcpstart.tv_sec,tcpstart.tv_usec);
    printf("Copy finished: %d seconds and %d microseconds from UTC start.\n",tcpfinish.tv_sec,tcpfinish.tv_usec);
    printf("Time for Copy: %d seconds and %d microseconds.\n",tcpDifference->tv_sec,tcpDifference->tv_usec);
  }

  free(tcpDifference);
  free(infilenames);
  return returnstatus;
}

/** Copies one file to another using formatted I/O, one character at a time.
 * @param infilenames Names of input files
 * @param outfilename Name of output file
 * @param fileCount Number of input files to copy
 * @return 0 if successful, 1 if error.
*/
int copyfile1(char** infilenames, char* outfilename, int fileCount) {
  FILE* infile; //File handles for source and destination.
  FILE* outfile;
  DIR* dir;
  int i; //an iterator

  //Loop through the array, copying all the files
  for (i = 0; i < fileCount; i++) {


    // Open the input file.
    infile = fopen(infilenames[i], "r");
    if (infile == NULL) {
      open_file_error(infilenames[i]);
      return 1;
    }
    
    //open the output file
    dir = opendir(outfilename); //try to open the directory
    if (dir == NULL) {
      //the directoy doesn't exist, copy the file to a new name in the current directory
      outfile = fopen(outfilename, "w");
    } else {
      //the directory does exist, copy the file with the same name to the directory
      char* tempStr = (char*) malloc(sizeof(char)*(strlen(outfilename)+3+strlen(basename(infilenames[i]))));
      strcat(tempStr,"./"); 
      strcat(tempStr,outfilename);
      strcat(tempStr,"/");
      strcat(tempStr,basename(infilenames[i]));
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
    
    // All done--close the files
    fclose(infile);
    fclose(outfile);
    closedir(dir);
    
  }
  return 0; // Success!
}

/** Copies one file to another using raw unformatted I/O, one byte at a time.
 * @param infilenames Name of input file
 * @param outfilename Names of output file
 * @param fileCount Number of input files to copy
 * @return 0 if successful, 1 if error.
 * @author Steven Kordell
*/
int copyfile2(char** infilenames, char* outfilename, int fileCount) {
  int infile;
  int outfile;
  DIR* dir;
  int i; //an iterator

  for (i = 0; i < fileCount; i++) {

    //open file for reading
    infile = open(infilenames[i],O_RDONLY);
    if (infile == -1) {
      open_file_error(infilenames[i]);
      return 1;
    }
    
    
    // Open or create file for writing
    dir = opendir(outfilename); //try to open the directory
    if (dir == NULL) {
      //the directoy doesn't exist, copy the file to a new name in the current directory
      outfile = open(outfilename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    } else {
      //the directory does exist, copy the file with the same name to the directory
      char* tempStr = (char*) malloc(sizeof(char)*(strlen(outfilename)+3+strlen(basename(infilenames[i]))));
      strcat(tempStr,"./"); 
      strcat(tempStr,outfilename);
      strcat(tempStr,"/");
      strcat(tempStr,basename(infilenames[i]));
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
  }
  return 0;
}


/** Copies one file to another using raw unformatted I/O, one byte at a time.
 * @param infilenames Name of input file
 * @param outfilename Names of output file
 * @param fileCount Number of input files to copy
 * @param bufferSize Size of the copy buffer
 * @return 0 if successful, 1 if error.
 * @author Steven Kordell
*/
int copyfile3(char** infilenames, char* outfilename, int fileCount, int bufferSize) {
  int infile;
  int outfile;
  int sizeRead;
  DIR* dir;
  int i; //an iterator

  for (i = 0; i < fileCount; i++) {

    //make a buffer to hold the copied data
    unsigned char* buffer = (unsigned char*) malloc(sizeof(unsigned char)*bufferSize);
    if(buffer == NULL) {
      printf("Error: Buffer exceeds available memory.\n");
      return -1;
    }
    
    //open file for reading
    infile = open(infilenames[i],O_RDONLY);
    if (infile == -1) {
      open_file_error(infilenames[i]);
      return 1;
    }
    
    // Open or create file for writing
    dir = opendir(outfilename); //try to open the directory
    if (dir == NULL) {
      //the directoy doesn't exist, copy the file to a new name in the current directory
      outfile = open(outfilename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    } else {
      //the directory does exist, copy the file with the same name to the directory
      char* tempStr = (char*) malloc(sizeof(char)*(strlen(outfilename)+3+strlen(basename(infilenames[i]))));
      strcat(tempStr,"./"); 
      strcat(tempStr,outfilename);
      strcat(tempStr,"/");
      strcat(tempStr,basename(infilenames[i]));
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

  }

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
  result->tv_sec = finishTime->tv_sec - startTime->tv_sec;
  if (finishTime->tv_usec - startTime->tv_usec < 0) {
    result->tv_sec--;
    result->tv_usec = 1000000+(finishTime->tv_usec - startTime->tv_usec);
  } else {
    result->tv_usec = finishTime->tv_usec - startTime->tv_usec;
  }
  return result;
}


/** Converts a string to all upper case characters, the retruned string comes from the heap and should be freed after being used
 * @param str Pointer to the c-style string to convert
 * @return Pointer to the returned string
 * @author Steven Kordell
 */
char* convertToUpper(char *str){
    char *newstr, *p;
    p = newstr = strdup(str); //amke a cpy of the string
    while(*p++=toupper(*p)); //iterate over it, uppercasing the characters
    return newstr; //return the resulting string
}

/** searches an array of strings for the existance of one particular string,not case sensititve
 * @param arr The array of strings to search
 * @param count Number of elements in the array
 * @param key The string to search the array for
 * @return The insex of the sting in the array or -1 if the string wasn't found
 * @author Steven Kordell
 */
int searchArrayForString(char* arr[], int count, char* key) {
  int n;
  char* elementUp;
  char* keyUp;
  for(n = 0; n < count; n++) {
    elementUp = convertToUpper(arr[n]);
    keyUp = convertToUpper(key);
    if (!strcmp(elementUp,keyUp)) {
      free(elementUp);
      free(keyUp);
      return n;
    }
    free(elementUp);
    free(keyUp);
   }
  return -1;
}

/** Finds the index of the first filename in the parameter list
 * @param argv The array of parameters
 * @param argc The number of elelements in the array
 * @return The index of the first file or -1 if no file names were entered
 * @author Steven Kordell
 */
int findFirstFile(char* argv[], int argc) {
  int paramIndex;
  char* upperArg;
  for (paramIndex = 1; paramIndex < argc; paramIndex++) {
    upperArg = convertToUpper(argv[paramIndex]);
    if (strcmp(upperArg,"-C") && strcmp(upperArg,"-B")) {
      free(upperArg);
      return paramIndex;
    } else {
      free(upperArg);
      paramIndex++;
    }
  }
  return -1; //no file names entered
}

/** Counts the number of input files to copy
 * @param argv The array of incoming parameters
 * @param argc The number of incoming parameters
 * @return The number of filename to copy
 * @author Steven Kordell
*/
int countInputFiles(char* argv[], int argc) {
  int fileCount = 0;
  int i;
  char* upperArg;
  for (i = 1; i < argc; i++) {
    upperArg = convertToUpper(argv[i]);
    if (strcmp(upperArg,"-C") && strcmp(upperArg,"-B")) {
      free(upperArg);
      fileCount++;
    } else {
      free(upperArg);
      i++;
    }
  }
  return --fileCount;
}
