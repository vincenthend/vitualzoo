#include "facility.h"

Road::Road()
{
  locX = 0;
  locY = 0;
  cellID = 21;
  Cell::SetCode(default_code);
}

Road::Road(int x, int y)
{
  locX = x;
  locY = y;
  cellID = 21;
  Cell::SetCode(default_code);
}

Road::Road(int x, int y, bool IsEntrance)
{  
  locX = x;
  locY = y;
  if (IsEntrance) {
    cellID = 210;
  }
  else {
    cellID = 211;
  }
  Cell::SetCode(default_code);
}

Resto::Resto()
{
  locX = 0;
  locY = 0;
  cellID = 22;
  Cell::SetCode(default_code);
}

Resto::Resto(int x, int y)
{
  locX = x;
  locY = y;
  cellID = 22;
  Cell::SetCode(default_code);
}

Park::Park()
{
  locX = 0;
  locY = 0;
  cellID = 23;
  Cell::SetCode(default_code);
}

Park::Park(int x, int y)
{
  locX = x;
  locY = y;
  cellID = 23;
  Cell::SetCode(default_code);
}
