#include <wx/icon.h>

#include "../img/close.xpm"
#include "../img/home_32.xpm"
#include "MainWindow.h"
#include "PanelSqlquery.h"

// #include <wx/wxsqlite3.h>

// #include "leftPanel.h"
// #include "rightPanel.h"

// #include "google.xpm"

// const int ID_PLUS = 101;
// const int ID_MINUS = 102;

MainWindow::MainWindow(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {

  SetIcon(wxIcon(_home_32_xpm));

  //   wxPanel *panel = new wxPanel(this,wxID_ANY);
  //   wxBitmapButton *m_btnBlocoInicio = new wxBitmapButton(panel, wxID_ANY,
  //   wxBitmap(_home_32_xpm), wxPoint(120,20)); wxButton *button = new
  //   wxButton(panel,wxID_EXIT,wxT("Quit"),wxPoint(20,20));

  //   button->Bind(wxEVT_BUTTON,&MainWindow::OnQuit,this,wxID_EXIT);

  //   m_btnBlocoInicio->SetFocus();

  menubar = new wxMenuBar;
  file = new wxMenu;

  file->Append(wxID_ANY, wxT("&New"));
  file->Append(wxID_ANY, wxT("&Open"));
  file->Append(wxID_ANY, wxT("&Save"));
  file->AppendSeparator();

  wxMenu *imp = new wxMenu;
  imp->Append(wxID_ANY, wxT("Import new sfeedlist..."));
  imp->Append(wxID_ANY, wxT("Import bookmarks..."));
  imp->Append(wxID_ANY, wxT("Importmail..."));
  file->AppendSubMenu(imp, wxT("I&mport"));
  wxMenuItem *quit = new wxMenuItem(file, wxID_EXIT, wxT("&Quit\tCtrl+W"));
  file->Append(quit);

  menubar->Append(file, wxT("&File"));
  SetMenuBar(menubar);

  // wxBitmap exit(_quit_xpm);
  wxImage img(_close_xpm);
  // img.Rescale(2, 32);

  wxToolBar *toolbar = CreateToolBar();
  toolbar->AddTool(wxID_EXIT, wxT("Exitapplication"), img);
  // toolbar->AddTool()
  toolbar->Realize();

  Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
          wxCommandEventHandler(MainWindow::OnQuit));

  wxPanel *panel = new wxPanel(this, wxID_ANY);
  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  // панель запроса ---------------------------------------------------------

  // BaseConnect("./ngkb0012.dbad");
  base = new GBase(wxT("./ngkb0012.dbad"));

  wxString TextQuery;
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

  m_p = new PanelSQLQuery(panel, base, TextQuery);
  // m_p = new PanelSQLQuery(panel);
  // m_rp = new rightPanel(panel);
  //
  //
  // -------------------------------------------------------------------------
  // hbox->Add(m_lp,1,wxEXPAND|wxALL,5);
  hbox->Add(m_p, 1, wxEXPAND | wxALL, 5);
  //    hbox->Add(m_rp,1,wxEXPAND|wxALL,5);
  panel->SetSizer(hbox);

  Centre();
}

void MainWindow::OnQuit(wxCommandEvent &WXUNUSED(event)) { Close(true); };
