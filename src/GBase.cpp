#include "GBase.h"
#include <cstring>
/*
GBase::GBase() {
  baseName = "";
  database = new wxSQLite3Database();
}
*/
GBase::GBase(wxString name) {
  database = new wxSQLite3Database();
  baseName = name;
  OpenBase();
}

int GBase::OpenBase() {
  // wxString testBaseName = wxT("./ngkb0012.dbad");
  //  database->Open(testBaseName);
  // проверка на наличие файла
  // baseName = name;

  wxSQLite3ResultSet Res;
  try {
    wxMessageOutputDebug().Printf("Open base: %s", baseName);

    database->Open(baseName);

    wxMessageOutputDebug().Printf("Open error: %i",
                                  database->GetSystemErrorCode());
    return 1;
    //      wxMessageOutputDebug().Printf("Querry: %s ", TextQuery);

    //  database->Begin();
    // database-<query
    // database->PreparePersistentStatement(wxString::Format(_("%s"),m_TextCtrlSqlQuery->GetValue()));
    // Res = database->ExecuteUpdate();
    //     Res =
    //     database->ExecuteQuery(wxString::Format(_("%s"),m_TextCtrlSqlQuery->GetValue()));
    //    Res = database->ExecuteQuery(TextQuery);
    // if (database->GetSystemErrorCode()!=0) wxLogError(wxString(_("Error:
    // "))+wxString::Format(_("%i"),database->GetSystemErrorCode()));
    // wxSQLite3Exception& e0;
    //     wxMessageOutputDebug().Printf("***** Select %i",
    //     database->GetSystemErrorCode());
    // wxMessageOutputDebug().Printf("Select: %s ",  e0.GetMessage());
    //    database->Commit();
  } catch (wxSQLite3Exception &e) {

    // wxUnusedVar(e);
    wxMessageOutputDebug().Printf("Open Base Error: %s ", e.GetMessage());
    return 0;
    // wxLogError(wxString(_("Error: "))+e.GetMessage());
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
