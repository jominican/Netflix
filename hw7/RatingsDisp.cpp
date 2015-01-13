#include "RatingsDisp.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

RatingsDisp::RatingsDisp(QMainWindow *parent, Netflix * n) : QMainWindow(parent)
{
	netflix = n;
	p = parent;
	movieInfo			  				= new QLabel("Movie Ratings");
	movieTitle							= new QLabel(netflix->getCurrentMovieTitleLabel3());

	movieLayout				     	= new QVBoxLayout();

	buttonLayout 						= new QHBoxLayout();

	rate 				    				= new QPushButton("&Rate");
	nextMovie   						= new QPushButton("&Next Movie");
	returnToMain		    		= new QPushButton("&Return to Main Menu");

	QFrame* line1						= new QFrame();


	// // setup the grid layout and make it fill the window
	centerWidget  = new QWidget(this);
	centerWidget->setLayout(movieLayout);
	this->setCentralWidget(centerWidget);


	// // add all widgets to the layout
	movieLayout->addWidget(movieTitle);
	line1->setFrameShape(QFrame::HLine);
	line1->setFrameShadow(QFrame::Sunken);
	movieLayout->addWidget(line1);
	movieLayout->addWidget(movieInfo);


	buttonLayout->addWidget(rate);
	buttonLayout->addWidget(nextMovie);
	buttonLayout->addWidget(returnToMain);
	movieLayout->addLayout(buttonLayout);

	connect(nextMovie,      SIGNAL(clicked()),     this, SLOT(next()));
	connect(rate,      SIGNAL(clicked()),     this, SLOT(change()));
	connect(returnToMain,      SIGNAL(clicked()),     this, SLOT(returnToMainMenu()));

}


RatingsDisp::~RatingsDisp()
{
	qDeleteAll(this->children());
}


void RatingsDisp::next()
{
	movieTitle->setText(netflix->next2());
}

void RatingsDisp::change()
{
	RatingScreen* rs = new RatingScreen(this, netflix);
	rs->show();
	this->hide();
	//currentQueueLabel->setText(netflix->getCurrentQueueLabel());

}

void RatingsDisp::returnToMainMenu()
{
	p->show();
	this->close();
}

void RatingsDisp::closeEvent(QCloseEvent *x)
{
	x->accept();
	p->show();
	this->close();
}