#include "LoginScreen.h"
#include <sstream>
#include <string>
#include <iostream>
#include <exception>

using namespace std;

LoginScreen::LoginScreen(int argc, char* argv[])
{
	welcomeLabel  = new QLabel("Welcome to Netflics!");
	winLayout     = new QVBoxLayout();
	buttonLayout  = new QHBoxLayout();
	//txtWordsInput = new QPlainTextEdit;
	quitButton    = new QPushButton("&Quit");
	loginButton   = new QPushButton("&Login");
	newuserButton = new QPushButton("&New User");
	loginRow 			= new QFormLayout();
	login 				= new QLineEdit();
	password      = new QLineEdit();


	netflix 			= new Netflix(argc, argv);
	
	// setup the grid layout and make it fill the window

	centerWidget  = new QWidget(this);
	centerWidget->setLayout(winLayout);
	this->setCentralWidget(centerWidget);

	// add all widgets to the layout
	// redo the following 4 lines to customize the layout
	winLayout->addWidget(welcomeLabel);
	loginRow->addRow("Login:", login);
	loginRow->addRow("Password:", password);
	buttonLayout->addWidget(loginButton);
	buttonLayout->addWidget(newuserButton);	
	buttonLayout->addWidget(quitButton);
	winLayout->addLayout(loginRow);
	winLayout->addLayout(buttonLayout);

	connect(quitButton,      SIGNAL(clicked()),     this, SLOT(quit()));
	connect(newuserButton,      SIGNAL(clicked()),     this, SLOT(newUser()));
	connect(loginButton,      SIGNAL(clicked()),     this, SLOT(loginIn()));

}

LoginScreen::~LoginScreen()
{
	qDeleteAll(this->children());
}

void LoginScreen::loginIn()
{
	string temp = login->text().toStdString();
	string temp2 = password->text().toStdString();
	if(netflix->loginIn(temp,temp2)){
		MainScreen* ms = new MainScreen(this, netflix);
		// ms.setNetflix();
		ms->show();
		this->hide();
	}
	else{
		QMessageBox::information( 
		this, 
		tr("ERROR!"), 
		tr("username does not exist or password is incorrect! Try again") );
	}
}



void LoginScreen::newUser()
{
	NewUser* ns = new NewUser(this, netflix);

	ns->show();
	this->hide();
}

void LoginScreen::quit()
{
	netflix->quit();
	this->close();
}