// X3D
#include "X3D.h"

X3D_String X3D::prefix("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                     "<!DOCTYPE X3D PUBLIC \"ISO//Web3D//DTD X3D 3.2//EN\" \"../../schemas/x3d-3.2.dtd\">\n"
                     "<X3D profile='Interchange' version='3.1' xmlns:xsd='http://www.w3.org/2001/XMLSchema-instance' xsd:noNamespaceSchemaLocation='http://www.web3d.org/specifications/x3d-3.1.xsd'>\n"
                     "<head>\n"
                     " <meta content='Test.x3d' name='title'/>\n"
                     " <meta content='Generated scene' name='description'/>\n"
                     " </head>\n" "<Scene>\n" "<Background skyColor='1 1 1'/>\n");
X3D_String X3D::suffix("\n</Scene>\n</X3D>");

X3D::X3D():solids(0){}

void X3D::Clear(){
 for(unsigned int i = 0;i<solids.size();i++){
   X3D_SolidPtr ptr = solids[i];
   if(ptr){
     ptr->Clear();
     if(ptr)
       delete ptr;
     solids[i] = NULL;
     }
   }
  solids.clear(); 
}

X3D::~X3D(){
 Clear();
}

unsigned X3D::SaveToFile (const char * filename){
  char fn[1000];
  strcpy(fn,filename);
  strcat(fn,".x3d");
  ofstream outfile(fn);
  outfile << prefix.c_str(); // Needs to be set to versions
  int count = 0;
  for(unsigned int i=0;i<solids.size();i++)
    if(solids[i]){
      count++;
      outfile <<
       #ifdef CB4
         solids[i]->ToXML().c_str();
       #endif
       #ifdef CB10
		 solids[i]->ToXML().c_str();
	   #endif
	   #ifdef DEV
         solids[i]->ToXML().c_str();
       #endif
       }
  outfile << suffix.c_str();   // Needs to be set to versions
  return count;
}

X3D_SolidPtr X3D::Get(unsigned i){
  if(i<solids.size())
    return solids[i];
  return NULL;
}

X3D_String X3D::ToString() const{
 X3D_String result = "The items ";
 unsigned size = solids.size();
 result = result
    #ifdef CB4
       + " ("+size+")\n";
       #endif
	#ifdef CB10
	   + " ("+size+")\n";
	   #endif
	#ifdef VS
	   + " ("+to_string(size)+")\n";
	   #endif
	#ifdef DEV
	   << " (" << size << ")\n ";
	   #endif
 for(unsigned i = 0;i<size;i++){
   result = result
	#ifdef CB4
	   + " " + i + ": " + solids[i]->ToString() +"\n";
	   #endif
	#ifdef CB10
	   + " " + i + ": " + solids[i]->ToString() +"\n";
	   #endif
	#ifdef VS
	   + " " + to_string(i) + ": " + solids[i]->ToString() +"\n";
	   #endif
	#ifdef DEV
	   << " " << i << ": " << solids[i]->ToString() << "\n";
	   #endif
   }// for
 return result;
}
