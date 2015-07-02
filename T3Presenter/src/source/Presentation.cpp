#include "Presentation.hpp"
#include <QTextStream>
#include <QFile>
#include <QDir>
/*
 * Class that holds the paths of content
 */
Presentation::Presentation() : QObject() {}

/*
 * Capsuling List access methods
 */
void Presentation::add(QString imgPath) {
    pathList.append(imgPath);
}

bool Presentation::isEmpty() {
    return pathList.empty();
}

void Presentation::clear() {
    title = "";
    pathList.clear();
}

qint32 Presentation::getNumberOfPages() {
    return pathList.length();
}

QString Presentation::get(qint32 i) {
    return pathList.at(i);
}
/*
 * parameter access: title
 */
QString Presentation::getTitle() {
    return title;
}
void Presentation::setTitle(QString title) {
    this->title = title;
}
