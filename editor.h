#ifndef EDITOR_H
#define EDITOR_H
#include <QString>
#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <QtMultimedia/QSound>
#include "pokemondata.h"
#include <QFile>
namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

private slots:
    void on_actionOpen_project_triggered();

    void on_actionSave_triggered();

    void on_spriteSheets_clicked();

    void on_spriteSheets_2_clicked();

    void on_Icons_clicked();



    void on_actionImport_pokemon_file_triggered();

    void on_Cry_Button_clicked();

    void on_play_Button_clicked(QFile cryFile);

    void on_pokemon_Number_Box_activated(const QString &arg1);

    void on_pokemon_Name_Box_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_play_Button_clicked(QString soundfile);

private:
    Ui::Editor *ui;


};

#endif // EDITOR_H
