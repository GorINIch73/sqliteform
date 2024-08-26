#include <wx/menu.h>
#include <wx/wx.h>
#include <wx/wxprec.h>

#include "PanelSqlquery.h"
// #include "GBase.h"

class MainWindow : public wxFrame {
public:
  MainWindow(const wxString &title);

  void OnQuit(wxCommandEvent &WXUNUSED(event));
  // void BaseConnect(wxString name);

  PanelSQLQuery *m_p;

  wxMenuBar *menubar;
  wxMenu *file;
};
