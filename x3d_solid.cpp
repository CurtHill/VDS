// X3D_Solid
#include "X3D_Solid.h"
#include <assert.h>


X3D_Solid::X3D_Solid(): translate(X3D_Coordinate(0,0,0)),rotation(X3D_Coordinate(0,0,0)),
   scale(X3D_Coordinate(1,1,1)),transparency(0),commentary(""){}


X3D_Solid::X3D_Solid (const X3D_Solid & that){
  translate = that.translate;
  scale = that.scale;
  rotation = that.rotation;
  color = that.color;
  transparency = that.transparency;
  commentary = that.commentary;
}


X3D_Solid::~X3D_Solid(){
  // Nothing to do but this allows the right amount of data to be released
}

X3D_String X3D_Solid::ToString() const{
  return
  #ifdef CB4
     AnsiString(Name()+": Translation (")+translate.ToString()+
              "), rotation (" + rotation.ToString()+
              "), scale (" + scale.ToString()+
              "), color (" + color.ToString() +
              ") transparency ("+transparency+")";
     #endif
  #ifdef CB10
	 String(Name()+": Translation (")+translate.ToString()+
			  "), rotation (" + rotation.ToString()+
			  "), scale (" + scale.ToString()+
			  "), color (" + color.ToString() +
			  ") transparency ("+transparency+")";
	 #endif
  #ifdef VS
	 string(Name()+": Translation (")+translate.ToString()+
			  "), rotation (" + rotation.ToString()+
			  "), scale (" + scale.ToString()+
			  "), color (" + color.ToString() +
			  ") transparency ("+to_string(transparency)+")";
	 #endif
  #ifdef DEV
	wxString(Name()<< ": Translation (")<<translate.ToString()<<
			  "), rotation (" << rotation.ToString()<<
			  "), scale (" << scale.ToString()<<
			  "), color (" << color.ToString() <<
			  ") transparency ("<<transparency<<")";
	 #endif
}

X3D_String X3D_Solid::XML_Start()const{
  X3D_String temp = X3D_String("\n<!-- Start Shape(XML_Start): ")
   #ifdef CB4
	+ Name() + " (" + commentary + ") " +
	#endif
   #ifdef CB10
	+ Name() + " (" + commentary + ") " +
	#endif
   #ifdef VS
	+ Name() + " (" + commentary + ") " +
	#endif
   #ifdef DEV
	<< Name() <<  " (" << commentary << ") " <<
	#endif
	"-->\n";
  // Rotation
  float xr = rotation.get_x();
  float yr = rotation.get_y();
  float zr = rotation.get_z();

  if(xr) {
	temp = temp
	#ifdef CB4
	   + "<Transform rotation=\"1 0 0 " + xr + "\">\n";
	   #endif
	#ifdef CB10
	   + "<Transform rotation=\"1 0 0 " + xr + "\">\n";
	   #endif
	#ifdef VS
	   + "<Transform rotation=\"1 0 0 " + to_string(xr) + "\">\n";
	   #endif
	#ifdef DEV
	   << "<Transform rotation=\"1 0 0 " << xr << "\">\n";
	   #endif
	}

  if(yr) {
	temp = temp
	#ifdef CB4
	   + "<Transform rotation=\"0 1 0 " + yr + "\">\n";
	   #endif
	#ifdef CB10
	   + "<Transform rotation=\"0 1 0 " + yr + "\">\n";
	   #endif
	#ifdef VS
	   + "<Transform rotation=\"0 1 0 " + to_string(yr) + "\">\n";
	   #endif
	#ifdef DEV
	   << "<Transform rotation=\"0 1 0 " << yr << "\">\n";
	   #endif
	}
  if(zr) {
	temp = temp
	#ifdef CB4
	   + "<Transform rotation=\"0 0 1 " + zr + "\">\n";
	   #endif
	#ifdef CB10
	   + "<Transform rotation=\"0 0 1 " + zr + "\">\n";
	   #endif
	#ifdef VS
	   + "<Transform rotation=\"0 0 1 " + to_string(zr) + "\">\n";
	   #endif
	#ifdef DEV
	   << "<Transform rotation=\"0 0 1 " << zr << "\">\n";
	   #endif
	}
  // translation and scale are always done
  temp = temp
  #ifdef CB4
	 + "  <Transform translation=\""+ translate.ToString() + "\" scale=\"" +
	   scale.ToString() + "\">\n";
	#endif
  #ifdef CB10
	 + "  <Transform translation=\""+ translate.ToString() + "\" scale=\"" +
	   scale.ToString() + "\">\n";
	#endif
  #ifdef VS
	 + "  <Transform translation=\""+ translate.ToString() + "\" scale=\"" +
	   scale.ToString() + "\">\n";
	#endif
  #ifdef DEV
	 << "  <Transform translation=\"" << translate.ToString() << "\" scale=\"" <<
	   scale.ToString() << "\">\n";
	#endif

  return temp;
}

