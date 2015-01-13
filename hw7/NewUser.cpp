#include "NewUser.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

NewUser::NewUser(QMainWindow *parent, Netflix * n) : QMainWindow(parent)
{
	p = parent;

	netflix = n;

	signupLabel  						= new QLabel("Please sing up for Netflics");
	newuserLayout     			= new QVBoxLayout();
	buttonLayout 						= new QHBoxLayout();
	confirmButton    				= new QPushButton("Confir&m");
	cancelButton   					= new QPushButton("&Cancel");
	signupRow 							= new QFormLayout();
	login 									= new QLineEdit();
	name 										= new QLineEdit();
	password 								= new QLineEdit();
	address 								= new QLineEdit();
	card 										= new QLineEdit();

	//cout<<netflix<<endl;
	
	// // setup the grid layout and make it fill the window

	centerWidget  = new QWidget(this);
	centerWidget->setLayout(newuserLayout);
	this->setCentralWidget(centerWidget);

	// // add all widgets to the layout
	newuserLayout->addWidget(signupLabel);
	signupRow->addRow("Login:", login);
	signupRow->addRow("Name:", name);
	signupRow->addRow("Password:", password);
	signupRow->addRow("Address:", address);
	signupRow->addRow("Credit Card:", card);

	buttonLayout->addWidget(confirmButton);
	buttonLayout->addWidget(cancelButton);	
	newuserLayout->addLayout(signupRow);
	newuserLayout->addLayout(buttonLayout);

	connect(confirmButton,      SIGNAL(clicked()),     this, SLOT(confirm()));
	connect(cancelButton,      SIGNAL(clicked()),     this, SLOT(cancel()));

	//winLayout->addWidget(txtWordsInput, 0);
	//winLayout->addLayout(genLayout,     1);

}

NewUser::~NewUser()
{
	qDeleteAll(this->children());
}

void NewUser::confirm()
{
	string userID = login->text().toStdString();
	string userName = name->text().toStdString();
	string pass = password->text().toStdString();
	string a = address->text().toStdString();
	string c = card->text().toStdString();

	if(userID == "" || userName == "" || pass == "" || a == "" || c == ""){
		QMessageBox::information( 
		this, 
		tr("ERROR!"), 
		tr("You did not enter a user ID or name or password") );
	}
	else{
		if(netflix->confirm(userID, userName, pass, a, c)){
	  	QMessageBox::information( 
			this, 
			tr("ERROR!"), 
			tr("Username already exist! Try again") );
		}
		else{
			QMessageBox::information( 
			this, 
			tr("SUCCESS!"), 
			tr("You have created a new user. Click OK to return to login menu") );
			this->close();
			p->show();
		}
	}
}

void NewUser::cancel()
{
	p->show();

	this->close();
}

void NewUser::closeEvent(QCloseEvent *x)
{
	x->accept();
	p->show();
	this->close();
}
