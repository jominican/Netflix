#include <QApplication>

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Netflix.h"
#include "LoginScreen.h"
#include "MainScreen.h"
#include "QueueDisp.h"
#include "NewUser.h"

using namespace std;


int main(int argc, char* argv[])
{

		QApplication app( argc, argv );

		Netflix netflix(argc, argv);//initializing an instance of netflix 
		LoginScreen n(argc, argv);//create a login window as the first window that shows up
		n.show();
		return app.exec();

}

