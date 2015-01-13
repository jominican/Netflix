#include "../lib/nsee.h"

class MyApplication : public QApplication
{
public:
    MyApplication(int &argc, char ** argv);
    // ~MyApplication();
private:
    bool notify(QObject *receiver, QEvent *event){
			try {
			    return QApplication::notify( receiver, event );
			} catch ( std::exception& e ) {
			    NoSuchElementException( e );
			    return false;
			}
    }
};