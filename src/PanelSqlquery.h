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

protected:
  wxBitmapButton *m_bpButtonFirst;
  wxBitmapButton *m_bpButtonLast;
  wxBitmapButton *m_bpButtonNext;
  wxBitmapButton *m_bpButtonPrevious;
  wxBitmapButton *m_bpButtonClose;

  wxGrid *m_GridResult;

  GBase *base;
  wxString TextQuery;

  //   void OnRun(wxCommandEvent& event) ;
  void OnRun();

public:
  PanelSQLQuery(wxPanel *parent, GBase *pbase, wxString pQuery);
  // PanelSQLQuery(wxPanel *parent, wxSQLite3Database db, wxString tQuery);
  //  void OnSetText (wxCommandEvent& event) ;

  // wxStaticText *m_text ;

  // wxTextCtrl *m_TextCtrlSqlQuery;
  // void goQuery();
};

#endif
