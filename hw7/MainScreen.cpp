#include "MainScreen.h"
#include <sstream>
#include <string>
#include <exception>

using namespace std;

MainScreen::MainScreen(QMainWindow *parent, Netflix * n) : QMainWindow(parent)
{
	p = parent;
	netflix = n;
	QString welcomeLabel = "Welcome to Netflics, "+netflix->ID()+" ("+netflix->Name()+")";
	mainScreenLabel  				= new QLabel(welcomeLabel);
	label1									= new QLabel("Your Current Movie");
	label2									= new QLabel("Your Movie Queue");
	label3									= new QLabel("Search for a Movie");
	QString movieLabel 			= netflix->getCurrentMovieLabel();
	currentMovieLabel       = new QLabel(movieLabel);
	QString queueLabel      = netflix->getCurrentQueueLabel();
	currentQueueLabel       = new QLabel(queueLabel);
	QString p               = "$"+netflix->getCurrentPriceLabel();
	priceLabel              = new QLabel(p);

	mainLayout				     	= new QVBoxLayout();

	button1Layout 					= new QHBoxLayout();
	button2Layout 					= new QHBoxLayout();
	button3Layout 					= new QHBoxLayout();
	button4Layout 					= new QHBoxLayout();
	button5Layout 					= new QHBoxLayout();
	button6Layout 					= new QHBoxLayout();


	returnButton    				= new QPushButton("&Return Movie");
	rentButton   						= new QPushButton("R&ent Movie");
	deleteQueueButton    		= new QPushButton("&Delete from Queue");
	moveBackButton    			= new QPushButton("Move to &Back of Queue");
	searchByTitleButton    	= new QPushButton("Search by &Title");
	searchByKeywordButton   = new QPushButton("Search by &Keyword");
	searchByActorButton     = new QPushButton("Search by &Actor");
	logoutButton						= new QPushButton("&Logout");
	refreshButton						= new QPushButton("Re&fresh Queue");
	viewRatings							= new QPushButton("View Ratings");
	no 											= new QPushButton("NO");
	changePass							= new QPushButton("Change Password");

	searchRow 							= new QFormLayout();
	search 									= new QLineEdit();
	passRow									= new QFormLayout();
	pass                    = new QLineEdit();

	QFrame* line1						= new QFrame();
	QFrame* line2						= new QFrame();
	QFrame* line3						= new QFrame();
	QFrame* line4						= new QFrame();
	QFrame* line5						= new QFrame();
	QFrame* line6						= new QFrame();


	
	// // setup the grid layout and make it fill the window

	centerWidget  = new QWidget(this);
	centerWidget->setLayout(mainLayout);
	this->setCentralWidget(centerWidget);


	// // add all widgets to the layout
	mainLayout->addWidget(mainScreenLabel);
	line1->setFrameShape(QFrame::HLine);
	line1->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line1);
	mainLayout->addWidget(label1);
	mainLayout->addWidget(currentMovieLabel);
	mainLayout->addWidget(priceLabel);
	button1Layout->addWidget(returnButton);
	mainLayout->addLayout(button1Layout);

	line2->setFrameShape(QFrame::HLine);
	line2->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line2);
	mainLayout->addWidget(label2);
	mainLayout->addWidget(currentQueueLabel);
	button2Layout->addWidget(rentButton);
	button2Layout->addWidget(deleteQueueButton);
	button2Layout->addWidget(moveBackButton);
	button2Layout->addWidget(refreshButton);
	mainLayout->addLayout(button2Layout);

	line3->setFrameShape(QFrame::HLine);
	line3->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line3);
	mainLayout->addWidget(label3);
	searchRow->addRow("Search:", search);
	button3Layout->addWidget(searchByTitleButton);
	button3Layout->addWidget(searchByKeywordButton);
	button3Layout->addWidget(searchByActorButton);
	mainLayout->addLayout(searchRow);
	mainLayout->addLayout(button3Layout);

	line4->setFrameShape(QFrame::HLine);
	line4->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line4);
	passRow->addRow("New Password:", pass);
	button4Layout->addWidget(changePass);
	mainLayout->addLayout(passRow);
	mainLayout->addLayout(button4Layout);

	line5->setFrameShape(QFrame::HLine);
	line5->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line5);
	button5Layout->addWidget(viewRatings);
	mainLayout->addLayout(button5Layout);

	line6->setFrameShape(QFrame::HLine);
	line6->setFrameShadow(QFrame::Sunken);
	mainLayout->addWidget(line6);
	button6Layout->addWidget(logoutButton);
	mainLayout->addLayout(button6Layout);


	connect(returnButton,      SIGNAL(clicked()),     this, SLOT(returnMovie()));
	connect(rentButton,      SIGNAL(clicked()),     this, SLOT(rentMovie()));
	connect(deleteQueueButton,      SIGNAL(clicked()),     this, SLOT(deleteFromQueue()));
	connect(moveBackButton,      SIGNAL(clicked()),     this, SLOT(moveToBack()));
	connect(searchByTitleButton,      SIGNAL(clicked()),     this, SLOT(searchByTitle()));
	connect(searchByKeywordButton,      SIGNAL(clicked()),     this, SLOT(searchByKeyword()));
	connect(searchByActorButton,      SIGNAL(clicked()),     this, SLOT(searchByActor()));
	connect(logoutButton,      SIGNAL(clicked()),     this, SLOT(logout()));
	connect(refreshButton, 	SIGNAL(clicked()), this, SLOT(refresh()));
	connect(viewRatings, 	SIGNAL(clicked()), this, SLOT(view()));
	connect(changePass, SIGNAL(clicked()), this, SLOT(changing()));



}


