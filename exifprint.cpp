#include <windows.h>
#include <stdio.h>
#include "exif.h"
#define  _CRT_SECURE_NO_WARNINGS

extern std::string sPosition;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: demo <JPEG file>\n");
    return -1;
  }
  exif::EXIFInfo *exifInfo = new exif::EXIFInfo; 
  if (!exifInfo->readEXIF(argv[1]))
	  printf("Error reading file %s",argv[1]);

  std::string output = exifInfo->toString();
  printf("%s",output.c_str());

  printf("\nGoogle Earth koordinates: ");
  printf("%s\n", sPosition.c_str());

  HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED, sPosition.length() + 1);
  memcpy(hGlob, sPosition.c_str(), sPosition.length() + 1 );

  OpenClipboard(NULL );
  EmptyClipboard();
  SetClipboardData(CF_TEXT, hGlob);
  CloseClipboard();
    
  std::string newOutput = std::string("test.jpg");

  return 0;
}
