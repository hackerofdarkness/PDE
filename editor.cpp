#include "editor.h"
#include "ui_editor.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QStringList>
#include <QImage>
#include "pokemondata.h"
#include "trainerdata.h"
#include <QtMultimedia/QSound>
#include <QPainter>
#include <QImageWriter>
#include <QSet>
#include <QDesktopServices>
#define Item_Max 60
/* Created by hackerofdarkness for the use of modifying the pokemon data in the poke decomps.
 * Files are located in the root directory, will work on: Windows, Mac, and Linux
 * Under development
*/

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(585, 450));
}

Editor::~Editor()
{
    delete ui;
}

// saves the data to JSON files
void JSON_Save()
{

}
// replaces the data in the original files
void appendPokeData(QString path, QString data)
{
    QFile file(path);
    QMessageBox box;
    if(file.open(QIODevice::Append))
    {
        file.write(data.toUtf8());
    }
    else
    {
        box.setText("file could not be appended.\n");
    }
}
// checks what version you're running.
QString pokemonVersion(QString root)
{

    qDebug() << "Pokemon version is : " << root;

    return root;
}
// opens the directory
void Editor::on_actionOpen_project_triggered()
{
    // Allows the user to set the existing directory to the decomp project.

    QString root = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    pokemonVersion(root);
}

// saves the data and changes
void Editor::on_actionSave_triggered()
{
    QString pokemonName;
    pokemonName = ui->pokemon_Name->text();
    ui->pokemon_Name_Box->addItem(pokemonName);
}

// uses a single sprite sheet and breaks it
void Editor::on_spriteSheets_clicked()
{
    QString root;
    QString spriteSheet =  QFileDialog::getOpenFileName(this, tr("Open front image"),"", tr("png (*.png);;All Files (*)"));
    QFile SpriteSheet(spriteSheet);
    QString frontLocation(root + "/graphics/pokemon/front_pics");
    QString backLocation(root + "/graphics/pokemon/front_pics");
    QString iconLocation(root + "/graphics/pokemon/icons");
    QString palLocation(root + "/graphics/pokemon/palettes");
    if(!SpriteSheet.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this, "Sprite sheet error", "Could not recieve image, was user input valid?");
    }
     else
    {
    QImage sprite(spriteSheet);
    QImage front(spriteSheet);
    QImage back;
    QImage shinyFront;
    QImage shinyBack;
    // reacts are used to grab the specific location of the image
    QRect spriteBack(130, 1, 64, 64);
    QRect spriteShinyFront(65, 1, 64, 64);
    QRect spriteShinyBack(195, 1, 64, 64);
    back = sprite.copy(spriteBack);
    shinyFront = sprite.copy(spriteShinyFront);
    shinyBack = sprite.copy(spriteShinyBack);
    ui->front_image->setPixmap(QPixmap::fromImage(front));
    ui->back_image->setPixmap(QPixmap::fromImage(back));
    ui->shiny_front->setPixmap(QPixmap::fromImage(shinyFront));
    ui->shiny_back->setPixmap(QPixmap::fromImage(shinyBack));
    }
}
// Allows the user to select a cry
void Editor::on_Cry_Button_clicked()
{
    QString cry =  QFileDialog::getOpenFileName(this, tr("Open cry"),"", tr("wave (*.wav);;All Files (*)"));
}
// lets the user select the icon
void Editor::on_Icons_clicked()
{
    QString iconSheet =  QFileDialog::getOpenFileName(this, tr("Open icon sprite sheet"),"",
                                                        tr("icon_sheet (*.png);;All Files (*)"));

    QFile icons(iconSheet);
    if(!icons.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this, "Sprite sheet error", "Could not recieve image, was user input valid?");
    }
     else
    {
        QImage iconSprite(iconSheet);
        QRect icon1(0,0, 64, 64);
        iconSprite.copy(icon1);
        ui->icon1->setPixmap(QPixmap::fromImage(iconSprite));
    }
}
// lets the user import a custom json file that contains the data
void Editor::on_actionImport_pokemon_file_triggered()
{
    QString fileImport =  QFileDialog::getOpenFileName(this, tr("Open pokemon json file"),"",
                                                        tr("Pokemon file (*.JSON);;All Files (*)"));
}




void Editor::on_pokemon_Number_Box_activated(const QString &arg1)
{
    ui->pokemon_Number_Box->insertItem(0, NULL);
}

void Editor::on_pokemon_Name_Box_activated(const QString &arg1)
{

}


// redirect to the github page
void Editor::on_pushButton_clicked()
{
    QUrl url;
    url.setScheme("http");
    url.setHost("github.com");
    url.setPath("/hackerofdarkness/PDE");
    QDesktopServices::openUrl(url);
}
// redirect to the issues page
void Editor::on_pushButton_3_clicked()
{
    QUrl url;
    url.setScheme("http");
    url.setHost("github.com");
    url.setPath("/hackerofdarkness/PDE/issues");
    QDesktopServices::openUrl(url);
}

void Editor::on_play_Button_clicked(QString soundfile)
{
   // QSound::play(soundfile);
}