MainScreen::~MainScreen()
{
	qDeleteAll(this->children());
}

void MainScreen::returnMovie()
{
				QString x = netflix->getCurrentPriceLabel();
				x = "You have been charged $"+x;
	if(netflix->returnMovie()){
					// this, tr("WARNING!"), tr("You have been charged"), p);
			QMessageBox* box = new QMessageBox();
			box->setText(x);
			box->exec();
		if(netflix->needsRating()){
			QMessageBox::information( 
			this, 
			tr("SUCCESS!"), 
			tr("Your movie has been returned") );
			currentMovieLabel->setText("You have no movie checked out");
			priceLabel->setText("No price");
			RatingScreen* rs = new RatingScreen(this, netflix);
			rs->show();
			this->hide();
		}
		else{
			int r = QMessageBox::information( 
			this, 
			tr("SUCCESS!"), 
			tr("Your movie has been returned. You have already rated this movie. Do you want to modify your ratings?"), QMessageBox::Yes | QMessageBox::No );
			if(r == QMessageBox::Yes){
				RatingScreen* rs = new RatingScreen(this, netflix);
				rs->show();
				this->hide();
			}
			currentMovieLabel->setText("You have no movie checked out");
			priceLabel->setText("No price");
		}
	}
	else{
	  QMessageBox::information( 
		this, 
		tr("!"), 
		tr("You have no movie to return!") );
	}

}

void MainScreen::rentMovie()
{
	if(netflix->rentMovie() == 1){
		QMessageBox::information( 
		this, 
		tr("SUCCESS!"), 
		tr("You have successfully rented this movie!") );
		currentMovieLabel->setText(netflix->getCurrentMovieLabel());
		currentQueueLabel->setText(netflix->getCurrentQueueLabel());
		priceLabel->setText(netflix->getCurrentPriceLabel());
	}
	else if(netflix->rentMovie() == 2){
		QMessageBox::information( 
		this, 
		tr("ERROR!"), 
		tr("You have no movie in queue. Please add a movie to queue") );
		currentQueueLabel->setText("You have no movies in queue");
	}
	else{
		QMessageBox::information( 
		this, 
		tr("ERROR!"), 
		tr("You already have a movie checked out. Please return your checkedout movie before renting another one") );
	}

}

void MainScreen::deleteFromQueue()
{
	if(netflix->deleteFromQueue()){
		QMessageBox::information( 
		this, 
		tr("SUCCESS!"), 
		tr("The movie has been deleted from queue") );
		currentQueueLabel->setText(netflix->getCurrentQueueLabel());
	}
	else{
		QMessageBox::information( 
		this, 
		tr("!"), 
		tr("There are no movies in your queue to remove") );
	}

}

void MainScreen::moveToBack()
{
	if(netflix->moveToBack()){
		QMessageBox::information( 
		this, 
		tr("SUCCESS!"), 
		tr("The movie has been moved to the back of the queue!") );
		currentQueueLabel->setText(netflix->getCurrentQueueLabel());
	}
	else{
		QMessageBox::information( 
		this, 
		tr("!"), 
		tr("There are no movies in your queue to move to back") );
	}	

}

void MainScreen::refresh()
{
	currentQueueLabel->setText(netflix->getCurrentQueueLabel());
}

void MainScreen::searchByTitle()
{
	string temp = search->text().toStdString();
	if(netflix->searchByTitle(temp)){
		QueueDisp* qd = new QueueDisp(this, netflix);
		qd->show();
		this->hide();
	}
	else{
		QMessageBox::information( 
		this, 
		tr(":("), 
		tr("No movie found with that title!") );
	}


}

void MainScreen::searchByKeyword()
{
	string temp = search->text().toStdString();
	if(netflix->searchByKeyword(temp) == 1){
		QueueDisp1* qd1 = new QueueDisp1(this, netflix);
		qd1->show();
		this->hide();
	}
	else if(netflix->searchByKeyword(temp) == 2){
		QMessageBox::information( 
		this, 
		tr("WARNING!"), 
		tr("You have entered a keyword that is also a movie title. Try searching by title with that keyword!") );		
	}
	else{
		QMessageBox::information( 
		this, 
		tr(":("), 
		tr("No movie found with that keyword!") );
	}
}

void MainScreen::searchByActor()
{
	string temp = search->text().toStdString();
	if(netflix->searchByActor(temp) == 1){
		QueueDisp1* qd1 = new QueueDisp1(this, netflix);
		qd1->show();
		this->hide();
	}
	else if(netflix->searchByActor(temp) == 2){
		QMessageBox::information( 
		this, 
		tr("WARNING!"), 
		tr("You have entered an actor that is also a movie title. Try searching by title with that actor!") );		
	}
	else{
		QMessageBox::information( 
		this, 
		tr(":("), 
		tr("No movie found with that actor!") );
	}
}

void MainScreen::view()
{

		RatingsDisp* qd1 = new RatingsDisp(this, netflix);
		qd1->show();
		this->hide();
}

void MainScreen::changing()
{
	string temp = pass->text().toStdString();
	if(netflix->changingPassword(temp)){
		QMessageBox::information( 
		this, 
		tr("SUCCESS!"), 
		tr("You have successfully changed your password!") );
	}
	else{
		QMessageBox::information( 
		this, 
		tr("WARNING!"), 
		tr("You have not entered anything for a new passowrd!") );
	}
}

void MainScreen::logout()
{
	p->show();
	this->close();
}

void MainScreen::closeEvent(QCloseEvent *x)
{
	x->accept();
	p->show();
	this->close();
}