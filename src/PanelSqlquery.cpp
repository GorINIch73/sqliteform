
#include "PanelSqlquery.h"
#include "GBase.h"
#include <wx/gdicmn.h>

// #include <iostream>
// #include <wx/wxsqlite3.h>

using namespace std;

#include "../img/first.xpm"
#include "../img/last.xpm"
#include "../img/next.xpm"
#include "../img/previous.xpm"
// #include "../img/add.xpm"
// #include "../img/delete.xpm"
#include "../img/close.xpm"
#include "../img/update.xpm"

// const int ID_FIRST = 105;

PanelSQLQuery::PanelSQLQuery(wxPanel *parent, GBase *pbase, wxString pQuery)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270, 150),
              wxBORDER_SUNKEN) {
  //    m_text = new wxStaticText(this,-1,wxT("0"),wxPoint(40,60));

  //    m_TextCtrlSqlQuery = new wxTextCtrl( this, wxID_ANY, wxEmptyString,
  //    wxDefaultPosition, wxDefaultSize, 0 );
  //    m_TextCtrlSqlQuery->SetValue("SELECT * from bank");
  //    TextQuery = wxT("SELECT * from bank");     //
  //    m_SqlQueryTextCtrl->SetToolTip(_("Enter SQL query"));
  // TextQuery = wxT("SELECT * FROM bank");

  // запоминаем параметры
  TextQuery = pQuery;
  base = pbase;

  //    m_ButtonSqlGo = new wxBitmapButton( this, ID_RUN,
  //    wxBitmap(_home_32_xpm), wxDefaultPosition, wxDefaultSize,
  //    wxBU_AUTODRAW
  //    );
  // folderAddBitmapButton->SetToolTip(_("Add new subfolder"));
  // folderControlBoxSizer->Add(folderAddBitmapButton, 0,
  // wxALIGN_CENTER_VERTICAL|wxALL, 3); m_ListBoxResult= new
  // wxListBox(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
  wxBoxSizer *bSizerMain;
  bSizerMain = new wxBoxSizer(wxVERTICAL);
  // bSizerMain->SetMinSize(FromDIP(400), wxDefaultSize.GetHeight()); // не
  //                                                                  //
  //                                                                  работает
  // bSizerMain->SetMinSize(FromDIP(wxSize(800, 600)));
  bSizerMain->SetMinSize(wxSize(800, 600));

  wxBoxSizer *bSizerBar;
  bSizerBar = new wxBoxSizer(wxHORIZONTAL);

  wxBitmap bb;

  m_bpButtonFirst =
      new wxBitmapButton(this, wxID_ANY, wxBitmap(_first_xpm),
                         wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);
  bSizerBar->Add(m_bpButtonFirst, 0, wxALL, 5);

  m_bpButtonLast =
      new wxBitmapButton(this, wxID_ANY, wxBitmap(_last_xpm), wxDefaultPosition,
                         wxDefaultSize, wxBU_AUTODRAW | 0);
  bSizerBar->Add(m_bpButtonLast, 0, wxALL, 5);

  m_bpButtonPrevious =
      new wxBitmapButton(this, wxID_ANY, wxBitmap(_previous_xpm),
                         wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);
  bSizerBar->Add(m_bpButtonPrevious, 0, wxALL, 5);

  m_bpButtonNext =
      new wxBitmapButton(this, wxID_ANY, wxBitmap(_next_xpm), wxDefaultPosition,
                         wxDefaultSize, wxBU_AUTODRAW | 0);
  bSizerBar->Add(m_bpButtonNext, 0, wxALL, 5);

  bSizerBar->Add(0, 0, 1, wxEXPAND, 5);

  m_bpButtonClose =
      new wxBitmapButton(this, wxID_ANY, wxBitmap(_close_xpm),
                         wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);
  bSizerBar->Add(m_bpButtonClose, 0, wxALL, 5);

  bSizerMain->Add(bSizerBar, 0, wxEXPAND, 2);

  m_GridResult =
      new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

  // m_grid1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0
  // );

  // Grid
  m_GridResult->EnableEditing(true);
  m_GridResult->EnableGridLines(true);
  m_GridResult->EnableDragGridSize(false);
  m_GridResult->SetMargins(0, 0);

  // Columns
  m_GridResult->EnableDragColMove(false);
  m_GridResult->EnableDragColSize(true);
  m_GridResult->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

  // Rows
  m_GridResult->EnableDragRowSize(true);
  m_GridResult->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

  // Label Appearance

  // Cell Defaults
  m_GridResult->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
  bSizerMain->Add(m_GridResult, 1, wxALL, 5);

  // таблица
  // вертикальный сайзер
  //  wxBoxSizer *hbox = new wxBoxSizer(wxVERTICAL);
  // hbox->Add(m_BtFirst, 0, wxEXPAND | wxALL, 2);
  //  hbox->Add(m_GridResult, 1, wxEXPAND | wxALL, 2);

  // SetSizer(hbox);

  //        Connect(ID_RUN,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(PanelSQLQuery::OnRun));
  this->SetSizer(bSizerMain);
  OnRun();
  this->Layout();
}
/*
void PanelSQLQuery::OnSetText(wxCommandEvent& event)
{
    kb
}
*/
void PanelSQLQuery::OnRun() {
  // тест загрузки базы
  // wxString testBaseName = wxGetCwd() + wxT("base.db");
  //    wxString testBaseName = wxT("./base.db");
  // wxString testBaseName = wxT("./ngkb0012.dbad");
  // database->Open(testBaseName);
  wxMessageOutputDebug().Printf("run...");
  wxSQLite3ResultSet Res;
  if (base->isOpen()) {
    try {

      // database->Open(testBaseName);

      // wxMessageOutputDebug().Printf("Open error: %i",
      // base->database->GetSystemErrorCode());

      // wxMessageOutputDebug().Printf("Querry: %s
      // ", TextQuery);
      wxMessageOutputDebug().Printf("go select...");
      base->database->Begin();
      // database-<query
      // database->PreparePersistentStatement(wxString::Format(_("%s"),m_TextCtrlSqlQuery->GetValue()));
      // Res = database->ExecuteUpdate();
      //     Res =
      //     database->ExecuteQuery(wxString::Format(_("%s"),m_TextCtrlSqlQuery->GetValue()));
      Res = base->database->ExecuteQuery(TextQuery);
      // if (database->GetSystemErrorCode()!=0)
      // wxLogError(wxString(_("Error:
      // "))+wxString::Format(_("%i"),database->GetSystemErrorCode()));
      //  wxSQLite3Exception& e0;
      wxMessageOutputDebug().Printf("***** Select %i",
                                    base->database->GetSystemErrorCode());
      // wxMessageOutputDebug().Printf("Select: %s
      // ",  e0.GetMessage());
      base->database->Commit();
    } catch (wxSQLite3Exception &e) {

      // wxUnusedVar(e);
      wxMessageOutputDebug().Printf("Select Error: %s ", e.GetMessage());

      // wxLogError(wxString(_("Error: "))+e.GetMessage());
    }

    // if (Res.IsNull) wxLogError(_("Error Querry!"));

    // m_GridResult->ClearGrid();
    int count = 0;

    //    m_GridResult->CreateGrid( 0, Res.GetColumnCount() );  //временно

    // m_GridResult->ClearGrid();

    int numCol = Res.GetColumnCount();
    if (numCol > 0) {
      m_GridResult->CreateGrid(0,
                               numCol); // временно - второй раз нельзя - надо
                                        // найти способ повторной инициализации
      // m_GridResult->CreateGrid( 0, Res.GetColumnCount() );  //временно

      // Label some columns
      while (numCol > 0) {
        m_GridResult->SetColLabelValue(numCol - 1,
                                       Res.GetColumnName(numCol - 1));
        //            wxLogInfo(wxString::Format(_("%s"),Res.GetColumnType(numCol-1)));
        wxMessageOutputDebug().Printf("ColumnType=%i",
                                      Res.GetColumnType(numCol - 1));
        numCol--;
      }
      // Grid1->SetColLabelValue(0, _("alpha")); //from wxSmith 2
      // Grid1->SetColLabelValue(1, _("beta"));  //from wxSmith
      // Grid1->SetColLabelValue(2, _("gamma")); //from wxSmith
      // Grid1->SetColLabelValue(3, _("delta "));
      // Grid1->SetColLabelValue(4, _("epsilon"));

      // Label some rows
      //  Grid1->SetRowLabelValue(0, _("mu")); // from wxSmith
      //  Grid1->SetRowLabelValue(1, _("nu")); // from wxSmith
      //  Grid1->SetRowLabelValue(2, _("xi")); // from wxSmith
      //  Grid1->SetRowLabelValue(3, _("omicron"));
      //  Grid1->SetRowLabelValue(4, _("pi"));
      m_GridResult->SetColFormatFloat(4, -1, 2);
      m_GridResult->SetColFormatNumber(0);

      while (Res.NextRow()) {
        m_GridResult->InsertRows(count);
        int numCol = Res.GetColumnCount();
        while (numCol > 0) {
          /*
          if (Res.GetColumnType(numCol-1)==2)
                m_GridResult->SetCellValue(count,numCol-1,wxString::Format(_("%8.2f"),Res.GetDouble(numCol-1)));
          else
                m_GridResult->SetCellValue(count,numCol-1,wxString::Format(_("%s"),Res.GetAsString(numCol-1)));
            */
          m_GridResult->SetCellValue(
              count, numCol - 1,
              wxString::Format(_("%s"), Res.GetAsString(numCol - 1)));

          numCol--;
        }
        // m_GridResult->InsertRows();
        //   m_GridResult->SetCellValue(count,0,wxString::Format(_("%s"),Res.GetAsString(0)));
        //   m_GridResult->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)));
        //          m_GridResult->SetCellValue(count,2,wxString::Format(_("%s"),Res.GetAsString(2)));
        //          m_GridResult->SetCellValue(count,3,wxString::Format(_("%s"),Res.GetAsString(3)));
        //          m_GridResult->SetCellValue(count,4,wxString::Format(_("%s"),Res.GetAsString(4)));
        //          m_GridResult->SetCellValue(count,2,wxString::Format(_("%8.2f"),Res.GetDouble(2)));
        //          m_GridResult->SetCellValue(count,2,wxString::Format(_("%f"),Res.GetDouble(2)));
        // m_GridResult->SetCellValue(count,4,Res.GetDouble(4));
        count++;
        // m_GridResult->InsertRows(count);
        // std::cout  << wxString::Format(_("%s"),Res.GetAsString(0)) << "\n";

        // count++;
      }
    }
    //}
    Res.Finalize();
    // database->Close();
  } else {
    wxMessageOutputDebug().Printf("Base %s not opening", base->baseName);
  }
}
