#include "colors.h"


const Color darkGrey ={20,30,40,255};
  const  Color green    ={11,156,16,255};
 const   Color red      ={237,5,20,255};
  const  Color orange    ={245,15,17,255};
  const  Color yellow    ={245,237,17,255};
 const   Color purple    ={176,44,209,255};
  const  Color cyan      ={11,222,230,255};
  const  Color blue      ={41,60,204,255};
  const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

  std::vector <Color>GetCellColors()
  {
    return {darkGrey,green,red,orange,yellow,purple,cyan,blue};
  }