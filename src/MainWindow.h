#include <wx/menu.h>
#include <wx/wx.h>
#include <wx/wxprec.h>

#include "GBase.h"
#include "PanelSqlquery.h"

class MainWindow : public wxFrame {
public:
  MainWindow(const wxString &title);

  void OnQuit(wxCommandEvent &WXUNUSED(event));
  // void BaseConnect(wxString name);

  GBase *base;

  PanelSQLQuery *m_p;

  wxMenuBar *menubar;
  wxMenu *file;
};
