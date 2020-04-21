#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

class OpenGLWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
		Q_OBJECT
	public:
		OpenGLWindow(QOpenGLContext* shareContext,
		             QOpenGLWindow::UpdateBehavior updateBehaviour = QOpenGLWindow::NoPartialUpdate,
		             QWindow* parent=0);

		OpenGLWindow(QOpenGLWindow::UpdateBehavior updateBehaviour = QOpenGLWindow::NoPartialUpdate,
		             QWindow* parent=0);
		~OpenGLWindow();
		// QOpenGLWindow interface
	protected:
		virtual void initializeGL() override;
		virtual void resizeGL(int w, int h) override;
		virtual void paintGL() override;

	private:
		QOpenGLShaderProgram* mProgram = nullptr;
		int mPosAttr = -1;
		int mColAttr = -1;

		int mMatrixUniform = -1;
};

#endif // OPENGLWINDOW_H
