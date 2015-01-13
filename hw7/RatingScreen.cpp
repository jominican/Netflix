#include "RatingScreen.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

RatingScreen::RatingScreen(QMainWindow *parent, Netflix * n) : QMainWindow(parent)
{
	p = parent;
	netflix = n;
	QString welcomeLabel 		= "Please rate the movie";
	ratings  								= new QLabel(welcomeLabel);

	mainLayout				     	= new QVBoxLayout();

	button1Layout 					= new QHBoxLayout();

	one    									= new QPushButton("*");
	two   									= new QPushButton("* *");
	three    								= new QPushButton("* * *");
	four    								= new QPushButton("* * * * *");
	five    								= new QPushButton("* * * * * *");
	noRating								= new QPushButton("Return to Main Menu");

	
	// // setup the grid layout and make it fill the window

	centerWidget  = new QWidget(this);
	centerWidget->setLayout(mainLayout);
	this->setCentralWidget(centerWidget);


	// // add all widgets to the layout
	mainLayout->addWidget(ratings);
	button1Layout->addWidget(one);
	button1Layout->addWidget(two);
	button1Layout->addWidget(three);
	button1Layout->addWidget(four);
	button1Layout->addWidget(five);
	button1Layout->addWidget(noRating);

	mainLayout->addLayout(button1Layout);

	

	connect(one,      SIGNAL(clicked()),     this, SLOT(oneS()));
	connect(two,      SIGNAL(clicked()),     this, SLOT(twoS()));
	connect(three,      SIGNAL(clicked()),     this, SLOT(threeS()));
	connect(four,      SIGNAL(clicked()),     this, SLOT(fourS()));
	connect(five,      SIGNAL(clicked()),     this, SLOT(fiveS()));
	connect(noRating,      SIGNAL(clicked()),     this, SLOT(noRatingS()));


}


RatingScreen::~RatingScreen()
{
	qDeleteAll(this->children());
}

void RatingScreen::oneS()
{
	netflix->one();
	QMessageBox::information( 
	this, 
	tr("!"), 
	tr("You rated this movie one star!") );
		p->show();
	this->close();
}

void RatingScreen::twoS()
{
	netflix->two();
	QMessageBox::information( 
	this, 
	tr("!"), 
	tr("You rated this movie two stars!") );
		p->show();
	this->close();
}

void RatingScreen::threeS()
{
	netflix->three();
	QMessageBox::information( 
	this, 
	tr("!"), 
	tr("You rated this movie three stars!") );
		p->show();
	this->close();
}

void RatingScreen::fourS()
{
	netflix->four();
	QMessageBox::information( 
	this, 
	tr("!"), 
	tr("You rated this movie four stars!") );
		p->show();
	this->close();
}

void RatingScreen::fiveS()
{
	netflix->five();
	QMessageBox::information( 
	this, 
	tr("!"), 
	tr("You rated this movie five stars!") );
		p->show();
	this->close();
}

void RatingScreen::noRatingS()
{
	QMessageBox::information( 
	this, 
	tr(":("), 
	tr("You have chosen to not rate this movie") );
	p->show();
	this->close();
}

void RatingScreen::closeEvent(QCloseEvent *x)
{
	x->accept();
	p->show();
	this->close();
}