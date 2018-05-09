// X3D_Text
#include "X3D_Text.h"


X3D_Text::X3D_Text():X3D_Solid(),length(0), max_extent(5){}

X3D_Text::X3D_Text (const X3D_Text & that):X3D_Solid(){
  text = that.text;
  length = that.length;
  max_extent = that.max_extent;
}

X3D_Text:: X3D_Text(const X3D_String & parm1):
       X3D_Solid(),
       length(0),
      #ifdef CB4
         max_extent(parm1.Length()),
         #endif
      #ifdef VS
         max_extent(parm1.length()),
         #endif
      #ifdef DEV
         max_extent(parm1.length()),
         #endif
       text(parm1)
       {}

X3D_Text X3D_Text::operator =  (const X3D_Text & that){
  X3D_Solid::operator = (that);
  text = that.text;
  length = that.length;
  max_extent = that.max_extent;
  return *this;
}

X3D_String X3D_Text::ToString() const{
  X3D_String temp = X3D_Solid::ToString();
  temp = temp 
    #ifdef CB4
     + ", text (" + text+") " + ", length("+length+"), max("+max_extent+")";
     #endif
	#ifdef CB10
	 + ", text (" + text+") " + ", length("+length+"), max("+max_extent+")";
	 #endif
	#ifdef VS
	 + ", text (" + text+") " + ", length("+length+"), max("+max_extent+")";
	 #endif
	#ifdef DEV
	 << ", text (" << text+") " << ", length(" << length << "), max(" << max_extent << ")";
	 #endif
  return temp;
}


X3D_String X3D_Text::X3D_Shape_XML()const{
  X3D_String temp = "";
  temp = temp
  #ifdef CB4
	   + "\n<Text string=\"" + text.c_str() + "\" length='" + length + "' maxExtent='"+max_extent+"'/>\n";
	 #endif
  #ifdef CB10
	   + "\n<Text string=\"" + text.c_str() + "\" length='" + length + "' maxExtent='"+max_extent+"'/>\n";
	 #endif
  #ifdef VS
	   + "\n<Text string=\"" + text.c_str() + "\" length='" + length + "' maxExtent='"+max_extent+"'/>\n";
	 #endif
  #ifdef DEV
	   << "\n<Text string=\"" << text.c_str() << "\" length='" << length << "' maxExtent='" << max_extent << "'/>\n";
	#endif
  return temp;
}