X3D_String X3D_Solid::XML_End()const{
  X3D_String temp = "";


  temp = temp
  #ifdef CB4
	  + "\n<Appearance>\n<Material diffuseColor=\"" + color.ToString() +
	  "\" transparency='" + transparency + "' " +
	  #endif
  #ifdef CB10
	  + "\n<Appearance>\n<Material diffuseColor=\"" + color.ToString() +
	  "\" transparency='" + transparency + "' " +
	  #endif
  #ifdef VS
	  + "\n<Appearance>\n<Material diffuseColor=\"" + color.ToString() +
	  "\" transparency='" + to_string(transparency) + "' " +
	  #endif
  #ifdef DEV
	   << "\n<Appearance>\n<Material diffuseColor=\"" << color.ToString() <<
	  "\" transparency='" << transparency << "' " <<
	  #endif
	"/>\n</Appearance>\n</Transform>\n";

  if(rotation.get_z()){
	temp = temp
	#ifdef CB4
	  + "</Transform><!-- z(125) -->\n";
	  #endif
	#ifdef CB10
	   + "</Transform><!-- z(125) -->\n";
	  #endif
	#ifdef VS
	   + "</Transform><!-- z(125) -->\n";
	  #endif
	#ifdef DEV
	   << "</Transform><!-- z -->\n";
	  #endif
  }
  if(rotation.get_y()){
	temp = temp
	#ifdef CB4
	  + "</Transform><!-- y -->\n";
	  #endif
	#ifdef CB10
	  + "</Transform><!-- y -->\n";
	  #endif
	#ifdef VS
	  + "</Transform><!-- y -->\n";
	  #endif
	#ifdef DEV
	   << "</Transform><!-- y -->\n";
	  #endif
  }
  if(rotation.get_x()){
	temp = temp
	#ifdef CB4
	  + "</Transform><!-- x-->\n";
	  #endif
	#ifdef CB10
	  + "</Transform><!-- x-->\n";
	  #endif
	#ifdef VS
	  + "</Transform><!-- x-->\n";
	  #endif
	#ifdef DEV
	  << "</Transform><!-- x-->\n";
	  #endif
  }

  return temp;
}

