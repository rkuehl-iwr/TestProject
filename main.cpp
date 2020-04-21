#include <QApplication>
#include "OpenGLWindow.h"

int main(int argc, char** argv)
{

	QApplication app(argc, argv);

	QSurfaceFormat format;
	format.setSamples(16);

	OpenGLWindow window;
	window.setFormat(format);
	window.resize(640,480);
	window.show();



	return app.exec();
}
