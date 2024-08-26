#ifndef PANEL_SQL_H
#define PANEL_SQL_H

#include <wx/panel.h>
#include <wx/wx.h>

#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/wxsqlite3.h>

#include "GBase.h"

class PanelSQLQuery : public wxPanel {
public:
  PanelSQLQuery(wxPanel *parent);
  // PanelSQLQuery(wxPanel *parent, wxSQLite3Database db, wxString tQuery);
  //  void OnSetText (wxCommandEvent& event) ;

  // wxStaticText *m_text ;

  // wxTextCtrl *m_TextCtrlSqlQuery;
  // wxBitmapButton* m_ButtonSqlGo;

  GBase *base;
  // wxSQLite3Database *database;

  wxGrid *m_GridResult;
  wxString TextQuery;

  //   void OnRun(wxCommandEvent& event) ;
  void OnRun();
  // void goQuery();
};

#endif
