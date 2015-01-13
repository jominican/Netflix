#include "QueueDisp.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

QueueDisp::QueueDisp(QMainWindow *parent, Netflix * n) : QMainWindow(parent)
{
	int i=0;
	netflix = n;
	p = parent;
	movieInfo			  				= new QLabel("Movie Info");
	movieTitle							= new QLabel(netflix->getCurrentMovieTitleLabel());

	movieLayout				     	= new QVBoxLayout();

	buttonLayout 						= new QHBoxLayout();

	addToQueue   						= new QPushButton("&Add to my Queue");
	returnToMain		    		= new QPushButton("&Return to Main Menu");

	QFrame* line1						= new QFrame();

	


	 size = netflix->numKeywords();
	 string * list = new string[size];

	keywords = new QLabel* [size];

	tempMapKeyWords = netflix->getAllKeywords();
	setIter = tempMapKeyWords.begin();
	while(setIter != tempMapKeyWords.end() && i<size){
		list[i] = *(setIter);
		i++;
		++setIter;
	}

	for(int i=0; i<size; i++){
		keywords[i] = new QLabel(QString::fromStdString(list[i]));
	}


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
	for(int i=0; i<size; i++){
		movieLayout->addWidget(keywords[i]);
	}
	buttonLayout->addWidget(addToQueue);
	buttonLayout->addWidget(returnToMain);
	movieLayout->addLayout(buttonLayout);

	connect(addToQueue,      SIGNAL(clicked()),     this, SLOT(addToMyQueue()));
	connect(returnToMain,      SIGNAL(clicked()),     this, SLOT(returnToMainMenu()));

}


QueueDisp::~QueueDisp()
{
	qDeleteAll(this->children());
}

void QueueDisp::addToMyQueue()
{
	netflix->addToMyQueue();
	QMessageBox::information( 
	this, 
	tr("SUCCESS!"), 
	tr("Movie has been added to queue!") );

}

void QueueDisp::returnToMainMenu()
{
	p->show();
	this->close();
}

void QueueDisp::closeEvent(QCloseEvent *x)
{
	x->accept();
	p->show();
	this->close();
}