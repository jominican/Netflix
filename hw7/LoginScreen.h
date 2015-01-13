#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QString>
#include <string>


#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Netflix.h"
#include "MainScreen.h"
#include "NewUser.h"


// helper function

class LoginScreen : public QMainWindow
{
	Q_OBJECT
	public:
		LoginScreen(int argc, char* argv[]);//(QWidget *parent = 0) //display the login window (first window displayed)
		~LoginScreen();

	private:

		QLabel 				 * welcomeLabel;
		QLabel 				 * loginLabel;

		QLineEdit 		 * login;
		QLineEdit 		 * password;

		QFormLayout 	 * loginRow;

		QPushButton    * quitButton;
		QPushButton    * loginButton;
		QPushButton    * newuserButton;	

		//QPlainTextEdit * txtWordsInput;
		QVBoxLayout    * winLayout;

		QHBoxLayout    * buttonLayout;
		QWidget        * centerWidget;

		Netflix 			 * netflix;

	private slots:
	//login window
		void loginIn();
		void newUser();
		void quit();




};

#endif