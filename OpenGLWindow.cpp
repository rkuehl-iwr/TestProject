#include "OpenGLWindow.h"

static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colAttr;\n"
    "varying lowp vec4 col;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   col = colAttr;\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 col;\n"
    "void main() {\n"
    "   gl_FragColor = col;\n"
    "}\n";

OpenGLWindow::OpenGLWindow(QOpenGLContext* shareContext,
                           QOpenGLWindow::UpdateBehavior updateBehaviour,
                           QWindow* parent) : QOpenGLWindow(shareContext, updateBehaviour, parent)
{

}

OpenGLWindow::OpenGLWindow(QOpenGLWindow::UpdateBehavior updateBehaviour, QWindow* parent)
                        : QOpenGLWindow(updateBehaviour, parent)
{

}

OpenGLWindow::~OpenGLWindow()
{

}


void OpenGLWindow::initializeGL()
{
	initializeOpenGLFunctions();

	mProgram = new QOpenGLShaderProgram(this);
	mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	mProgram->link();

	mPosAttr = mProgram->attributeLocation("posAttr");
	mColAttr = mProgram->attributeLocation("colAttr");

	mMatrixUniform = mProgram->uniformLocation("matrix");
}

void OpenGLWindow::resizeGL(int w, int h)
{

}

void OpenGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	const auto retinaScale = devicePixelRatio();
	glViewport(0,0, width() * retinaScale, height()*retinaScale);

	mProgram->bind();

	QMatrix matrix;

	mProgram->setUniformValue(mMatrixUniform, matrix);

	GLfloat vertices[] = {
	    0.0f, 0.707f,
	    -0.5f, -0.5f,
	    0.5f, -0.5f
	};

	GLfloat colors[] = {
	    1.0f, 0.0f, 0.0f,
	    0.0f, 1.0f, 0.0f,
	    0.0f, 0.0f, 1.0f
	};

	glVertexAttribPointer(mPosAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(mColAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	mProgram->release();
}
