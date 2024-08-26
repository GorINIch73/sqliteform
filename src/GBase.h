#ifndef GBase_H
#define GBase_H

#include <wx/wx.h>
#include <wx/wxsqlite3.h>

// Объект базы данных наврятли нужен!

class GBase {
public:
  // GBase();
  GBase(wxString name);
  int OpenBase();
  ~GBase();

  wxSQLite3Database *database;
  wxString baseName;

  int isOpen();

private:
  // wxString baseName;
  //         wxSQLite3Database *database;
};

#endif
