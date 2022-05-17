#include <opencv2/opencv.hpp>
#include "MeshFlow.h"
#include "MotionDenoiser.h"
#include <time.h>


int main(int argc, char** argv){

  
  //  vector<char*> names;
  //  vector<char*> outNames;
   
  //  for (int i = 1; i <= 1; i++){
	//    char* name = new char[1024];
	//    char* outname = new char[1024];

	//    sprintf(name, "16.avi");
	//    sprintf(outname, "16_out.avi");

	//    names.push_back(name);   
	//    outNames.push_back(outname);
	// }
  char suffix[10] = "_mesh";
  char outName[1024];
	for (int i = 1; i < argc; i++){
     int n = 0;
     while(argv[i][n]) n++;
     
     int dot_pos =n-1;
     while(argv[i][dot_pos]!= '.') dot_pos--;
    int j=0;
     for(; j< dot_pos;j++){
       outName[j] = argv[i][j];
     }
     int k=0;
     while(suffix[k]) {
       outName[j+k] = suffix[k];
       k++;
     }
    while(argv[i][j]) {
       outName[j+k] = argv[i][j];
       j++;
     }
     outName[j+k] = '\0';

	   MotionDenoiser denoiser(argv[i]);
	   denoiser.Execute();
	   denoiser.SaveResult(outName);
   }

	//getchar();
  return 0;
}