#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTranslator traducion;
    QStringList idiomas;
    idiomas << "Ruso" << "Chino" << "Albanes" << "Catalan";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);
    if (idiomaSeleccionado == "Catalan"){
        traducion.load(":/Graficos_ca_AD");
    }else if (idiomaSeleccionado == "Chino"){
        traducion.load(":/Graficos_zh_CN");
    }else if (idiomaSeleccionado == "Ruso"){
        traducion.load(":/Graficos_ru.qm");
    }else if (idiomaSeleccionado == "Albanes") {
        traducion.load(":/Graficos_sq_AL");
    }
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    Principal w;
    w.show();
    return a.exec();
}
