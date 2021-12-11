Practice applets for beginners in C++
// file filterfq.cpp
// Dot4diw
// practice
// filter
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
  char* filein;
  char* fileout;
  int min_length;
  int max_length;

  int opt;

  const char *optstring = "i:o:m:M:h"; // set the parameter type.
  while (( opt = getopt(argc, argv, optstring)) != -1)
    {
      switch (opt)
        {
        case 'i':
          filein = optarg;
          break;
        case 'o':
          fileout = optarg;
          break;
        case 'm':
          min_length = atoi(optarg); // use the atoi form stdlib.h to convert the string to int.
          break;
        case 'M':
          max_length = atoi(optarg); // use the atoi from stdlin.h to convert the string to int.
          break;
        case 'h':
          cout << "Usage: filterfq -i [input fastq] -o [output fastq] -m min_length -M max_length" << endl;
          cout << "    -i : the fastq file of input;" << endl;
          cout << "    -o : the fastq file of oupput;" << endl;
          cout << "    -m : setting the minimum length of reads;" << endl;
          cout << "    -M : setting the maximum length of reads;" << endl;
          cout << "    -h : display the usage help information." << endl;
          break;
        default:
          break;
        }
    }

  // use 4 variable to get the fastq seqinfo.
  string strline;
  string headinfo;
  string sequence;
  string comment;
  string quality;
  int index = 1;
  int str_length;
  ifstream file(filein);
  ofstream fout(fileout,ofstream::app);

  while (getline(file, strline))
    {
      if(index==1)
        {
        headinfo = strline;
            index ++;
        }
        else if(index==2)
        {
            sequence = strline;
            index ++;
        }
        else if(index==3)
        {
            comment = strline;
            index ++;
        }
        else if(index==4)
        {
            quality = strline;
            index = 1;
            //cout << quality << endl;
            str_length = sequence.length();
            //cout << str_length << endl;
            if(min_length <= str_length && str_length <= max_length)
              {
                fout << headinfo << "\n" << sequence << "\n" << comment << "\n" << quality << endl;
              }
            else {;}
        }
        else{;}
    }

  fout.close();
  return 0;
}
