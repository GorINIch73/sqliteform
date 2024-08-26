
#include "PanelSqlquery.h"
#include "GBase.h"

#include <iostream>
#include <wx/wxsqlite3.h>

using namespace std;

// #include "../img/home_32.xpm"

// const int ID_RUN = 105;

PanelSQLQuery::PanelSQLQuery(wxPanel *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270, 150),
              wxBORDER_SUNKEN) {
  //    m_text = new wxStaticText(this,-1,wxT("0"),wxPoint(40,60));

  //    m_TextCtrlSqlQuery = new wxTextCtrl( this, wxID_ANY, wxEmptyString,
  //    wxDefaultPosition, wxDefaultSize, 0 );
  //    m_TextCtrlSqlQuery->SetValue("SELECT * from bank");
  //    TextQuery = wxT("SELECT * from bank");     //
  //    m_SqlQueryTextCtrl->SetToolTip(_("Enter SQL query"));

  TextQuery = wxT("SELECT counterparties.counterparty, 'N ' || \
        contracts.contract_number, contracts.contract_date,\
        contracts.for_check, ROUND(SUM(sum),2), COUNT(DISTINCT bank.id),\
        articles.article, contracts.note  FROM bank_decryption inner join\
        contracts on bank_decryption.contract_id=contracts.id inner join\
        articles on bank_decryption.article_id=articles.id inner join bank\
        on bank_decryption.bank_id=bank.id inner join counterparties on \
        contracts.counterparty_id =counterparties.id WHERE\
        contracts.for_audit GROUP BY counterparties.counterparty,\
        contracts.contract_number, \
        contracts.contract_date, articles.article ORDER BY \
        contracts.contract_date, contracts.contract_number");

  // TextQuery = wxT("SELECT * FROM bank");

  // base = new GBase(wxT("./base.db"));
  base = new GBase(wxT("./ngkb0012.dbad"));

  //    m_ButtonSqlGo = new wxBitmapButton( this, ID_RUN,
  //    wxBitmap(_home_32_xpm), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW
  //    );
  // folderAddBitmapButton->SetToolTip(_("Add new subfolder"));
  // folderControlBoxSizer->Add(folderAddBitmapButton, 0,
  // wxALIGN_CENTER_VERTICAL|wxALL, 3); m_ListBoxResult= new
  // wxListBox(this,wxID_ANY,wxDefaultPosition,wxDefaultSize);
  m_GridResult = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  // m_GridResult = new wxGrid( this,-1,wxPoint( 0, 0 ),wxSize( 400, 300 ) );
  // m_GridResult = new wxGrid( NULL,-1);

  // wxGrid *grid = new wxGrid( this, -1,wxPoint( 0, 0 ), wxSize( 400, 300 ) );

  // wxPanel *panel = new wxPanel(this,wxID_ANY) ;
  wxBoxSizer *hbox = new wxBoxSizer(wxVERTICAL);
  //    hbox->Add(m_text,0,wxEXPAND|wxALL,5);
  //    hbox->Add(m_TextCtrlSqlQuery,0,wxEXPAND|wxALL,2);
  //    hbox->Add(m_ButtonSqlGo,0,wxEXPAND|wxALL,2);
  hbox->Add(m_GridResult, 1, wxEXPAND | wxALL, 2);

  // Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,wxCommandEventHandler(Listbox::OnDblClick))
  // ;
  // Connect(wxID_NEW,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(MyPanel::OnNew));

  // m_GridResult->CreateGrid( 10, 10 );
  //  //m_GridResult->SetTable();
  //  m_GridResult->InsertRows(0,10);
  //  // We can set the sizes of individual rows and columns
  //  // in pixels
  //  m_GridResult->SetRowSize( 0, 60 );
  //  m_GridResult->SetColSize( 0, 120 );
  //  // And set grid cell contents as strings
  //  m_GridResult->SetCellValue( 0, 0, "wxGrid is good" );
  //  // We can specify that some cells are read->only
  //  m_GridResult->SetCellValue( 0, 3, "This is read->only" );
  //  m_GridResult->SetReadOnly( 0, 3 );
  //  // Colours can be specified for grid cell contents
  //  m_GridResult->SetCellValue(3, 3, "green on grey");
  //  m_GridResult->SetCellTextColour(3, 3, *wxGREEN);
  //  m_GridResult->SetCellBackgroundColour(3, 3, *wxLIGHT_GREY);
  //  // We can specify the some cells will store numeric
  //  // values rather than strings. Here we set grid column 5
  //  // to hold floating point values displayed with width of 6
  //  // and precision of 2
  //  m_GridResult->SetColFormatFloat(5, 6, 2);
  //  m_GridResult->SetCellValue(0, 6, "3.1415");

  // wxString str=wxGetTextFromUser(wxT("Addnewitem"));
  // if(str.Len()>0)
  //     m_ListBoxResult->Append(str);
  SetSizer(hbox);

  // wxSQLite3Database::InitializeSQLite();

  // database = new wxSQLite3Database();

  //        Connect(ID_RUN,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(PanelSQLQuery::OnRun));
  OnRun();
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
    m_GridResult->ClearGrid();

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
