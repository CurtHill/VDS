#include <string.h>
#include "x3d.h"
#include <fstream>
#include <iostream>
using namespace std;

int main (){
  // Create a line of several blocks - Aligned in X
 X3D scene;
 X3D_Text * tptr;
 X3D_Box * boxptr;
 
 boxptr = new X3D_Box(X3D_Coordinate(4,2,-2));
 scene.Add(boxptr);
 tptr = new X3D_Text("W: First Line, which is really large");
 tptr->set_color(X3D_Color(0,1,1));
 scene.Add(tptr);
 tptr = new X3D_Text("W2");
 tptr->set_color(X3D_Color(0,1,1));
 scene.Add(tptr);

 int result = scene.SaveToFile("vstest");
 cout << "Align2.x3d was written, objects written: "
      << result <<"\n";
 ofstream outf("vs_test.lst");
 outf << scene.ToString().c_str();
 
}