#include "GBase.h"
#include <cstring>
GBase::GBase(wxString name) {
  database = new wxSQLite3Database();
  baseName = name;
  OpenBase();
}

int GBase::OpenBase() {

  wxSQLite3ResultSet Res;
  try {
    wxMessageOutputDebug().Printf("Open base: %s", baseName);

    database->Open(baseName);

    wxMessageOutputDebug().Printf("Open error: %i",
                                  database->GetSystemErrorCode());
    return 1;
  } catch (wxSQLite3Exception &e) {

    // wxUnusedVar(e);
    wxMessageOutputDebug().Printf("Open Base Error: %s ", e.GetMessage());
    return 0;
  }
  return 0;
};

GBase::~GBase() {

  wxMessageOutputDebug().Printf("close base: %s ", baseName);

  if (database != NULL)
    database->Close();
};

// Проверка на открытость базы
int GBase::isOpen() {
  wxMessageOutputDebug().Printf("is open ... ");
  if (database != NULL)
    return database->IsOpen();
  return 0;
}
