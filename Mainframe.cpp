/**
 * @file Mainframe.cpp
 * @author Alex Bocchi
 */

#include "pch.h"
#include "ids.h"
#include "Mainframe.h"
#include "ChessView.h"

/**
 * Initialize the MainFrame window.
 */
void Mainframe::Initialize()
{
    Create(nullptr, wxID_ANY, L"Chess Game", wxDefaultPosition,  wxSize( 800,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto chessView = new ChessView();
    chessView->Initialize(this);

    // Add it to the sizer
    sizer->Add(chessView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto gameMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(gameMenu, L"&Game");
    menuBar->Append(helpMenu, L"&Help");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    gameMenu->Append(IDM_STARTGAME, L"&Start Game", L"Start a game of chess");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");



    SetMenuBar(menuBar);

    CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::AboutApp, this, wxID_ABOUT);
}

/**
* Exit menu option handlers
 * @param exit
*/
void Mainframe::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
* About menu option handlers
 * @param exit
*/
void Mainframe::AboutApp(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to the Game of Chess!",
            L"About Chess",
            wxOK,
            this);
}


