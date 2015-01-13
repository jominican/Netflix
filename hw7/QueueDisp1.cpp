#include "QueueDisp1.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

QueueDisp1::QueueDisp1(QMainWindow *parent, Netflix * n) : QMainWindow(parent)
{
	int i = 0;
	size = 0;
	netflix = n;
	p = parent;
	movieInfo			  				= new QLabel("Movie Info");
	movieTitle							= new QLabel(netflix->getCurrentMovieTitleLabel2());

	movieLayout				     	= new QVBoxLayout();

	buttonLayout 						= new QHBoxLayout();

	nextMovie		    				= new QPushButton("&Next Movie");
	addToQueue   						= new QPushButton("&Add to my Queue");
	returnToMain		    		= new QPushButton("&Return to Main Menu");

	QFrame* line1						= new QFrame();

	size = netflix->setNumKeywords();
	string * list = new string[size];

	tempMapKeyWords = netflix->getAllKeywords1();
	setIter = tempMapKeyWords.begin();
	while(setIter != tempMapKeyWords.end() && i<size){
		list[i] = *(setIter);
		i++;
		setIter++;
	}

	for(int i=0; i<size; i++){
		line = line + list[i] + '\n';
	}

	keywords = new QLabel(QString::fromStdString(line));

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
		movieLayout->addWidget(keywords);
	}
	// this->create();

	buttonLayout->addWidget(nextMovie);
	buttonLayout->addWidget(addToQueue);
	buttonLayout->addWidget(returnToMain);
	movieLayout->addLayout(buttonLayout);

	connect(nextMovie,      SIGNAL(clicked()),     this, SLOT(next()));
	connect(addToQueue,      SIGNAL(clicked()),     this, SLOT(addToMyQueue()));
	connect(returnToMain,      SIGNAL(clicked()),     this, SLOT(returnToMainMenu()));

}


QueueDisp1::~QueueDisp1()
{
	qDeleteAll(this->children());
}


void QueueDisp1::next()
{
	string x = "";
	int i = 0;
	movieTitle->setText(netflix->next());
	size = netflix->setNumKeywords();
	string * list = new string[size];

	tempMapKeyWords = netflix->getAllKeywords2();
	setIter = tempMapKeyWords.begin();
	while(setIter != tempMapKeyWords.end() && i<size){
		list[i] = *(setIter);
		i++;
		setIter++;
	}
	for(int i=0; i<size; i++){
		x = x + list[i] + '\n';
	}
	keywords->setText(QString::fromStdString(x));
	//movieLayout->addWidget(keywords[i]);
}

void QueueDisp1::addToMyQueue()
{
	netflix->addToMyQueue2();
	QMessageBox::information( 
	this, 
	tr("SUCCESS!"), 
	tr("Movie has been added to queue!") );
	//currentQueueLabel->setText(netflix->getCurrentQueueLabel());

}

void QueueDisp1::returnToMainMenu()
{
	p->show();
	this->close();
}

void QueueDisp1::closeEvent(QCloseEvent *x)
{
	x->accept();
	p->show();
	this->close();
}