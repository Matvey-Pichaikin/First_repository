#include "My_Form.h"
#include <thread>

using namespace System;
using namespace Binary_tree;
using namespace System::Windows::Forms;

void runWindowsForms() {
    Application::Run(gcnew My_Form());
}

void runGLUT(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Binary tree");
    glutDisplayFunc(display);
    glutMainLoop();
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RU");
    // Запускаем GLUT в отдельном потоке
    std::thread glut_thread(runGLUT, argc, argv);
    glut_thread.detach(); // Отсоединяем поток GLUT

    // Запускаем Windows Forms в основном потоке
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    runWindowsForms();

    return 0;
}