// X3D_Solid - Abstract base class for a series of manipulables
#ifndef __X3D_Solid
#define __X3D_Solid
#include <assert.h>
#include "X3D_Coordinate.h"
#include "X3D_Color.h"

class X3D_Solid {
   X3D_Solid(const X3D_Solid & that);

 protected:
   X3D_Coordinate translate;
   X3D_Coordinate scale;
   X3D_Coordinate rotation;
   X3D_Color color;
   float transparency;
   X3D_String commentary;

   X3D_String XML_Start()const;
   X3D_String XML_End()const;
   virtual X3D_String X3D_Shape_XML()const = 0;
   virtual X3D_String Name() const=0;

 public:
   X3D_Solid();
   virtual ~X3D_Solid();
   virtual void Clear(){}

  //Accessor functions
   X3D_Coordinate get_translate() const {return translate;}
   void  set_translate(const X3D_Coordinate& param0){ translate = param0;}
   X3D_Coordinate get_scale() const {return scale;}
   void  set_scale(const X3D_Coordinate& param0){ scale = param0;}
   X3D_Coordinate get_rotation() const {return rotation;}
   void  set_rotation(const X3D_Coordinate& param0){ rotation = param0;}
   X3D_Color get_color() const {return color;}
   void  set_color(const X3D_Color& param0){ color = param0;}
   float get_transparency() const {return transparency;}
   void set_transparency(float t){transparency = t;}
   void Append_Commentary(X3D_String);

   virtual X3D_String ToString() const;
   virtual X3D_String ToXML() const;

};
typedef X3D_Solid * X3D_SolidPtr;
#endif