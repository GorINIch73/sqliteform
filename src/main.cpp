// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/string.h>
#include <wx/utils.h>

#include "MainWindow.h"


class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MainWindow *MW = new MainWindow("Hello");
    MW->Show(true);
    return true;
}

   
    // wxString msg = wxT("Ваша система: ");    

    // msg << wxGetHomeDir( ) << "\n";
    // msg << wxGetOsDescription( ) << "\n";
    // msg << wxGetUserName( ) << "\n";
    // msg << wxGetFullHostName( ) << "\n";
    // msg << wxGetFreeMemory().ToLong() << "\n";

    // wxLogMessage(msg);