X3D_String X3D_Solid::ToXML() const{
  // Stuff outside of shape
  X3D_String temp = X3D_String("\n<!-- Start Shape(ToXML): ")
  #ifdef CB4
	+ Name() + " (" + commentary + ") " +
	#endif
  #ifdef CB10
	+ Name() + " (" + commentary + ") " +
	#endif
  #ifdef VS
	+ Name() + " (" + commentary + ") " +
	#endif
  #ifdef DEV
	<< Name() <<  " (" << commentary << ") " <<
	#endif
	 " -->\n";
  // Rotation
  float xr = rotation.get_x();
  float yr = rotation.get_y();
  float zr = rotation.get_z();

  if(zr) {
	temp = temp
	#ifdef CB4
		+ "<Transform rotation=\"0 0 1 " + zr + "\">\n";
	   #endif
	#ifdef CB10
		+ "<Transform rotation=\"0 0 1 " + zr + "\">\n";
	   #endif
	#ifdef VS
	   + "<Transform rotation=\"0 0 1 " + zr + "\">\n";
	   #endif
	#ifdef DEV
	   << "<Transform rotation=\"0 0 1 " << zr << "\">\n";
	   #endif
	}
  if(yr) {
	temp = temp
	#ifdef CB4
	   + "<Transform rotation=\"0 1 0 " + yr + "\">\n";
	   #endif
	#ifdef CB10
	   + "<Transform rotation=\"0 1 0 " + yr + "\">\n";
	   #endif
	#ifdef VS
	   + "<Transform rotation=\"0 1 0 " + yr + "\">\n";
	   #endif
	#ifdef DEV
	   << "<Transform rotation=\"0 1 0 " << yr << "\">\n";
	   #endif
	}
  if(xr) {
	temp = temp
	#ifdef CB4
	   + "<Transform rotation=\"1 0 0 " + xr + "\">\n";
	   #endif
	#ifdef CB10
	   + "<Transform rotation=\"1 0 0 " + xr + "\">\n";
	   #endif
	#ifdef VS
	   + "<Transform rotation=\"1 0 0 " + xr + "\">\n";
	   #endif
	#ifdef DEV
	   << "<Transform rotation=\"1 0 0 " << xr << "\">\n";
	   #endif
	}

  // translation and scale are always done
  temp = temp
  #ifdef CB4
	 + "  <Transform translation=\""+ translate.ToString() + "\" scale=\"" +
	   scale.ToString() + "\">\n<Shape>";
	#endif
  #ifdef CB10
	 + "  <Transform translation=\""+ translate.ToString() + "\" scale=\"" +
	   scale.ToString() + "\">\n<Shape>";
	#endif
  #ifdef VS
	 + "  <Transform translation=\""+ translate.ToString() + "\" scale=\"" +
	   scale.ToString() + "\">\n<Shape>";
	#endif
  #ifdef DEV
	<< "  <Transform translation=\"" << translate.ToString() << "\" scale=\"" +
	   scale.ToString() << "\">\n<Shape>";
	#endif


  // The actual shape itself does not include the <Shape tags
  temp = temp
  #ifdef CB4
		+ X3D_Shape_XML();
	#endif
  #ifdef CB10
		+ X3D_Shape_XML();
	#endif
  #ifdef VS
		+ X3D_Shape_XML();
	#endif
  #ifdef DEV
		<< X3D_Shape_XML();
	#endif

  // Now the after shape stuff
  temp = temp
  #ifdef CB4
	  + "\n <Appearance>\n  <Material diffuseColor=\"" + color.ToString() +
	  "\" transparency='" + transparency + "' " +
	  #endif
  #ifdef CB10
	  + "\n <Appearance>\n  <Material diffuseColor=\"" + color.ToString() +
	  "\" transparency='" + transparency + "' " +
	  #endif
  #ifdef VS
	  + "\n <Appearance>\n  <Material diffuseColor=\"" + color.ToString() +
	  "\" transparency='" + transparency + "' " +
	  #endif
  #ifdef DEV
	   << "\n <Appearance>\n  <Material diffuseColor=\"" << color.ToString() <<
	  "\" transparency='" << transparency << "' " <<
	  #endif
	"/>\n </Appearance>\n </Shape>\n</Transform>\n";

  if(rotation.get_x()){
	temp = temp
	#ifdef CB4
	  + "</Transform>\n";
	  #endif
	#ifdef CB10
	  + "</Transform>\n";
	  #endif
	#ifdef VS
	  temp = temp + "</Transform>\n";
	  #endif
	#ifdef DEV
	  temp = temp << "</Transform>\n";
	  #endif
  }
  if(rotation.get_y()){
	temp = temp
	#ifdef CB4
	  + "</Transform><!-- y -->\n";
	  #endif
	#ifdef CB10
	  + "</Transform><!-- y -->\n";
	  #endif
	#ifdef VS
	  + "</Transform><!-- y -->\n";
	  #endif
	#ifdef DEV
	  << "</Transform><!-- y -->\n";
	  #endif
  }
  if(rotation.get_z()){
   temp = temp
   #ifdef CB4
	  + "</Transform>\n";
	  #endif
   #ifdef CB10
	  + "</Transform>\n";
	  #endif
	#ifdef VS
	  + "</Transform>\n";
	  #endif
	#ifdef DEV
	  << "</Transform>\n";
	  #endif
  }

  return temp;

}

void X3D_Solid::Append_Commentary(X3D_String c){
  commentary = commentary
	#ifdef CB4
	   + c +
	  #endif
	#ifdef CB10
	   + c +
	  #endif
	#ifdef VS
	   + c +
	  #endif
	#ifdef DEV
	   << c <<
	  #endif
	" ";
}

