// X3D_Group
#include "X3D_Group.h"


X3D_Group::X3D_Group():X3D_Solid(){}

X3D_Group::X3D_Group (const X3D_Group & that):X3D_Solid(){
  items = that.items;
}

X3D_Group::~X3D_Group(){
 int size = items.size();
 for(int i = 0;i<size;i++){
   X3D_SolidPtr ptr = items[i];
   if(ptr){
     delete ptr;
     items[i] = NULL;
     }
   }
}

X3D_Group X3D_Group::operator =  (const X3D_Group & that){
  X3D_Solid::operator = (that);
  items = that.items;
  return *this;
}

X3D_String X3D_Group::ToString() const{
  X3D_String temp = X3D_Solid::ToString();
  for(unsigned int i = 0;i<items.size();i++){
  temp = temp
  #ifdef CB4
     +"\n   " + i+": " + items[i]->ToString();
     #endif
  #ifdef CB10
	 +"\n   " + i+": " + items[i]->ToString();
	 #endif
  #ifdef DEV
	 << "\n   " << i << ": " << items[i]->ToString();
	#endif
   }
  return temp;
}

X3D_String X3D_Group::ToXML() const{
  if(items.size() < 1)
	return "\n<!-- Empty group omitted -->\n";
  X3D_String temp = XML_Start();
  temp = temp
  #ifdef CB4
	   + "<Group><!-- "+Name()+"-->\n";
	 #endif
  #ifdef CB10
	   + "<Group><!-- "+Name()+"-->\n";
	 #endif
  #ifdef DEV
	   << "<Group><!-- "<<Name()<<"-->\n";
    #endif
  for(unsigned int i=0;i<items.size();i++){
    X3D_SolidPtr ptr = items[i];
    // is this a group itself?
    X3D_Group * gptr = dynamic_cast<X3D_Group*>(ptr);
    if(gptr) {
       temp = temp
        #ifdef CB4
          +
		 #endif
		#ifdef CB10
		  +
		 #endif
		#ifdef VS
		  +
		 #endif
		#ifdef DEV
		  <<
		  #endif
	   //gptr->X3D_Solid::ToXML();
	   gptr->ToXML();
	   }
	else {
	  temp = temp
	  #ifdef CB4
		+ ptr->ToXML();
		#endif
	  #ifdef CB10
		+ ptr->ToXML();
		#endif
	  #ifdef DEV
		<< ptr->ToXML();
		#endif
	  #ifdef VS
		+ ptr->ToXML();
		#endif
	  }
	} // end of subordinate shapes
  temp = temp
  #ifdef CB4
	   + "</Group>\n";
	 #endif
  #ifdef CB10
	   + "</Group>\n";
	 #endif
  #ifdef DEV
	   << "</Group>\n";
	#endif
  #ifdef VS
	   + "</Group>\n";
	 #endif

  temp = temp
  #ifdef CB4
	   + XML_End();
	 #endif
  #ifdef CB10
	   + XML_End();
	 #endif
  #ifdef DEV
	   << XML_End();
	#endif
  #ifdef VS
	   + XML_End();
	 #endif
  return temp;
}


X3D_String X3D_Group::X3D_Shape_XML()const{
  return "";
}

X3D_SolidPtr X3D_Group::get_solid(unsigned index){
  if(index > items.size())
	return NULL;
  return items[index];
}

void X3D_Group::Clear(){
 for(unsigned i = 0;i<items.size();i++){
   X3D_SolidPtr ptr = items[i];
   if(ptr){
	  ptr->Clear();
	  delete ptr;
	  ptr = NULL;
	  }
   }
 items.clear();
}

void __fastcall X3D_Group::set_color(X3D_Color color){
 for(unsigned i = 0;i<items.size();i++)
	items[i]->set_color(color);
}
